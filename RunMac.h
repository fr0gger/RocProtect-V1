#include <stdio.h>
#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>
#pragma comment(lib, "iphlpapi.lib")

char* getMAC()
{
    PIP_ADAPTER_INFO AdapterInfo;
    DWORD dwBufLen = sizeof(AdapterInfo);
    char *mac_addr = (char*)malloc(17);

    DWORD dwType = REG_SZ;
    HKEY hKey = 0;
    char value[1024];
    char adaptinfo[1024];
    DWORD value_length = 1024;
    // You can change by other Mac Address
    // VMware Mac Address: "00:0C:29", "00:1C:14", "00:50:56", "00:05:69"
    string vboxmac = "08:00:27";

    LPSTR RegPath[] = { "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\0001",
                        "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\0000",
                        "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\0002",
                        "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\0003",
                        "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\0004",
                        "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\0005"};

    AdapterInfo = (IP_ADAPTER_INFO *) malloc(sizeof(IP_ADAPTER_INFO));

    if (AdapterInfo == NULL)
    {
        printf("[!]Error allocating memory needed to call GetAdaptersinfo\n");
    }
    // Make an initial call to GetAdaptersInfo to get the necessary size into the dwBufLen variable
    if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_BUFFER_OVERFLOW)
    {
        AdapterInfo = (IP_ADAPTER_INFO *) malloc(dwBufLen);
        if (AdapterInfo == NULL)
        {
            printf(" [!]Error allocating memory needed to call GetAdaptersinfo\n");
        }
    }

    if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR)
    {
        PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
        do
        {
            sprintf(mac_addr, "%02X:%02X:%02X:%02X:%02X:%02X",
            pAdapterInfo->Address[0], pAdapterInfo->Address[1],
            pAdapterInfo->Address[2], pAdapterInfo->Address[3],
            pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
            printf(" [*] Current IP address: %s\n", pAdapterInfo->IpAddressList.IpAddress.String);
            printf(" [*] Current MAC Address: %s\n", mac_addr);
            printf(" [*] Current Adaptater description: %s\n", pAdapterInfo->Description);
            //printf(" [LOG] ComboIndex: \t%d\n", pAdapterInfo->ComboIndex);
            //printf(" [LOG] Adapter Name: \t%s\n\n", pAdapterInfo->AdapterName);

            // Variable manipulation
            char* adaptinfo = pAdapterInfo->Description;
            char* NewValue = value;

            for (int i = 0; i < (sizeof(RegPath) / sizeof(LPSTR)); i++)
            {
                if ( RegOpenKeyEx(
                     HKEY_LOCAL_MACHINE,
                     RegPath[i],
                     0,
                     KEY_ALL_ACCESS,
                     &hKey ) == ERROR_SUCCESS)
                {
                    //cout << " [LOG] Success registry key " << (RegPath[i]) << " opened " << endl;
                    // read the version value
                    if( RegQueryValueEx(hKey, "DriverDesc", NULL, &dwType, (LPBYTE)&value, &value_length) == ERROR_SUCCESS)
                    {

                        if(strcmp(adaptinfo, NewValue))
                        {
                            //printf(" [LOG] %s\n", adaptinfo);
                            //printf(" [LOG]%s\n", NewValue);
                            //printf(" [LOG] Not Matching!!! \n\n");
                        }
                        else
                        {
                            printf(" [LOG] Matching!!! \n");
                            // Convert mac_addr to string
                            std::string MAC(mac_addr);
                            // Split strings => MAC.substr(0,8);
                            // Replace the first 6 byte
                            string MacSplit = MAC.replace (0,8,vboxmac);
                            // Convert the string to char
                            const char* NewMac = MacSplit.c_str();

                            //modify the registry value related to the mac address
                            LPCTSTR value1 = TEXT("NetworkAddress");
                            LPCTSTR data1 = NewMac;

                            if (RegSetValueEx (hKey, value1, 0, REG_SZ, (LPBYTE)data1, strlen(data1)+1) == ERROR_SUCCESS)
                            {
                                cout << " [*] Registry key " << (RegPath[i]) << " created!\n [*] With the value " << (data1) << endl;
                                printf(" [INFO] Fake MAC address creation OK!\n\n");
                            }
                            else
                            {
                                printf(" [!] Error writing to Registry\n");
                            }
                        }
                    }
                    else
                    {
                        //printf("ERROR\n\n");
                    }

                    if (RegCloseKey(hKey) == ERROR_SUCCESS)
                    {
                        //printf("close key ok \n");
                        Sleep(500);
                    }
                    else
                    {
                        printf(" [!] Error closing key\n");
                    }
                }
                else
                {
                    printf(" [!]Error opening key\n");
                }
            }
            return mac_addr;
            pAdapterInfo = pAdapterInfo->Next;
        }
        while(pAdapterInfo);
    }
    free(AdapterInfo);
}

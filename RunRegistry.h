#ifndef RUNREGISTRY_H_INCLUDED
#define RUNREGISTRY_H_INCLUDED
#include<Windows.h>
#include<stdio.h>
#include<iostream>

#endif // RUNREGISTRY_H_INCLUDED

using namespace std;

void RegistryArtifacts()
{
    HKEY hKey;
    // Replace Scsifake by Scsi on a target machine
    // Replace VMwareFAKE by VMware
    // Table initialization
    LPCTSTR RegValuePath[] = { "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 0\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0",
                               "SOFTWARE\\VMware, Inc.\\VMware Tools",
                               "HARDWARE\\Description\\System",  // Don't change the place of this key
                               "SOFTWARE\\Oracle\\VirtualBox Guest Additions",
                               "SYSTEM\\ControlSet001\\Services\\Disk\\Enum",
                               "HARDWARE\\ACPI\\DSDT\\VBOX__",
                               "HARDWARE\\ACPI\\FADT\\VBOX__",
                               "HARDWARE\\ACPI\\RSDT\\VBOX__",
                               "SYSTEM\\ControlSet001\\Services\\VBoxGuest",
                               "SYSTEM\\ControlSet001\\Services\\VBoxMouse",
                               "SYSTEM\\ControlSet001\\Services\\VBoxService",
                               "SYSTEM\\ControlSet001\\Services\\VBoxSF",
                               "SYSTEM\\ControlSet001\\Services\\VBoxVideo",
                               };

    LPCTSTR RegWine = "SOFTWARE\\Wine";
    //create Wine key
    if (RegCreateKeyEx(
                       HKEY_CURRENT_USER,
                       RegWine, // variable for the loop
                       0,
                       NULL,
                       REG_OPTION_NON_VOLATILE,
                       KEY_WRITE,
                       NULL,
                       &hKey,
                       NULL
                       ) == ERROR_SUCCESS)
        {
            cout << " [*] Success registry key " << (RegWine) << " created" << endl;
        }
        else
        {
            cout << " [!] Failed Registry key " << (RegWine) << " not created\n" << endl;
        }

    // Loop to write registry
    for (int i = 0; i < (sizeof(RegValuePath) / sizeof(LPCWSTR)); i++)
    {
        if (RegCreateKeyEx(
                       HKEY_LOCAL_MACHINE,
                       RegValuePath[i], // variable for the loop
                       0,
                       NULL,
                       REG_OPTION_NON_VOLATILE,
                       KEY_WRITE,
                       NULL,
                       &hKey,
                       NULL
                       ) == ERROR_SUCCESS)
        {
            cout << " [*] Success registry key " << (RegValuePath[i]) << " created" << endl;
        }
        else
        {
            cout << " [!] Failed Registry key " << (RegValuePath[i]) << " not created\n" << endl;
        }

        // Open the new key just created
        if (RegOpenKeyEx(
                     HKEY_LOCAL_MACHINE,
                     RegValuePath[i],
                     0,
                     KEY_ALL_ACCESS,
                     &hKey) == ERROR_SUCCESS)
        {
            //nothing use for debug
        }
        else
        {
            printf("[!]Error opening key\n");
        }
        // Setup the value virtual value into the new registry key
        LPCTSTR value1 = TEXT("Identifier");
        LPCTSTR data1 = "VMWARE";

        LPCTSTR value2 = TEXT("SystemBiosVersion");
        LPCTSTR data2 = "VBOX";

        LPCTSTR value3 = TEXT("0");
        LPCTSTR data3 = "VBOX VIRTUAL VMWARE";

        LPCTSTR value4 = TEXT("VideoBiosVersion");
        LPCTSTR data4 = "VIRTUALBOX";
        // Date for VirtualBox
        LPCTSTR value5 = TEXT("SystemBiosDate");
        LPCTSTR data5 = "06/23/99";

        if (RegValuePath[i] == RegValuePath[0])
        {
            if (RegSetValueEx (hKey, value1, 0, REG_SZ, (LPBYTE)data1, strlen(data1)+1) == ERROR_SUCCESS)
            {
                cout << " [*] Success registry key " << (RegValuePath[i]) << " created\n [*] With the value " << (data1) << endl;
            }
            else
            {
                printf(" [!] Error writing to Registry\n");
            }
        }
        else if (RegValuePath[i] == RegValuePath[2])
        {
            if (RegSetValueEx (hKey, value2, 0, REG_SZ, (LPBYTE)data2, strlen(data2)+1) == ERROR_SUCCESS)
            {
                cout << " [*] Success registry key " << (RegValuePath[i]) << " created\n [*] With the value " << (data2) << endl;
            }
            else
            {
                printf(" [!] Error writing to Registry\n");
            }
        }
        else if (RegValuePath[i] == RegValuePath[4])
        {
            if (RegSetValueEx (hKey, value3, 0, REG_SZ, (LPBYTE)data3, strlen(data3)+1) == ERROR_SUCCESS)
            {
                cout << " [*] Success registry key " << (RegValuePath[i]) << " created\n [*] With the value " << (data3) << endl;
            }
            else
            {
                printf(" [!] Error writing to Registry\n");
            }
        }

        if (RegValuePath[i] == RegValuePath[2])
        {
            if (RegSetValueEx (hKey, value4, 0, REG_SZ, (LPBYTE)data4, strlen(data4)+1) == ERROR_SUCCESS)
            {
                cout << " [*] Success registry key " << (RegValuePath[i]) << " created\n [*] With the value " << (data4) << endl;
            }
            else
            {
                printf(" [!] Error writing to Registry\n");
            }
        }

        if (RegValuePath[i] == RegValuePath[2])
        {
            if (RegSetValueEx (hKey, value5, 0, REG_SZ, (LPBYTE)data5, strlen(data5)+1) == ERROR_SUCCESS)
            {
                cout << "[ *] Success registry key " << (RegValuePath[i]) << " created\n [*] With the value " << (data5) << endl;
            }
            else
            {
                printf(" [!] Error writing to Registry\n");
            }
        }

        // Close the registry key
        if (RegCloseKey(hKey) == ERROR_SUCCESS)
            {
                //nothing use for debug
            }
        else
            {
                printf(" [!] Error closing key\n");
            }
    }
    printf(" [INFO] Registry artifacts creation OK! \n\n");
}

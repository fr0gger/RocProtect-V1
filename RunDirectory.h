#ifndef RUNDIRECTORY_H_INCLUDED
#define RUNDIRECTORY_H_INCLUDED
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <WCHAR.h>
#include <winbase.h>
#include <direct.h>
#endif // RUNDIRECTORY_H_INCLUDED

using namespace std;

int CreateFakeDirectory()
{
    LPCSTR fname[] = {"C\\Cuckoo",
                      "C\\SANDBOX",
                      "C\\VIRUS",
                      "C\\MALWARE",
                      "c:\\test",
                     //"C:\\program files\\oracle\\virtualbox guest additions\\",
                    };

    // create folder quick & dirty style
    mkdir("C:\\Cuckoo");
    mkdir("C:\\SANDBOX");
    mkdir("C:\\VIRUS");
    mkdir("C:\\MALWARE");
    //mkdir("C:\\program files\\oracle\\virtualbox guest additions\\");

    /*for (int i = 0; i < (sizeof(fname) / sizeof(LPCSTR)); i++)
    {
        // create a new fake directory.
        /*if (CreateDirectoryA(fname[i], NULL) || ERROR_ALREADY_EXISTS == GetLastError())
        {
            cout << "[*] Fake directory " << fname[i] << " created!" << endl;
        }
        else
        {
            cout << "[!] Directory creation failed!" << endl;

        }
    }*/
    printf(" [INFO] Fake directory creation OK!\n\n");
    return 0;
}

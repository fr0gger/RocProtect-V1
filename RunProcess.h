#ifndef RUNPROCESS_H_INCLUDED
#define RUNPROCESS_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#endif // RUNPROCESS_H_INCLUDED

using namespace std;

int CreateFakeProcess()
{
    // You have to setup the folder with the fake program (e.g: c:\tmp\fake.exe)
    LPSTR ProcessName[] = { "c:\\temp\\fake.exe",
                            "c:\\temp\\ProcMon.exe",
                            "c:\\temp\\VBoxService.exe",
                            "c:\\temp\\VBoxTray.exe",
                            "c:\\temp\\Fiddler.exe",
                            /*"c:\\temp\\Wireshark.exe",
                            "c:\\temp\\VMwareService.exe",
                            "c:\\temp\\TPAutoConnSvc.exe",
                            "c:\\temp\\vmtoolsd.exe",
                            "c:\\temp\\VMwareTray.exe",
                            "c:\\temp\\python.exe",
                            "c:\\temp\\pythonw.exe",*/
                            // INSERT NEW PROCESS HERE
                            "c:\\temp\\ProcExp.exe",
                            };

    for (int i = 0; i < (sizeof(ProcessName) / sizeof(LPSTR)); i++)
    {
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory( &si, sizeof(si) );
        si.cb = sizeof(si);
        ZeroMemory( &pi, sizeof(pi) );

        // Run son process
        if( !CreateProcessA
            (
            NULL,
            ProcessName[i],
            NULL,
            NULL,
            FALSE,
            CREATE_SUSPENDED, //CREATE_NO_WINDOW,
            NULL,
            NULL,
            &si,
            &pi))
        {
            printf( " [!] Process creation failed...\n" );
        }
            cout << " [*] Processus " << (ProcessName[i]) << " created!" << endl;

        // Wait 5000 ms than loop on the other
        WaitForSingleObject( pi.hProcess, 2000 );

        // Ferme les handles de processus et de thread
        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );

        // Loop until ProcExp.exe
        if (ProcessName[i] == "c:\\temp\\ProcExp.exe")
        {
            printf(" [INFO] Fake process creation OK!\n\n");
            return 0;
        }
        else
        {
            CopyFile(ProcessName[i],ProcessName[i+1],0);
        }
    }
}



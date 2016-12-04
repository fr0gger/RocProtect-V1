#ifndef RUNFILE_H_INCLUDED
#define RUNFILE_H_INCLUDED
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<WCHAR.h>
#endif // RUNFILE_H_INCLUDED


int CreateFakeFile()
{
    bool hAppend;
    LPSTR fname[] = {"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\agent.pyw",
                     "C:\\WINDOWS\\system32\\drivers\\vmmouse.sys",
                     "C:\\WINDOWS\\system32\\drivers\\vmhgfs.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxMouse.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxGuest.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxSF.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxVideo.sys",
                     "C:\\WINDOWS\\system32\\vboxdisp.dll",
                     "C:\\WINDOWS\\system32\\vboxhook.dll",
                     "C:\\WINDOWS\\system32\\vboxmrxnp.dll",
                     "C:\\WINDOWS\\system32\\vboxogl.dll",
                     "C:\\WINDOWS\\system32\\vboxoglarrayspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglcrutil.dll",
                     "C:\\WINDOWS\\system32\\vboxoglerrorspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglfeedbackspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglpackspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglpassthroughspu.dll",
                     "C:\\WINDOWS\\system32\\vboxservice.exe",
                     "C:\\WINDOWS\\system32\\vboxtray.exe",
                     "C:\\WINDOWS\\system32\\VBoxControl.exe",
                     // ADD YOUR FILE HERE!
                    };

    for (int i = 0; i < (sizeof(fname) / sizeof(LPSTR)); i++)
    {
        // Open the existing file, or if the file does not exist,
        // Create a new file.
       if(hAppend = CreateFile(fname[i], // open file
                         GENERIC_WRITE, // open for writing
                         0, // do not share
                         NULL, // default security
                         OPEN_ALWAYS, // open or create
                         FILE_ATTRIBUTE_NORMAL, // normal file
                         NULL) == INVALID_HANDLE_VALUE) // no attribute template
        {
            cout << " [!] File creation failed!" << endl;
        }
        else
        {
            cout << " [*] File " << fname[i] << " created!" << endl;
        }
    }
    printf(" [INFO] Fake file creation OK!\n\n");
    return 0;
}

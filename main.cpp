// RocProtect - A simple emulation tool to protect against malware aware of Analysis Machine
// By Thomas Roccia
// @fr0gger_
// thomas.roccia@gmail.com

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <windows.h>
#include "RunProcess.h"
#include "RunRegistry.h"
#include "RunFile.h"
#include "RunDirectory.h"
#include "RunMac.h"

#ifndef RUNREGISTRY_H_INCLUDED
#define RUNREGISTRY_H_INCLUDED

#endif // RUNREGISTRY_H_INCLUDED


int main()
{
    printf("***************************************************************************\n"
           "**           _____            _____           _            _             **\n"
           "**          |  __ \\          |  __ \\         | |          | |            **\n"
           "**          | |__) |___   ___| |__) | __ ___ | |_ ___  ___| |_           **\n"
           "**          |  _  // _ \\ / __|  ___/  __/ _ \\| __/ _ \\/ __| __|          **\n"
           "**          | | \\ \\ (_) | (__| |   | | | (_) | ||  __/ (__| |_           **\n"
           "**          |_|  \\_\\___/ \\___|_|   |_|  \\___/ \\__\\___|\\___|\\__|          **\n"
           "**                                                                       **\n"
           "**                  © Unprotect Project - unprotect.tdgt.org             **\n"
           "**     Stay protected against malware by emulating analysis machine      **\n"
           "**                     Thomas Roccia - @fr0gger_                         **\n"
           "***************************************************************************\n\n");

    printf(" [INFO] Run this tool with administrator right!\n\n");

    CreateFakeProcess();
    RegistryArtifacts();
    CreateFakeDirectory();
    CreateFakeFile();
    getMAC();

    printf(" [DONE] You put the artifacts in your system!\n\n");

    system("PAUSE");
    return 0;
}

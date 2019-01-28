# RocProtect 

Malware are able sometimes to detect a virtual environment to avoid analysis and detection. RocProtect is a quick and dirty POC to simulate Virtual artifacts into a physical machine.

It will create the following on a machine:
* Fake registry keys of Vmware/VirtualBox/Qemu
* Fake processes (VmwareTray.exe, VboxService.exe, wireshark.exe...)
* Fake directories (Wine, Vmware Tools, VirtualBox Tools...)
* Fake files (vmouse.sys, vboxhook.dll, VboxGuest.sys...)
* Fake MAC address related to Vmware or VirtualBox


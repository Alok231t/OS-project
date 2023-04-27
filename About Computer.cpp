#include <iostream>
#include <windows.h>
#include <psapi.h>

using namespace std;

int main() {


    #ifndef ONLINE_JUDGE
                        freopen("inputf.in", "r", stdin);
                        freopen("outputf.out", "w", stdout);
                        #endif
    // Get the computer name
    char buffer[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(buffer);
    if (!GetComputerName(buffer, &size)) {
        cerr << "Error: Unable to get computer name." << endl;
        return 1;
    }
    string computerName(buffer, size);

    // Get the amount of RAM
    MEMORYSTATUSEX memory;
    ZeroMemory(&memory, sizeof(memory));
    memory.dwLength = sizeof(memory);
    if (!GlobalMemoryStatusEx(&memory)) {
        cerr << "Error: Unable to get memory information." << endl;
        return 1;
    }
    string ramSize = to_string(memory.ullTotalPhys / (1024 * 1024)) + " MB";

    // Get the amount of storage
    ULARGE_INTEGER freeBytes;
    ULARGE_INTEGER totalBytes;
    ULARGE_INTEGER totalFreeBytes;
    if (!GetDiskFreeSpaceEx(NULL, &freeBytes, &totalBytes, &totalFreeBytes)) {
        cerr << "Error: Unable to get storage information." << endl;
        return 1;
    }
    string storageSize = to_string(totalBytes.QuadPart / (1024 * 1024 * 1024)) + " GB";

    // Get the operating system information
    string osName;
    #ifdef _WIN32
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    if (!GetVersionEx(reinterpret_cast<OSVERSIONINFO*>(&osvi))) {
        cerr << "Error: Unable to get operating system information." << endl;
        return 1;
    }
    switch (osvi.dwMajorVersion) {
        case 11:
            osName = "Windows 11";
            break;
        case 10:
            if (osvi.dwMinorVersion == 0) {
                osName = "Windows 10";
            } else if (osvi.dwMinorVersion == 1) {
                osName = "Windows 10 October 2020 Update (20H2)";
            } else if (osvi.dwMinorVersion == 2) {
                osName = "Windows 10 May 2021 Update (21H1)";
            }
            break;
        case 6:
            switch (osvi.dwMinorVersion) {
                case 3:
                    osName = "Windows 8.1";
                    break;
                case 2:
                    osName = "Windows 8";
                    break;
                case 1:
                    osName = "Windows 7";
                    break;
                case 0:
                    osName = "Windows Vista";
                    break;
            }
            break;
        case 5:
            switch (osvi.dwMinorVersion) {
                case 2:
                    osName = "Windows Server 2003";
                    break;
                case 1:
                    osName = "Windows XP";
                    break;
                case 0:
                    osName = "Windows 2000";
                    break;
            }
            break;
    }
    #elif _APPLE_
    struct utsname info;
    if (uname(&info) != 0) {
        cerr << "Error: Unable to get operating system information." << endl;
        return 1;
    }
    osName = info.sysname;
    #elif _linux_
    struct utsname info;
    if (uname(&info) != 0) {
        cerr << "Error: Unable to get operating system information." << endl;
        return 1;
    }
    osName = info.sysname;
    #else
    osName = "Unknown operating system";
#endif

    // Print the system information
    cout << "Computer name: " << computerName << endl;
    cout << "Operating system: " << osName << endl;
    cout << "RAM size: " << ramSize << endl;
    cout << "Storage size: " << storageSize << endl;

    return 0;
}
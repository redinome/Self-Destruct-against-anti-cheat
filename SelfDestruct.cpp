#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>
#include "SelfDestruct.h"

// List of known anti-cheat processes or patterns
std::vector<std::wstring> antiCheatProcesses = {
    L"AntiCheatService.exe", // Replace with actual anti-cheat process names
    L"AntiCheatGuard.exe",
    L"BEService.exe",        // BattlEye
    L"DenuvoAntiCheat.exe",  // Denuvo Anti-Cheat
    L"EasyAntiCheat.exe",    // Easy Anti-Cheat (EAC)
    L"FairFight.exe",        // FairFight
    L"GameMon.des",          // GameGuard
    L"PnkBstrA.exe",         // PunkBuster Service A
    L"PnkBstrB.exe",         // PunkBuster Service B
    L"vgk.sys",              // Riot Vanguard
    L"SteamService.exe",     // Steam Anti-Cheat
    L"VAC.exe",              // Valve Anti-Cheat (VAC)
    L"x3.xem",               // Xenuine
    // ... add more as needed
};

bool IsBlacklistedProcessRunning() {
    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32W);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32FirstW(snapshot, &entry)) {
        do {
            for (const auto& process : antiCheatProcesses) {
                if (std::wstring(entry.szExeFile) == process) {
                    CloseHandle(snapshot);
                    return true;
                }
            }
        } while (Process32NextW(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return false;
}

void CheckForBlacklistedProcesses() {
    if (IsBlacklistedProcessRunning()) {
        // Take appropriate action, e.g., shut down your application
        ExitProcess(0);
    }
}

#pragma once

#ifndef SELF_DESTRUCT_H
#define SELF_DESTRUCT_H

#include <string>
#include <vector>

extern std::vector<std::string> antiCheatProcesses;

bool IsBlacklistedProcessRunning();
void CheckForBlacklistedProcesses();

#endif // SELF_DESTRUCT_H

#include "stdafx.h"

LONG g_cLocks = 0;

void LockModule(void) { InterlockedIncrement(&g_cLocks); }
void UnlockModule(void) { InterlockedDecrement(&g_cLocks); }
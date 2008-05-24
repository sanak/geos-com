#pragma once
#pragma warning(disable: 4996)

#include <windows.h>
#include <olectl.h>
#include <comutil.h>

#define offsetof(s,m) (size_t)&(((s *)0)->m)

extern LONG g_cLocks;

extern void LockModule(void);
extern void UnlockModule(void);

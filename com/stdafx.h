/*****************************************************************************
 *
 * FileName: stdafx.h
 * Project:  GEOS COM Wrapper - http://sourceforge.jp/projects/geos-com
 * Purpose:  Precompiled header definition.
 * Author:   geosanak, geosanak@gmail.com
 *
 * Copyright (C) 2006-2008 geosanak
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 *****************************************************************************/

#pragma once
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <windows.h>
#include <olectl.h>
#include <comutil.h>
#include <comdef.h>
#include <objbase.h>
#include <tchar.h>

#define offsetof(s,m) (size_t)&(((s *)0)->m)

extern LONG g_cLocks;

extern void LockModule(void);
extern void UnlockModule(void);

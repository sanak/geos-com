/*****************************************************************************
 *
 * FileName: stdafx.cpp
 * Project:  GEOS COM Wrapper - http://sourceforge.jp/projects/geos-com
 * Purpose:  Precompiled header implementation.
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

#include "stdafx.h"

LONG g_cLocks = 0;

void LockModule(void) { InterlockedIncrement(&g_cLocks); }
void UnlockModule(void) { InterlockedDecrement(&g_cLocks); }
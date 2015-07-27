////////////////////////////////////////////////////////////////////////////////////////////
// loader: command-line interface dll injector
// Copyright (C) 2009-2011 Wadim E. <wdmegrv@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <stdio.h>

#include <Windows.h>

#include "injectory/common.hpp"
#include "injectory/injector_helper.hpp"

// INFINITE can cause DeadLock if host process is in debug mode
#define INJLIB_WAITTIMEOUT		INFINITE
#define WII_WAITTIMEOUT			5000

void InjectLibrary(const pid_t& pid, const path& lib);

BOOL
EjectLibrary(
	DWORD dwProcessId,
	LPVOID lpModule
	);

BOOL
EjectLibraryW(
	DWORD dwProcessId,
	LPCWSTR lpLibPath
	);

BOOL
EjectLibraryA(
	DWORD dwProcessId,
	LPCSTR lpLibPath
	);

pid_t InjectLibraryOnStartup(const path& lib, const path& application, const wstring& applicationArgs, bool waitForInputIdle);

BOOL
EjectLibraryOnStartupW(
	LPCWSTR lpLibPath,
	LPCWSTR lpProcPath,
	LPWSTR lpProcArgs,
	BOOL bWaitForInputIdle
	);

BOOL 
EjectLibraryOnStartupA(
	LPCSTR lpLibPath,
	LPCSTR lpProcPath,
	LPSTR lpProcArgs,
	BOOL bWaitForInputIdle
	);

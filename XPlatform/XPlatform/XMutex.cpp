#include "XMutex.h"
#include <windows.h>

XMutex::XMutex()
{
	section = new CRITICAL_SECTION();
	InitializeCriticalSection((CRITICAL_SECTION*)section);
}


XMutex::~XMutex()
{
}

void XMutex::Lock()
{
	EnterCriticalSection((CRITICAL_SECTION*)section);
}

void XMutex::Unlock()
{
	LeaveCriticalSection((CRITICAL_SECTION*)section);
}

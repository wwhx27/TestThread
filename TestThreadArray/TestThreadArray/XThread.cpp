#include "XThread.h"
#include <windows.h>
#include <process.h>

XThread::XThread() :m_thread(0)
{
}

XThread::~XThread()
{
}

static void ThreadMain(void* para)
{
	XThread* pThread = (XThread*)para;
	pThread->Main();
	_endthread();
}

bool XThread::Start()
{
	m_thread = _beginthread(ThreadMain, 0, this);
	if ((int)m_thread <= 0)
	{
		return false;
	}
	return true;
}

void XThread::Wait()
{
	WaitForSingleObject((HANDLE)m_thread, INFINITE);
}

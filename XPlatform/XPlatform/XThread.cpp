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
	if (m_thread == 0)
	{
		return false;
	}
	return true;
}

void XThread::Wait()
{
	if (m_thread == 0)
	{
		return;
	}
	WaitForSingleObject((HANDLE)m_thread, INFINITE);
}

void XThread::Suspend()
{
	if (m_thread == 0)
	{
		return;
	}
	SuspendThread((HANDLE)m_thread);
}

void XThread::Resume()
{
	if (m_thread == 0)
	{
		return;
	}
	ResumeThread((HANDLE)m_thread);
}

#include <iostream>
#include <windows.h>
#include <XThread.h>
#include <XMutex.h>

// CRITICAL_SECTION section;
static XMutex xMutex;
static char buf[1024] = { 0 };
class MyThread : public XThread
{
public:
	void Main()
	{
		while (true)
		{
			int nSize = sizeof(buf);
// 			EnterCriticalSection(&section);  //¾¡Íí½øÈë
			xMutex.Lock();
			for (int i = 0; i < nSize; ++i)
			{
				buf[i] = c;
				Sleep(1);
			}
			buf[nSize - 1] = '\0';
			std::cout << "[" << buf << "]" << std::endl;
// 			LeaveCriticalSection(&section);  //¾¡ÔçÍË³ö
			xMutex.Unlock();
			std::cout << std::endl;
			Sleep(1);
		}
	}

public:
	char c;
};


int main()
{
// 	InitializeCriticalSection(&section);

	MyThread myThread,myThread2;
	myThread.c = 'a';
	myThread2.c = 'b';

	myThread.Start();
	myThread2.Start();

	getchar();
	return 0;
}
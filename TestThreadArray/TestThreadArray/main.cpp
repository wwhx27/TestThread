#include <iostream>
#include <windows.h>
#include "XThread.h"

static char* arr = NULL;

class MyThread :public XThread
{
public:
	int b = 0;
	int e = 0;
	void Main()
	{
		for (int i = b; i <= e; ++i)
		{
			arr[i] = i;
		}
	}
};

int main()
{
	int nSize = 1000 * 1000 * 1000;
	arr = new char[nSize];

	int nThSize = 4;
	MyThread* thread = new MyThread[nThSize];

	long long start = GetTickCount();
// 	for (int i = 0; i < nSize; ++i)
// 	{
// 		arr[i] = i;
// 	}
	for (int i = 0; i < nThSize; ++i)
	{
		thread[i].b = i*(nSize / nThSize);
		thread[i].e = thread->b + nSize / nThSize;
		if (thread[i].e >= nSize)
		{
			thread[i].e = nSize-1;
		}
		thread[i].Start();
	}
	for (int i = 0; i < nThSize; ++i)
	{
		thread[i].Wait();
	}
	long long end = GetTickCount();
	std::cout << "main thread ms = " << end - start << std::endl;
	getchar();
	return 0;
}
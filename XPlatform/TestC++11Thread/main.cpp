#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

static int g_nTicks = 100;
static std::mutex g_Mutex;
class SaleTick
{
public:
	void Main()
	{
		std::cout << "in saletick " << std::endl;

		while (true)
		{
			g_Mutex.lock();
			if (g_nTicks <= 0)
			{
				g_Mutex.unlock();
				break;
			}
			--g_nTicks;
			g_Mutex.unlock();
			++nSale;
			Sleep(1);
		}
	}

	int nSale = 0;
};

int main()
{
	SaleTick st1, st2;
	
	std::thread st1Thread(&SaleTick::Main, &st1);
	Sleep(20);
	std::thread st2Thread(&SaleTick::Main, &st2);

	st1Thread.join();
	st2Thread.join();
	std::cout << "st1 sale: " << st1.nSale << std::endl;
	std::cout << "st2 sale: " << st2.nSale << std::endl;

	getchar();
	return 0;
}
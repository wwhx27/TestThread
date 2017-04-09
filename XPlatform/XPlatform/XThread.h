#pragma once
#ifdef XPLATFORM_EXPORTS
#define XPLATFORM_API __declspec(dllexport)
#else
#define XPLATFORM_API __declspec(dllimport)
#endif

class XPLATFORM_API XThread
{
public:
	XThread();
	virtual ~XThread();

	bool Start();
	void Wait();
	void Suspend();
	void Resume();
	virtual void Main() = 0;

private:
	unsigned int m_thread;
};


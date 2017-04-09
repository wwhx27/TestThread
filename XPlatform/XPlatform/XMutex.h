#pragma once
#ifdef XPLATFORM_EXPORTS
#define XPLATFORM_API __declspec(dllexport)
#else
#define XPLATFORM_API __declspec(dllimport)
#endif

class XPLATFORM_API XMutex
{
public:
	XMutex();
	~XMutex();

	void Lock();
	void Unlock();

private:
	void* section;
};


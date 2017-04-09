#pragma once
#pragma once

class XThread
{
public:
	XThread();
	~XThread();

	bool Start();
	void Wait();
	virtual void Main() = 0;

private:
	unsigned int m_thread;
};


// XPlatform.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "XPlatform.h"


// ���ǵ���������һ��ʾ��
XPLATFORM_API int nXPlatform=0;

// ���ǵ���������һ��ʾ����
XPLATFORM_API int fnXPlatform(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� XPlatform.h
CXPlatform::CXPlatform()
{
	return;
}

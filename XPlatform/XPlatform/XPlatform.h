// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� XPLATFORM_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// XPLATFORM_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef XPLATFORM_EXPORTS
#define XPLATFORM_API __declspec(dllexport)
#else
#define XPLATFORM_API __declspec(dllimport)
#endif

// �����Ǵ� XPlatform.dll ������
class XPLATFORM_API CXPlatform {
public:
	CXPlatform(void);
	// TODO:  �ڴ�������ķ�����
};

extern XPLATFORM_API int nXPlatform;

XPLATFORM_API int fnXPlatform(void);

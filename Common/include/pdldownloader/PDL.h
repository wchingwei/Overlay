#pragma once 

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� PDL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// PDL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef PDL_EXPORTS
#define PDL_API extern "C" __declspec(dllexport)
#else
#define PDL_API extern "C" __declspec(dllimport)
#endif

// ����PDL.dll�İ汾��
#define PDL_VERSION_INITIALIZE						_T("1")
#define PDL_VERSION_20130418						_T("2")
#define PDL_VERSION_CURRENT							PDL_VERSION_20130418

// ����֪ͨ��Ϣ
#define	WM_PASSIVE_DOWNLOAD_NOTIFY_MSG				(WM_USER + 1890)	// ���������߳�֪ͨ��Ϣ��wParamΪ�߳�����,lParamΪ֪ͨ��Ϣ�ı�����
#define	WM_ACTIVE_DOWNLOAD_NOTIFY_MSG				(WM_USER + 1891)	// ���������߳�֪ͨ��Ϣ��ͬ�ϣ�

#define	MAXCOUNT_PASSIVE_DOWNLOAD_THREAD			10					// ���������߳�������
#define	MAXCOUNT_ACTIVE_DOWNLOAD_THREAD				10					// ���������߳�������

// ��������״̬
#define PDL_STATUS_INIT								0X00000000			// ��ʼ״̬
#define PDL_STATUS_DOWNLOAD_JSON					0X00000010			// ����JSON�ļ�
#define PDL_STATUS_PREPARE							0X00000020			// ׼�����л�������������PDL�ļ��������ٶȼ��ȣ�
#define PDL_STATUS_DOWNLOAD_INITPACKAGE				0X00000030			// ���س�ʼ��
#define PDL_STATUS_UNCOMPRESS_INITPACKAGE			0X00000031			// ��ѹ����ʼ��
#define PDL_STATUS_DOWNLOAD_MINPACKAGE				0X00000050			// ������С��
#define PDL_STATUS_RUN								0X00000100			// �������У�ָ�Ѿ���ʼ�����ı��±����ˣ�
#define PDL_STATUS_COMPLETED						0X00001000			// ���������
#define PDL_STATUS_PAUSED							0X40000000			// ��������ͣ����ֵΪһ����־ֵ��������ǰ���ֵһ��ʹ�ã�����������ͣ�ڶ�Ӧ�Ľ׶Σ�
#define PDL_STATUS_STOPPED							0X80000000			// ������ֹͣ����ֵΪһ����־ֵ��������ǰ���ֵһ��ʹ�ã���������ֹͣ�ڶ�Ӧ�Ľ׶Σ�

// ��������ID
// ����Ϊ�ı�ֵ������
#define PDL_CFGID_TEXT_GAMEHOMEDIR					1					// ������Ϸ����Ŀ¼����ֵֻ�ܻ�ȡ���������ã�
// ����Ϊ����ֵ������
#define PDL_CFGID_INT_BEGIN							1000				// ��������ID��ʼ��ϵͳ������
#define PDL_CFGID_INT_PASSIVE_DOWNLOAD_THREADCOUNT	1001				// ���������߳���
#define PDL_CFGID_INT_ACTIVE_DOWNLOAD_THREADCOUNT	1002				// ���������߳���
#define PDL_CFGID_INT_ACTIVE_DOWNLOAD_MAXSPEED		1003				// ������������ٶ�(0���Զ�����(ȱʡֵ )��1�������٣��������������ٶ�ֵ��KB/S)
#define PDL_CFGID_INT_PACKAGEDOWNLOADTHREADCOUNT	1004				// ��ʼ������С�������߳���
#define PDL_CFGID_INT_RUNFORMINPACKAGE				1005				// Ϊ��ȡ��С����Ϣ����

// ���������
#define PDL_ERROR_SUCCESS											0		// �ɹ�
#define PDL_ERROR_NEEDUPDATE										1		// PDL.dll��Ҫ����

#define PDL_ERROR_DOWNLOADJSON_NETWORK								10		// ����JSON�ļ�ʧ�ܣ�ԭ�����������
#define PDL_ERROR_DOWNLOADJSON_DISKFULL								11		// ����JSON�ļ�ʧ�ܣ�ԭ���Ǵ��̿ռ���
#define PDL_ERROR_DOWNLOADJSON_ACCESS_DENIED						12		// ����JSON�ļ�ʧ�ܣ�ԭ����Ȩ�޲���
#define PDL_ERROR_DOWNLOADJSON_DATAERROR							13		// ����JSON�ļ�ʧ�ܣ�ԭ�����ļ���������

#define PDL_ERROR_CREATE_GAMEDIR_ACCESS_DENIED						20		// ������ϷĿ¼ʧ�ܣ�ԭ����Ȩ�޲���
#define PDL_ERROR_CREATE_GAMEDIR_INVALID_NAME						21		// ������ϷĿ¼ʧ�ܣ�ԭ����Ŀ¼�����д����ַ�
#define PDL_ERROR_CREATE_GAMEDIR_TOOLONG							22		// ������ϷĿ¼ʧ�ܣ�ԭ����Ŀ¼������
#define PDL_ERROR_CREATE_GAMEDIR_PATH_NOT_FOUND						23		// ������ϷĿ¼ʧ�ܣ�ԭ�����ϼ�Ŀ¼������
#define PDL_ERROR_CREATE_GAMEDIR_INSUFFICIENT_DISK_SPACE			24		// ������ϷĿ¼ʧ�ܣ�ԭ���Ǵ��̿ռ䲻��

#define PDL_ERROR_REGISTERDRIVER_QUERYDOSDEVICE						30		// ע������ʧ��֮��ѯdos deviceʧ��
#define PDL_ERROR_REGISTERDRIVER_COMMUNICATION						31		// ע������ʧ��֮����ͨ�Ŷ˿�ʧ��
#define PDL_ERROR_REGISTERDRIVER_SENDMESSAGE						32		// ע������ʧ��֮��˿ڷ�����Ϣʧ��
#define PDL_ERROR_REGISTERDRIVER_INSTANCE_ALTITUDE_COLLISION		33		// ע������ʧ��֮��������ָ������ͬattitude��Pwepdl

#define PDL_ERROR_INIT_FILEMANAGE_JSONDATA							40		// ��ʼ���ļ�����ģ��ʧ�ܣ�ԭ����JSON�ļ��е����ݲ��ԣ���������������ݴ�ͷ��ʼ
#define PDL_ERROR_INIT_FILEMANAGE_DISKFULL							41		// ��ʼ���ļ�����ģ��ʧ�ܣ�ԭ���Ǵ��̿ռ���
#define PDL_ERROR_INIT_FILEMANAGE_ACCESS_DENIED						42		// ��ʼ���ļ�����ģ��ʧ�ܣ�ԭ����Ȩ�޲���
#define PDL_ERROR_INIT_FILEMANAGE_PDLDATA_CHECKFILE					43		// ��ʼ���ļ�����ģ��ʧ�ܣ�ԭ����װ��PDL����У���ļ�ʧ�ܣ���������������ݴ�ͷ��ʼ

#define PDL_ERROR_DOWNLOAD_INITPACKAGE_NETWORK						50		// ���س�ʼ��ʧ�ܣ�ԭ����������ϣ���ʱ�ص������������TRUE��������ԣ������˳���
#define PDL_ERROR_DOWNLOAD_INITPACKAGE_DISKFULL						51		// ���س�ʼ��ʧ�ܣ�ԭ���Ǵ��̿ռ���
#define PDL_ERROR_DOWNLOAD_INITPACKAGE_ACCESS_DENIED				52		// ���س�ʼ��ʧ�ܣ�ԭ����Ȩ�޲���

#define PDL_ERROR_UNCOMPRESS_INITPACKAGE_DATAERROR					60		// ��ѹ����ʼ��ʧ�ܣ�ԭ�������ݲ���ȷ
#define PDL_ERROR_UNCOMPRESS_INITPACKAGE_DISKFULL					61		// ��ѹ����ʼ��ʧ�ܣ�ԭ���Ǵ��̿ռ���
#define PDL_ERROR_UNCOMPRESS_INITPACKAGE_ACCESS_DENIED				62		// ��ѹ����ʼ��ʧ�ܣ�ԭ����Ȩ�޲���

#define PDL_ERROR_DOWNLOAD_MINPACKAGE_NETWORK						70		// ������С��ʧ�ܣ�ԭ����������ϣ���ʱ�ص������������TRUE��������ԣ������˳���
#define PDL_ERROR_DOWNLOAD_MINPACKAGE_DISKERROR						71		// ������С��ʧ�ܣ�ԭ���Ǵ��̴���
#define PDL_ERROR_DOWNLOAD_MINPACKAGE_CHECKFAILED					72		// ������С��ʧ�ܣ�ԭ��������У��ʧ��

// ����DllPDLInitialize�ķ���ֵ
#define PDL_INIT_ERR_SUCCESS										0					// �ɹ�
#define PDL_INIT_ERR_PDLDIR											1					// PDLĿ¼�����ڻ��޷�����
#define PDL_INIT_ERR_PDLDIR_ACCESS_DENIED							2					// PDLĿ¼Ȩ�޲������޷����������ļ��ȣ�
#define PDL_INIT_ERR_LOADDRIVER_ALREADY_EXISTS						20					// ��������ʧ�ܣ�ԭ�����Ѽ��ع�
#define PDL_INIT_ERR_LOADDRIVER_FILE_NOT_FOUND						21					// ��������ʧ�ܣ�ԭ���������ļ�������
#define PDL_INIT_ERR_LOADDRIVER_BAD_DRIVER							22					// ��������ʧ�ܣ�ԭ���������ļ�����ȷ
#define PDL_INIT_ERR_LOADDRIVER_INVALID_IMAGE_HASH					23					// ��������ʧ�ܣ�ԭ���������ļ�ǩ�����󡢻���δǩ��
#define PDL_INIT_ERR_LOADDRIVER_ACCESS_DENIE						24					// ��������ʧ�ܣ�ԭ����Ȩ�޲���
#define PDL_INIT_ERR_LOADDRIVER_UNKOWN_ERROR						25					// ��������ʧ�ܣ�ԭ����δ֪����

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������Ϸ����ӿ���
class IGameTask
{
public:

	// ��ȡ��Ϸ����
	virtual LPCTSTR GetGameName() = 0;

	// ��ȡ����״̬������ֵ���궨�壬�磺PDL_STATUS_RUNNING
	virtual DWORD GetStatus() = 0;

	// ��ѯ�����Ƿ��������У�ע�⣺��ͣ״̬Ҳ��������״̬��
	virtual BOOL IsRunning() = 0;

	// ��ѯ�����Ƿ�����ͣ״̬
	virtual BOOL IsPaused() = 0;

	// ��ѯ�����Ƿ���Ա���ͣ����׼�����л�����ɺ���ܱ���ͣ��
	virtual BOOL CanBePaused() = 0;

	// ��ѯ�����Ƿ��Ѿ����
	virtual BOOL IsCompleted() = 0;

	// ��ȡ����ǰ״̬�Ľ��ȣ�����ֵΪ0-10000���ʾ��ȷ�Ľ��ȣ�-1��ʾû�ж�Ӧ�Ľ�����Ϣ������Ϊ����
	// bCombineBeforeRun��ΪTRUE��ʾ�ϲ���ʼ״̬������ǰ״̬����ʱ����ʼ״̬������ǰ������״̬�ϲ�Ϊһ������
	// ΪFALSEʱ���ǵ�ǰ״̬�Ľ���
	virtual int GetProgress(__in BOOL bCombineBeforeRun = TRUE) = 0;

	// ��ȡʣ�����������㵽������Ϸ����ʱ����ΪMAXDWORDʱ���ʾ��Ч
	virtual DWORD GetRemainSeconds() = 0;

	// ��ȡ�����ٶȣ���λKB/S��
	virtual DWORD GetDownloadSpeed() = 0;

	// �����Զ�������
	virtual void SetCustomData(__in DWORD dwCustomData) = 0;

	// ��ȡ�Զ�������
	virtual DWORD GetCustomData() = 0;

	// �����ӿ�
	virtual DWORD Res1() = 0;
	virtual DWORD Res2(__in DWORD dwRes) = 0;
	virtual DWORD Res3(__in DWORD dwRes1, __in DWORD dwRes2) = 0;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ����ص�������BOOL PDLCallback(...)
// pIGameTask����Ϸ����ӿ�ָ�룬lpCaller:������ָ�룬��ֵΪDllPDLInitialize�д���Ķ�Ӧֵ�����������ʹ��
// dwType�����ͣ����궨�壬�磺PDL_CBTYPE_STATUS_CHANGED��dwValue����Ӧ�����µ�ֵ��
// ����ֵֻ���ض�������Ч����������Ͷ���˵��
typedef BOOL (*FNPDLCALLBACK)(__in IGameTask *pIGameTask, __in LPVOID lpCaller, __in DWORD dwType, __in DWORD dwValue);
// ��������
#define PDL_CBTYPE_ERROR								0				// ���󣬴�ʱdwValueΪ�����룬���궨�壬�磺PDL_ERROR_SUCCESS
#define PDL_CBTYPE_STATUS_CHANGED						1				// ״̬�ı䣬��ʱdwValueΪ״ֵ̬
#define PDL_CBTYPE_PREPARING							10				// ����׼�����л�������ʱdwValue��Ч
#define PDL_CBTYPE_DOWNLOADING_INITPACKAGE				20				// �������س�ʼ������ʱdwValueΪ����ֵ��0-10000��ת��Ϊ�ٷֱ�ʱ����λС����������ͬ��
#define PDL_CBTYPE_UNCOMPRESSING_INITPACKAGE			21				// ���ڽ�ѹ����ʼ������ʱdwValueΪ����ֵ
#define PDL_CBTYPE_DOWNLOADING_MINPACKAGE				30				// ����������С������ʱdwValueΪ����ֵ
#define PDL_CBTYPE_NEEDLAUNCHGAME						50				// ��Ҫ������Ϸ����ʱdwValueΪLPCTSTR(�������Ŀ�ִ���ļ�ȫ·��)����ʱ��Ч
#define PDL_CBTYPE_RUNNING								80				// �������У���ʱdwValueΪ����ֵ
#define PDL_CBTYPE_COMPLETED							100				// �����
#define PDL_CBTYPE_NETWORK_PASSIVE_DOWNLOAD_BEGIN		200				// �������ؿ�ʼ����ʱdwValueΪԤ����Ҫ���ڵ�ʱ�䣬��λ�����루��δ�ṩ��
#define PDL_CBTYPE_NETWORK_PASSIVE_DOWNLOAD_END			201				// �������ؽ�������δ�ṩ��
#define PDL_CBTYPE_NETWORK_PASSIVE_DOWNLOAD_FAILED		210				// ��������ʧ�ܣ�ԭ����������ϣ���ʱ����ֵ��Ч���������TRUE���ʾ�������£������˳����أ���ʱdwValueΪLPCTSTR������ĵ�����Ϣ��
#define PDL_CBTYPE_NETWORK_PASSIVE_DOWNLOAD_DISKERROR	211				// ��������ʧ�ܣ�ԭ���Ǵ��̴��󣬴�ʱ����ֵ��Ч���������TRUE���ʾ�������ԣ������˳�����ʱdwValueΪLPCTSTR������ĵ�����Ϣ��
#define PDL_CBTYPE_NETWORK_PASSIVE_DOWNLOAD_CHECKFAILED	212				// ��������ʧ�ܣ�ԭ��������У��ʧ�ܣ���ʱ����ֵ��Ч���������TRUE���ʾ�������£������˳����أ���ʱdwValueΪLPCTSTR������ĵ�����Ϣ��
#define PDL_CBTYPE_NETWORK_ACTIVE_DOWNLOAD_FAILED		310				// ��������ʧ�ܣ�ԭ����������ϣ���ʱdwValueΪLPCTSTR������ĵ�����Ϣ��
#define PDL_CBTYPE_NETWORK_ACTIVE_DOWNLOAD_DISKERROR	311				// ��������ʧ�ܣ�ԭ���Ǵ��̴��󣬴�ʱdwValueΪLPCTSTR������ĵ�����Ϣ��
#define PDL_CBTYPE_NETWORK_ACTIVE_DOWNLOAD_CHECKFAILED	312				// ��������ʧ�ܣ�ԭ��������У��ʧ�ܣ���ʱdwValueΪLPCTSTR������ĵ�����Ϣ��
#define PDL_CBTYPE_PASSIVE_DOWNLOAD_REPORT				400				// ����������Ϣ�ϱ�����ʱdwValueΪLPCTSTR���ϱ��ı�����ʱ��Ч��

#define PROGRESS_VALUE_ZERO (0)
#define PROGRESS_VALUE_MAX  (10000)

// ���ݵ�ǰֵ����ֵ��������ֵ
#define MAKE_PROGRESS_VALUE(nCurValue, nTotalValue) (int)((double(nCurValue) / double(nTotalValue)) * double(PROGRESS_VALUE_MAX))


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��ʼ����lpszPDLDir��PDL�ļ�Ŀ¼�����ΪNULL����ʹ�õ�ǰ���������ڵ�Ŀ¼��
// fnPDLCallback���ص�����ָ�룬ΪNULL����Ч
// lpCaller�����ã�������DllPDLInitialize�������ߣ�ͨ��Ϊ�����ָ�룬���fnPDLCallback��ΪNULL����ΪNULL
// hNotifyWnd������֪ͨ��Ϣ�ľ�������ڵ�����Ϣ���������������Ϣ��Ϣ���궨��
// ����ֵ���궨�壬�磺PDL_INIT_ERR_SUCCESS
PDL_API DWORD DllPDLInitialize(__in LPCTSTR lpszPDLDir, __in FNPDLCALLBACK fnPDLCallback, __in LPVOID lpCaller, __in HWND hNotifyWnd = NULL);
typedef DWORD (*FNDLLPDLINITIALIZE)(__in LPCTSTR lpszPDLDir, __in FNPDLCALLBACK fnPDLCallback, __in LPVOID lpCaller, __in HWND hNotifyWnd);

// ����ʼ��
PDL_API void DllPDLUninitialize();
typedef void (*FNDLLPDLUNINITIALIZE)();

// ������Ϸ����lpszJsonFilename�������Ӧ��Json�ļ���������·��������ֵΪ�����Ψһ����
// lpszJsonURL��Json�ļ���Ӧ�����ص�ַ����Json�ļ������ڻ�����Ҫ����ʱ����ݴ�URL����
// lpszGameDir����Ϸ�����Ŀ¼
// ppIGameTask�����洴�����������ָ��
// ����FALSE���ʾ����ʧ��
PDL_API BOOL DllPDLCreateGameTask(__in LPCTSTR lpszJsonFilename, __in LPCTSTR lpszJsonURL, __in LPCTSTR lpszGameDir, __out IGameTask **ppIGameTask);
typedef DWORD (*FNDLLPDLCREATEGAMETASK)(__in LPCTSTR lpszJsonFilename, __in LPCTSTR lpszJsonURL, __in LPCTSTR lpszGameDir, __out IGameTask **ppIGameTask);

// ������Ϸ����ppIGameTask���������������ָ���ָ��
PDL_API void DllPDLDestroyGameTask(__in IGameTask **ppIGameTask);
typedef void (*FNDLLPDLDESTROYGAMETASK)(__in IGameTask **ppIGameTask);

// ������Ϸ����pIGameTask��ָ������Ϸ����ӿ�ָ��
// �ú����Ǹ��첽������ͨ���ص�����PDLCallback�ɻ�ȡ�����Ϣ
PDL_API void DllPDLStartGameTask(__in IGameTask *pIGameTask);
typedef void (*FNDLLPDLSTARTGAMETASK)(__in IGameTask *pIGameTask);

// ֹͣ��Ϸ����pIGameTask��ָ������Ϸ����ӿ�ָ�룬���ΪNULL����Ϊ��ǰ�������е���Ϸ����
PDL_API void DllPDLStopGameTask(__in IGameTask *pIGameTask);
typedef void (*FNDLLPDLSTOPGAMETASK)(__in IGameTask *pIGameTask);

// ��ͣ��Ϸ����pIGameTask��ָ������Ϸ����ӿ�ָ�룬���ΪNULL����Ϊ��ǰ�������е���Ϸ����
PDL_API void DllPDLSuspendGameTask(__in IGameTask *pIGameTask);
typedef void (*FNDLLPDLSUSPENDGAMETASK)(__in IGameTask *pIGameTask);

// ������Ϸ����pIGameTask��ָ������Ϸ����ӿ�ָ��
PDL_API void DllPDLResumeGameTask(__in IGameTask *pIGameTask);
typedef void (*FNDLLPDLRESUMEGAMETASK)(__in IGameTask *pIGameTask);

// ������Ϸ���񣬽�ɾ��������������ݣ����bIncludeGameFilesΪTRUE��ɾ����Ϸ�������ļ�������������������򷵻�FALSE
PDL_API BOOL DllPDLCleanGameTask(__in IGameTask *pIGameTask, __in BOOL bIncludeGameFiles = FALSE);
typedef BOOL (*FNDLLPDLCLEANGAMETASK)(__in IGameTask *pIGameTask, __in BOOL bIncludeGameFiles);

// �����������ٶȣ�����ÿ��ƽ���ֽ�����ΪMAXDWORD���ǲ��ʧ�ܣ�������URL�����
// nDetectTime�����ʱ�䣨��λ�룩��lpszDetectURL�����ʹ�õ�URL��ΪNULLʱϵͳֱ��ʹ�������ļ��е���Ϣ��nDetectThreadCount�����ʱͬʱ����������߳���
PDL_API DWORD DllPDLDetectMaxDownloadSpeed(__in int nDetectTime = 10, __in LPCTSTR lpszDetectURL = NULL, __in int nDetectThreadCount = 5);
typedef DWORD (*FNDLLPDLDETECTMAXDOWNLOADSPEED)(__in int nDetectTime, __in LPCTSTR lpszDetectURL, __in int nDetectThreadCount);

// ��ȡ����ֵ��dwConfigIDΪ����ID�����궨�壬�磺PDL_CFGID_GAMEHOMEDIR
// lpReturnedValue�������ı�����ֵ���������Ϊ����ֵ����봫��NULL
// dwSize�����lpReturnedValueΪNULL������ԣ�����ΪlpReturnedValue�Ŀռ��С
// ������ֵΪ����ʱֱ�ӷ�������ֵ�����򷵻�����ֵ�ı��ĳ���
PDL_API int DllPDLGetConfigValue(__in DWORD dwConfigID, __out LPTSTR lpReturnedValue, __in DWORD dwSize);
typedef int (*FNDLLPDLGETCONFIGVALUE)(__in DWORD dwConfigID, __out LPTSTR lpReturnedValue, __in DWORD dwSize);

// ��������ֵ��dwConfigIDΪ����ID�����궨�壬�磺PDL_CFGID_GAMEHOMEDIR
// nValue��������ֵΪ����ʱ���ñ���Ϊ����ֵ��������Ч
// lpValue��������ֵΪ����ʱ���ñ�������ΪNULL������Ϊ�ı�����ֵ
// �ɹ��򷵻�TRUE��ʧ���򷵻�FALSE
PDL_API BOOL DllPDLSetConfigValue(__in DWORD dwConfigID, __in int nValue, __in LPCTSTR lpValue);
typedef BOOL (*FNDLLPDLSETCONFIGVALUE)(__in DWORD dwConfigID, __in int nValue, __in LPCTSTR lpValue);

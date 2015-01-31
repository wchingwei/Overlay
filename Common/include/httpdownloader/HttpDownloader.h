// HttpDownloader �ӿ�ͷ�ļ�
#pragma once 
#include <Windows.h>
#include <vector>

using namespace std;

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� HTTPDOWNLOADER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// HTTPDOWNLOADER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef HTTPDOWNLOADER_EXPORTS
#define HTTPDOWNLOADER_API EXTERN_C __declspec(dllexport)
#else
#define HTTPDOWNLOADER_API EXTERN_C __declspec(dllimport)
#endif

// ��������״̬
typedef enum
{
	HD_TASK_STATUS_INIT = 0,				// ��ʼ״̬
	HD_TASK_STATUS_CONNECTING,				// ��������
	HD_TASK_STATUS_DOWNLOADING,				// �������أ�ֻ�и�״̬���ܱ���ͣ��
	HD_TASK_STATUS_SUSPENDED,				// ����ͣ
	HD_TASK_STATUS_STOPPING,				// ����ֹͣ
	HD_TASK_STATUS_STOPPED,					// ��ֹͣ
	HD_TASK_STATUS_COMPLETED,				// �����
	HD_TASK_STATUS_ERROR					// ����״̬����ʱ��ͨ������GetErrorNumber��ȡ������
}HDTaskStatus;

// ���������
typedef enum
{
	HD_ERROR_SUCCESS = 0,					// �ɹ�
	HD_ERROR_INVALID_URL,					// URL����
	HD_ERROR_CANNOT_CONNECT,				// ���Ӳ������ط�����
	HD_ERROR_AUTH_CERT_NEEDED,				// ��Ҫ��֤
	HD_ERROR_LOGIN_FAILURE,					// ��¼����
	HD_ERROR_SERVER_FILENOTFOUND,			// �ļ�������
	HD_ERROR_SERVER_FILEMODIFIED,			// �ļ��Ѹı䣨�����ļ���С��ʱ������ǰ���ر���Ĳ�һ����
	HD_ERROR_SERVER_FORBIDDEN,				// ���������
	HD_ERROR_SERVER_TIMEOUT,				// ��ʱ�����������Դ�����
	HD_ERROR_FILE_INSUFFICIENTDISKSPACE,	// ���̿ռ䲻��
	HD_ERROR_FILE_ACCESS_DENIED,			// Ȩ�޲������޷����ʱ����ļ�
	HD_ERROR_FILE_DISK_ERROR,				// ���̴����޷����ʱ����ļ�
	HD_ERROR_FILE_MD5FILENOTFOUND,			// MD5�ļ�δ�ҵ�
	HD_ERROR_FILE_MD5FILEERROR,				// MD5�ļ����ݴ���
	HD_ERROR_MEMORY_INSUFFICIENT,			// �ڴ�ռ䲻��
	HD_ERROR_THREAD_CREATEFAILED,			// �������߳�ʧ��
	HD_ERROR_NAME_NOT_RESOLVED=20,			// ��������ʧ�ܣ���Ϊ��ǰHD_ERROR_DEBUG�õ���16��������������Ϊ20������ֵ�Ա������ǰ��ֵ������2013-08-27��

	HD_ERROR_DEBUG=99,						// ��ȡ���������Ϣ����16��Ϊ99��

	HD_ERROR_LAST							// �������루����ϵͳʹ�ã�
}HDErrorNumber;

#define WM_HTTPDOWN_NOTIFY		WM_USER + 97				// ֪ͨ��ϢID�����ڵ���

// ����HTTPѡ��ֵ
typedef enum 
{
	HD_HTTP_OPTION_USERNAME = 0,			// ��¼�û�����TCHAR[]��ȱʡΪ�մ�
	HD_HTTP_OPTION_PASSWORD,				// ��¼�����룬TCHAR[]��ȱʡΪ�մ�
	HD_HTTP_OPTION_PROXY,					// ������Ϣ��WINHTTP_PROXY_INFO
	HD_HTTP_OPTION_PROXY_USERNAME,			// �����û�����TCHAR[]��ȱʡΪ�մ�
	HD_HTTP_OPTION_PROXY_PASSWORD,			// �������룬TCHAR[]��ȱʡΪ�մ�
	HD_HTTP_OPTION_USER_AGENT,				// UserAgent��Ϣ��TCHAR[]��ȱʡΪ�մ�
	HD_HTTP_OPTION_CONTENT_MD5,				// ����MD5ֵ�����ʹ������ݲ��ṩ��
	HD_HTTP_OPTION_CONTENT_ENCODING,		// �������ݱ��룬ֵ����"gzip"��TCHAR[]��ȱʡΪ�մ�

	HD_HTTP_OPTION_COUNT					// ѡ������������ϵͳʹ�ã�
}HDHttpOption;

// ����ȱʡֵ
#define DEFAULT_IGNORE					MAXDWORD				// ȱʡ����ֵ
#define DEFAULT_TIMEOUT_CONNECT			(30 * 1000)				// ȱʡ�����ӳ�ʱֵ��λ������
#define DEFAULT_TIMEOUT_SEND			(30 * 1000)				// ȱʡ�ķ��ͳ�ʱֵ��λ������
#define DEFAULT_TIMEOUT_RECEIVE			(30 * 1000)				// ȱʡ�Ľ��ճ�ʱֵ��λ������
#define DEFAULT_RETRY_TIMES				10						// ȱʡ�����Դ���ֵ
#define DEFAULT_RETRY_DELAYTIME			5000					// ȱʡ������ʱ����ֵ����λ�����룩

// ===========================================================================================================
// ����ӿ���
// ===========================================================================================================
class IHttpDownTask
{
public: // ���ýӿڣ���Ҫ�ڿ�ʼ����ǰ��������

	// �����������٣�dwLimitSpeed���������٣���λ���ֽ�/�룩��MAXDWORDΪ������
	virtual void SetLimitSpeed(__in DWORD dwLimitSpeed) = 0;
	// ��ȡ��ǰ����ֵ������λ���ֽ�/�룩��0Ϊ������
	virtual DWORD GetLimitSpeed() = 0;

	// ������س�ʱֵ����λ�����룩��dwConnectTimeout�����ӳ�ʱֵ��dwSendTimeout���ͳ�ʱֵ��dwReceiveTimeout�����ճ�ʱֵ����ֵΪDEFAULT_IGNORE���ʾ���޸ĵ�ǰ������ֵ
	virtual void SetTimeouts(__in DWORD dwConnectTimeout = DEFAULT_TIMEOUT_CONNECT, __in DWORD dwSendTimeout = DEFAULT_TIMEOUT_SEND, __in DWORD dwReceiveTimeout = DEFAULT_TIMEOUT_RECEIVE) = 0;
	// ��ȡ��ʱ���ã�lpSendTimeout�����淢�ͳ�ʱֵ��lpReceiveTimeout��������ճ�ʱֵ���������ӳ�ʱֵ
	virtual DWORD GetTimeouts(__out LPDWORD lpSendTimeout = NULL, __out LPDWORD lpReceiveTimeout = NULL) = 0;

	// ����������Ϣ��dwRetryTimes�����Դ�����ΪDEFAULT_IGNORE���޸ĵ�ǰֵ����dwDelayTime�������ӳ�ʱ�䣨��λ�����룬ΪDEFAULT_IGNORE���޸ĵ�ǰֵ��
	virtual void SetRetryInfo(__in DWORD dwRetryTimes = DEFAULT_RETRY_TIMES, __in DWORD dwDelayTime = DEFAULT_RETRY_DELAYTIME) = 0;
	// ��ȡ������Ϣ��lpDelayTime�����������ӳ�ʱ�䣬�������Դ���
	virtual DWORD GetRetryInfo(__out LPDWORD lpDelayTime = NULL) = 0;

	// ����HTTPѡ��ֵ��option��ѡ��壬lpBuffer��ѡ��ֵ����������ѡ���ȷ�����ͣ���dwBufferLength������������
	virtual BOOL SetHttpOption(__in HDHttpOption option, __in LPVOID lpBuffer, __in DWORD dwBufferLength) = 0;
	// ��ȡHTTPѡ��ֵ
	virtual BOOL GetHttpOption(__in HDHttpOption option, __in LPVOID lpBuffer, __inout LPDWORD lpdwBufferLength) = 0;

	// ���������̸߳������ڵ���Start�����Ч
	virtual void SetThreadCount(__in DWORD dwThreadCount = 5) = 0;

	// ��ȡ�����̸߳�����bOnlyRunning��ΪTRUEʱ���ʾ��ȡ�������е������߳���������Ϊ���õ������߳���
	virtual DWORD GetThreadCount(BOOL bOnlyRunning = FALSE) = 0;

public:	// �����ӿ�
	
	// ��ʼ����
	virtual void Start() = 0;
	// ֹͣ����
	virtual void Stop() = 0;
	// ��ͣ����
	virtual void Suspend() = 0;
	// ��������
	virtual void Resume() = 0;

	// ���������Ϣ��Ŀǰ��ɾ��idx�ļ�����������ֹͣ״̬���ܵ��øú���������Ժ��ٴο�ʼ����ʱ���ͷ����
	// bDelDownloadFile���Ƿ�ɾ�������ļ�
	virtual void Clean(BOOL bDelDownloadFile = FALSE) = 0;

public:	// ��ȡ��Ϣ�ӿ�

	// ��ȡ�����������ڵ����ļ��������򷵻��ļ���������·����������Ŀ¼�����򷵻�Ŀ¼���������ϼ�Ŀ¼��
	// ע�⣺�����������ظ�������ͬ�������������ͬ�������������Բ�����Ϊ�����Ψһ����
	virtual LPCTSTR GetTaskName() = 0;

	// ��ȡ����״̬
	virtual HDTaskStatus GetStatus() = 0;
	// ��ȡ����ֵ��0-10000��ΪMAXDWORDʱ��ʾ��ǰ�޷�������ȣ�����ֵΪ���� 
	virtual DWORD GetProgress() = 0;
	// ��ȡʣ��������ΪMAXDORDʱ��ʾ��ǰ�޷����㣨������ͣ�У�
	virtual DWORD GetRemainSeconds() = 0;
	// ��ȡ��ǰ�����ٶȣ���λ���ֽ�/��
	virtual DWORD GetDownloadSpeed() = 0;
	// ��ȡ�����ش�С
	virtual UINT64 GetDownloadedSize() = 0;
	// ��ȡ�����ش�С
	virtual UINT64 GetTotalSize() = 0;

	// �Ƿ�����ҪMD5У�������
	virtual BOOL IsMD5Check() = 0;

	// �Ƿ�����������״̬
	virtual BOOL IsDownloading() = 0;
	// �Ƿ�����ͣ״̬
	virtual BOOL IsSuspended() = 0;
	// �Ƿ���ֹͣ״̬
	virtual BOOL IsStopped() = 0;
	// �Ƿ����������
	virtual BOOL IsCompleted() = 0;

	// ��ѯ��ǰ״̬���Ƿ������������
	virtual BOOL CanStart() = 0;
	// ��ѯ��ǰ״̬���Ƿ����ֹͣ����
	virtual BOOL CanStop() = 0;
	// ��ѯ��ǰ״̬���Ƿ���Լ�������
	virtual BOOL CanResume() = 0;
	// ��ѯ��ǰ״̬���Ƿ������ͣ����
	virtual BOOL CanSuspend() = 0;
	// ��ѯ��ǰ״̬���Ƿ���������������
	virtual BOOL CanClean() = 0;

	// ��ȡ�����루���궨�壩
	virtual DWORD GetErrorNumber() = 0;

public:	// ���ڵ����ļ����صĽӿ�

	// ��ȡ���ص�ַ
	virtual LPCTSTR GetURL() = 0;
	// ��ȡ�����ļ�·������Ϊ�����Ψһ���֣�
	virtual LPCTSTR GetSavePath() = 0;

public:	// ��������Ŀ¼���صĽӿ�

	// ��ȡ���ػ���ַ
	virtual LPCTSTR GetBaseURL() = 0;
	// ��ȡ�ļ����·������
	virtual vector<LPCTSTR>& GetFilePaths() = 0;
	// ��ȡ����Ŀ¼����Ϊ�����Ψһ���֣�
	virtual LPCTSTR GetSaveDir() = 0;

public:	// �Զ�������

	// �����Զ�������
	virtual void SetCustomData(__in DWORD dwCustomData) = 0;

	// ��ȡ�Զ�������
	virtual DWORD GetCustomData() = 0;

public: // ������Ϣ�ӿ�

	// ����֪ͨ��Ϣ���ڣ�hNotifyWnd������֪ͨ��Ϣ�ľ����nMessageID����ϢID��������Ϣ��Ϣ���궨��
	// ���hNotifyWndΪNULL����nMessageIDΪWM_NULL����ȡ��֪ͨ
	virtual void SetNotifyWnd(__in HWND hNotifyWnd, __in UINT nMessageID = WM_HTTPDOWN_NOTIFY) = 0;
	
	// ���ݴ������ȡ������Ϣ��dwErrorNumber�������루���궨�壩�����ΪHD_ERROR_LAST����ֱ�ӻ�ȡ��ǰ�Ĵ�����Ϣ
	virtual LPCTSTR GetErrorMsg(__in HDErrorNumber errorNumber = HD_ERROR_LAST) = 0;

public:	// �����ӿ�
	
	virtual DWORD Reserve1(DWORD dwRes) = 0;
	virtual DWORD Reserve2(DWORD dwRes, DWORD dwRes2) = 0;
	virtual DWORD Reserve3(DWORD dwRes, DWORD dwRes2, DWORD dwRes3) = 0;
};

// ===========================================================================================================
// ����ص�������BOOL HttpDownCallback(...)
// pIHttpDownTask������ӿ�ָ�룬lpCaller:������ָ�룬��ֵΪHttpDownInitialize�д���Ķ�Ӧֵ�����������ʹ��
// type�����ͣ������壬�磺HD_CBTYPE_STATUS_CHANGED��dwValue����Ӧ�����µ�ֵ��
// ����ֵֻ���ض�������Ч����������Ͷ���˵��
// ===========================================================================================================
// ��������
typedef enum
{
	HD_CBTYPE_ERROR = 0,					// ���󣬴�ʱdwValueΪ�����룬�����壬�磺HD_ERROR_NETWORK_URL
	HD_CBTYPE_STATUS_CHANGED,				// ״̬�ı䣬��ʱdwValueΪ״ֵ̬
	HD_CBTYPE_PROGRESS_CHANGED,				// ����ֵ�ı䣬��ʱdwValueΪ����ֵ
	HD_CBTYPE_COMPLETE						// �������
}HDCallbackType;

typedef BOOL (*FNHTTPDOWNCALLBACK)(__in IHttpDownTask *pIHttpDownTask, __in LPVOID lpCaller, __in HDCallbackType type, __in DWORD dwValue);

// ===========================================================================================================
// ��������
// ===========================================================================================================
// ����汾�ţ�����ֽ�Ϊ�ӿ���IHttpDownTask�İ汾���ڶ��ֽ�Ϊ���������汾������Ϊ���ܰ汾
#define HTTPDOWN_VERSION_1								0X01010001							// ��һ�棬2013-05-23
#define HTTPDOWN_VERSION_CURRENT						HTTPDOWN_VERSION_1					// ��ǰ�汾

// ����HttpDownCreateTask�ķ���ֵ
#define HD_CREATETASK_ERROR_SUCCESS						0			// �ɹ�
#define HD_CREATETASK_ERROR_ALREADYEXIST				10			// �����Ѵ���
#define HD_CREATETASK_ERROR_URL							20			// URL����
#define HD_CREATETASK_ERROR_SAVEPATH					21			// �����ļ�·������
#define HD_CREATETASK_ERROR_INSUFFICIENTMEMORY			30			// �ڴ治�㣬�޷������������
#define HD_CREATETASK_ERROR_NOTINITIALIZED				40			// HttpDownloaderδ��ʼ��

// ��ʼ�����������ȵ��ã�����FALSE���ʾ��ǰ��İ汾������İ汾��ƥ�䣬���ܵ���
// dwHttpDownVersion�����ܿ�İ汾�ţ����봫��HTTPDOWN_VERSION_CURRENT���Ա���ȷ���Ƿ����ʹ�õ�ǰ��
// fnHttpDownCallback���ص�����ָ�룬ΪNULL����Ч
// lpCaller�����ã�������HttpDownInitialize�������ߣ�ͨ��Ϊ�����ָ�룬���fnHttpDownCallback��ΪNULL����ΪNULL
HTTPDOWNLOADER_API BOOL HttpDownInitialize(__in DWORD dwHttpDownVersion, __in FNHTTPDOWNCALLBACK fnHttpDownCallback, __in LPVOID lpCaller);
typedef BOOL (*FNHTTPDOWNINITIALIZE)(__in DWORD dwHttpDownVersion, __in FNHTTPDOWNCALLBACK fnHttpDownCallback, __in LPVOID lpCaller);

// ����ʼ��
HTTPDOWNLOADER_API void HttpDownUninitialize();
typedef void (*FNHTTPDOWNUNINITIALIZE)();

// �����������ص����ļ�����lpszURL�����ص�ַ��lpszSavePath������·��
// ppIHttpDownTask���ڴ����ɹ����������Ѵ���ʱ�����Ӧ���������ָ�룬������ΪNULL
// bMD5Check���Ƿ�ʹ��MD5У��
// ����ֵ���궨�壬�磺HD_CREATETASK_ERROR_SUCCESS��
HTTPDOWNLOADER_API DWORD HttpDownCreateTask(__in LPCTSTR lpszURL, __in LPCTSTR lpszSavePath, __out IHttpDownTask **ppIHttpDownTask, __in BOOL bMD5Check);
typedef DWORD (*FNHTTPDOWNCREATETASK)(__in LPCTSTR lpszURL, __in LPCTSTR lpszSavePath, __out IHttpDownTask **ppIHttpDownTask, __in BOOL bMD5Check);

// ����������������Ŀ¼����lpszBaseURL�����ػ���ַ��vctFilePaths���ļ����·������lpszBaseURL��ϳ�һ�������URL�����ϣ�
// lpszSaveDir������Ŀ¼��ppIHttpDownTask�����洴�����������ָ�룬����ֵ���궨��
HTTPDOWNLOADER_API DWORD HttpDownCreateTaskEx(__in LPCTSTR lpszBaseURL, __in vector<LPCTSTR>vctFilePaths, __in LPCSTR lpszSaveDir, __out IHttpDownTask **ppIHttpDownTask);
typedef DWORD (*FNHTTPDOWNCREATETASKEX)(__in LPCTSTR lpszBaseURL, __in vector<LPCTSTR>vctFilePaths, __in LPCSTR lpszSaveDir, __out IHttpDownTask **ppIHttpDownTask);

// ��������ע�⣺�ú�������ɾ�����ص��ļ���IDX�ļ�����ppIHttpDownTask������ָ���ַ
HTTPDOWNLOADER_API void HttpDownDestoryTask(__in IHttpDownTask **ppIHttpDownTask);
typedef void (*FNHTTPDOWNDESTORYTASK)(__in IHttpDownTask **ppIHttpDownTask);

// ��ȡ��ǰȫ���������ٶȣ���λ���ֽ�/��
HTTPDOWNLOADER_API DWORD HttpDownGetTotalSpeed();
typedef DWORD (*FNHTTPDOWNGETTOTALSPEED)();

// ����ȫ���������٣�dwSpeed���ٶ�ֵ����λ���ֽ�/�룬ΪMAXDWORD���ʾ������  
// �ݲ��ṩ�ù��� 
HTTPDOWNLOADER_API void HttpDownSetLimitSpeed(__in DWORD dwSpeed = MAXDWORD);
typedef void (*FNHTTPDOWNSETLIMITSPEED)(DWORD dwSpeed);

// ��ȡȫ���������٣������ٶ�ֵ����λ���ֽ�/�룬ΪMAXDWORD���ʾ������
HTTPDOWNLOADER_API DWORD HttpDownGetLimitSpeed();
typedef DWORD (*FNHTTPDOWNGETLIMITSPEED)();

/**
 * @file      WebData.h
   @brief     The header file for web data.
   @author    shenhui@pwrd.com
   @data      2011/09/16
   @version   01.00.00
 */

/* 
 *  Copyright(C) 2010. Perfect World Entertainment Inc
 *
 *  This PROPRIETARY SOURCE CODE is the valuable property of PWE and 
 *  its licensors and is protected by copyright and other intellectual 
 *  property laws and treaties.  We and our licensors own all rights, 
 *  title and interest in and to the SOURCE CODE, including all copyright 
 *  and other intellectual property rights in the SOURCE CODE.
 */

/*
 * $LastChangedBy: shenhui@pwrd.com
 * $LastChangedDate: 
 * $Revision: 01.00.01
 * $Id: 
 * $notes:
 */

#pragma once

#include <tchar.h>
#include "tstring/tstring.h"
#include "data/WebService.h"
#include "constant.h"
#include "datatype.h"
#include <vector>
#include <map>

using namespace std ;
using namespace String ;

class CWebData
{
public:

	CWebData(void);
	~CWebData(void);
                                                                  
	enum 
	{
		SERVICE_INBOX_MSG=0,	
		SERVICE_FRIEND_REQ,
		SERVICE_CONNECT_UPDATE,
		SERVICE_COUPON,
		SERVICE_NOTIFY,
		SERVICE_GAMEPLAY,
		SERVICE_MAX
	};

	enum
	{
		SERVICE_GET_DATACOUNT = SERVICE_MAX ,
		SERVICE_GET_USERNAMEBYMAIL ,
		SERVICE_REGISTER_USER ,
		SERVICE_ISALLOW_SIGNUP ,
		SERVICE_SIGNUP_BETA ,
		SERVICE_IS_SIGNUP ,
		SERVICE_CLEAR_CNTUPT,
		SERVICE_GET_GAMECHARACTER ,
		SERVICE_RESPONSE_FRDREQ ,
		SERVICE_GET_GAMESERVER ,
		SERVICE_IS_GAMEBETAOFFLINE,
		SERVICE_GET_POPUPNOTIFICATION,
		SERVICE_GET_CCDOWNLOADOPTION,
		SERVICE_GET_ALLCHANGED,
        SERVICE_UPDATE_NUMBER,
        SERVICE_EMS_NOTITY,
	};

	enum 
	{
		CNT_UPDATE_SEND_MESSAGE=1,
		CNT_UPDATE_POST_WALL=2,
		CNT_UPDATE_COMMENT_PHOTO=3,
		CNT_UPDATE_COMMENT_STATUS=4
	};

	//Inbox message data struct
	typedef struct _WEB_INBOX_MSG{

		_tstring  _id;          //message id, unique with groud id
		_tstring  _gid;         //group id, unique with id
		_tstring  _senderId;    //id of user that sends the message
		_tstring  _szType;      //from user or from arc game
		_tstring  _szSender;    //name of user that sends the message
		_tstring  _szTitle;     //title of the message
		_tstring  _szDateLine;  //send time of the message
		_tstring  _szLink;      //hyperlink of the message
		_tstring  _szFriendLink;
		_tstring  _szArcMailSubject; //subject of the arc mail message

	}WEB_INBOX_MSG;

	//Friend request data struct
	typedef struct _WEB_FRIEND_REQ{

		int       _id;          //request id, unique with _senderId
		int       _senderId;    //id of user that sends the request
		_tstring  _szSender;    //name of user that sends the request
		_tstring  _szContent;   //content of the request
		_tstring  _szDateLine;  //send time of the request
		_tstring  _szAvatar;    //url of avatar for user that sends the request
		_tstring  _szHeaderPath;//local file path of user's avatar
		_tstring  _szFriendLink;

	}WEB_FRIEND_REQ;

	//Connnect Update data struct, connect update includes all of updates
	//for user, such as inbox message, friend request and coupon.
	typedef struct _WEB_CONNECT_UPDATE{

		int       _id;	        //connect update id
		int       _type;        //type of connect update
		_tstring  _szLink;      //hyperlink of the connect update
		_tstring  _szMsg;       //message body of connect update
		_tstring  _szUserList;  //names of user that sends the connect update
		_tstring  _szDateLine;  //send time of connect update

	}WEB_CONNECT_UPDATE;

	///Coupon data struct
	typedef struct _WEB_COUPON_MSG{

		int       _id;          //coupon id
		int       _ownerId;     //useless
		int       _isnew;       //flag indicates coupon is new
		_tstring  _szLink;      //hyperlink of the coupon
		_tstring  _szTitle;		//title of the coupon
		_tstring  _szMsg;       //message body of the coupon
		_tstring  _szDateLine;  //send time of the coupon

	}WEB_COUPON_MSG;

	///User-Profile data struct
	typedef struct _WEB_CHARACT_MSG{
		_tstring _szName;         //name of user
		_tstring _szNick;        //nick name 
		_tstring _szCharater;   //character name in games.
		_tstring _szServer;    //name of game server that user registered in
		_tstring _szAvatar;    //url of avatar for user in game and chat
		_tstring _szHeaderPath;// the local file path of user's avatar
	}WEB_CHARACT_MSG;

	typedef struct _WEB_GAMESERVER_INFO{

		_tstring _szLastLoginTime ; //YYYY-MM-DD HH:MM:SS
		_tstring _szGameAbbr ;      //abbreviation of game
		uint32   _serverId ;        //id of game server
	}WEB_GAMESERVER_INFO ;

	///ems data struct
	typedef struct _WEB_EMS_DATA{
		//_tstring  _szUrl;         //the remote file path that including the ems content.
		//_tstring _szPath;        //the local file path that including the ems content. 
		_tstring _szId;            // id for the ems.
		_tstring _szTimeBegin;    //the time that the ems changed to be valid.
		_tstring _szTimeEnd;     //the time that the ems changed to be invalid..
		_tstring _szLink;       //the content involved a link.
		_tstring _szIconPath;  //the local icon file path for the ems.
		_tstring _szContent;  //the EMS content.
		_tstring _szTitle;   // the ems title.
	}WEB_EMS_DATA;

	enum _DOWNLOAD_OPTION{
		PANDO = 0 ,
		AKAMAI,
		MAX
	};
	typedef struct _AUTOPLAYNOW_INFO{
		_tstring  _szAbbrName;
		_tstring  _szAbbrLang;
		_tstring  _szIsLatest;
	}AUTOPLAYNOW_INFO;

	bool GetService(_tstringA sSessionId, vector<int>& vecCount) ;
	bool GetInboxMessageService(_tstringA sSessionId, vector<WEB_INBOX_MSG>& vecInbox) ;
	bool GetPlayNowRequestService(_tstringA sSessionId, _tstring sLang, vector<AUTOPLAYNOW_INFO>& vecPlayNowReq);
	bool GetFriendRequestService(_tstringA sSessionId, vector<WEB_FRIEND_REQ>& vecFriendReq) ;
	bool ResponseFriendReq(_tstringA sSessionId, int fid,int rid,bool bAccept) ;
	bool GetConnectUpdateService(_tstringA sSessionId, vector<WEB_CONNECT_UPDATE>& vecConUpt) ;
	void ClearConncectUpdateItems(_tstringA sSeesionId) ;
	bool GetCouponMessageService(_tstringA sSessionId, vector<WEB_COUPON_MSG>& vecCoupon) ;
	bool PostDisplayNameRequestService(_tstringA sSessionId, _tstring sNick, UINT nTimeout, _tstring& sError);
	bool GetUserInfoFromWebService(_tstringA szSessionId, _tstring& szNick, UINT nTimeout);

	bool GetGameCharactorService(_tstringA sSessionId, WEB_CHARACT_MSG& gameInfo);
	bool GetGameServerService(_tstringA sSessionId, vector<WEB_GAMESERVER_INFO>& vecGameServerInfo) ;
	
	bool RegisterUser(_tstring sUserName, _tstringA sPassword, _tstringA& sSessionId, _tstring& sUserName2, _tstring& sNickName) ;
	bool GetUserFromMail(_tstring sEmailName, _tstring& sUserName) ;
	bool IsGameSignupForBeta(_tstring sUserName, _tstring sGameAbbr, _tstring sLanguage = _T("en")) ;
	bool GetSignupForBetaService(_tstringA sSessionId, _tstring sUserName, _tstring sGameAbbr, _tstring sLanguage = _T("en")) ;
	bool GetGameBetaKeyInfo(_tstringA sSessionId, map<_tstring, int>& mapBetaKeyFlag) ; //map<_tstring, int> represents <game abbreviation, beta key flag> key-value pair.
	bool GetGameBetaPayInfo(_tstring sUserName, _tstring sAbbr, int& nBetaPayFlag) ;
	bool IsGameOffline(_tstring sLang, map<_tstring, _tstring>& mapBetaOffline) ; //map<_tstring, _tstring> represents <game abbreviation, offline falg> key-value pair.
	bool GetPopupNotificationService(_tstring sGameAbbr, _tstring sLang, map<_tstring, _tstring>& mapNotificationText) ; //map<_tstring, _tstring> represents <notification type, notification content> key-value pair.
	bool GetDownloadOptionService(int& nDownloadOption) ; //return value, 0 stands for http, 1 stands for pando
	bool GetEmergencyMessageServicce(_tstring sProduct, _tstring sLang, vector<EMERGENCY_MESSAGE_DATA>& vecEmergencyMessage);
	bool IsGameInEarlyBeta(_tstring sLang, map<_tstring, _tstring>& mapEarlyBetaData);
	bool GetVersionInfoService(_tstring sLang, _tstring sLocalVer, _tstring& sRemoteVer, _tstring& sUrl, int& nMode);

	bool GetBetaFeedbackService(_tstring sUserName, _tstring sSummary, _tstring sDescription, _tstring sLang, _tstring sCCVersion, _tstring sSysInfo, _tstring sZipMd5File) ;
	bool GetBugReportService(_tstring sUserName, _tstring sBugType, _tstring sSummary, _tstring sDescription, _tstring sLang, _tstring sCCVersion, _tstring sSysInfo, _tstring sZipMd5File) ;
	bool GetUninstallGameService(_tstring sUserName, _tstring sFactor, _tstring sGameName, _tstring sStar, _tstring sLang, _tstring sCCVersion, _tstring sComment, _tstring sSysInfo, _tstring sZipMd5File) ;
	bool GetCrashReportService(_tstring sUserName, _tstring sLang, _tstring sCCVersion, _tstring sDumpFile, _tstring sSysInfo, _tstring sZipMd5File,_tstring szDumpTyoe) ;
	bool GetUninstallService(_tstring sLang, _tstring sFactor, _tstring sStar, _tstring sSysInfo, _tstring sComment) ;
	bool GetGameEULAService(_tstring sGameAbbr, _tstring sLang, _tstring& sVersion, _tstring& sEula) ;
	bool GetCOREEULAService(_tstring sLang, _tstring& sVersion, _tstring& sEula) ;
	bool IsBanedRegion();
    bool GetEmsService(_tstring sLang,WEB_EMS_DATA& EmsData,bool bNotify=false, const std::string sEmsData="");

	bool DownloadFile(LPCTSTR lpszUrl,LPCTSTR lpszFile,bool bRetry=true, int nTimeout = 0);

	bool GetSaltService(_tstring sUser, int &nLoginType, _tstring &salt);

	// game publish platform
	bool GetGameinfoVersion(_tstring sLan, int &nVersion);
	bool GetAllGameinfo(_tstring sLan, _tstring &sData);
	bool GetGameinfoByAbbr(_tstring sLan, _tstring sAbbr, _tstring &sData);
	
	// redemption key add by sw
	bool GetRedemptionKeyInfoService(const _tstring& sSessionID, const _tstring& sKeycode, std::string& resultXml);
	// serverId and client id can be empty string
	bool GetRedemptionKeyReigistService(const _tstring& sSessionID,const _tstring& keycode, const _tstring& keyType,const _tstring& serverId, const _tstring& roleId, std::string& resultXml);

	//Promotion Popup
	bool GetPromotionCampaignListService(const _tstring& sSessionID, std::string& resultXml);
	bool PostPromotionListService(_tstringA sSessionId, _tstring sPostData);
	bool PostLocalGameListService(_tstringA sSessionId, _tstring sPostData);

	//Tracking hasoffers
	bool GetADTrackingService(const _tstring& sSessionID, std::string& resultXml);
	bool PostADTrackingService(_tstringA sSessionId, _tstring sPostData);
	bool PostBackHasoffersGoal(const _tstring& sTransactionID, const _tstring& sGoalID);
	bool GetGoalInfo(const _tstringA sSessionId, const _tstring& sOfferID, const _tstring& sRefID, _tstring& sGoalID);

	bool GetBannedGameListService(const _tstring& sSessionID, std::string& resultXml);

	bool GetShoppingCartService(_tstringA sSessionId, int& count);

	bool GetIsFirstPlayingGameService(const _tstring& sSessionId, const _tstring& szGameAbbr, const _tstring& lang, bool& bSuccess, bool& isFirstTime,_tstring& szFaildReason);
 
    //arc guard sytem 
    int EanbleDefenderSystem(const _tstring& sSessionId, const bool bEnable,const _tstring& szPassword);
    bool UpdateDevName(const _tstring& sSessionId,const _tstring& szDevId,const _tstring& szDevName);

	//arc cloud game management
	bool AddGameToCloud(const _tstring& sSessionId, _tstring sGames);
	bool UpdateCloudGame(const _tstring& sSessionId, _tstring sGames);
	bool DeleteCloudGame(const _tstring& sSessionId, _tstring sGames);
	bool GetAllCloudGames(const _tstring& sSessionId, _tstring& sGames);
	bool IsGameDeletable(const _tstring& sSessionId, _tstring sGames);

protected:
	bool GetFeedbackService(_tstring sPostData) ;
	bool GetFeedbackService(const std::map<_tstring,CWebService::POST_DATA>& mapField_Value) ;
 
	bool process_service_data(std::string sData, vector<int>& vecCount) ;
	bool process_mail_data(std::string sData, _tstring& sUserName) ;
	bool process_login_data(std::string sData, _tstringA& sSessionId, _tstring& sUserName, _tstring& sNickName) ;
	bool process_inbox_data(std::string sData, vector<WEB_INBOX_MSG>& vecInbox) ;
	bool process_playnow_data(std::string sData, vector<AUTOPLAYNOW_INFO>& vecPlayNowReq);
	bool process_displayname_data(std::string sData, _tstring& sError);
	bool process_userinfo_data(std::string szData, _tstring& szNick);
	bool process_friend_data(std::string sData, vector<WEB_FRIEND_REQ>& vecFriendReq) ;
	bool process_connect_data(std::string sData, vector<WEB_CONNECT_UPDATE>& vecConUpt) ;
	bool process_coupon_data(std::string sData, vector<WEB_COUPON_MSG>& vecCoupon) ;
	bool process_charactor_data(std::string sData, CWebData::WEB_CHARACT_MSG &webData) ;
	bool process_response_data(std::string sData) ;
	bool process_gameserver_data(std::string sData, vector<CWebData::WEB_GAMESERVER_INFO>& vecGameServerInfo) ;
	bool process_gamebetakey_data(std::string sData, map<_tstring, int>& mapBetaKeyFlag) ;
	bool process_gamebetapay_data(std::string sData, int& nBetaPayFlag) ;
	bool process_gamebetaoffline_data(std::string sData, map<_tstring, _tstring>& mapBetaOffline) ;
	bool process_popuptext_data(std::string sData, map<_tstring, _tstring>& mapNotificationText) ;
	bool process_eula_data(std::string sData, _tstring& sVersion, _tstring& sEula) ;
	bool process_downloadoption_data(std::string sData, int& nDwonloadOption) ;
	bool process_emergencymessage_data(std::string sData, vector<EMERGENCY_MESSAGE_DATA>& vecEmergencyMessage);
	bool process_goal_info(std::string sData, const _tstring& sOfferID, _tstring& sGoalID);

	bool MakeDir(LPCTSTR lpszStr) ;
};

extern CWebData g_theWebData ;
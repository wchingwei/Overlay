/**
 * @file      CoreInfo.h
   @brief     The header file for exporting some useful functions.
   @author    shenhui@pwrd.com
   @data      2010/09/26
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
 * $Revision: 
 * $Note: 
 * $Id: N/A
 *
 * $LastChangedBy: shenhui@pwrd.com
 * $LastChangedDate: 2010-12-31
 * $Revision: 01.00.10
 * $Note: add bNeedUpdate parameter for GetGameLocalInfo interface
 * $Id: N/A
 */

#pragma once 

#include "datatype.h"

/*
Note: 
Verify whether specified game is installed on local machine 
and obtain the version if installed.

Param:
[in]      nType       specified game type
[in]      bFirstLogin verify whether CORE Client is firstly logged in after installation.
[in|out]  pGameData   specified game information, and get the full path of game launcher.exe
[out]     bInstalled  true if game is already installed, otherwise false
[out]     bNeedUpdate true if game is needed to be updated

Return:
true if succeeded, otherwise false.
call GetLaseError() if you want to know speicifed error info.
*/
//BOOL GetGameLocalInfo(int nType, bool bFirstLogin, GAME_DATA* pGameData, bool& bInstalled, bool& bNeedUpdate) ;

class CThirdPartyApp;

BOOL GetAppLocalInfo(CThirdPartyApp *pApp);
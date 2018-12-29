#pragma once
/*
* Module:   TRTCGetUserIDAndUserSig
*
* Function: ���ڻ�ȡ��װ TRTCParam ������� UserSig����Ѷ��ʹ�� UserSig ���а�ȫУ�飬�������� TRTC ������������
*/

#include <string>
#include <vector>
#include <stdint.h>
#include "HttpClient.h"
struct UserInfo
{
    std::string userId;
    std::string userSig;
};

class TRTCGetUserIDAndUserSig
{
protected:
    TRTCGetUserIDAndUserSig();
    TRTCGetUserIDAndUserSig(const TRTCGetUserIDAndUserSig&);
    TRTCGetUserIDAndUserSig operator =(const TRTCGetUserIDAndUserSig&);
public:
    ~TRTCGetUserIDAndUserSig();
    static TRTCGetUserIDAndUserSig& instance();

    /**
    * �ӱ��صĲ����������ļ��ж�ȡһ��userid �� usersig
    * �����ļ�����ͨ��������Ѷ��TRTC����̨��https://console.cloud.tencent.com/rav���еġ��������֡�ҳ������ȡ
    * �����ļ��е� userid �� usersig ������Ѷ��Ԥ�ȼ������ɵģ�ÿһ�� usersig ����Ч��Ϊ 180��
    *
    * �÷������ʺϱ�����ͨdemo�͹��ܵ��ԣ���Ʒ�������߷�����Ҫʹ�÷�������ȡ�������� getUserSigFromServer
    *
    * �ο��ĵ���https://cloud.tencent.com/document/product/647/17275#GetForDebug
    *
    */
    bool loadFromConfig();
    uint32_t getConfigSdkAppId() const;
    std::vector<UserInfo> getConfigUserIdArray() const;

    /**
    * ͨ�� http ���󵽿ͻ���ҵ��������ϻ�ȡ userid �� usersig
    * ���ַ�ʽ���Խ�ǩ�� usersig �ļ��㹤����������ҵ��������Ͻ��У�����һ����usersig ��ǩ�������Ϳ��԰�ȫ�ɿ�
    *
    * ����demo�е� getUserSigFromServer ��������Ϊʾ�����룬Ҫ��ͨ���߼�������Ҫ�ο���https://cloud.tencent.com/document/product/647/17275#GetFromServer
    */
    //��ʾ����������ο�
    std::string getUserSigFromServer(std::string userId, std::string pwd, int roomId, int sdkAppId);
private:
    uint32_t m_sdkAppId;
    std::vector<UserInfo> m_userInfos;
private:
    HttpClient m_http_client;
};

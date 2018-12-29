/*
* Module:   TRTCMainViewController
*
* Function: ʹ��TRTC SDK��� 1v1 �� 1vn ����Ƶͨ������
*
*    1. ֧�־Ź���ƽ�̺�ǰ��������ֲ�ͬ����Ƶ���沼�ַ�ʽ���ò����� TRTCVideoViewLayout ������ÿ����Ƶ�����λ���Ų��ʹ�С�ߴ�
*
*    2. ֧�ֶ���Ƶͨ���ķֱ��ʡ�֡�ʺ�����ģʽ���е������ò����� TRTCSettingViewController ��ʵ��
*
*    3. �������߼���ĳһ��ͨ�����䣬��Ҫ��ָ�� roomid �� userid���ⲿ���� TRTCNewViewController ��ʵ��
*/

#pragma once

#include "TRTCCloud.h"

#include <string>
#include <functional>
#include <map>


TRTCCloud* getTRTCCloud();
void destroyTRTCCloud();
// CTRTCDemoDlg �Ի���
class TRTCSettingViewController;
class TRTCMainViewController
    : public CDialogEx
    , public ITRTCCloudCallback
{
    // ����
public:
    TRTCMainViewController(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_TESTTRTCAPP_DIALOG };
#endif

public:
    void enterRoom(TRTCParams& params);

protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
    virtual BOOL OnInitDialog();
// ʵ��
protected:
    CFont newFont;
    HICON m_hIcon;
    int m_roomId = 0;
    std::map<int, std::string> m_remoteUserInfo;
    TRTCSettingViewController *m_pTRTCSettingViewController = nullptr;
    // ���ɵ���Ϣӳ�亯��
    int m_showDebugView = 0;
    DECLARE_MESSAGE_MAP()
protected:
    void switchToMainThread(std::function<void(void)> func);
    virtual void onEnterRoom(uint64_t elapsed);
    virtual void onExitRoom(int reason);
    virtual void onUserEnter(const char* userId);
    virtual void onUserExit(const char* userId, int reason);

    
private:
    int FindIdleRemoteVideoView();
    int FindOccupyRemoteVideoView(std::string userId);
    void UpdateRemoteViewInfo(int id, std::string userId);
public:
    static TRTCCloud* g_cloud;
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    afx_msg LRESULT OnCustomMessage(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnMsgSettingViewClose(WPARAM wParam, LPARAM lParam);
    afx_msg void OnBnClickedExitRoom();
    afx_msg void OnBnClickedSetting();
    afx_msg void OnBnClickedLog();
};

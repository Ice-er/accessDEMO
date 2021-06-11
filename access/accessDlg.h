
// accessDlg.h: 头文件
//

#pragma once

#pragma warning(disable:4995)
#include"afxdao.h"



// CaccessDlg 对话框
class CaccessDlg : public CDialogEx
{
// 构造
public:
	CaccessDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ACCESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	CString studentID;
	CString studentName;
	BOOL sex;
	CString registDate;
	CString studentMajor;
	CString classID;
	afx_msg void OnBnClickedConnectdatabase();
	afx_msg void OnBnClickedDisconnect();
	afx_msg void OnBnClickedDataset();
	afx_msg void OnBnClickedClosetable();
	afx_msg void OnBnClickedAddrecord();
	afx_msg void OnBnClickedPreone();
	afx_msg void OnBnClickedNext();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit8();


	//void readStudent();
	void CaccessDlg::readStudent();

};

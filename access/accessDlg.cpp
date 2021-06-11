
// accessDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "access.h"
#include "accessDlg.h"
#include "afxdialogex.h"

//
#pragma warning(disable:4995)
#include"afxdao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//
CDaoDatabase* studentDB;
CDaoRecordset* studentsTb;
COleVariant studentNumber;
COleVariant Propertys;




// CaccessDlg 对话框

CaccessDlg::CaccessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ACCESS_DIALOG, pParent)
	, studentID(_T(""))
	, studentName(_T(""))
	, sex(FALSE)
	, registDate(_T(""))
	, studentMajor(_T(""))
	, classID(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CaccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, studentID);
	DDX_Text(pDX, IDC_EDIT2, studentName);
	DDX_Text(pDX, IDC_EDIT3, sex);
	DDX_Text(pDX, IDC_EDIT4, registDate);
	DDX_Text(pDX, IDC_EDIT5, studentMajor);
	DDX_Text(pDX, IDC_EDIT6, classID);
}

BEGIN_MESSAGE_MAP(CaccessDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_EN_CHANGE(IDC_EDIT1, &CaccessDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CaccessDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CaccessDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CaccessDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CaccessDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CaccessDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(Connectdatabase, &CaccessDlg::OnBnClickedConnectdatabase)
	ON_BN_CLICKED(Disconnect, &CaccessDlg::OnBnClickedDisconnect)
	
	ON_BN_CLICKED(Dataset, &CaccessDlg::OnBnClickedDataset)
	ON_BN_CLICKED(Closetable, &CaccessDlg::OnBnClickedClosetable)
	ON_BN_CLICKED(Addrecord, &CaccessDlg::OnBnClickedAddrecord)
	ON_BN_CLICKED(Preone, &CaccessDlg::OnBnClickedPreone)
	ON_BN_CLICKED(Next, &CaccessDlg::OnBnClickedNext)
	ON_EN_CHANGE(IDC_EDIT7, &CaccessDlg::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &CaccessDlg::OnEnChangeEdit8)
END_MESSAGE_MAP()


// CaccessDlg 消息处理程序

BOOL CaccessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CaccessDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CaccessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CaccessDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CaccessDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CaccessDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CaccessDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CaccessDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CaccessDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CaccessDlg::OnBnClickedConnectdatabase()
{
	// TODO: 在此添加控件通知处理程序代码
	studentDB = new CDaoDatabase(NULL);
	studentDB->Open(_T("E:\\students.mdb"), 0, 0, _T(""));
	//E:\\database\\studenttest.mdb
}


void CaccessDlg::OnBnClickedDisconnect()
{
	// TODO: 在此添加控件通知处理程序代码
	studentDB->Close();
}



void CaccessDlg::OnBnClickedDataset()
{
	// TODO: 在此添加控件通知处理程序代码
	studentsTb = new CDaoRecordset(studentDB);
	studentsTb->Open(dbOpenDynaset, _T("select * from student"));
	studentNumber = studentsTb->GetRecordCount();
	Propertys = studentsTb->GetFieldCount();
	studentsTb->MoveFirst();
	readStudent();
	UpdateData(false);
}


void CaccessDlg::OnBnClickedClosetable()
{
	// TODO: 在此添加控件通知处理程序代码
	studentsTb->Close();
}


void CaccessDlg::OnBnClickedAddrecord()
{
	// TODO: 在此添加控件通知处理程序代码
	studentsTb->AddNew();
	studentsTb->SetFieldValue(_T("studentID"), _T("0000003"));
	studentsTb->Update();
	studentNumber = studentsTb->GetRecordCount();
	UpdateData(false);
}


void CaccessDlg::OnBnClickedPreone()
{
	// TODO: 在此添加控件通知处理程序代码
	studentsTb->MovePrev();
	readStudent();
	UpdateData(false);

}


void CaccessDlg::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	studentsTb->MoveNext();
	readStudent();
	UpdateData(false);
}


void CaccessDlg::readStudent()
{
	// TODO: 在此处添加实现代码.
	COleVariant fieldValue;
	studentsTb->GetFieldValue(_T("studentID"), fieldValue);
	studentID = fieldValue.bstrVal;

	studentsTb->GetFieldValue(_T("studentName"), fieldValue);
	studentName = fieldValue.bstrVal;

	studentsTb->GetFieldValue(_T("sex"), fieldValue);
	sex = fieldValue.boolVal;

	studentsTb->GetFieldValue(_T("classID"), fieldValue);
	classID = fieldValue.bstrVal;

	studentsTb->GetFieldValue(_T("studentMajor"), fieldValue);
	studentMajor = fieldValue.bstrVal;

	studentsTb->GetFieldValue(_T("registDate"), fieldValue);
	CTime registDateValue;
	registDateValue = fieldValue.date;
	registDate = registDateValue.Format(_T("%Y-%m-%d"));
}


void CaccessDlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CaccessDlg::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

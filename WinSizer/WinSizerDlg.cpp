﻿
// WinSizerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "WinSizer.h"
#include "WinSizerDlg.h"
#include "CaptureDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinSizerDlg 对话框



CWinSizerDlg::CWinSizerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WINSIZER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWinSizerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_CAPTURE_VISIBLE_ONLY, m_checkCaptureVisibleOnly);
}

BEGIN_MESSAGE_MAP(CWinSizerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CAPTURE, &CWinSizerDlg::OnBnClickedBtnCapture)
END_MESSAGE_MAP()


// CWinSizerDlg 消息处理程序

BOOL CWinSizerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ModifyStyle(WS_CAPTION, 0);
	m_checkCaptureVisibleOnly.SetCheck(BST_CHECKED);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWinSizerDlg::OnPaint()
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
HCURSOR CWinSizerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWinSizerDlg::OnBnClickedBtnCapture()
{
	CCaptureDlg dlg;
	dlg.CaptureVisibleOnly(m_checkCaptureVisibleOnly.GetCheck() == BST_CHECKED);
	dlg.DoModal();
	CWnd* pWnd = dlg.GetSelectWindow();
	CString strClassName = _T("");
	CString strWindowText = _T("");
	CRect winRect;
	CString strWidth(_T("0")), strHeight(_T("0"));
	if (pWnd == NULL)
	{
		GetDlgItem(IDC_EDIT_CURRENT_WINDOW_CLASS)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_CURRENT_WINDOW_CLASS)->SetWindowText(strClassName);
		GetDlgItem(IDC_EDIT_CURRENT_WINDOW_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_CURRENT_WINDOW_NAME)->SetWindowText(strWindowText);
		GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(strWidth);
		GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(strHeight);
	}
	else
	{
		::GetClassName(pWnd->GetSafeHwnd(), strClassName.GetBuffer(256), 256);
		::GetWindowText(pWnd->GetSafeHwnd(), strWindowText.GetBuffer(256), 256);
		pWnd->GetWindowRect(&winRect);
		strWidth.Format(_T("%d"), winRect.Width());
		strHeight.Format(_T("%d"), winRect.Height());
		GetDlgItem(IDC_EDIT_CURRENT_WINDOW_CLASS)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_CURRENT_WINDOW_CLASS)->SetWindowText(strClassName);
		GetDlgItem(IDC_EDIT_CURRENT_WINDOW_NAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_CURRENT_WINDOW_NAME)->SetWindowText(strWindowText);
		GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(strWidth);
		GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(strHeight);
	}
}


// WinSizerDlg.h: 头文件
//

#pragma once


// CWinSizerDlg 对话框
class CWinSizerDlg : public CDialogEx
{
// 构造
public:
	CWinSizerDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINSIZER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CWnd* m_pWnd;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnCapture();
	afx_msg void OnBnClickedBtnResize();
	int m_winWidth;
	int m_winHeight;
	afx_msg void OnBnClickedBtnMaximize();
	afx_msg void OnBnClickedBtnMinimize();
	afx_msg void OnBnClickedCheckTop();
	BOOL m_bTopWindow;
	BOOL m_bCaptureVisibleOnly;
};

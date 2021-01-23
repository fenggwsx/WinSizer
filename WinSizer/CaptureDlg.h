#pragma once
#include <afxwin.h>

// CCaptureDlg 对话框

class CCaptureDlg : public CDialog
{
	DECLARE_DYNAMIC(CCaptureDlg)

public:
	CCaptureDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCaptureDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAPTURE_DIALOG };
#endif

protected:
	BOOL m_bCaptureVisibleOnly;
	CRect m_currentRect;
	CWnd* m_pWnd;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void CaptureVisibleOnly(BOOL bCaptureVisibleOnly = TRUE)
	{
		m_bCaptureVisibleOnly = bCaptureVisibleOnly;
	}
	CWnd* GetSelectWindow()
	{
		return m_pWnd;
	}
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

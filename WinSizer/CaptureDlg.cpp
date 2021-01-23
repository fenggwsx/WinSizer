// CaptureDlg.cpp: 实现文件
//

#include "pch.h"
#include "WinSizer.h"
#include "CaptureDlg.h"
#include "afxdialogex.h"


// CCaptureDlg 对话框

IMPLEMENT_DYNAMIC(CCaptureDlg, CDialog)

CCaptureDlg::CCaptureDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CAPTURE_DIALOG, pParent)
{
	m_bCaptureVisibleOnly = FALSE;
	m_currentRect.SetRectEmpty();
	m_pWnd = NULL;
}

CCaptureDlg::~CCaptureDlg()
{
}

void CCaptureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCaptureDlg, CDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CCaptureDlg 消息处理程序


BOOL CCaptureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	::SetLayeredWindowAttributes(m_hWnd, 0, 128, LWA_ALPHA);
	ShowWindow(SW_MAXIMIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CCaptureDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);

	CWnd* pWnd = CWnd::GetDesktopWindow()->GetTopWindow();
	while (pWnd != this)
		pWnd = pWnd->GetNextWindow();

	CRect winRect, oldRect;
	oldRect = m_currentRect;
	m_currentRect.SetRectEmpty();
	pWnd = pWnd->GetNextWindow();
	while (pWnd != NULL)
	{
		pWnd->GetWindowRect(&winRect);
		if (winRect.PtInRect(point) == TRUE && (m_bCaptureVisibleOnly == FALSE || pWnd->IsWindowVisible() == TRUE))
		{
			m_currentRect = winRect;
			break;
		}
		pWnd = pWnd->GetNextWindow();
	}

	InvalidateRect(oldRect, FALSE);
	InvalidateRect(m_currentRect, FALSE);

	CDialog::OnMouseMove(nFlags, point);
}


void CCaptureDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rectClient;
	GetClientRect(&rectClient);

	dc.FillSolidRect(rectClient, GetSysColor(COLOR_BTNFACE));
	dc.FillSolidRect(m_currentRect, RGB(255, 0, 0));
}


void CCaptureDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);

	CWnd* pWnd = CWnd::GetDesktopWindow()->GetTopWindow();
	while (pWnd != this)
		pWnd = pWnd->GetNextWindow();

	CRect winRect;
	pWnd = pWnd->GetNextWindow();
	while (pWnd != NULL)
	{
		pWnd->GetWindowRect(&winRect);
		if (winRect.PtInRect(point) == TRUE && (m_bCaptureVisibleOnly == FALSE || pWnd->IsWindowVisible() == TRUE)) break;
		pWnd = pWnd->GetNextWindow();
	}

	m_pWnd = pWnd;

	SendMessage(WM_CLOSE);
}

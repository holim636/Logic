// KeyInputView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Logic.h"
#include "LogicDoc.h"
#include "KeyInputView.h"

#define IDC_LIST1 100
// CKeyInputView
IMPLEMENT_DYNCREATE(CKeyInputView, CView)

typedef class UNIT{
private:
	int state = 0;//����
	int gate1 = 0;
	int gate2 = 0;
	int clk;
public:
	POINT next;
	int type;
	int gateIn1(int a){ gate1 = a; }
	int gateIn2(int a){ gate2 = a; }
	int output();
}unit;//����� ��Ʈ��Ʈ
typedef struct BOARD{
	int type = 0;
	int face = 0;
	POINT next;//7�ϰ�� ���� ��ǥ�� ����
	unit* unit;
}Board;

extern Board board[1200][800];

CKeyInputView::CKeyInputView()
{
	
}

CKeyInputView::~CKeyInputView()
{
}

BEGIN_MESSAGE_MAP(CKeyInputView, CView)
	
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CKeyInputView �׸����Դϴ�.

void CKeyInputView::OnDraw(CDC* pDC)
{
	CLogicDoc* pDoc = (CLogicDoc *)GetDocument();
	CClientDC dc(this);

	CBitmap bitmap7;


	bitmap7.LoadBitmap(IDB_BITMAP7);


	BITMAP bmpinfo7;

	bitmap7.GetBitmap(&bmpinfo7);


	CDC dcmem7;

	dcmem7.CreateCompatibleDC(&dc);


	dcmem7.SelectObject(&bitmap7);
	dc.BitBlt(0, 200, bmpinfo7.bmWidth, bmpinfo7.bmHeight, &dcmem7, 0, 0, SRCCOPY);
	
	
}


// CKeyInputView �����Դϴ�.

#ifdef _DEBUG
void CKeyInputView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CKeyInputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CKeyInputView �޽��� ó�����Դϴ�.





int CKeyInputView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// �� ����Ʈ ��Ʈ�� ����
	m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT,
		CRect(0, 0, 300, 198), this, IDC_LIST1);


	// �� �̹��� ����Ʈ ������ �ʱ�ȭ
	CImageList ilLarge, ilSmall;
	ilLarge.Create(32, 32, ILC_COLOR4, 1, 1);
	ilSmall.Create(16, 16, ILC_COLOR4, 1, 1);


	// �� �̹��� ����Ʈ ����
	m_list.SetImageList(&ilLarge, LVSIL_NORMAL);
	m_list.SetImageList(&ilSmall, LVSIL_SMALL);
	ilLarge.Detach();
	ilSmall.Detach();

	// �� ��� �ʱ�ȭ
	m_list.InsertColumn(0, _T("Selection"), LVCFMT_LEFT, 150, 0);
	m_list.InsertColumn(1, _T("$s Gate"), LVCFMT_LEFT, 150, 1);
	

	// �� �׸� �߰�
	m_list.InsertItem(0, _T("Facing"), 0);
	m_list.InsertItem(1, _T("Data Bits"), 0);
	m_list.InsertItem(3, _T("Gate Size"), 0);
	m_list.InsertItem(4, _T("Number of Inputs"), 0);
	m_list.InsertItem(5, _T("Output Value"), 0);
	m_list.InsertItem(6, _T("Label"), 0);
	m_list.InsertItem(7, _T("Lavel Font"), 0);
	m_list.InsertItem(8, _T("Negate 1"), 0);
	m_list.InsertItem(9, _T("Negate 2"), 0);
	


	// �� ���� �׸� �߰�
	m_list.SetItemText(0, 1, _T(""));
	m_list.SetItemText(1, 1, _T(""));
	m_list.SetItemText(2, 1, _T(""));
	m_list.SetItemText(3, 1, _T(""));
	m_list.SetItemText(4, 1, _T(""));
	m_list.SetItemText(5, 1, _T(""));
	m_list.SetItemText(6, 1, _T(""));
	m_list.SetItemText(7, 1, _T(""));
	m_list.SetItemText(8, 1, _T(""));
	m_list.SetItemText(9, 1, _T(""));
	

	// Ȯ�� ��Ÿ�� ����
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_GRIDLINES);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_SIMPLESELECT);

	
	
	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}

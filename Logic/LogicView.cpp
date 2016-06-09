
// LogicView.cpp : CLogicView Ŭ������ ����
//
#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Logic.h"
#endif

#include "LogicDoc.h"
#include "LogicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define and 1
#define or 2
#define not 3
typedef struct BOARD{
	int type;
	int face;
}Board;
typedef struct UNIT{
	int type; //Ÿ��
	int pointx;
	int pointy;//��ǥ
	int state;//����
	int gate1;
	int gate2;
	int clk;
	int output1;
	int output2;
}unit;//����� ��Ʈ��Ʈ
class electric : public CPtrList{
private :
	unit Unit;


};


Board board[1200][800] = {0,};//��ǥ ������ ����
// CLogicView

IMPLEMENT_DYNCREATE(CLogicView, CView)

BEGIN_MESSAGE_MAP(CLogicView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32772, &CLogicView::On32772)
	ON_COMMAND(ID_32773, &CLogicView::On32773)
	ON_COMMAND(ID_32774, &CLogicView::On32774)
	ON_COMMAND(ID_32775, &CLogicView::On32775)
	ON_COMMAND(ID_32776, &CLogicView::On32776)
	ON_COMMAND(ID_32777, &CLogicView::On32777)
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CLogicView ����/�Ҹ�

CLogicView::CLogicView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CLogicView::~CLogicView()
{
}

BOOL CLogicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CLogicView �׸���

void CLogicView::OnDraw(CDC* pDC)
{
	CClientDC dc(this);
	CLogicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen pen(PS_SOLID, 1, RGB(234,234,234));
	dc.SelectObject(&pen);
	
	for (int x = 0; x <= 100; x++)
	{
		dc.MoveTo(10 + 10 * x, 0);
		dc.LineTo(10 + 10 * x, 10 + 20 * 50);
	}

	for (int y = 0; y <= 100; y++)
	{
		dc.MoveTo(0, 10 + 10 * y);
		dc.LineTo(10 + 20 * 50, 10 + 10 * y);
	}
	
	
}
	
	
		
	

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.



// CLogicView ����

#ifdef _DEBUG
void CLogicView::AssertValid() const
{
	CView::AssertValid();
}

void CLogicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLogicDoc* CLogicView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogicDoc)));
	return (CLogicDoc*)m_pDocument;
}
#endif //_DEBUG


// CLogicView �޽��� ó����


void CLogicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CBitmap bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, bitmap6;
	
	bitmap1.LoadBitmap(IDB_BITMAP1);
	bitmap2.LoadBitmap(IDB_BITMAP2);
	bitmap3.LoadBitmap(IDB_BITMAP3);
	bitmap4.LoadBitmap(IDB_BITMAP4);
	bitmap5.LoadBitmap(IDB_BITMAP5);
	bitmap6.LoadBitmap(IDB_BITMAP6);

	BITMAP bmpinfo1, bmpinfo2, bmpinfo3, bmpinfo4, bmpinfo5, bmpinfo6;

	bitmap1.GetBitmap(&bmpinfo1);
	bitmap2.GetBitmap(&bmpinfo2);
	bitmap3.GetBitmap(&bmpinfo3);
	bitmap4.GetBitmap(&bmpinfo4);
	bitmap5.GetBitmap(&bmpinfo5);
	bitmap6.GetBitmap(&bmpinfo6);

	CDC dcmem1, dcmem2, dcmem3, dcmem4, dcmem5, dcmem6;

	dcmem1.CreateCompatibleDC(&dc);
	dcmem2.CreateCompatibleDC(&dc);
	dcmem3.CreateCompatibleDC(&dc);
	dcmem4.CreateCompatibleDC(&dc);
	dcmem5.CreateCompatibleDC(&dc);
	dcmem6.CreateCompatibleDC(&dc);

	dcmem1.SelectObject(&bitmap1);
	dcmem2.SelectObject(&bitmap2);
	dcmem3.SelectObject(&bitmap3);
	dcmem4.SelectObject(&bitmap4);
	dcmem5.SelectObject(&bitmap5);
	dcmem6.SelectObject(&bitmap6);

	CRect rect;
	CRgn rgn1;
	m_nButtonDown = 1;

			if (button1 == 1 ){
				button1 = 0;
				board[box(point.x)][box(point.y)].type = 1;
			}
			if (button2 == 1){
				button2 = 0;
				board[box(point.x)][box(point.y)].type = 2;
			}
			if (button3 == 1){
				button3 = 0;
				board[box(point.x)][box(point.y)].type = 3;
			}
			if (button4 == 1){
				dc.TransparentBlt(point.x, point.y, bmpinfo4.bmWidth, bmpinfo4.bmHeight, &dcmem4, 0, 0, bmpinfo4.bmWidth, bmpinfo4.bmHeight, RGB(255, 255, 255));
				button4 = 0;

			}
			if (button5 == 1){
				dc.TransparentBlt(point.x, point.y, bmpinfo5.bmWidth, bmpinfo5.bmHeight, &dcmem5, 0, 0, bmpinfo5.bmWidth, bmpinfo5.bmHeight, RGB(255, 255, 255));
				button5 = 0;
	
			
			}
			if (button6 == 1){
				dc.TransparentBlt(point.x, point.y, bmpinfo1.bmWidth, bmpinfo6.bmHeight, &dcmem6, 0, 0, bmpinfo6.bmWidth, bmpinfo6.bmHeight, RGB(255, 255, 255));
				button6 = 0;
			}
			
	m_p2.x = m_p.x = point.x;

	m_p2.y = m_p.y = point.y;

	m_bTrack = TRUE;
	int i, j;
	for (i = 0; i < 1200; i++){
		for (j = 0; j < 800; j++)
		{
			switch (board[i][j].type){
			case 0: break;
			case 1: dc.TransparentBlt(i, j, bmpinfo1.bmWidth, bmpinfo1.bmHeight, &dcmem1, 0, 0, bmpinfo1.bmWidth, bmpinfo1.bmHeight, RGB(255, 255, 255)); break;
			case 2: dc.TransparentBlt(i,j, bmpinfo2.bmWidth, bmpinfo2.bmHeight, &dcmem2, 0, 0, bmpinfo2.bmWidth, bmpinfo2.bmHeight, RGB(255, 255, 255)); break;
			case 3: dc.TransparentBlt(i, j, bmpinfo3.bmWidth, bmpinfo3.bmHeight, &dcmem3, 0, 0, bmpinfo3.bmWidth, bmpinfo3.bmHeight, RGB(255, 255, 255)); break;
			}
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CLogicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	dc.MoveTo(m_p.x, m_p.y);

	dc.LineTo(point.x, point.y);

	m_bTrack = FALSE;
	
	
	CView::OnLButtonUp(nFlags, point);
}


void CLogicView::OnMouseMove(UINT nFlags, CPoint point)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		CDC * pDc = GetDC();
		pDc->SetROP2(R2_NOT);
		pDc->MoveTo(m_p.x, m_p.y);
		pDc->LineTo(m_p2.x, m_p2.y);
		pDc->MoveTo(m_p.x, m_p.y);
		pDc->LineTo(point.x, point.y);
		ReleaseDC(pDc);
		m_p2 = point;

	
	
		
	}
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnMouseMove(nFlags, point);
}


void CLogicView::On32772() //AND
{
	button1 = 1;
	button2 = 0;
	button3 = 0;
	button4 = 0;
	button5 = 0;
	button6 = 0;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CLogicView::On32773() //OR
{
	button1 = 0;
	button2 = 1;
	button3 = 0;
	button4 = 0;
	button5 = 0;
	button6 = 0;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CLogicView::On32774() //NAND
{
	button1 = 0;
	button2 = 0;
	button3 = 1;
	button4 = 0;
	button5 = 0;
	button6 = 0;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CLogicView::On32775() //XOR
{
	button1 = 0;
	button2 = 0;
	button3 = 0;
	button4 = 1;
	button5 = 0;
	button6 = 0;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CLogicView::On32776() //NOR
{
	button1 = 0;
	button2 = 0;
	button3 = 0;
	button4 = 0;
	button5 = 1;
	button6 = 0;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CLogicView::On32777() //NOT
{
	button1 = 0;
	button2 = 0;
	button3 = 0;
	button4 = 0;
	button5 = 0;
	button6 = 1;
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


int CLogicView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}


void CLogicView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

int box(int x)
{
	int a;
	a = x % 10;
	x = x - a;
	return x;
}

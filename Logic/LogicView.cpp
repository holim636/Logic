
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
	
	for (int y = 0; y<100; y++)
		for (int x = 0; x<100; x++)
			m_nBoard[y][x] = 0;

	
	
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
	m_nButtonDown = 1;
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CBitmap bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, bitmap6;
	CBitmap *pOldBit1, *pOldBit2, *pOldBit3, *pOldBit4, *pOldBit5, *pOldBit6;
	
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

	pOldBit1 = dcmem1.SelectObject(&bitmap1);
	pOldBit2 = dcmem2.SelectObject(&bitmap2);
	pOldBit3 = dcmem3.SelectObject(&bitmap3);
	pOldBit4 = dcmem4.SelectObject(&bitmap4);
	pOldBit5 = dcmem5.SelectObject(&bitmap5);
	pOldBit6 = dcmem6.SelectObject(&bitmap6);

	CRect rect;
	CRgn rgn1;
	m_nButtonDown = 1;

			if (button1 == 1 ){
				dc.TransparentBlt(point.x, point.y, bmpinfo1.bmWidth, bmpinfo1.bmHeight, &dcmem1, 0, 0, bmpinfo1.bmWidth, bmpinfo1.bmHeight, RGB(255, 255, 255));
				button1 = 0;
				dcmem1.SelectObject(pOldBit1);
				rgn1.CreateRectRgn(point.x, point.y, point.x + 50, point.y + 50);
				
				
			}
			if (button2 == 1){
				dc.TransparentBlt(point.x, point.y, bmpinfo2.bmWidth, bmpinfo2.bmHeight, &dcmem2, 0, 0, bmpinfo2.bmWidth, bmpinfo2.bmHeight, RGB(255, 255, 255));
				button2 = 0;
				dcmem2.SelectObject(pOldBit2);
			}
			if (button3 == 1){
				dc.TransparentBlt(point.x, point.y, bmpinfo3.bmWidth, bmpinfo3.bmHeight, &dcmem3, 0, 0, bmpinfo3.bmWidth, bmpinfo3.bmHeight, RGB(255, 255, 255));
				button3 = 0;
				dcmem3.SelectObject(pOldBit3);
			}
			if (button4 == 1){
				dc.TransparentBlt(point.x, point.y, bmpinfo4.bmWidth, bmpinfo4.bmHeight, &dcmem4, 0, 0, bmpinfo4.bmWidth, bmpinfo4.bmHeight, RGB(255, 255, 255));
				button4 = 0;
				dcmem4.SelectObject(pOldBit4);
			}
			if (button5 == 1){
				dc.TransparentBlt(point.x, point.y, bmpinfo5.bmWidth, bmpinfo5.bmHeight, &dcmem5, 0, 0, bmpinfo5.bmWidth, bmpinfo5.bmHeight, RGB(255, 255, 255));
				button5 = 0;
				dcmem5.SelectObject(pOldBit5);
			
			}
			if (button6 == 1){
				dc.TransparentBlt(point.x, point.y, bmpinfo1.bmWidth, bmpinfo6.bmHeight, &dcmem6, 0, 0, bmpinfo6.bmWidth, bmpinfo6.bmHeight, RGB(255, 255, 255));
				button6 = 0;
				dcmem6.SelectObject(pOldBit6);
			}
			
	m_p2.x = m_p.x = point.x;

	m_p2.y = m_p.y = point.y;

	m_bTrack = TRUE;


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


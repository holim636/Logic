// KeyInputView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Logic.h"
#include "LogicDoc.h"
#include "KeyInputView.h"


// CKeyInputView

IMPLEMENT_DYNCREATE(CKeyInputView, CView)

CKeyInputView::CKeyInputView()
{

}

CKeyInputView::~CKeyInputView()
{
}

BEGIN_MESSAGE_MAP(CKeyInputView, CView)
	
END_MESSAGE_MAP()


// CKeyInputView �׸����Դϴ�.

void CKeyInputView::OnDraw(CDC* pDC)
{
	CLogicDoc* pDoc = (CLogicDoc *)GetDocument();


	// ȭ�� ��¿� ��Ʈ�� �����Ѵ�.
	

	// ������� �Էµ� ���ڵ��� ȭ�鿡 ����Ѵ�.
	
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




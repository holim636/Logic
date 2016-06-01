// KeyInputView.cpp : 구현 파일입니다.
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


// CKeyInputView 그리기입니다.

void CKeyInputView::OnDraw(CDC* pDC)
{
	CLogicDoc* pDoc = (CLogicDoc *)GetDocument();


	// 화면 출력용 폰트를 선택한다.
	

	// 현재까지 입력된 글자들을 화면에 출력한다.
	
}


// CKeyInputView 진단입니다.

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


// CKeyInputView 메시지 처리기입니다.




#pragma once


// CKeyInputView ���Դϴ�.

class CKeyInputView : public CView
{
	DECLARE_DYNCREATE(CKeyInputView)

protected:
	CKeyInputView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CKeyInputView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};



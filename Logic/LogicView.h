
// LogicView.h : CLogicView Ŭ������ �������̽�
//

#pragma once

class CLogicView : public CView
{
protected: // serialization������ ��������ϴ�.
	CLogicView();
	DECLARE_DYNCREATE(CLogicView)

// Ư���Դϴ�.
public:
	CLogicDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	bool button1;
	bool button2;
	bool button3;
	bool button4;
	bool button5;
	bool button6;
	CPoint m_p;
	CPoint m_p2;
	BOOL m_bTrack;
	CPoint point;

	BITMAP bmpinfo1, bmpinfo2, bmpinfo3, bmpinfo4, bmpinfo5, bmpinfo6;
	CDC dcmem1, dcmem2, dcmem3, dcmem4, dcmem5, dcmem6;

	bool m_nButtonDown;
	bool m_nButtonUp;

	

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
protected:
	
// �����Դϴ�.
public:
	virtual ~CLogicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32776();
	afx_msg void On32777();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // LogicView.cpp�� ����� ����
inline CLogicDoc* CLogicView::GetDocument() const
   { return reinterpret_cast<CLogicDoc*>(m_pDocument); }
#endif

int box(int x);
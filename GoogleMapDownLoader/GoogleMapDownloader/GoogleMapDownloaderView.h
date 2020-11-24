
// GoogleMapDownloaderView.h: CGoogleMapDownloaderView 类的接口
//

#pragma once


class CGoogleMapDownloaderView : public CView
{
protected: // 仅从序列化创建
	CGoogleMapDownloaderView() noexcept;
	DECLARE_DYNCREATE(CGoogleMapDownloaderView)

// 特性
public:
	CGoogleMapDownloaderDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CGoogleMapDownloaderView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // GoogleMapDownloaderView.cpp 中的调试版本
inline CGoogleMapDownloaderDoc* CGoogleMapDownloaderView::GetDocument() const
   { return reinterpret_cast<CGoogleMapDownloaderDoc*>(m_pDocument); }
#endif


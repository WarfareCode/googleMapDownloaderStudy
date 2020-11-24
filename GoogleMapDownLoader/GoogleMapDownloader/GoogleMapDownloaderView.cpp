
// GoogleMapDownloaderView.cpp: CGoogleMapDownloaderView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GoogleMapDownloader.h"
#endif

#include "GoogleMapDownloaderDoc.h"
#include "GoogleMapDownloaderView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGoogleMapDownloaderView

IMPLEMENT_DYNCREATE(CGoogleMapDownloaderView, CView)

BEGIN_MESSAGE_MAP(CGoogleMapDownloaderView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGoogleMapDownloaderView 构造/析构

CGoogleMapDownloaderView::CGoogleMapDownloaderView() noexcept
{
	// TODO: 在此处添加构造代码

}

CGoogleMapDownloaderView::~CGoogleMapDownloaderView()
{
}

BOOL CGoogleMapDownloaderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGoogleMapDownloaderView 绘图

void CGoogleMapDownloaderView::OnDraw(CDC* /*pDC*/)
{
	CGoogleMapDownloaderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CGoogleMapDownloaderView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGoogleMapDownloaderView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGoogleMapDownloaderView 诊断

#ifdef _DEBUG
void CGoogleMapDownloaderView::AssertValid() const
{
	CView::AssertValid();
}

void CGoogleMapDownloaderView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGoogleMapDownloaderDoc* CGoogleMapDownloaderView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGoogleMapDownloaderDoc)));
	return (CGoogleMapDownloaderDoc*)m_pDocument;
}
#endif //_DEBUG


// CGoogleMapDownloaderView 消息处理程序

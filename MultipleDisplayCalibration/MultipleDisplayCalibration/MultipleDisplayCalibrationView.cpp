
// MultipleDisplayCalibrationView.cpp: CMultipleDisplayCalibrationView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MultipleDisplayCalibration.h"
#endif

#include "MultipleDisplayCalibrationDoc.h"
#include "MultipleDisplayCalibrationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultipleDisplayCalibrationView

IMPLEMENT_DYNCREATE(CMultipleDisplayCalibrationView, CView)

BEGIN_MESSAGE_MAP(CMultipleDisplayCalibrationView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMultipleDisplayCalibrationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMultipleDisplayCalibrationView 생성/소멸

CMultipleDisplayCalibrationView::CMultipleDisplayCalibrationView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMultipleDisplayCalibrationView::~CMultipleDisplayCalibrationView()
{
}

BOOL CMultipleDisplayCalibrationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMultipleDisplayCalibrationView 그리기

void CMultipleDisplayCalibrationView::OnDraw(CDC* /*pDC*/)
{
	CMultipleDisplayCalibrationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMultipleDisplayCalibrationView 인쇄


void CMultipleDisplayCalibrationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMultipleDisplayCalibrationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMultipleDisplayCalibrationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMultipleDisplayCalibrationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMultipleDisplayCalibrationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMultipleDisplayCalibrationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMultipleDisplayCalibrationView 진단

#ifdef _DEBUG
void CMultipleDisplayCalibrationView::AssertValid() const
{
	CView::AssertValid();
}

void CMultipleDisplayCalibrationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultipleDisplayCalibrationDoc* CMultipleDisplayCalibrationView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultipleDisplayCalibrationDoc)));
	return (CMultipleDisplayCalibrationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultipleDisplayCalibrationView 메시지 처리기

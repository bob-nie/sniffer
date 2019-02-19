// snifferView.cpp : implementation of the CSnifferView class
//

#include "stdafx.h"
#include "sniffer.h"

#include "snifferDoc.h"
#include "snifferView.h"

#include <Afxcview.h>
#include <winsock2.h>
#include <process.h>

#include "Define.h"

	CListView* clv;
	CListCtrl* clc;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void WINAPI ThreadProc(LPVOID lpVoid)
{
	SOCKET      sock;
    SOCKADDR_IN	addr_in;
    IpHeader    Lip;
    TcpHeader   Ltcp;
    char        RecvBuf[BUFFER_SIZE];
	char szMsg[BUFFER_SIZE];
	WSADATA     WSAData;
    BOOL	    flag = true;
    int         nTimeout = 1000;
    char        LocalName[16];
    struct      hostent *pHost;
	CSnifferView* csv = (CSnifferView*)lpVoid;
	CListView * cList = (CListView*)csv->GetDlgItem(IDC_LIST);
	CListCtrl* cCtrl = &(cList->GetListCtrl());
 

 
    // 检查 Winsock 版本号
    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
	{
		return;
	}
 
    // 初始化 Raw Socket
    if ((sock = socket(AF_INET, SOCK_RAW,IPPROTO_IP)) == INVALID_SOCKET)
	{
		return;
	}
 
    // 设置IP头操作选项
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (char*)&flag, sizeof(flag)) == SOCKET_ERROR)
	{
		return;
	}
 
    // 获取本机名
    if (gethostname((char*)LocalName, 16) == SOCKET_ERROR)
	{
		return;
	}
 
    // 获取本地 IP 地址
    if ((pHost = gethostbyname((char*)LocalName)) == NULL)
	{
		return;
	}
	
    addr_in.sin_addr    = *(in_addr *)pHost->h_addr_list[0]; //IP
    addr_in.sin_family  = AF_INET;
    addr_in.sin_port    = htons(52013);//57274
 
    // 把 sock 绑定到本地地址上
    if (bind(sock, (PSOCKADDR)&addr_in, sizeof(addr_in)) == SOCKET_ERROR)
	{
		return;
	}
 
	DWORD dwValue = 1;
    
	// 设置 SOCK_RAW 为SIO_RCVALL，以便接收所有的IP包
	if (ioctlsocket(sock, SIO_RCVALL, &dwValue) != 0)
	{
		return;
	}
 
	int nRowId=0;
	//消息接收循环
	while (1)
    {
 
		nRowId++;
		int ret = recv(sock, RecvBuf, BUFFER_SIZE, 0); 
		if(SOCKET_ERROR == ret)
		{
			continue;
		}
		else if(!ret)
		{
			//网络中断
			return;
		}
 
 
 
		Lip  = *(IpHeader *)RecvBuf;
		Ltcp = *(TcpHeader *)(RecvBuf + Lip.HdrLen);
 
		char    Tbuff[16] = "";

		lstrcpy(Tbuff, inet_ntoa(*(in_addr*)&Lip.SrcAddr));

		

		cCtrl->InsertItem(nRowId-1,"");
		cCtrl->SetItemText(nRowId-1,1,Tbuff);
		

		int iDataLen = ntohs(Lip.TotalLen);
		memcpy(szMsg, RecvBuf+sizeof(IpHeader)+sizeof(TcpHeader), (DWORD)iDataLen);
		cCtrl->SetItemText(nRowId-1,2,szMsg);

		//Sleep(5000);

	}
}

/////////////////////////////////////////////////////////////////////////////
// CSnifferView

IMPLEMENT_DYNCREATE(CSnifferView, CFormView)

BEGIN_MESSAGE_MAP(CSnifferView, CFormView)
	//{{AFX_MSG_MAP(CSnifferView)
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnifferView construction/destruction

CSnifferView::CSnifferView()
	: CFormView(CSnifferView::IDD)
{
	//{{AFX_DATA_INIT(CSnifferView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CSnifferView::~CSnifferView()
{
}

void CSnifferView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSnifferView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CSnifferView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSnifferView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	clv = (CListView*)(this->GetDlgItem(IDC_LIST));
	clc = &(clv->GetListCtrl());

	RECT rect;

	clv->GetClientRect(&rect);
	clc->InsertColumn(0,"id",LVCFMT_LEFT,0,0);
	clc->InsertColumn(1,"address",LVCFMT_LEFT,150,0);
	clc->InsertColumn(2,"msg",LVCFMT_LEFT,rect.right-150,0);



}

/////////////////////////////////////////////////////////////////////////////
// CSnifferView printing

BOOL CSnifferView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSnifferView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSnifferView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSnifferView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CSnifferView diagnostics

#ifdef _DEBUG
void CSnifferView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSnifferView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSnifferDoc* CSnifferView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnifferDoc)));
	return (CSnifferDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnifferView message handlers

void CSnifferView::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	int nThreadId=0;
	HANDLE hThread;
	hThread = (HANDLE) _beginthreadex(NULL,0,(unsigned int (__stdcall *)(void *))ThreadProc,this,0,(UINT *)&nThreadId);

	if(hThread == NULL)
	{
		return;
	}

	CloseHandle(hThread);

}

void CSnifferView::OnBtnStop() 
{
	// TODO: Add your control notification handler code here
	//_endthread();
}

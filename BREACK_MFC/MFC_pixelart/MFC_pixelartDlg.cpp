
// MFC_pixelartDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "MFC_pixelart.h"
#include "MFC_pixelartDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo de CMFCpixelartDlg

RECT miRect;


CMFCpixelartDlg::CMFCpixelartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MFC_PIXELART_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCpixelartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCpixelartDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCpixelartDlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// Controladores de mensajes de CMFCpixelartDlg

BOOL CMFCpixelartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional
	//SetTimer(1, 33, NULL);
	//SetTimer(2, 499, NULL);
	GetClientRect(&miRect);
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMFCpixelartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMFCpixelartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCpixelartDlg::OnBnClickedOk()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	//CDialog::OnOK();
	//PaintBall(0,0);
	//x += 10;
	//y += 10;
	SetTimer(1, 33, NULL);
}

void CMFCpixelartDlg::PaintBall(int x=0,int y=0)
{
	HANDLE hBItimap=LoadImage(0,TEXT("ball.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBItimap));
	CDC* pDC = this->GetDC();
	CDC bmDC;
	bmDC.CreateCompatibleDC(pDC);
	CBitmap* oldBMP=bmDC.SelectObject(&bmp);
	pDC->BitBlt(x,y,64,64,&bmDC,0,0,SRCCOPY);
}

void CMFCpixelartDlg::Paintwhite(int x = 0, int y = 0)
{
	HANDLE hBItimap = LoadImage(0, TEXT("fondoTotal.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBItimap));
	CDC* pDC = this->GetDC();
	CDC bmDC;
	bmDC.CreateCompatibleDC(pDC);
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);
	pDC->BitBlt(x,y, 64, 64, &bmDC, 0, 0, SRCCOPY);
}
void CMFCpixelartDlg::Paintwhitet()
{
	/*HANDLE hBItimap = LoadImage(0, TEXT("fondoTotal.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBItimap));
	CDC* pDC = this->GetDC();
	CDC bmDC;
	bmDC.CreateCompatibleDC(pDC);
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);
	pDC->BitBlt(0,0, 1000, 1000, &bmDC, 0, 0, SRCCOPY);*/
	CDC* pDC = this->GetDC();
	pDC->Rectangle(0,0,miRect.right,miRect.bottom);
}
void CMFCpixelartDlg::Paintbarra(int posicion=0)
{
	HANDLE hBItimap = LoadImage(0, TEXT("barra.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBItimap));
	CDC* pDC = this->GetDC();
	CDC bmDC;
	bmDC.CreateCompatibleDC(pDC);
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);

	Barrax1 = posicion - 60;
	Barrax2 = posicion + 60;
	if (Barrax1 < miRect.left )
	{
		Barrax1 = miRect.left;
		Barrax2 = Barrax1 + 120;
	}
	else if (Barrax2>miRect.right)
	{
		Barrax2 = miRect.right;
		Barrax1 = Barrax2 - 120;
	}
	pDC->BitBlt(Barrax1,miRect.bottom-60, 120, 40, &bmDC, 0, 0, SRCCOPY);
}


void CMFCpixelartDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	
	//int Posicion_x_cursorante = Posicion_x_cursor;
	//Paintbafondo(Posicion_x_cursorante-1);
	//OnTimer(2);
		//Paintwhite(x-Xx,y-Yy);

		
	movimiento();


}


void CMFCpixelartDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado

	CDialog::OnMouseMove(nFlags, point);
	Posicion_x_cursor = point.x;
}
void CMFCpixelartDlg::movimiento()
{
	Paintwhitet();

	Abarra.x = Barrax1;
	Abarra.x2 = Barrax2;
	Apelota.x2 = x + 32;
	Apelota.y = y + 64;
	Abarra.y = miRect.bottom - 60;

	Paintbarra(Posicion_x_cursor);
	PaintBall(x, y);
	if (x > (miRect.right) - 64)
	{
		Xx = -10;
	}
	if (x <= 0)
	{
		Xx = 10;
	}
	if (y > (miRect.bottom) - 64)
	{
		y = 0;
		x = 0;
	}
	if (y == 0)
	{
		Yy = 10;
	}
	else if (Apelota.y > Abarra.y && Apelota.y < miRect.bottom - 40)
	{
		if (Apelota.x2> Abarra.x && Apelota.x2<Abarra.x2)
		{
			Yy = -10;
		}
	}
	x += Xx;
	y += Yy;
}

// MFC_pixelartDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CMFCpixelartDlg
class CMFCpixelartDlg : public CDialog
{
	// Construcción
public:
	CMFCpixelartDlg(CWnd* pParent = NULL);	// Constructor estándar
	struct area
	{
		int x;
		int x2;
		int y;
		int y2;
	};
	area Abarra;
	area Apelota;
	int x = 0, y = 0;
	int Xx = 10, Yy = 10;
	int Barrax1, Barrax2;
	int Posicion_x_cursor = 0;
	void PaintBall(int x, int y);
	void Paintwhite(int x, int y);
	void Paintbarra(int posicion);
	void Paintwhitet();
	void movimiento();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_PIXELART_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV
	
	

// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


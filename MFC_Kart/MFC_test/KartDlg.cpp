// KartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_test.h"
#include "KartDlg.h"
#include "afxdialogex.h"
#include "World.h"


// CKartDlg dialog

IMPLEMENT_DYNAMIC(CKartDlg, CDialog)

CKartDlg::CKartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_KART, pParent)
{

}
CKartDlg::~CKartDlg() {

}

void CKartDlg::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_KARTBOX, m_KartBox);
}


BEGIN_MESSAGE_MAP(CKartDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CKartDlg message handlers


BOOL CKartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO:  Add extra initialization here
	this->SetTimer(1, 16, NULL);

	World::getInstance()->Init();

	//Make timer here
	//timer calls update
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
void CKartDlg::Update() {
	World::getInstance()->Update();
}

void CKartDlg::OnTimer(UINT_PTR nIDEvent) {
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1) 	{
		Update();
		UpdatePaintData();
		m_KartBox.UpdateData(FALSE);
	}
	//CTime CurrTime = CTime::GetCurrentTime();

	CDialog::OnTimer(nIDEvent);
}
void CKartDlg::OnPaint()
{
	                   // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialog::OnPaint() for painting messages
	CPaintDC dc(this);
	CDC* IMG_DC = m_KartBox.GetDC();
}
void CKartDlg::UpdatePaintData() {
	RECT ClientRect;
	m_KartBox.GetClientRect(&ClientRect);
	CPaintDC dc(this);
	CDC* IMG_DC = m_KartBox.GetDC();
	IMG_DC->Rectangle(&ClientRect);
	IMG_DC->MoveTo(World::getInstance()->m_GameObj.front()->m_Pos.x, World::getInstance()->m_GameObj.front()->m_Pos.y);

	for (auto gameObj : World::getInstance()->m_GameObj)
	{
		Checkpoint* pCP = nullptr;
		pCP = dynamic_cast<Checkpoint*>(gameObj);
		if (pCP == nullptr)
			continue;
		IMG_DC->Rectangle(gameObj->m_Pos.x - 7, gameObj->m_Pos.y - 7, gameObj->m_Pos.x + 7, gameObj->m_Pos.y + 7);
		IMG_DC->LineTo(gameObj->m_Pos.x, gameObj->m_Pos.y);
	}
	IMG_DC->LineTo(World::getInstance()->m_GameObj.front()->m_Pos.x, World::getInstance()->m_GameObj.front()->m_Pos.y);
	

	CBrush myBrush[2] = { (RGB(255, 0, 0)), (RGB(0, 0, 255)) };
	HGDIOBJ pLastObj;

	int count = 0;
	for (auto gameObj : World::getInstance()->m_GameObj)
	{
		Kart* pK = nullptr;
		pK = dynamic_cast<Kart*>(gameObj);
		if (pK == nullptr)
			continue;
		
		pLastObj = IMG_DC->SelectObject(myBrush[count % 2]);
		IMG_DC->Ellipse(gameObj->m_Pos.x - 5, gameObj->m_Pos.y - 5, gameObj->m_Pos.x + 5, gameObj->m_Pos.y + 5);
		IMG_DC->SelectObject(pLastObj);
		++count;
	}
}



// DlgName.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_test.h"
#include "DlgName.h"
#include "afxdialogex.h"


// CDlgName dialog

IMPLEMENT_DYNAMIC(CDlgName, CDialogEx)

CDlgName::CDlgName(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_NAME, pParent)
	, m_Name(_T(""))
{

}

CDlgName::~CDlgName()
{
}

void CDlgName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(CDlgName, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgName::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CDlgName::OnEnChangeEditName)
END_MESSAGE_MAP()


// CDlgName message handlers


void CDlgName::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CDialogEx::OnOK();
}


void CDlgName::OnEnChangeEditName()
{
	// TODO:  Si �ste es un control RICHEDIT, el control no
	// enviar� esta notificaci�n a menos que se invalide CDialogEx::OnInitDialog()
	// funci�n y llamada CRichEditCtrl().SetEventMask()
	// con la marca ENM_CHANGE ORed en la m�scara.

	// TODO:  Agregue aqu� el controlador de notificaci�n de controles
}

// TreeDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "TreeDlg.h"
#include "afxdialogex.h"
#include "TreeSeedDlg.h"


// CTreeDlg dialog

IMPLEMENT_DYNAMIC(CTreeDlg, CDialog)

CTreeDlg::CTreeDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TREEDLG, pParent)
	, mStartFrame1(0)
	, mHarvestFrame(0)
{

}

CTreeDlg::~CTreeDlg()
{
}

void CTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TREE1STARTFRAME, mStartFrame1);
	DDV_MinMaxInt(pDX, mStartFrame1, 0, 10000);
	DDX_Text(pDX, IDC_HARVESTONEFRAME, mHarvestFrame);
	DDV_MinMaxInt(pDX, mHarvestFrame, 0, 10000);
}


BEGIN_MESSAGE_MAP(CTreeDlg, CDialog)
	//ON_BN_CLICKED(IDC_BUTTON1, &CTreeDlg::OnBnClickedButtonrand)
	ON_STN_CLICKED(IDC_TREEONEHARVEST, &CTreeDlg::OnStnClickedTreeoneharvest)
END_MESSAGE_MAP()


// CTreeDlg message handlers

/*
void CTreeDlg::OnBnClickedButtonrand()
{
	CTreeSeedDlg dlg(mTree);
	if (dlg.DoModal() == IDOK)
	{
		


	}
	// TODO: Add your control notification handler code here
}
*/

void CTreeDlg::OnStnClickedTreeoneharvest()
{
	// TODO: Add your control notification handler code here
}

#pragma once

#include "Tree.h"
// CTreeDlg dialog
#include <memory>

class CTreeSeedDlg;

class CTreeDlg : public CDialog
{
	DECLARE_DYNAMIC(CTreeDlg)

public:
	CTreeDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTreeDlg();

	/** Get start frame tree 1
	 * \returns mStartFrame1 */
	int GetStartOne() { return mStartFrame1; }

	/** Set Start frame tree 1
	 * \param frame */
	void SetStartOne(int frame) { mStartFrame1 = frame; }

	/** Get Harvest frame tree 1
	 * \returns mHarvestFrame */
	int GetHarvest() { return mHarvestFrame; }

	/** Set harvest frame tree 1
	 * \param frame */
	void SetHarvest(int frame) { mHarvestFrame = frame; }

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedButtonrand();

private:
	std::shared_ptr<CTree> mTree;


	int mStartFrame1;
public:
	afx_msg void OnStnClickedTreeoneharvest();
private:
	int mHarvestFrame;
};

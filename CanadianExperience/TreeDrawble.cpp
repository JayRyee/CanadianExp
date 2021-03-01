#include "pch.h"
#include "TreeDrawble.h"
#include "TreeFactory.h"
#include "TreeActual.h"




CTreeDrawble::CTreeDrawble(const std::wstring &name) : CDrawable(name)
{
	CTreeFactory factory;
	mTree = factory.CreateTree();
	//mTimeline = 
	//mTree = std::make_shared<CTreeActual>();
	
}


void CTreeDrawble::Draw(Gdiplus::Graphics* graphics)
{
	if (mTimeline->GetCurrentFrame() >= mStartFrame)
	{
		mTree->SetRootLocation((float)mPlacedPosition.X, (float)mPlacedPosition.Y);
		mTree->SetTreeFrame(mTimeline->GetCurrentFrame());
		mTree->DrawTree(graphics);
	}
	//if(mTimeline->GetCurrentFrame)
	//mTree->SetRootLocation((float)mPlacedPosition.X, (float)mPlacedPosition.Y);
	//mTree->SetTreeFrame(mTimeline->GetCurrentFrame());
	//mTree->DrawTree(graphics);
}

bool CTreeDrawble::HitTest(Gdiplus::Point point)
{
	return false;
}

void CTreeDrawble::SetTimeline(CTimeline* timeline)
{

	CDrawable::SetTimeline(timeline);
	mTimeline = timeline;

}

void CTreeDrawble::ShowDialogBox()
{
	CTreeDlg dlg;
	dlg.SetStartOne(mStartFrame);
	dlg.SetHarvest(mHarvestFrame);
	if (dlg.DoModal() == IDOK)
	{
		mStartFrame = dlg.GetStartOne();
		mHarvestFrame = dlg.GetHarvest();
	}
}

void CTreeDrawble::ShowSeedDialogBox()
{
	CTreeSeedDlg dlg(mTree);
	if (dlg.DoModal() == IDOK)
	{
	}
}

void CTreeDrawble::SetKeyframe()
{
	//mTree->SetTreeFrame(mTimeline->Get);
}



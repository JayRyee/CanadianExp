/**
 * \file TreeDrawble.h
 *
 * \author Jon Ryan
 *
 * 
 */

#pragma once
#include "Drawable.h"
#include "TreeLib.h"
#include "Tree.h"
#include "TreeFactory.h"
#include "Timeline.h"
#include "TreeActual.h"
#include "TreeDlg.h"

#include <vector>
#include <memory>

/** Class for our drawable tree item */
class CTreeDrawble :
	public CDrawable
{
public:
	/** Constructor
	 * \param name */
	CTreeDrawble(const std::wstring& name);

	//CTreeDrawable() = delete;

	/** Shows Properties dialog box */
	void ShowDialogBox();

	/** Shows Seed Dialog Box */
	void ShowSeedDialogBox();
	
private:

	/** Set Keyframe */
	void SetKeyframe() override;

	/** Draw function 
	 * \param graphcis */
	void Draw(Gdiplus::Graphics* graphics) override;
	
	/** Hit Test 
	 * \param point */
	bool HitTest(Gdiplus::Point point);

	/** Set Timeline 
	  \param timeline */
	void SetTimeline(CTimeline* timeline) override;

	/// Tree member
	std::shared_ptr<CTree> mTree;

	/// Start frame
	int mStartFrame = 0;

	/// Harvest Frame
	int mHarvestFrame = 0;

	/// Timeline we belong to for animation
	CTimeline* mTimeline = nullptr;

};


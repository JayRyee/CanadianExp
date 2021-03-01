/**
 * \file BasketDrawable.h
 *
 * \author Jon Ryan
 *
 * 
 */

#pragma once
#include "Drawable.h"
#include "Basket.h"
#include "Timeline.h"


#include <vector>
#include <memory>

/** Class for our drawable basket */
class CBasketDrawable :
	public CDrawable
{
public:
	/** Constructor */
	CBasketDrawable(const std::wstring& name);


private:
	/** Draw 
	 * \param graphics */
	void Draw(Gdiplus::Graphics* graphics) override;

	/** Set timeline
	 * \param timeline */
	void SetTimeline(CTimeline* timeline) override;

	/** Hit Test
	 *\ return bool */
	bool HitTest(Gdiplus::Point point);

	/// Basket memver
	std::shared_ptr<CBasket> mBasket;
	/// Timeline member
	CTimeline* mTimeline = nullptr;
};


/**
 * \file BasketDrawable.cpp
 *
 * \author Jon Ryan
 */

#include "pch.h"
#include "BasketDrawable.h"
#include "TreeFactory.h"
#include "BasketActual.h"



void CBasketDrawable::Draw(Gdiplus::Graphics* graphics)
{
	mBasket->SetBasketLocation((float)mPlacedPosition.X, (float)mPlacedPosition.Y);
	mBasket->DrawBasket(graphics);
}

void CBasketDrawable::SetTimeline(CTimeline* timeline)
{
	CDrawable::SetTimeline(timeline);
	mTimeline = timeline;
}

bool CBasketDrawable::HitTest(Gdiplus::Point point)
{
	return false;
}
CBasketDrawable::CBasketDrawable(const std::wstring& name) : CDrawable(name)
{
	CTreeFactory factory;
	mBasket = factory.CreateBasket();
}
/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "TreeFactory.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(200, 500));
    picture->AddActor(sparty);

	auto Tree = make_shared<CActor>(L"Tree");
	Tree->SetClickable(false);
	Tree->SetPosition(Point(800, 500));
	auto treeI = make_shared<CTreeDrawble>(L"Tree");
	Tree->AddDrawable(treeI);
	Tree->SetRoot(treeI);
	picture->AddActor(Tree);

	picture->SetTreeOne(treeI);
	//mTree1 = treeI;

	auto Tree2 = make_shared<CActor>(L"Tree");
	Tree2->SetClickable(false);
	Tree2->SetPosition(Point(600, 400));
	auto treeI2 = make_shared<CTreeDrawble>(L"Tree");
	Tree2->AddDrawable(treeI2);
	Tree2->SetRoot(treeI2);
	picture->AddActor(Tree2);
	
	picture->SetTreeTwo(treeI2);

	auto basket = make_shared<CActor>(L"Basket");
	basket->SetClickable(false);
	basket->SetPosition(Point(75, 200));
	auto basketI = make_shared<CBasketDrawable>(L"Basket");
	basket->AddDrawable(basketI);
	basket->SetRoot(basketI);
	picture->AddActor(basket);

	picture->SetBasket(basketI);

    return picture;
}

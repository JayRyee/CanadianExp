/**
 * \file Picture.h
 *
 * \author Charles B. Owen
 *
 * The picture we are drawing
 */

#pragma once

#include <vector>
#include "PictureObserver.h"
#include "Timeline.h"
#include "TreeDrawble.h"
#include "BasketDrawable.h"
#include "PictureFactory.h"
#include "Tree.h"
#include "TreeSeedDlg.h"
class CActor;


/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of 
 * our actors, which then contains the drawables. 
 */
class CPicture
{
public:
    CPicture();
    virtual ~CPicture();

    /// Copy Constructor (Disabled)
    CPicture(const CPicture &) = delete;
    /// Assignment Operator (Disabled)
    /// \return none
    CPicture &operator=(const CPicture &) = delete;

    /** The picture size
    * \returns Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** The picture size
    * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

    void AddObserver(CPictureObserver *observer);
    void RemoveObserver(CPictureObserver *observer);
    void UpdateObservers();
    void Draw(Gdiplus::Graphics *graphics);
    void AddActor(std::shared_ptr<CActor> actor);

    void Save(const std::wstring &filename);
    void Load(const std::wstring &filename);

	/** Set Tree 1
	 * \param tree */
	void SetTreeOne(std::shared_ptr<CTreeDrawble> tree) { mTree1 = tree; }

	/** Get Tree 1 
	 *\ return mTree1 */
	std::shared_ptr<CTreeDrawble> GetTreeOne() { return mTree1; }

	/** Set Tree 2
	  * \param tree */
	void SetTreeTwo(std::shared_ptr<CTreeDrawble> tree) { mTree2 = tree; }

	/** Get Tree 2
	 *\ return mTree2 */
	std::shared_ptr<CTreeDrawble> GetTreeTwo() { return mTree2; }

	/** Set Basket
	 * \param basket */
	void SetBasket(std::shared_ptr<CBasketDrawable> basket) { mBasket = basket; }

	/** Get Basket
	 *\ return mBasket */
	std::shared_ptr<CBasketDrawable> GetBasket() { return mBasket; }

	void SetStartFrame1(int start) { mFrame1 = start; }


	int GetStart1() { return mFrame1; }


    /** Iterator that iterates over the actors in a picture */
    class ActorIter
    {
    public:
        /** Constructor
        * \param picture Picture we are iterating
        * \param pos Starting position */
        ActorIter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}

        /** Test for end of the iterator
        * \param other Other object to test against
        * \returns True if we this position equals not equal to the other position */
        bool operator!=(const ActorIter &other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
        * \returns Value at mPos in the collection */
        std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

        /** Increment the iterator
        * \returns Reference to this iterator */
        const ActorIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CPicture *mPicture; ///< Picture we are iterating over
        int mPos;           ///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
    * \returns Iter object at position 0 */
    ActorIter begin() { return ActorIter(this, 0); }

    /** Get an iterator for the end of the collection
    * \returns Iter object at position past the end */
    ActorIter end() { return ActorIter(this, mActors.size()); }

    /** Get a pointer to the Timeline object
    * \returns Pointer to the Timeline object
    */
    CTimeline *GetTimeline() { return &mTimeline; }
    void SetAnimationTime(double time);
    double GetAnimationTime();

private:
    /// The picture size
    Gdiplus::Size mSize = Gdiplus::Size(800, 600);

    /// The observers of this picture
    std::vector<CPictureObserver *> mObservers;

    //! The actors associated with this picture
    std::vector<std::shared_ptr<CActor>> mActors;

    /// The animation timeline
    CTimeline mTimeline;

	CTreeDrawble* mTreeAdapter = nullptr;

	std::shared_ptr<CTreeDrawble> mTree1;

	int mFrame1 = 0;

	std::shared_ptr<CTreeDrawble> mTree2;

	int mFrame2 = 0;

	std::shared_ptr<CBasketDrawable> mBasket;
};


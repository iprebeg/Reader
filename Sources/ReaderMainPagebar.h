//
//	ReaderMainPagebar.h
//	Reader v2.4.0
//
//	Created by Julius Oklamcak on 2011-09-01.
//	Copyright © 2011 Julius Oklamcak. All rights reserved.
//
//	This work is being made available under a Creative Commons Attribution license:
//		«http://creativecommons.org/licenses/by/3.0/»
//	You are free to use this work and any derivatives of this work in personal and/or
//	commercial products and projects as long as the above copyright is maintained and
//	the original author is attributed.
//

#import <UIKit/UIKit.h>

#import "ReaderThumbView.h"
#import "ReaderConstants.h"

@class ReaderMainPagebar;
@class ReaderPreview;
@class ReaderTrackControl;
@class ReaderPagebarThumb;
@class ReaderDocument;



@protocol ReaderMainPagebarDelegate <NSObject>

@required // Delegate protocols

- (void)pagebar:(ReaderMainPagebar *)pagebar gotoPage:(NSInteger)page;

@end

@interface ReaderMainPagebar : UIView
{
@private // Instance variables

	ReaderDocument *document;

#if (READER_SLIDER == TRUE)
    ReaderPreview *scrollView;
#else
	ReaderTrackControl *trackControl;
#endif
    
	NSMutableDictionary *miniThumbViews;

	ReaderPagebarThumb *pageThumbView;

	UILabel *pageNumberLabel;

	UIView *pageNumberView;

	NSTimer *enableTimer;
	NSTimer *trackTimer;
}

@property (nonatomic, assign, readwrite) id <ReaderMainPagebarDelegate> delegate;

- (id)initWithFrame:(CGRect)frame document:(ReaderDocument *)object;

- (void)updatePagebar;

- (void)hidePagebar;
- (void)showPagebar;

@end


#pragma mark -

//
//  ReaderPreview class interface
//
@interface ReaderPreview : UIScrollView
<UIScrollViewDelegate, UIGestureRecognizerDelegate>
{
@private
}

@end

#pragma mark -

//
//	ReaderTrackControl class interface
//

@interface ReaderTrackControl : UIControl
{
@private // Instance variables

	CGFloat _value;
}

@property (nonatomic, assign, readonly) CGFloat value;

@end

#pragma mark -

//
//	ReaderPagebarThumb class interface
//

@interface ReaderPagebarThumb : ReaderThumbView
{
@private // Instance variables
}

- (id)initWithFrame:(CGRect)frame small:(BOOL)small;
- (void)makeTransparent;
- (void)makeOpaque;

@end

#pragma mark -

//
//	ReaderPagebarShadow class interface
//

@interface ReaderPagebarShadow : UIView
{
@private // Instance variables
}

@end

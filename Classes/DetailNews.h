//
//  DetailNews.h
//  Apfeltalk Magazin
//
//  Created by Alexander v. Below on 29.08.09.
//  Copyright 2009 AVB Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DetailViewController.h"

@interface DetailNews : DetailViewController {
	BOOL showSave;
}
@property (readwrite) BOOL showSave;

@end

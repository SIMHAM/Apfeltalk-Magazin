//
//  RootViewController.h
//  Apfeltalk Magazin
//
//	Apfeltalk Magazin -- An iPhone Application for the site http://apfeltalk.de
//	Copyright (C) 2009	Stephan König (stephankoenig at me dot com), Stefan Kofler
//						Alexander von Below, Michael Fenske, Jesper (Graphics),
//						Patrick Rollbis (Graphics),
//						
//	This program is free software; you can redistribute it and/or
//	modify it under the terms of the GNU General Public License
//	as published by the Free Software Foundation; either version 2
//	of the License, or (at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program; if not, write to the Free Software
//	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.//
//

#import <UIKit/UIKit.h>
#import <sqlite3.h>
#import "DetailViewController.h"
#import "Story.h"

@interface RootViewController : UITableViewController {
	
	IBOutlet UITableView * newsTable;
		
	UIActivityIndicatorView * activityIndicator;
	
	CGSize cellSize;
		
	NSMutableArray * stories;
		
	// a temporary item; added to the "stories" array one at a time, and cleared for the next one
	@protected
	Story *item;
		
	// it parses through the document, from top to bottom...
	// we collect and cache each sub-element value, and then save each item to our array.
	// we use these to track each current item, until it's ready to be added to the "stories" array
	NSString * currentElement;

	NSMutableString * currentText;
	sqlite3 * database;
	NSDateFormatter *dateFormatter;
@private
	NSArray *desiredElementKeysCache;

}

- (void)parseXMLFileAtURL:(NSString *)URL;
- (IBAction)openSafari:(id)sender;
- (IBAction)about:(id)sender;
- (NSString *) supportFolderPath;

+ (NSDate *) oldestStoryDate;
+ (void) setOldestStoryDate:(NSDate *)date;
- (Class) detailControllerClass;
- (Class) storyClass;
- (NSDateFormatter *) dateFormatter;
- (NSArray *) desiredElementKeys;

- (void)updateApplicationIconBadgeNumber;
- (BOOL) databaseContainsURL:(NSString *)link;
@end
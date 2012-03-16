//
//  AvidaEDOrgansimView.h
//  viewer-macos
//
//  Created by David M. Bryson on 3/5/12.
//  Copyright 2012 Michigan State University. All rights reserved.
//  http://avida.devosoft.org/viewer-macos
//
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
//  following conditions are met:
//  
//  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the
//      following disclaimer.
//  2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
//      following disclaimer in the documentation and/or other materials provided with the distribution.
//  3.  Neither the name of Michigan State University, nor the names of contributors may be used to endorse or promote
//      products derived from this software without specific prior written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY MICHIGAN STATE UNIVERSITY AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
//  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL MICHIGAN STATE UNIVERSITY OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
//  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  Authors: David M. Bryson <david@programerror.com>
//

#import <Cocoa/Cocoa.h>

#import "DropDelegate.h"

#include "avida/viewer/OrganismTrace.h"

@class AvidaEDController;
@class AvidaEDEnvActionsDataSource;
@class AvidaEDOrganismSettingsViewController;
@class AvidaRun;
@class OrganismView;


@interface AvidaEDOrganismView : NSView <DropDelegate, NSPopoverDelegate> {
  IBOutlet OrganismView* orgView;
  IBOutlet NSTextField* txtOrgName;
  IBOutlet NSTableView* tblTaskCounts;
  IBOutlet NSSlider* sldStatus;
  
  IBOutlet NSButton* btnBegin;
  IBOutlet NSButton* btnBack;
  IBOutlet NSButton* btnGo;
  IBOutlet NSButton* btnForward;
  IBOutlet NSButton* btnEnd;
  
  IBOutlet AvidaEDOrganismSettingsViewController* ctlrSettings;
  IBOutlet NSPanel* panelSettings;
  NSPopover* popoverSettings;

  IBOutlet AvidaEDController* ctlr;
  
  AvidaRun* testWorld;
  Avida::Viewer::OrganismTracePtr trace;
  int curSnapshotIndex;
  
  AvidaEDEnvActionsDataSource* envActions;
  
  NSTimer* tmrAnim;
}

- (IBAction) selectSnapshot:(id)sender;
- (IBAction) nextSnapshot:(id)sender;
- (IBAction) prevSnapshot:(id)sender;
- (IBAction) firstSnapshot:(id)sender;
- (IBAction) lastSnapshot:(id)sender;
- (IBAction) toggleAnimation:(id)sender;
- (IBAction) showSettings:(id)sender;


// DropDelegate
- (NSDragOperation) draggingEnteredDestination:(id<NSDraggingDestination>)destination sender:(id<NSDraggingInfo>)sender;
- (NSDragOperation) draggingUpdatedForDestination:(id<NSDraggingDestination>)destination sender:(id<NSDraggingInfo>)sender;
- (BOOL) prepareForDragOperationForDestination:(id<NSDraggingDestination>)destination sender:(id<NSDraggingInfo>)sender;
- (BOOL) performDragOperationForDestination:(id<NSDraggingDestination>)destination sender:(id<NSDraggingInfo>)sender;


@end

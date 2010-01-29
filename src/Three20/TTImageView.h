//
// Copyright 2009 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import "Three20/TTView.h"
#import "Three20/TTURLRequest.h"

#import "Three20/TTCorePreprocessorMacros.h"

@protocol TTImageViewDelegate;

/**
 * A view that asynchronously loads an image and subsequently displays it.
 */
@interface TTImageView : TTView <TTURLRequestDelegate> {
  TTURLRequest* _request;
  NSString*     _urlPath;
  UIImage*      _image;
  UIImage*      _defaultImage;
  BOOL          _autoresizesToImage;

  id<TTImageViewDelegate> _delegate;
}

@property(nonatomic,copy)     NSString* urlPath;
@property(nonatomic,copy)     NSString* URL __TTDEPRECATED_METHOD;
@property(nonatomic,retain)   UIImage*  image;
@property(nonatomic,retain)   UIImage*  defaultImage;

/**
 * @default NO
 */
@property(nonatomic)          BOOL      autoresizesToImage;

@property(nonatomic,readonly) BOOL      isLoading;
@property(nonatomic,readonly) BOOL      isLoaded;

@property(nonatomic,assign)   id<TTImageViewDelegate> delegate;

- (void)reload;
- (void)stopLoading;

- (void)imageViewDidStartLoad;
- (void)imageViewDidLoadImage:(UIImage*)image;
- (void)imageViewDidFailLoadWithError:(NSError*)error;

@end


///////////////////////////////////////////////////////////////////////////////////////////////////
@protocol TTImageViewDelegate <NSObject>

@optional

- (void)imageView:(TTImageView*)imageView didLoadImage:(UIImage*)image;
- (void)imageViewDidStartLoad:(TTImageView*)imageView;
- (void)imageView:(TTImageView*)imageView didFailLoadWithError:(NSError*)error;

@end

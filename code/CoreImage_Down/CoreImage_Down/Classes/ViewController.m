//
//  ViewController.m
//  CoreImage_Down
//
//  Created by 王潇 on 16/12/11.
//  Copyright © 2016年 王潇. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	
	UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake(100, 100, 100, 100)];
	imgView.backgroundColor = [UIColor lightGrayColor];
	
	UIImage *image = [UIImage imageNamed:@"aaa.jpg"];
	
	CIImage *ciImage = [CIImage imageWithCGImage:image.CGImage];
	
	imgView.image = [self applyFilterChain:ciImage];
	
	[self.view addSubview:imgView];
	
	
	
}

- (UIImage *)applyFilterChain:(CIImage *)image {
	
	CIFilter *colorFilter = [CIFilter filterWithName:@"CIPhotoEffectProcess"];
	
	[colorFilter setValue:image forKey:kCIInputImageKey];
	
	CIImage *colorImage = colorFilter.outputImage;
	colorImage = [colorImage imageByApplyingFilter:@"CIBloom" withInputParameters:@{kCIInputRadiusKey: @(10.0), kCIInputIntensityKey: @(1.0)}];
	
	CGRect frame = CGRectMake(350, 350, 150, 150);
	
	[colorImage imageByCroppingToRect:frame];
	CGRect extent = [colorImage extent];
	CIContext *context = [CIContext contextWithOptions:nil];
	CGImageRef cgImage = [context createCGImage:colorImage fromRect:extent];
	
	return [UIImage imageWithCGImage:cgImage];
}


@end

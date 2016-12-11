#Processing Images


Core Image has three classes that support image processing on iOS and OS X:

* CIFilter is a mutable object that represents an effect. A filter object has at least one input parameter and produces an output image.
* CIImage is an immutable object that represents an image. You can synthesize image data or provide it from a file or the output of another CIFilter object.
* CIContext is an object through which Core Image draws the results produced by a filter. A Core Image context can be based on the CPU or the GPU.


The remainder of this chapter provides all the details you need to use Core Image filters and the CIFilter, CIImage, and CIContext classes on iOS and OS X.

##Overview

Processing an image is straightforward as shown in Listing 1-1. This example uses Core Image methods specific to iOS; see below for the corresponding OS X methods. Each numbered step in the listing is described in more detail following the listing.

>Note: To use Core Image in your app, you should add the framework to your Xcode project (CoreImage.framework on iOS or QuartzCore.framework on OS X) and import the corresponding header in your source code files (<CoreImage/CoreImage.h> on iOS or <QuartzCore/CoreImage.h> on OS X).

#####Listing 1-1  The basics of applying a filter to an image on iOS

```Objectivc-C
CIContext *context = [CIContext contextWithOptions:nil];               // 1
CIImage *image = [CIImage imageWithContentsOfURL:myURL];               // 2
CIFilter *filter = [CIFilter filterWithName:@"CISepiaTone"];           // 3
[filter setValue:image forKey:kCIInputImageKey];
[filter setValue:@0.8f forKey:kCIInputIntensityKey];
CIImage *result = [filter valueForKey:kCIOutputImageKey];              // 4
CGRect extent = [result extent];
CGImageRef cgImage = [context createCGImage:result fromRect:extent];   // 5
```

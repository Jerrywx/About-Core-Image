#Getting the Best Performance

Core Image provides many options for creating images, contexts, and rendering content. How you choose to accomplish a task depends on:

* How often your app needs to perform a task
* Whether your app works with still or video images
* Whether you need to support real-time processing or analysis
* How important color fidelity is to your users

You should read over the performance best practices to ensure your app runs as efficiently as possible.

##1、Performance Best Practices

Follow these practices for best performance:

* Don’t create a CIContext object every time you render.
Contexts store a lot of state information; it’s more efficient to reuse them.

* Evaluate whether you app needs color management. Don’t use it unless you need it. See Does Your App Need Color Management?.
* Avoid Core Animation animations while rendering CIImage objects with a GPU context.
If you need to use both simultaneously, you can set up both to use the CPU.

* Make sure images don’t exceed CPU and GPU limits.
Image size limits for CIContext objects differ depending on whether Core Image uses the CPU or GPU. Check the limit by using the methods inputImageMaximumSize and outputImageMaximumSize.

* User smaller images when possible.
Performance scales with the number of output pixels. You can have Core Image render into a smaller view, texture, or framebuffer. Allow Core Animation to upscale to display size.

* Use Core Graphics or Image I/O functions to crop or downsample, such as the functions CGImageCreateWithImageInRect or CGImageSourceCreateThumbnailAtIndex.

* The UIImageView class works best with static images.
If your app needs to get the best performance, use lower-level APIs.

* Avoid unnecessary texture transfers between the CPU and GPU.
* Render to a rectangle that is the same size as the source image before applying a contents scale factor.
* Consider using simpler filters that can produce results similar to algorithmic filters.
For example, CIColorCube can produce output similar to CISepiaTone, and do so more efficiently.

* Take advantage of the support for YUV image in iOS 6.0 and later.
Camera pixel buffers are natively YUV but most image processing algorithms expect RBGA data. There is a cost to converting between the two. Core Image supports reading YUB from CVPixelBuffer objects and applying the appropriate color transform.

```
options = @{ (id)kCVPixelBufferPixelFormatTypeKey :
    @(kCVPixelFormatType_420YpCbCr88iPlanarFullRange) };
```

##2、Does Your App Need Color Management?

By default, Core Image applies all filters in light-linear color space. This provides the most accurate and consistent results.

The conversion to and from sRGB adds to filter complexity, and requires Core Image to apply these equations:

```
rgb = mix(rgb.0.0774, pow(rgb*0.9479 + 0.05213, 2.4), step(0.04045, rgb))
rgb = mix(rgb12.92, pow(rgb*0.4167) * 1.055 - 0.055, step(0.00313, rgb))
```

Consider disabling color management if:

* Your app needs the absolute highest performance.
* Users won't notice the quality differences after exaggerated manipulations.

To disable color management, set the kCIImageColorSpace key to null. If you are using an EAGL context, also set the context colorspace to null when you create the EAGL context. See Building Your Own Workflow with a Core Image Context.



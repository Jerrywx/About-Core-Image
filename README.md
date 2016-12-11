# About-Core-Image
**About Core Image**

Core Image is an image processing and analysis technology designed to provide near real-time processing for still and video images. It operates on image data types from the Core Graphics, Core Video, and Image I/O frameworks, using either a GPU or CPU rendering path. Core Image hides the details of low-level graphics processing by providing an easy-to-use application programming interface (API). You don’t need to know the details of OpenGL or OpenGL ES to leverage the power of the GPU, nor do you need to know anything about Grand Central Dispatch (GCD) to get the benefit of multicore processing. Core Image handles the details for you.

######Figure I-1  Core Image in relation to the operating system

![MacDown logo](https://developer.apple.com/library/prerelease/content/documentation/GraphicsImaging/Conceptual/CoreImaging/art/architecture_2x.png)

##At a Glance

The Core Image framework provides:

* Access to built-in image processing filters
* Feature detection capability
* Support for automatic image enhancement
* The ability to chain multiple filters together to create custom effects
On OS X, Core Image also provides support for creating custom filters and performing feedback-based image processing.

####Core Image is Efficient and Easy to Use for Processing and Analyzing Images

Core Image provides more than 90 built-in filters on iOS and over 120 on OS X. You set up filters by supplying key-value pairs for a filter’s input parameters. The output of one filter can be the input of another, making it possible to chain numerous filters together to create amazing effects. If you create a compound effect that you want to use again, you can subclass CIFilter to capture the effect “recipe.”

There are more than a dozen categories of filters. Some are designed to achieve artistic results, such as the stylize and halftone filter categories. Others are optimal for fixing image problems, such as color adjustment and sharpen filters.

Core Image can analyze the quality of an image and provide a set of filters with optimal settings for adjusting such things as hue, contrast, and tone color, and for correcting for flash artifacts such as red eye. It does all this with one method call on your part.

Core Image can detect human face features in still images and track them over time in video images. Knowing where faces are can help you determine where to place a vignette or apply other special filters.


>Relevant chapters: [Processing Images](), [Detecting Faces in an Image](), [Auto Enhancing Images](), [Subclassing CIFilter: Recipes for Custom Effects]()

####Query Core Image to Get a List of Filters and Their Attributes
Core Image has “built-in” reference documentation for its filters. You can query the system to find out which filters are available. Then, for each filter, you can retrieve a dictionary that contains its attributes, such as its input parameters, defaults parameter values, minimum and maximum values, display name, and more.

>Relevant chapter:  [Querying the System for Filters]()


####Core Image Can Achieve Real-Time Video Performance

If your app needs to process video in real-time, there are several things you can do to optimize performance.

>Relevant chapter: [Getting the Best Performance]()


####Use an Image Accumulator to Support Feedback-Based Processing in OS X
The CIImageAccumulator class is designed for efficient feedback-based image processing, which you might find useful if your OS X app needs to image dynamical systems.

>Relevant chapter:  [Using Feedback to Process Images]()

####Create and Distribute Custom Kernels and Filters in OS X
If none of the built-in filters suits your needs, even when chained together, consider creating a custom filter. You’ll need to understand kernels—programs that operate at the pixel level—because they are at the heart of every filter.

You can package one or more custom filter as an image unit so that other apps can load and use them.

>Relevant chapters: [What You Need to Know Before Writing a Custom Filter](), [Creating Custom Filters](), [Packaging and Loading Image Units]()


##See Also

Other important documentation for Core Image includes:

* Core Image Reference Collection provides a detailed description of the classes available in the Core Image framework.
* Core Image Filter Reference describes the built-in image processing filters that Apple provides with iOS and OS X, and shows how images appear before and after processing with a filter.
* Core Image Kernel Language Reference describes the language for creating kernel routines for custom filters. Available only on OS X.





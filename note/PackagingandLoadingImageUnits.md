#Packaging and Loading Image Units

An image unit represents the plug-in architecture for Core Image filters. Image units use the NSBundle class as the packaging mechanism to allow you to make the filters that you create available to other apps. An image unit can contain filters that are executable or nonexecutable. (See Executable and Nonexecutable Filters for details.)

To create an image unit from a custom filter, you must perform the following tasks:

1. Write the filter by following the instructions in Creating a Custom Filter.
2. Create an Image Unit Project in Xcode.
3. Add Your Filter Files to the Project.
4. Customize the Load Method.
5. Modify the Description Property List.
6. Build and Test the Image Unit

After reading this chapter, you may also want to

* Read Image Unit Tutorial for in-depth information on writing kernels and creating image units.
* Visit Apple’s Image Units Licensing and Trademarks webpage to find out how to validate image units and obtain the Image Unit logo.

##1、Before You Get Started

Download the CIDemoImageUnit sample. When you create an image unit, you should have similar files. This image unit contains one filter, FunHouseMirror. Each filter in an image unit typically has three files: an interface file for the filter class, the associated implementation file, and a kernel file. As you can see in sample code project, this is true for the FunHouseMirror filter: FunHouseMirrorFilter.h, FunHouseMirrorFilter.m, and funHouseMirror.cikernel.

Each image unit should also have interface and implementation files for the CIPlugInRegistration protocol. In the figure, see MyPlugInLoader.h and MyPlugInLoader.m. The other important file that you’ll need to modify is the Description.plist file.

Now that you know a bit about the files in an image unit project, you’re ready to create one.

##2、Create an Image Unit Project in Xcode

Xcode provides a template for creating image units. After you create an image unit project, you’ll have most of the files you need to get started and the project will be linked to the appropriate frameworks.

**To create an image unit project in Xcode**
Launch Xcode and choose File > New Project.

1. In the template window, choose System Plug-in > Image Unit Plug-in. Then click Next.
2. Name the image unit project and click Finish.
3. The project window opens with these files created:

	* MyImageUnitPlugInLoader.h and MyImageUnitPlugInLoader.m, the interface and implementation files for the CIPlugInRegistration protocol
	* MyImageUnitFilter.h and MyImageUnitFilter.m
	* MyImageUnitFilterKernel.cikernel



The MyImageUnitKernelFilter.cikernel file provided in the image unit project is a sample kernel file. If you’ve already created a filter you won’t need this file, so you can delete it. You’ll add your own to the project in just a moment.

##3、Customize the Load Method

Open the file that implements the CIPlugInRegistration protocol. In it you’ll find a load method, as shown in Listing 10-1. You have the option to add code to this method to perform any initialization that’s needed, such as a registration check. The method returns true if the filter is loaded successfully. If you don’t need any custom initialization, you can leave the load method as it is.

**Listing 10-1  The load method provided by the image unit template**

```
-(BOOL)load:(void*)host
{
    // Custom image unit initialization code goes here
    return YES;
}
```

If you want, you can write an unload method to perform any cleanup tasks that might be required by your filter.

##3、Add Your Filter Files to the Project

Add the filter files you created previously to the image unit project. Recall that you’ll need the interface and implementation files for each filter and the associated kernel file. If you haven’t written the filter yet, see Creating Custom Filters.

Keep in mind that you can package more than one filter in an image unit, and you can have as many kernel files as needed for your filters. Just make sure that you include all of the filter and kernel files that you want to package.

##4、Modify the Description Property List

For executable filters, only the version number, filter class, and filter name are read from the Description.plist file. You provide a list of attributes for the filter in your code (see Write a Custom Attributes Method). You need to check the Description.plist file provided in the image unit template to make sure the filter name is correct and to enter the version number.

For CPU–nonexecutable filters, the image unit host reads the Description.plist file to obtain information about the filter attributes listed inTable 10-1. You need to modify the Description.plist file so it contains the appropriate information. (For information about filter keys, see also Core Image Reference Collection.)

**Table 10-1  Keys in the filter description property list**

Key
Associated values
CIPlugInFilterList
A dictionary of filter dictionaries. If this key is present, it indicates that there is at least one Core Image filter defined in the image unit.
CIFilterDisplayName
The localized filter name available in the Description.strings file.
CIFilterClass
The class name in the binary that contains the filter implementation, if available.
CIKernelFile
The filename of the filter kernel in the bundle, if available. Use this key to define a nonexecutable filter.
CIFilterAttributes
A dictionary of attributes that describe the filter. This is the same as the attributes dictionary that you provided when you wrote the filter.
CIInputs
An array of input keys and associated attributes. The input keys must be in the same order as the parameters of the kernel function. Each attribute must contain its parameter class (see Table 10-2) and name.
CIOutputs
Reserved for future use.
CIHasCustomInterface
None. Use this key to specify that the filter has a custom user interface. The host provides a view for the user interface.
CIPlugInVersion
The version of the CIPlugIn architecture, which is 1.0.
Table 10-2 lists the input parameter classes and the value associated with each class. For a nonexecutable filter, you provide the parameter class for each input and output parameter.

Table 10-2  Input parameter classes and expected values
Input parameter class
Associated value
CIColor
A string that specifies a color.
CIVector
A string that specifies a vector. See vectorWithString:.
CIImage
An NSString object that describes either the relative path of the image to the bundle or the absolute path of the image.
All scalar types
An NSNumber value.

##4、Build and Test the Image Unit

Before you start creating an image unit, you should test the kernel code to make sure that it works properly. (See Use Quartz Composer to Test the Kernel Routine.) After you successfully build the image unit, you’ll want to copy it to the following directories:

/Library/Graphics/Image Units
~/Library/Graphics/Image Units
Then, you should try loading the image unit from an app and using the filter (or filters) that are packaged in the unit. See Loading Image Units, Querying the System for Filters, and Processing Images.

##5、Loading Image Units

The built-in filters supplied by Apple are loaded automatically. The only filters you need to load are third-party filters packaged as image units. An image unit, which is simply a bundle, can contain one or more image processing filters. If the image unit is installed in one of the locations discussed in Build and Test the Image Unit, then it can be used by any app\ that calls one of the load methods provided by the CIPlugin class and shown in Table 10-3. You need to load image units only once. For example, to load all globally installed image units, you could add the following line of code to an initialization routine in your app.

  [CIPlugIn loadAllPlugIns];
After calling the load method, you proceed the same as you would for using any of the image processing filters provided by Apple. Follow the instructions in the rest of this chapter.

Table 10-3  Methods used to load image units
Method
Comment
loadAllPlugIns
Scans image unit directories (/Library/Graphics/Image Units and ~/Library/Graphics/Image Units) for files that have the .plugin extension and then loads the image unit.
loadNonExecutablePlugIns
Scans image unit directories (/Library/Graphics/Image Units and ~/Library/Graphics/Image Units) for files that have the .plugin extension and then loads only the kernels of the image unit. That is, it loads only those files that have the .cikernel extension. This call does not execute any of the image unit code.
loadPlugIn:allowNonExecutable:
Loads the image unit at the location specified by the url argument. Pass true for the allowNonExecutable argument if you want to load only the kernels of the image unit without executing any of the image unit code.

##5、See Also

Image Unit Tutorial which provides step-by-step instructions for writing a variety of kernels and packaging them as image units.
CIDemoImageUnit is a sample image unit Xcode project.
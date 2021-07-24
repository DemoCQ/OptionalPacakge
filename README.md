# OptionalPacakge

## MSIX
contains mapping file and script about how to create appx bundle of RelatedSetHostApp

## HostApp
### RelatedSetHostApp
Main package, contains code to load code and resouces from Optional package

### RelatedSetHostAppNativeHelper
A winrt component used by RelatedSetHostApp, help to use native interface LoadPackagedLibrary.

## Optional Package
### RelatedSetOptionalPackageCPP
OP project which is wirtten by C++, contains resouces and DLL

### RelatedSetOptionalPackageCPPDll
OP project RelatedSetOptionalPackageCPP's depedency, as a inproc COM server in OptionalPackage RelatedSetOptionalPackageCPP.

It export an interface "Entry", RelatedSetHostAppNativeHelper can use LoadPackagedLibrary to load it. 

You can implement any XAML user control and logic code in this DLL, can use "Entry" to share it to RelatedSetHostApp(RelatedSetHostAppNativeHelper)

### RelatedSetOptionalPackageCS
OP project which is wirteen by c#, only contains resouces.

## Common component
### RelatedSetCommon
A Winrt Component defined interfacec will be used by RelatedSetHostAppNativeHelper and  RelatedSetOptionalPackageCPPDll.

#include <Carbon/Carbon.h>
#include <stdio.h>

extern void LMSetKeyThresh(int16_t rate);
extern void LMSetKeyRepThresh(int16_t rate);

extern int16_t LMGetKeyThresh();
extern int16_t LMGetKeyRepThresh();

// extern StringPtr  LMGetCurApName(void)

int main (int argc, char **args)
{
    printf("Key thresh: %d\n", LMGetKeyThresh());
    return 0;
}

// mouse sens:
// https://opensource.apple.com/source/IOHIDFamily/IOHIDFamily-1633.140.4/IOHIDFamily/IOHIDEventServiceKeys.h.auto.html
// https://opensource.apple.com/source/IOHIDFamily/IOHIDFamily-1633.140.4/IOHIDSystem/IOKit/hidsystem/IOHIDParameter.h.auto.html


// https://github.com/phracker/MacOSX-SDKs/blob/master/MacOSX11.3.sdk/System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/CarbonCore.framework/Versions/A/Headers/Resources.h#L839=
// insert and remove resource bundles for appearance changing?


// CFBundle    calls by bundle id ( "com.apple.finder" )

// https://github.com/phracker/MacOSX-SDKs/blob/master/MacOSX11.3.sdk/System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/CarbonCore.framework/Versions/A/Headers/LowMem.h

// https://github.com/phracker/MacOSX-SDKs/blob/10dd4868459aed5c4e6a0f8c9db51e20a5677a6b/MacOSX10.3.9.sdk/System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/CarbonCore.framework/Versions/A/Headers/MacTypes.h
/********************************************************************************
    Base integer types for all target OS's and CPU's

        UInt8            8-bit unsigned integer
        SInt8            8-bit signed integer
        UInt16          16-bit unsigned integer
        SInt16          16-bit signed integer
        UInt32          32-bit unsigned integer
        SInt32          32-bit signed integer
        UInt64          64-bit unsigned integer
        SInt64          64-bit signed integer
*********************************************************************************/
//typedef unsigned char                   UInt8;
//typedef signed char                     SInt8;
//typedef unsigned short                  UInt16;
//typedef signed short                    SInt16;
//typedef unsigned long                   UInt32;
//typedef signed long                     SInt32;

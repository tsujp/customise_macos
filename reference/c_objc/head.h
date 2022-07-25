#include <objc/message.h>
#include <objc/runtime.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <CoreFoundation/CoreFoundation.h>

#ifndef FOOBAR_OBJCTYPES_H
#define FOOBAR_OBJCTYPES_H

// objc runtime: message.h
typedef id(*FOOBARmessage)(id, SEL);
typedef id(*FOOBARmessage2)(id, SEL, const char *);

extern FOOBARmessage fb_message;
extern FOOBARmessage2 fb_message_nsstring_init;
//extern FOOBARinvoke fb_invoke;

extern void NSLog(CFStringRef format, ...);

#endif

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#import <CoreFoundation/CoreFoundation.h>

// NSLog
//	void NSLog(NSString *format, ...);
// doc:
//	Simply calls NSLogv, passing it a variable number of arguments.

// NSLogv
//	https://developer.apple.com/documentation/foundation/1395074-nslogv

// id appDelObj = cmacs_simple_msgSend((id)objc_getClass("AppDelegate"), sel_getUid("alloc"));

#include "main.h"

CMacsSimpleMessage cmacs_simple_msgSend = (CMacsSimpleMessage)objc_msgSend;
CMacsVoidMessage cmacs_void_msgSend	 = (CMacsVoidMessage)objc_msgSend;
CMacsVoidMessage1 cmacs_void_msgSend1 = (CMacsVoidMessage1)objc_msgSend;
CMacsRectMessage1 cmacs_rect_msgSend1 = (CMacsRectMessage1)objc_msgSend;
CMacsWindowInitMessage cmacs_window_init_msgSend = (CMacsWindowInitMessage)objc_msgSend;

Class StringClass;

typedef void(*enessLog)(CFStringRef, ...);
extern enessLog NSLog;


int main(int argc, char **argv)
{
	printf("Start\n");
	//cmacs_simple_msgSend((id)objc_getClass("NSString"), CFSTR("Foo"));
	//cmacs_simple_msgSend((id)objc_getClass("NSLog"), CFSTR("Foo"));

	StringClass = objc_allocateClassPair((Class)objc_getClass("NSString"), "foobar", 0);
	objc_registerClassPair(StringClass);

	//id nslogObj = cmacs_simple_msgSend((id)objc_getClass("NSLog"), sel_getUid("alloc"));
	//nslogObj = cmacs_simple_msgSend1(nslogObj, sel_getUid("init"), "Foo");
	NSLog(StringClass);

	printf("End\n");
	return EXIT_SUCCESS;
}

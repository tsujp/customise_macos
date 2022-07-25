// clang -framework CoreFoundation -framework Foundation main.c -o main
#include <stdlib.h>
#include <stdio.h>
#include "head.h"

int main(int argc, char **argv)
{
    printf("=> start\n");

    // Can also directly create instance by doing this.
    id nsStringDirect = class_createInstance(
        objc_getClass("NSString"),
        0
    );

    // Calling implementing method for selector `alloc` returns an `id` whose
    //   `isa` (`Class`) is set to the requested `Class` (first parameter) but
    //   whose instance variables are all zeroed in memory. In other words,
    //   invoking the implementation of `alloc` on a `Class` returns an `id`
    //   which still needs to be intialised and until then is merely a skeleton
    //   of a fully instantiated object of that `Class`.
    // `id` is a pointer to an `objc_object` struct with single field `Class`
    //   named `isa`.
    id nsString = fb_message(
        (id)objc_getClass("NSString"),  // Get `Class` of given name.
        sel_getUid("alloc")             // Get `SEL` for named selector.
    );

    // Call initialisation on `id` with parameters for said initialisation.
    nsString = fb_message_nsstring_init(
        nsString,
        sel_getUid("initWithCString:"),
        "FooBarBaz Bing Bong Blah 123 FFF XXX !@#$%^&*("
    );

    // Selector `new` is similar except it calls `alloc` and `init` for us.
    id nsStringNew = fb_message(
        (id)objc_getClass("NSString"),
        sel_getUid("new")
    );

    // Now our `nsString` is a fully instantiated `NSString` object.
    //   Note: May observe this name printed as: `NSTaggedPointerString` which
    //         is fine as that is a subclass of NSString and they are completely
    //         replaceable. Calling selector `stringWithString:` will return a
    //         "real" `NSString` if need be.
    printf("Manual: %s\n", object_getClassName(nsString));
    printf("Direct: %s\n", object_getClassName(nsStringDirect));

    // May see `__NSCFConstantString` for creation via `new` selector.
    //   They're both concrete subclasses of NSString. __NSCFString is
    //   created during runtime via Foundation or Core Foundation, while
    //   __NSCFConstantString is either a CFSTR("...") constant or an
    //   @"..." constant, created at compile-time.
    printf("   New: %s\n", object_getClassName(nsStringNew));

    // Print the contents of `nsString`.
    printf("-----\n");
    CFIndex len1 = CFStringGetMaximumSizeForEncoding(
        CFStringGetLength((CFStringRef)nsString),
        kCFStringEncodingUTF8
    );

    char *buf1 = nsString ? (char *)malloc(len1 + 1) : 0;

    if (buf1) {
        Boolean converted = CFStringGetCString(
            (CFStringRef)nsString,
            buf1,
            len1,
            kCFStringEncodingUTF8
        );
        if (converted) {
            // null-terminate
            buf1[len1] = 0;
            printf("->>%s<<-\n", buf1);
        }
    }

    // Let's try and call NSLog passing in the `nsString`.
    printf("-----\n");

    NSLog((CFStringRef)nsString);

    printf("=> end\n");
    if (buf1) free(buf1);
    return EXIT_SUCCESS;
}

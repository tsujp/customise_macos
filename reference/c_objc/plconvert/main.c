// clang -framework CoreFoundation main.c -o main && ./main

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include <CoreFoundation/CoreFoundation.h>

static void enessLog(CFStringRef format, ...)
{
	va_list args;
	va_start(args, format);
	CFStringRef str = CFStringCreateWithFormatAndArguments(kCFAllocatorSystemDefault, NULL, format, args);
	if (!str) return;

CFIndex blen = CFStringGetMaximumSizeForEncoding(CFStringGetLength(str), kCFStringEncodingUTF8);
    char *buf = str ? (char *)malloc(blen + 1) : 0;
    if (buf) {
        Boolean converted = CFStringGetCString(str, buf, blen, kCFStringEncodingUTF8);
        if (converted) {
            // null-terminate
            buf[blen] = 0;
            printf("%s\n", buf);
        }
    }
    if (buf) free(buf);
    if (str) CFRelease(str);      va_end(args);
}

int main(int argc, char **argv)
{
	enessLog(CFSTR("Foo bar"));
	printf("Hi there\n");
	return EXIT_SUCCESS;
}

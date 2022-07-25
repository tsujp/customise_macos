    // Calling selector `lengthOfBytesUsingEncoding` passing encoding gives us
    //   the size of the buffer we need to allocate.
    CFStringEncoding encoding = CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingUTF8);

    UInt32 len = fb_message_getsize(
        nsString,
        sel_getUid("lengthOfBytesUsingEncoding:"),
        encoding
    ) + 1; // For NUL.

    // It's buffin time.
    printf("Bytes with encoding: %d\n", len);
    UniChar *theString = malloc(len * sizeof(UniChar));

    // Objective-C runtime: YES = 1 ; NO = 0
    BOOL wasSuccess = fb_message_getstring(
        nsString,
        sel_getUid("getCString:"),
        theString,
        1,
        1
    );

    printf("Success? %d\n", wasSuccess);

    //printf("%d\n", len);
    printf(">%s<\n", theString);
    printf("%d\n", theString[0]);
    printf("%d\n", theString[1]);
    printf("%d\n", theString[2]);
    printf("%d\n", theString[3]);
    printf("%d\n", theString[4]);
    printf("%d\n", theString[5]);
    printf("%d\n", theString[6]);
    printf("%d\n", theString[7]);
    printf("%d\n", theString[8]);
    printf("%d\n", theString[9]);
    printf("%d\n", theString[10]);
    printf("%d\n", theString[11]);

    int c = 0;
    while(theString[c] != '\0') {
        printf("%s\n", theString[c]);
        c++;
    }

    printf("c size %d\n", c);

    // CFLog(kCFLogLevelWarning, CFSTR("*** %@: Range {%lu, %lu} out of bounds; string length %lu. This will become an exception for apps linked after 10.10 and iOS 8. Warning shown once per app execution."), __CFExceptionProem((id)self, _cmd), (unsigned long)range.location, (unsigned long)range.length, (unsigned long)len);

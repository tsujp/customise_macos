// Compile and run:
// clang -framework Foundation main.m -o main && ./main
#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    // Autorelease the stuff in scope of the pool.
    @autoreleasepool {
        // The @ is shorthand for NSString, so NSString("Hello, World!");
        NSLog(@"Hello, World!");
    }
    return 0;
}

// Barebones main instead would be:
// int main(int argc, const char * argv[]) {
//     NSLog(@"Hello, World!");
//     return 0;
// }

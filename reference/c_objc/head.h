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


// quick pointer refresher:
// * on a type marks the variable name as a pointer to that type.
//  i.e. `int *foo;` means `foo` (no `*`) is a pointer to a type `int`. It's a
//  pointer because `foo` is assigned the type `int *` i.e. `int*`.
// & gets the address of the given variable.
// `int bar = *foo` sets `bar` equal to the integer that `foo` points to because
// we de-referenced `foo` with the `*`. So, `*` on the left = its a pointer to
// that type and `*` on the right = de-reference the variable name address.

// typedef foo bar
// ^^^ creates a new type alias `bar` which is of type `foo`, e.g. you could do
// typedef int Integer
//  which means you can now type `Integer x = 5;` and that means _exactly_ the
//  same as `int x = 5;` because `Integer` is an alias for `int`.

// typedef'd identifiers typically have suffix _t but it's not requried, jsut a
// convention. e.g. `size_t`.

// if you do something like `typedef int *ptr` the new type alias you've made
// is `ptr` which is of (real) type `int *`. The type alias is not `*ptr`. So,
// if you then do `ptr x = y;` the `x` is an `int *` i.e. `int*` (because
// whitespace means nothing in C). `ptr` is a pointer which points to an `int`.
// Furthermore, if you did `ptr *a = b;` the `a` is of type `int **` i.e. a
// pointer to a pointer which points to an `int`.

// pointers to functions look like this:
//  return_type(*name_of_func_pointer)(param1_type, param2_type)
// the `return_type` is the real return type of the function being pointed to.
// `param1_type` and `param2_type` are just the types of those positional
// parameters not their names, so just (int, int) if the function being pointed
// to accepts two integers.
// the `name_of_func_pointer` can be any valid C name, it's used to refer to
// the function pointer (i.e. it's a new name) and not an existing one.

// Say we had a function pointer `int (*a)(int);`. The name of this function
// pointer is `a` and it points to (because `*`) a function which takes an int
// and returns an `int`. Note that `a` isn't anything yet because we haven't
// given it an address to point to!
// Let's make a function for it to point to:
// `int foo(int bar) { return bar + 1; }`
// Now we can set `a = &foo;` so `a` stores the address of function `foo` and
// we previously defined `a` to be a pointer `(*a)`.
// To invoke `foo` via `a` we'd do: `int result = (*a)(5);` which would return
// the integer 6 i.e. `result` is now `6`.

// so we're typedef'ing function pointers with names. Then we do `extern` to
// tell the compiler we're going to be linking objects which have those types.
// Then in `head.c` we actually initialise the extern'd variables by casting
// the function we know exists (objc_msgSend) with the typedef of the function
// pointer which gives us an initialised pointer to that function.
// ^^^^ that is possible because `typedef` allows us to convert type definition
// syntax to type cast syntax. See: "Type casts" on https://en.wikipedia.org/wiki/Typedef

// need clarify this:
//      typedef` allows us to convert type definition syntax to type cast syntax.


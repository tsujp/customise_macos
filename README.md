# Square macOS Windows

Does what it says on the tin, instead of rounded corners at the top-left, top-right, bottom-left and bottom-right of windows on macOS you can now have pixel-perfect square ones.

![gloriouis-square-edges](https://i.imgur.com/wZv3xFI.png)

## Yeah but, why?

I wanted the border function from Yabai to look better, and since apps tend to have different border radii my only sane choice was to force them all to have the same amount, that being 0.

## Okay, how do I use it?

1. I believe some SIP settings require turning off so you can modify the appropriate files, it's your choice whether or not you want to do this as far as I know you cannot achieve this effect unless this is done.

```
csrutil enable --without debug --without fs
```

2. While there are backup `.car` files in this repo, please back-up yours locally just in-case.

3. Copy the appropriate edited `.car` file into `/System/Library/CoreServices/SystemAppearance.bundle/Contents/Resources/`, for `DarkAquaAppearance` you'd copy `DarkAquaAppearance/Edited/DarkAquaAppearance.car`.

## How much time did you spend on this?

Too much my friend. A good 6 hours finding which files are in-control of the effect.

### TODO:

- [ ] Patch for other system themes, as far as I know this will only work in my setup but someone can try it out and let me know.
- [x] ~~For some reason Firefox doesn't appear to respect this (I think). I'll see if it's just some weird.. caching(?) or something.~~ *Firefox doesn't respect system appearance settings, this is a known defect/bug on macOS.~~
- [x] Check which SIP settings require being turned off.

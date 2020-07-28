# Square macOS Windows

Patches for appearance `.car` bundles to make GUI elements have square corners
instead of rounded ones.

```
TODO: better before and after example
```

## Usage

1.  Some SIP settings require disabling so you can modify the appropriate files,
    it's your choice whether or not you want to do this, not doing so means you
    cannot apply the changes required. **You have to reboot into Recovery Mode
    to make changes to SIP**, [the steps are explained in this SE answer](https://apple.stackexchange.com/questions/208478/how-do-i-disable-system-integrity-protection-sip-aka-rootless-on-macos-os-x) but summarised immediately below:

    ```bash
    csrutil enable --without debug --without fs
    ```

2.  While there are backup `.car` files in this repo, please backup yours
    locally just in-case. Here's an example of how to do so.

    ```bash
    rsync -rI /System/Library/CoreServices/SystemAppearance.bundle/Contents/Resources/ ~/Desktop/saResourcesBackup
    ```

3.  Copy the appropriate (for your theme, light or dark) edited `.car` file into
    `/System/Library/CoreServices/SystemAppearance.bundle/Contents/Resources/`,
    e.g. for `DarkAquaAppearance` you'd copy `DarkAquaAppearance/Edited/DarkAquaAppearance.car`.

## NB

-   Firefox doesn't respect system appearance settings, this is a known
    defect/bug on macOS.

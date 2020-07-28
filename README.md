# Custom macOS GUI

Patches for appearance `.car` bundles to change the macOS GUI.

## Current patches

-   Square GUI elements (windows, menus, etc)

```
TODO: better before and after example
```

## Usage

1.  Some SIP settings require disabling so you can modify the appropriate files
    -- _it's your choice whether or not you want to do this_ -- not doing so
    means you cannot apply the changes required. **You have to reboot into
    Recovery Mode to make changes to SIP**, [the steps are explained in this SE
    answer](https://apple.stackexchange.com/questions/208478/how-do-i-disable-system-integrity-protection-sip-aka-rootless-on-macos-os-x) but summarised immediately below:

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

## Compatibility

This file contains version numbers of confirmed working patches. The format is
quite simple:

-   it contains the macOS release number
-   if no additional grammar is present, full support is available
-   if a `~` is present: indicates partial support
-   if a `?` is present: indicates in progress work

### Example

```
11.0 ~    <-- version 11.0 is partially supported
11.0 ?    <-- version 11.0 support is in progress (and none exists currently as
              there is no `~`)
11.0 ~?   <-- in progress and partially supported currently
11.0      <-- this means version 11.0 is completely supported
```

## NB

-   Firefox doesn't respect system appearance settings, this is a known
    defect/bug on macOS.

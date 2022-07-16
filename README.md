# Customise macOS

Utilities and tools for customising macOS, e.g. appearance or settings like key
repeat rates, mouse sensitivity and more. The idea is things which are not easy
or are downright impossible to do via System Preferences et. al. are provided
here.


## Customisations


### Appearance

#### Aqua Desktop

Patches for `.car` bundles to change appearance of windows, menus, etc.

##### Features

- Square corners for windows, menus etc.

##### Installation

1. Some SIP settings require disabling so you can modify the appropriate files
-- _it's your choice whether or not you want to do this_ -- not doing so means
you cannot apply the changes required. **You have to reboot into Recovery Mode
to make changes to SIP**, [the steps are explained in this SE
answer](https://apple.stackexchange.com/questions/208478/how-do-i-disable-system-integrity-protection-sip-aka-rootless-on-macos-os-x)
but summarised immediately below:

    ```shell
    csrutil enable --without debug --without fs
    ```

2. While there are backup `.car` files in this repo, please backup yours
locally just in-case. Here's an example of how to do so.

    ```shell
    rsync -rI \
        /System/Library/CoreServices/SystemAppearance.bundle/Contents/Resources/ \
        ~/Desktop/saResourcesBackup
    ```

3. In the `Appearance` folder on this repo copy the appropriate (for your
theme i.e. light or dark) edited `.car` file into
`/System/Library/CoreServices/SystemAppearance.bundle/Contents/Resources/`,
e.g. for `DarkAquaAppearance` you'd copy
`DarkAquaAppearance/Edited/DarkAquaAppearance.car`.

##### Known Problems

- Firefox doesn't respect system appearance settings, this is a known
  defect/bug of Firefox's on macOS.


### More...

_...in development_

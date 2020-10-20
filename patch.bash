#!/usr/bin/env bash

# TODO: detect if SIP set correctly
# TODO: apply patches

# DOC: prints indented text wrapping at column width or 80, whichever is smaller
# NB: if people really want wrapped lines on 10 column wide terminals I guess
#     I can add that later but I'd rather not, effort vs reward et al
print_indented ()
{
  cols=$(tput cols)
  maxcol=$(($cols > 80 ? $cols : 80))
  printf ">> %s\n" "$1" | fold -s -w 80 | sed -e "2,$ s|^|>> |g"
}

main ()
{
  local -r backup_nag="backups in-place beforehand of course. Consult the README for instructions on how to backup."
  local -r qt="Patches are currently in-progress for your release, hang in there! There's more (or at least some) to come!"
  local -r tt="Patches give partial support depending on your theme colour variant, as well as dark or light mode. It likely works anyway so you can give it a shot but only with $backup_nag"

  if [[ "$OSTYPE" == "darwin"* ]]; then
    ver=$(sw_vers -productVersion)
    gs=$(grep "$ver" COMPATIBILITY)

    if [ -z "$gs" ]; then
      print_indented "Your macOS version is not supported. You can still try if you like, with $backup_nag"
    else
      # this isn't DRY but Apple only includes Bash 3.2 due to licensing issues
      # meaning case-fallthrough is not available (bash 4.0 feature)
      case "$gs" in
        *"?~"*)
          print_indented "$qt"
          print_indented "$tt"
        ;;
        *"?"*)
          print_indented "$qt"
        ;;
        *"~"*)
          print_indented "$tt"
        ;;
        *)
          print_indented "Your macOS version is supported! Do whatever you want, with $backup_nag"
        ;;
      esac
    fi
  else
    print_indented "This is for macOS only. Doing nothing."
  fi
}

# entry
main

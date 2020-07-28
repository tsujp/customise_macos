#!/bin/bash
[[ $- = *i* ]] || return
if [[ "$OSTYPE" == "darwin"* ]]; then
  sw_vers -productVersion
else
  echo ":: This has no use on your operating system."
fi

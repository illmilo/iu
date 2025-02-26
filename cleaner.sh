#!/usr/bin/bash

for filename in DSA/hw/*; do
    if [[ "$filename" == *.dSYM || "$filename" != *.* ]]; then
        rm -i -rf "$filename"
    fi
done

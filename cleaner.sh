#!/usr/bin/bash

for filename in DSA/hw/* SSAD/HW/*; do
    if [[ "$filename" == *.dSYM || "$filename" != *.* || "$filename" == *.txt ]]; then
        rm -i -rf "$filename"
    fi
done

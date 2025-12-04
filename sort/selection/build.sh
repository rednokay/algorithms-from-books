#!/usr/bin/env bash

set -e

mkdir -p build
cd build

if [ ! -f build.ninja ]; then
    cmake -G Ninja ..
else
    cmake -G Ninja .. > /dev/null 2>&1 || true
fi

ninja

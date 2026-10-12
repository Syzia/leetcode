#!/bin/sh
# Compile and run one problem by number or name, e.g. ./run.sh 088
cd "$(dirname "$0")" || exit 1
src=$(ls | grep -- "$1" | grep '\.cpp$' | head -n 1)
[ -n "$1" ] && [ -n "$src" ] || { echo "usage: ./run.sh <problem number>"; exit 1; }
mkdir -p build
c++ -std=c++17 -Wall -o "build/${src%.cpp}" "$src" && "build/${src%.cpp}"

#!/bin/sh
# Compile and run one problem by number or name, e.g. ./run.sh 088
cd "$(dirname "$0")" || exit 1
src=$(ls | grep -- "$1" | grep -E '\.(c|cpp|java|py)$' | head -n 1)
[ -n "$1" ] && [ -n "$src" ] || { echo "usage: ./run.sh <problem number>"; exit 1; }
mkdir -p build
case "$src" in
    *.cpp)
        c++ -std=c++17 -Wall -o "build/${src%.cpp}" "$src" && "build/${src%.cpp}"
        ;;
    *.c)
        cc -std=c11 -Wall -o "build/${src%.c}_c" "$src" && "build/${src%.c}_c"
        ;;
    *.java)
        out="build/${src%.java}_java"
        mkdir -p "$out" && javac -d "$out" "$src" && java -cp "$out" Main
        ;;
    *.py)
        python3 "$src"
        ;;
esac

#!/bin/bash

set -e -x

clang++ -Wall test.cpp
./a.out

#!/bin/bash
#
#
# - Generate cmake files
# - Build cmake project
# - move compile_commands.json to root

# from root
mkdir bin > /dev/null
cd bin/
CXX=/usr/bin/clang++-18 cmake ..

cd ..
cmake --build bin

mv bin/compile_commands.json .

# run

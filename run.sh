#!/bin/bash

VERBOSE=1

for var in "$@"
do
  case $var in
    -v | --verbose)
      VERBOSE=0
      ;;
  esac

done

# Mettre un switch case ?

if [ ! -d build/ ]; then
	if [ $VERBOSE -eq 0 ]; then
		echo "Directory build doesn't exists"
	fi
	exit
fi

cd build

if [ $VERBOSE -eq 0 ]; then
 	echo "Going into build"
 fi

command -v cmake

if [ $? -eq 1 ]; then
	if [ $VERBOSE -eq 0 ]; then
		echo "CMake is not installed, please run dnf install cmake"
	fi
	exit
fi

if [ $VERBOSE -eq 0 ]; then
	echo "Building from CMakeLists.txt"
fi

cmake ..

if [ $VERBOSE -eq 0 ]; then
	echo "Building the project with cache"
fi

cmake --build .

if [ $VERBOSE -eq 0 ]; then
	echo "Finished !"
fi

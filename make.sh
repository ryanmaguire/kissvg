#!/bin/bash

################################################################################
#                                   LICENSE                                    #
################################################################################
#   This file is part of KissVG.                                               #
#                                                                              #
#   KissVG is free software: you can redistribute it and/or modify             #
#   it under the terms of the GNU General Public License as published by       #
#   the Free Software Foundation, either version 3 of the License, or          #
#   (at your option) any later version.                                        #
#                                                                              #
#   KissVG is distributed in the hope that it will be useful,                  #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              #
#   GNU General Public License for more details.                               #
#                                                                              #
#   You should have received a copy of the GNU General Public License          #
#   along with KissVG.  If not, see <https://www.gnu.org/licenses/>.           #
################################################################################
#   Author:     Ryan Maguire                                                   #
#   Date:       July 19, 2023                                                  #
################################################################################

# Choose whatever C compiler you want. Tested with gcc, clang, tcc, and pcc.
CC=cc

# Version of C to be used. Change this with -std=cxx.
STDVER="-std=c89"

# Build the file library in place and do no store any header or library files
# in /usr/local/include/ and /usr/local/lib/, respectively. Use this if you
# do not have sudo priviledges. Enable this with -inplace.
INPLACE=0

# Use inline code for small functions (like absolute value). Can give a speed
# boost, but makes that compiled library file a tiny bit bigger. Only works
# with compilers supporting C99 (or higher) or the GNU inline extension.
# Enable this with -inline.
USEINLINE=0

# Compile the entire library by #include'ing all files into one translation
# unit. The compiler get's to the see the entire library at once and make many
# optimizations.
MAKEMONSTER=0

# Files to be excluded (added later based on USEINLINE and USEMATH.
Exclude=""

# You can pass extra arguments. Just add -MyArgument.
ExtraArgs=""

# Parse the inputs.
for arg in "$@"; do

    # If there are no more arguments, break out of this loop.
    if [ "$arg" == "" ]; then
        break

    # Check if the user wants to use a different compiler.
    elif [[ "$arg" == *"-cc"* ]]; then
        CC=${arg#*=}

    # Check if the user wants to use a different version of the C language.
    elif [[ "$arg" == *"-std"* ]]; then
        STDVER=$arg

    # Check if the user wants to build KissVG in the KissVG/ directory.
    elif [ "$arg" == "-inplace" ]; then
        INPLACE=1

    # Check if the user wants to inline small functions.
    elif [ "$arg" == "-inline" ]; then
        USEINLINE=1

    elif [ "$arg" == "-monster" ]; then
        MAKEMONSTER=1

    elif [ "$arg" == "-remove" ]; then
        SONAME="libkissvg.so"
        SODIR="/usr/local/lib"
        INCLUDE_TARGET=/usr/local/include/kissvg/

        echo "Removing KissVG:"
        echo "    Clearing older files..."
        rm -f *.so *.o *.obj *.lib

        echo -e "    Removing include directory if it exists..."
        if [ -d "$INCLUDE_TARGET" ]; then
            rm -rf "$INCLUDE_TARGET";
        fi

        echo "    Removing shared object file if it exists..."
        if [ -e "$SODIR/$SONAME" ]; then
            rm -f "$SODIR/$SONAME";
        fi

        echo "KissVG removed."
        exit 1

    # Check for any extra arguments.
    else
        ExtraArgs="$ExtraArgs ${arg#*}"
    fi
done

# Check for incompatible requests. inline can't be used with -std=c89/c90.
if [ $USEINLINE == 1 ]; then
    if [ "$STDVER" == "-std=c89" ]; then
        echo "Error: inline mode cannot be used with C89."
        echo "       Set -std to a version supporting inline."
        exit 1
    elif [ "$STDVER" == "-std=c90" ]; then
        echo "Error: inline mode cannot be used with C90."
        echo "       Set -std to a version supporting inline."
        exit 1
    fi
fi

# If OpenMP support is requested, add this to the extra arguments.
if [ $USEOMP == 1 ]; then
    ExtraArgs="$ExtraArgs -fopenmp"
fi

# LLVM's clang has the -Weverything warning which enables every possible
# warning. Padding warning's are unnecessary, as are warnings about comparing
# floats for equality. All other warnings should be enabled.
if [ "$CC" == "clang" ]; then
    ExtraArgs="$ExtraArgs -Weverything -Wno-padded -Wno-float-equal"
fi

# If we're inlining small functions, we must not also compile the files
# containing these functions. The inline functions are defined in their
# respective header files. Create an exclude list with all functions that
# should not be compiled.
if [ $USEINLINE == 1 ]; then
    ExtraArgs="$ExtraArgs -DKISSVG_SET_INLINE_TRUE"
    Exclude="$Exclude"
fi

# Name of the created Shared Object file (.so).
SONAME="libkissvg.so"

# Location to store SONAME at the end of building.
SODIR="/usr/local/lib"

# Compiler arguments. All of these are supported by gcc, tcc, pcc, and clang.
CArgs1="-pedantic -Wall -Wextra -Wpedantic -Wmissing-field-initializers"
CArgs2="-Wconversion -Wmissing-prototypes -Wmissing-declarations -Werror"
CArgs3="-Winit-self -Wnull-dereference -Wwrite-strings -Wdouble-promotion"
CArgs4="-Wfloat-conversion -Wstrict-prototypes -Wold-style-definition"
CArgs5="-I../ -DNDEBUG -g -fPIC -O3 -flto -c"
CompilerArgs="$STDVER $ExtraArgs $CArgs1 $CArgs2 $CArgs3 $CArgs4 $CArgs5"

# Linking arguments.
# -O3 is optimization level 3.
# -I../ means include the parent directory so kissvg/ is in the path.
# -flto is link time optimization.
# -o means create an output.
# -shared means the output is a shared object, like a library file.
LinkerArgs="-O3 -flto -shared -o $SONAME"

# Location where the .h files will be stored.
INCLUDE_TARGET=/usr/local/include/kissvg/

# There may be left-over .so and .o files from a previous build. Remove those
# to avoid a faulty build.
echo "Clearing older files"
rm -f *.so *.o *.obj *.lib

# If we're not building kissvg into kissvg/, clear older files.
if [ $INPLACE == 0 ]; then

    # Clear older header files.
    if [ -d "$INCLUDE_TARGET" ]; then
        echo "Clearing $INCLUDE_TARGET"
        rm -rf "$INCLUDE_TARGET";
    fi

    # Clear older library files.
    if [ -e "$SODIR/$SONAME" ]; then
        echo "Erasing $SODIR/$SONAME"
        rm -f "$SODIR/$SONAME";
    fi
fi

echo ""
echo "Compiling KissVG"
echo "    Compiler:"
echo "        $CC"
echo "    Version:"
echo "        $STDVER"
echo "    Compiler Options:"
echo "        $CArgs1"
echo "        $CArgs2"
echo "        $CArgs3"
echo "        $CArgs4"
echo "        $CArgs5"
echo "    Extra Compiler Arguments:"
echo "        $ExtraArgs"

if [ $MAKEMONSTER == 1 ]; then

    if [ -e "monster.c" ]; then
        rm -f monster.c;
    fi

    touch monster.c

    for file in include/*.h; do
        echo "#include \"$file\"" >> monster.c;
    done

    for dir in src/*/; do

        # assembly and buitlins only has assembly code. Skip this.
        if [[ $dir == *"assembly"* ]]; then
            continue;
        fi

        for filename in $dir*.c; do
            filename_without_path=$(basename -- $filename)
            if [[ $Exclude == *"$filename_without_path"* ]]; then
                continue;
            fi
            echo "#include \"$filename\"" >> monster.c;
        done
    done

    echo "Compiling KissVG..."
    if !($CC $CompilerArgs monster.c); then
        exit 1
    fi

    echo "Building KissVG Shared Object (.so file)"
    if !($CC ./*.o $LinkerArgs); then
        exit 1
    fi

    rm -f *.o
    rm -f monster.c
else

    # Loop over all directories in src/ and compile all .c files.
    for dir in src/*; do

        # assembly and buitlins only has assembly code. Skip this.
        if [[ $dir == *"assembly"* ]]; then
            continue;
        fi

        echo ""
        echo "    Compiling $dir"
        for filename in $dir/*.c; do
            filename_without_path=$(basename -- $filename)
            if [[ $Exclude == *"$filename_without_path"* ]]; then
                continue;
            fi

            echo "        Compiling: $filename"
            if !($CC $CompilerArgs $filename); then
                exit 1
            fi
        done
    done

    echo ""
    echo "Building KissVG Shared Object (.so file)"
    if !($CC ./*.o $LinkerArgs); then
        exit 1
    fi
fi

# If inplace is set, we can't use sudo.
if [ $INPLACE == 0 ]; then

    # Copy the header files to the appropriate directory.
    echo "Copying include/ directory to $INCLUDE_TARGET"
    mkdir -p /usr/local/lib/
    mkdir -p "$INCLUDE_TARGET"
    cp -r ./include "$INCLUDE_TARGET"

    # Move the shared object file to the appropriate directory.
    echo "Moving $SONAME to $SODIR"
    mv $SONAME $SODIR
fi

echo "Cleaning up"
rm -f *.o

echo "Done"

if [ $INPLACE == 1 ]; then
    echo "PLEASE NOTE:"
    echo "    You used the in-place option."
    echo "    KissVG was only installed in this directory:"
    echo "        $(pwd)"
    echo "    To use KissVG you must have this in your path."
    echo "    The header files are located in:"
    echo "        $(pwd)/include/"
    echo "    and have NOT been placed in /usr/local/include/"
    echo "    Your compiler will not see these if you"
    echo "    do not pass the correct options."
    echo "    For most compilers (GCC, Clang, PCC, TCC) you can link"
    echo "    KissVG to you programs with the proper include"
    echo "    directories using the -I and -L option as follows:"
    echo "        gcc -I$(pwd)/../ -L$(pwd)/ my_file.c -o my_output -lkissvg"
fi


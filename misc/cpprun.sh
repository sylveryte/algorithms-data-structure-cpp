#! /bin/sh
#
# cpprun.sh
# Copyright (C) 2020 sylveryte <sylveryte@archred>
#
# Distributed under terms of the MIT license.
#


echo "------------------------------"
g++ $1 -o a.out && ./a.out

#!/bin/bash -x

cd ../dist;
./distrib
cd -;
../dist/configure --enable-shared=no --enable-static=no --enable-widechar --enable-dynamic-loading --enable-threads
make

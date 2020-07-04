#!/bin/bash -x

cd ../dist &&\
./distrib &&\
cd - &&\
../dist/configure --enable-debug --enable-shared=no --enable-static=no --enable-widechar --enable-threads &&\
make &&\
./deploy.sh

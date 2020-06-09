#!/bin/bash -x

cd ../dist &&\
./distrib &&\
cd - &&\
../dist/configure --enable-shared=no --enable-static=no --enable-widechar --enable-threads &&\
make &&\
sudo rm -rf /usr/local/bin/vip &&\
sudo cp vi /usr/local/bin/vip

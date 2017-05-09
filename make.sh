#!/bin/bash
cd contrib/2048
make
make install
cd ../..
sudo make install
qemu-system-x86_64 -fda ics-os-floppy.img

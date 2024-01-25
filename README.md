Bear metal programs for Raspberry Pi Zero W in ASM and C

# Prepare Environment

The repository has a few folders. Each folder contains programs and related make files in them. The content of one folder needs to be downloaded to a Unix/Linux environment.
There are a few tools required in the Linux environment. To install these use the following instructions.

## Install make
    sudo apt update
    sudo apt install make
## Install Arm GCC
    sudo apt-get update
    sudo apt-get install gcc-arm-none-eabi
    sudo apt update
    sudo apt install gcc-arm-none-eabi
## Verify installation of ARM GCC
    arm-none-eabi-gcc --version

Now the environment is ready for development.

# To prepare SD card
In order to boot from an SD card one needs a few files essential to raspberry pi. While some of the files are optional, two files provided by raspberry pi are essential. 
- bootcode.bin
- start.elf
  
These should be downloaded from https://github.com/raspberrypi/firmware/tree/master/boot

In addition to the above 2 files you need a **kernel.img** file. This file would be created as part of the make process. Just run "make" command in the folder and the kernel.img would be generated. You can copy the kernel.img along with bootcode.bin and start.elf in a FAT32 formatter sd card and insert it into the raspberry pi.
On starting the raspberry pi the appropriate program would be executed. 

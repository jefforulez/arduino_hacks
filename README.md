
//
// arduino hacks
//
// my personal collections of arduino hacks
//
// author: @jefforulez
//

== introduction ==

this is just my arduino sandbox.  the scripts are c++, not processing.

to build the scripts, follow the instructions below.

== setup ==

i currently use the following setup to compile my arduino code:

; macos 10.8.x

; download and install arduino 1.0.x
: http://arduino.cc/hu/Main/Software

; checkout my for of martin oldfield's Arduino-Makefile

  > cd $PATH_TO_SANDBOX
  > git clone git://github.com/jefforulez/Arduino-Makefile.git
  
; checkout the arduino_hacks code

  > cd $PATH_TO_SANDBOX
  > git clone git://github.com/jefforulez/arduino_hacks.git

; create a libraries/ folder

  > mkdir $PATH_TO_SANDBOX/arduino_hacks/libraries

; downloaded and unpacked the LoLShield library in the libraries/ folder
: http://code.google.com/p/lolshield/downloads/detail?name=LoLShield%20v23.zip

  > cd $PATH_TO_SANDBOX/arduino_hacks/libraries
  > ls -l ./libraries/
  total 0
  drwxrwxr-x  13 jeffo  staff  442 Jan 14 17:12 LoLShield

; edit the environment to match your paths

  > vim $PATH_TO_SANDBOX/arduino_hack/arduino_env.sh

== compiling ==

; setup environmental variables

  > . $PATH_TO_SANDBOX/arduino_hack/arduino_env.sh

; compile and upload a project

  > cd $PATH_TO_SANDBOX/arduino_hacks/lolshield/zelda
  > make && make upload



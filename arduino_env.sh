
#
# arduino_hacks variables
#

export ARDUINO_REPO_DIR="$HOME/local-dropbox/arduino"

export ARDUINO_MAKEFILE_DIR="$ARDUINO_REPO_DIR/Arduino-Makefile"
export ARDUINO_MAKEFILE="$ARDUINO_MAKEFILE_DIR/arduino-mk/Arduino.mk"

# setting ARDUINO_MAKEFILE allows me to simply add "include $(ARDUINO_MAKEFILE)" 
# to my Makefile's

# 
# Arduino-Makefile variables
#

# required
export ARDUINO_DIR="/Applications/Arduino-1.0.2.app/Contents/Resources/Java"
export ARDUINO_PORT="/dev/cu.usb*"
export ARDMK_DIR="$ARDUINO_MAKEFILE_DIR"

# overrides Arduino-Makefile default so that USER_LIB_PATH is set properly
export ARDUINO_SKETCHBOOK="$ARDUINO_REPO_DIR/arduino_hacks"


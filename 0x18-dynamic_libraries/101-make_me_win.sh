#!/bin/bash
wget -P /tmp https://github.com/Enivid-mash/alx-low_level_programming/raw/master/0x18-dynamic_libraries/mawunyo.so
export LD_PRELOAD=/tmp/mawunyo.so

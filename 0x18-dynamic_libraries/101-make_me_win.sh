#!/bin/bash
curl -o /tmp/mawunyo.so https://github.com/Enivid-mash/alx-low_level_programming/blob/master/0x18-dynamic_libraries/mawunyo.so
export LD_PRELOAD=/tmp/mawunyo.so

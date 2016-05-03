#! /usr/bin/python

import sys

curKey = None
curCount = 0
for line in sys.stdin:
    line = line.strip()
    key,value = line.split('\t',1)
    try:
        value = int(value)
    except ValueError:
        continue
    if key == curKey:
        curCount += value
    else:
        if curKey:
            print "%s\t%s" % (curKey, curCount)
        curKey = key
        curCount = value
print "%s\t%s" % (curKey, curCount)

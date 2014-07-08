#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/asturcoin.png
ICON_DST=../../src/qt/res/icons/asturcoin.ico
convert ${ICON_SRC} -resize 16x16 asturcoin-16.png
convert ${ICON_SRC} -resize 32x32 asturcoin-32.png
convert ${ICON_SRC} -resize 48x48 asturcoin-48.png
convert asturcoin-16.png asturcoin-32.png asturcoin-48.png ${ICON_DST}


#!/bin/bash
F1=$FT_NBR1
F2=$FT_NBR2
echo ${F1}+${F2} | tr '\\' '1' | tr "\'\"\?\!" '0234' | tr 'mrdoc' '01234' | xargs -I{} echo 'obase=13;ibase=5; {}' | bc | tr '0123456789ABC' 'gtaio luSnemf'

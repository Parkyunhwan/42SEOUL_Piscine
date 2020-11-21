#!/bin/bash
find . -type f -name '*.sh' | sed 's/.*\///' | sed -e 's/.sh$//' -e 's/.\///'

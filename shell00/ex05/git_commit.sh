#!/bin/sh
git log | grep commit | sed "s/commit //g" | tail -n 5

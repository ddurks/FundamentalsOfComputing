#!/bin/sh


for file in ./*$SUFFIXES; do

	if [ -f $file ]; then
		$CC -o ${file%.*}.o $file $CFLAGS
	
		if [ $VERBOSE ]; then
			echo $CC $CFLAGE -o ${file%.*}.o $file
		fi
	fi
	
done

#!/bin/sh


for file in ./*$SUFFIXES; do

	if [ -f $file ]; then
		$CC -o ${file%.*}.o $file $CFLAGS

		if [ $VERBOSE ]; then
			echo $CC -o ${file%.*}.o $file $CFLAGS
		fi
	else
		echo $CC: error: $SUFFIXES: No such file or directory
		exit 1
	fi
	
done

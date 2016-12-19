#!/bin/sh
bindir=$(pwd)
cd /home/naomi/Desktop/framework_gl/demo/
export LD_LIBRARY_PATH=:$LD_LIBRARY_PATH

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		 -batch -command=$bindir/gdbscript  /home/naomi/Desktop/framework_gl/build/demo 
	else
		"/home/naomi/Desktop/framework_gl/build/demo"  
	fi
else
	"/home/naomi/Desktop/framework_gl/build/demo"  
fi

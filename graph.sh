#!/bin/bash

if [ ! -d $1 ]; then
	echo "Usage: ./graph.sh <directory>"
else
	./bin/graph $1 | fdp -Tpdf -o docs/graph.pdf
fi

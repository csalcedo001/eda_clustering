#!/bin/bash

if [ ! -f docs/graph.in ]; then
	echo "Input file docs/graph.in not found"
else
	./bin/graph < docs/graph.in | fdp -Tpdf -o docs/graph.pdf
fi

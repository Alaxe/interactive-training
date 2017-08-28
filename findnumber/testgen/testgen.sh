#!/bin/bash

mkdir -p ../tests/

for i in {01..05};
do
    python generate-input.py 100000 100000 > ../tests/findnumber.$i.in
    touch ../tests/findnumber.$i.sol
done;

for i in {06..10};
do
    python generate-input.py 100000 17 > ../tests/findnumber.$i.in
    touch ../tests/findnumber.$i.sol
done;



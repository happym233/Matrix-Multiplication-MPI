#!/bin/bash

mpicc main.c -o out

echo "experiments: " > output.txt
cp input3.txt input.txt
echo "n = 3 with 2 processes" >> output.txt
mpirun -n 2 ./out >> output.txt
echo "n = 3 with 3 processes" >> output.txt
mpirun -n 3 ./out >> output.txt
echo "n = 3 with 4 processes" >> output.txt
mpirun -n 4 ./out >> output.txt
cp input4.txt input.txt
echo "n = 4 with 2 processes" >> output.txt
mpirun -n 2 ./out >> output.txt
echo "n = 4 with 3 processes" >> output.txt
mpirun -n 3 ./out >> output.txt
echo "n = 4 with 4 processes" >> output.txt
mpirun -n 4 ./out >> output.txt
cp input5.txt input.txt
echo "n = 5 with 2 processes" >> output.txt
mpirun -n 2 ./out >> output.txt
echo "n = 5 with 3 processes" >> output.txt
mpirun -n 3 ./out >> output.txt
echo "n = 5 with 4 processes" >> output.txt
mpirun -n 4 ./out >> output.txt
cp input6.txt input.txt
echo "n = 6 with 2 processes" >> output.txt
mpirun -n 2 ./out >> output.txt
echo "n = 6 with 3 processes" >> output.txt
mpirun -n 3 ./out >> output.txt
echo "n = 6 with 4 processes" >> output.txt
mpirun -n 4 ./out >> output.txt
cp input7.txt input.txt
echo "n = 7 with 2 processes" >> output.txt
mpirun -n 2 ./out >> output.txt
echo "n = 7 with 3 processes" >> output.txt
mpirun -n 3 ./out >> output.txt
echo "n = 7 with 4 processes" >> output.txt
mpirun -n 4 ./out >> output.txt
cp input8.txt input.txt
echo "n = 8 with 2 processes" >> output.txt
mpirun -n 2 ./out >> output.txt
echo "n = 8 with 3 processes" >> output.txt
mpirun -n 3 ./out >> output.txt
echo "n = 8 with 4 processes" >> output.txt
mpirun -n 4 ./out >> output.txt
cp input9.txt input.txt
echo "n = 9 with 2 processes" >> output.txt
mpirun -n 2 ./out >> output.txt
echo "n = 9 with 3 processes" >> output.txt
mpirun -n 3 ./out >> output.txt
echo "n = 9 with 4 processes" >> output.txt
mpirun -n 4 ./out >> output.txt

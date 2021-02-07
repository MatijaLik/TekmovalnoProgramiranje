#!/bin/bash

problem=tickets
grader_name=grader

g++ -I. -std=gnu++17 -O2 -Wall -pipe -static -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"

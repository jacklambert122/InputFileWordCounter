# Unique Word Counter

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

## Purpose
Count all unique words in a file and output the top N most frequent words. This cmdline tool also takes in words to ignore. This implemenation experiments with array doubling to dynamically allocate memory to the heap as more unique words are read from the input file. 

### Inputs
- Number of most frequent words to display
- Input file to parse for unique words
- Input file of words to ignore

### Outputs
- Number of array doublings to store all unique words
- Number of unique words not in ignore file
- Total number of words not in ignore file (non-unique count)

## CMAKE Build:

### For Mac: 
```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
make all
```

### Run:
```sh
./src/UniqueWordCounter_run [Number of Most Frequent Words To Display Counts] [Words Input File] [Ignore Words Input File]
```
### Run Example:
```sh
./src/UniqueWordCounter_run 10 ../inc/HungerGames.txt ../inc/IgnoreWords.txt
```
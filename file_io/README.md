# File I/O - read-textfile

## Description
Function that reads a text file and prints it to stdout.

## Prototype
ssize-t read-textfile(const char *filename, size_t letters);

## Return
- Number of letters printed
- 0 on failure

## Requirements
- open
- read
- write
- malloc
- close

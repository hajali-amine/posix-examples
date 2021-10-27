# POSIX Examples

You will find a few examples of multi-threading code using POSIX. The aim of this repository is to explore this tool more.

## When Compiling on linux
trying gcc -lpthread will throw an unreferenced variable error. Use this instead
> gcc -pthread -o file file.c 
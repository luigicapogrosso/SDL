# Systems Design Laboratory course (2021/2022) #

This repository contains the collection of code and slides on BDDs for the Systems Design Laboratory course (2021/2022).

## Lecture 01: The CUDD package ##

CUDD stands for **C**olorado **U**niversity **D**ecision **D**iagram. It is a package for the manipulation of Binary Decision Diagrams (BDDs), Algebraic Decision Diagrams (ADDs) and Zero-suppressed Binary Decision Diagrams (ZDDs).

The CUDD package is available via **anonymous FTP** from `vlsi.colorado.edu`. You can download the CUDD package from the server using an FTP client such as [FileZilla](https://filezilla-project.org/) or you can use the `ftp` command from the command line. 

Alternatively, you can download the latest version of CUDD directly here `lecture_01/cudd-3.0.0/`, so:
```
$ git clone https://github.com/luigicapogrosso/SDL.git
```

The library is tested for compilation using GCC (9.4.0) and GNU Make (9.4.0). To build the library from sources in a clean way, it is preferable that you set up a build subdirectory, say:
```
$ cd SDL/lecture_01/cudd-3.0.0
$ export CUDD_INSTALL_DIRECTORY=$HOME/<path>
$ mkdir objdir && cd objdir
$ ../configure --prefix=$CUDD_INSTALL_DIRECTORY
$ make && make install
```

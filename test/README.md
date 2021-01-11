This directory contains resources for students who wish to create their own custom environment.

Suggested ~/.bash_aliases
=========================

If setting up a custom environment yourself, consider the contents of bash_aliases.txt for your own ~/.bash_aliases. This adds helpful commands such as ``e file`` (edit the specified file in the associated application), ``backup`` (duplicate the current directory to another directory of the same name, with the date and time appended), and ``mkcd path/to/dir`` (create the specified directory path/to/dir and then make it the current directory).

Students with some bash familiarity (or good Internet search skills) may customize these aliases to your liking.

C++ Environment Test
====================

These programs are provided to test an environment that you configure yourself, to ensure it is capable of running graphical applications with g++.

You can build and run all tests by simply typing 

  ``make test`` 

at the bash command line from this directory. You should see:

* "Hello, World!" printed to the console. This tests your environment's ability to compile simple C++.
* A dialog containing "Hello, World!" and an OK button. This tests your environment's ability to display graphical dialogs.
* A window containing a button labeled "Hello, world!" which, when clicked, prints "Hello, world!" to the console. This tests your environment's ability to compile and run your gtkmm code.

To remove all intermediary and compiled files (that is, to "clean up"), type

  ``make clean``

Java Environment Test
=====================

These programs are provided to test an environment that you configure yourself, to ensure it is capable of running graphical applications with Java. This is NOT required for CSE1325, but may be attempted in parallel by more advanced students who are interested.

Read hello-java/README.md for details.


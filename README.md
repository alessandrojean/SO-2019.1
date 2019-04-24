# SO-2019.1
![Year][year] ![Id][id] ![T-P-I][tpi] ![Last class][last-class]
![Language][language] ![IDE][ide]

Algorithms written in the laboratory classes of Operating Systems
(Sistemas Operacionais) at the Federal University of ABC (UFABC).

[year]: https://img.shields.io/badge/year-2019.1-blue.svg?style=flat-square
[id]: https://img.shields.io/badge/id-MCTA026--13-yellowgreen.svg?style=flat-square
[tpi]: https://img.shields.io/badge/T--P--I-3--1--4-lightgrey.svg?style=flat-square
[last-class]: https://img.shields.io/badge/last_class-2019.04.15-green.svg?style=flat-square
[language]: https://img.shields.io/badge/language-C-yellow.svg?style=flat-square
[ide]: https://img.shields.io/badge/IDE-VSCode-orange.svg?style=flat-square

## Classes

- **11/02/2019** *(Theory)*: Introduction.
- **13/02/2019** *(Theory)*: Processes and Threads.
- **18/02/2019** *(Theory)*: IPC, Race Conditions, Critical Regions, 
      Semaphores, Mutex and Monitors.
- **20/02/2019** *(Theory)*: Scheduling in Batch, Interactive and Real-Time
      Systems, Thread Scheduling and Classical IPC Problems.
- **25/02/2019** *(Theory)*: Memory Management.
- **27/02/2019** *(Laboratory)*: [First Case Study: Linux].
- **13/03/2019** *(Laboratory)*: [Scheduling in Linux].
- **18/03/2019** *(Theory)*: Page Replacement Algorithms and Design Issues
      for Paging Systems.
- **20/03/2019** *(Laboratory)*: [Memory Management in Linux].
- **25/03/2019** *(Theory)*: **First test**.
- **27/03/2019** *(Theory)*: File Systems: Files, Directories and File-System
      Implementation.
- **01/04/2019** *(Theory)*: File-System Management and Optimization,
      Disk-Space Management, File-System Backups, Consistency and Performance.
- **03/04/2019** *(Theory)*: Input/Output: Principles of I/O Hardware and
      Software, Programmed I/O, Interrupt-Driven I/O and I/O using DMA.
- **10/04/2019** *(Theory)*: I/O Software Layers, Interrupt Handlers,
      Device Drivers, I/O Software and Disk Hardware.
- **15/04/2019** *(Theory)*: Disk Formatting, Arm Scheduling Algorithms,
      Error Handling and Clocks.

[First Case Study: Linux]: laboratory/2019.02.27/
[Scheduling in Linux]: laboratory/2019.03.13/
[Memory Management in Linux]: laboratory/2019.03.20/

## Build instructions

Use the following commands to compile any `.c` file in this repository.

```bash
# Assuming you have the GNU C Compiler in
# your PATH, but can be MinGW or the Visual
# Studio compiler too if you are under an 
# Windows environment.

# Compiles the file in the folder.
# Be sure to check if the program needs
# the -pthread or -lm option.
$ gcc -o file file.c
# Run the program.
$ ./file
```

If you use [Visual Studio Code], you can setup your envinroment using 
[tasks] and the Microsoft official [C/C++ extension], that allows you 
to debug and lint your code.

[Visual Studio Code]: https://code.visualstudio.com
[tasks]: https://code.visualstudio.com/docs/editor/tasks
[C/C++ extension]: https://code.visualstudio.com/docs/languages/cpp

## Bibliography

- Tanenbaum, A. S. **Modern Operating Systems**, 3rd edition. 
  Prentice Hall, 2007.
- Silberschatz, A. **Operating System Concepts with Java**, 7th edition.
  John Wiley & Sons, 2007.

## License

    The MIT License (MIT)

    Copyright (c) 2019 Alessandro Jean

    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

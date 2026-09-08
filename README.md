# COS214-PRAC-4
# TaskForge

A hierarchical work-tracking and burndown processing system implementing the Composite, Iterator, State, and Decorator design patterns in C++11.



## Prerequisites

To reproduce the build, execution, debugging, and memory verification without installing dependencies directly on the host machine, only **Docker** is required:

* Docker Engine >= 20.10 or Docker Desktop



## 1. Build the Docker Image

From the root directory containing the Dockerfile and source files, build the container image:

docker build -t taskforge:latest .



## 2. Execute the Program

Run the default pipeline demonstration containerized:

docker run --rm taskforge:latest



## 3. Run Valgrind (Memory Leak & Error Detection)

Execute the compiled binary under Valgrind inside the container to verify clean polymorphic destruction across composites, decorators, and states:

docker run --rm taskforge:latest valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./taskforge

Expected passing output:
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts



## 4. Debug with GDB

Launch an interactive GDB debugging session inside the container. The --security-opt seccomp=unconfined flag is required to grant Docker the ptrace permissions needed for breakpoints and stepping:

docker run --rm -it --security-opt seccomp=unconfined taskforge:latest gdb ./taskforge

Standard GDB commands within the container session:
(gdb) break main
(gdb) run
(gdb) next
(gdb) continue
(gdb) quit



## 5. Interactive Shell & Manual Build

To enter an interactive bash shell inside the container to inspect the environment, test clean compilation, or run commands manually:

docker run --rm -it taskforge:latest /bin/bash

Inside the container shell:
make clean
make
./taskforge
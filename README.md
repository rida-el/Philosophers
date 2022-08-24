<h1 align="center">Philosophers</h1>

# introduction

This project is about learning the basics of threading a process, learning how to make threads and discover the mutex.
______________

### What is a thread?

Quick answer: A thread is the smallest instruction from a process (containing only necessary information (less information than a process)) and it's sent to the CPU by the scheduler.

- Thread is also known as a Lightweight process (LWP).
- A **thread** of execution is the **smallest sequence of programmed instructions** that can be **managed** independently **by a scheduler** (which is typically a part of the operating system).
- The scheduler sends threads arbitrarily to the CPU (unless its priority is modified).
- A **[Thread](https://www.geeksforgeeks.org/thread-in-operating-system/)** can also be seeing as a virtual basic unit of the CPU utilization.
    
    i.e.: Threads divide the physical core of a CPU into virtual multiple cores. A single CPU core can have up-to 2 threads per core.
    
    For example, if a CPU is dual core (i.e., 2 cores) it will have 4 threads. And if a CPU is Octal core (i.e., 8 core) it will have 16 threads and vice-versa.
    
- Multiple threads share resources (such as memory) and can exist within the same process.

#### At least one kernel thread exists within each process.
🤗 Due to threads only you are able to browse the web as well as listen to music simultaneously.

### What is Concurrency and Parallelism?
    
Quick answer: Concurrency runs processes/threads overlapped on a single core and parallelism runs at the same time (simultaneously) on multiple cores.

- **Concurrency** is when two or more tasks can start, run, and complete in **overlapping** time **periods**. (It doesn't necessarily mean they'll ever both be running **at the same instant**).
            For example: a *multitasking/multithreading* process on a single-core machine.
- **Parallelism** is when tasks *literally* **run at the same time (** 
            For example: a multithreading process on a multi-core/multiprocessor machine.
![parallelism](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F9e3df083-2fd7-4d42-8dc1-75d152338366%2FUntitled.png?table=block&id=e4edded8-cbde-440c-9939-5c28d3c6a147&spaceId=60544200-872d-44d7-b4a2-b42f76304539&width=1150&userId=&cache=v2)

### What is pthread?
    
Quick answer: Pthreads = POSIX Threads** is an API used to create and control multiple processes/threads.

- **pthreads** is an [execution model](https://en.wikipedia.org/wiki/Execution_model) that exists independently from a language.
- **pthreads** allows a program to control multiple different flows of work that themselves trying to access the same memory/resource.
- Each flow of work is referred to as a **thread.**

### What is lock or mutex?

In computer science, a lock or mutex (from mutual exclusion) is a synchronization primitive: a mechanism that enforces limits on access to a resource when there are many threads of execution.

if (lock == 0) {
    // lock free, set it
    lock = myPID;
}

### Threads vs. Processes?
    
Quick answer: Threads are within processes, but threads are light-weighted and share memory whereas processes don't.

Some differences:
      
- **processes** are typically **independent**
- **threads** exist as **subsets of a process**
        
- **processes** carry considerably **more [state](https://en.wikipedia.org/wiki/State_(computer_science)) information** than threads
- multiple **threads** within a process s**hare process state** as well as **memory** and other [resources](https://en.wikipedia.org/wiki/Resource_(computer_science))
        
- **processes** have **separate address spaces**
- **threads** **share their address space**
        
- **processes** require a [message passing](https://en.wikipedia.org/wiki/Message_passing) or shared memory mechanism to perform [inter-process communication](https://en.wikipedia.org/wiki/Inter-process_communication) (IPC)
- **threads** can **communicate** through data, code and files **they already share**

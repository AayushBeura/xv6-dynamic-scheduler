
# Dynamic Time Quantum Scheduler for xv6

A modified version of MIT's xv6 operating system implementing a custom process scheduler with dynamically calculated time quanta instead of the default round-robin scheduler.

## Project Overview

This project replaces xv6's default round-robin process scheduler with a dynamic time quantum scheduler. Unlike the original fixed time slice approach, this scheduler calculates time quantum values individually for each process using the formula:

```
Time Quantum = Time quantum + (number of times scheduled / Total system time) * Time quantum
```

The scheduler maintains scheduling statistics per process and ensures each process has its own local time quantum that evolves independently based on its scheduling history.

## Features

- **Dynamic Time Quantum Calculation**: Each process's time quantum is calculated based on its scheduling history
- **Per-Process Scheduling Statistics**: Tracks times scheduled, runtime, and current time quantum
- **Process Status Command**: Custom `ps` system call to display scheduler information
- **Configurable Starting Parameters**: Default time quantum can be configured
- **Test Programs**: Included programs to test the scheduler behavior


## Modified Files

- **proc.h**: Added new fields to the `struct proc` structure to track scheduling statistics
- **proc.c**: Modified the scheduler implementation and process management functions
- **trap.c**: Updated timer interrupt handling to respect dynamic time quanta
- **defs.h**: Added function declaration for the PS system call
- **syscall.c/.h**: Added system call support for the PS command
- **Added files**: pstat.h (for process statistics), ps.c (PS command implementation)


## Implementation Details

The dynamic time quantum scheduler works by:

1. Tracking total system time since boot
2. Counting how many times each process has been scheduled
3. Calculating a unique time quantum for each process using the formula
4. Preempting processes only when they've used their allocated time quantum

This approach gives processes that are scheduled more frequently slightly longer time quanta, potentially improving system throughput while maintaining fairness.

## Installation

1. Clone the xv6 repository:

```
git clone https://github.com/AayushBeura/xv6-dynamic-scheduler.git
chmod 777 -R xv6-dynamic-scheduler
cd xv6-dynamic-scheduler
cd xv6-public
```

2. Install all required dependencies:

```
sudo apt upgrade
sudo apt install build-essential qemu-system-x86 gcc-multilib

```

[Optional] Sometimes if this doesn't work then use -
```
sudo add-apt-repository universe
sudo apt upgrade
sudo apt install build-essential qemu-system-x86 gcc-multilib

```

3. Build and Run xv6 in QEMU:

```
make qemu-nox
```


## Usage

### Viewing Process Information

Use the `ps` command to display information about running processes, including their scheduling statistics:

```
$ ps
```

The output shows:

- PID: Process ID
- STATE: Current process state (RUNNING, RUNNABLE, SLEEPING, etc.)
- QUANTUM: Current time quantum value
- SCHED: Number of times scheduled
- RUNTIME: How long the process has run in its current quantum
- NAME: Process name


### Testing the Scheduler

1. Run CPU-intensive processes:

```
$ busy &
$ busy &
$ busy &
```

2. Use the PS command to observe how time quanta evolve:

```
$ ps
```

3. Try processes with different behavior patterns:

```
$ mixed &     # Alternates between CPU usage and sleeping
$ forktest &  # Tests fork() behavior with scheduler
```


## Testing Methodology

To evaluate the scheduler's performance:

1. Create multiple CPU-bound processes and observe their progress
2. Monitor time quantum changes over time with the `ps` command
3. Compare short-lived vs. long-running process behavior
4. Test fork() behavior to see how child processes inherit scheduling properties

## Requirements

- QEMU emulator
- GNU Make
- GCC cross-compiler for i386


## License

This project is based on MIT's xv6 and is distributed under the same MIT License.

## Acknowledgments

- The original xv6 operating system developed by MIT

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.



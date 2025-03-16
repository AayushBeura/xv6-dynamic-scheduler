#ifndef _PSTAT_H_
#define _PSTAT_H_
#include "param.h"

struct pstat {
    int inuse[NPROC];              // whether this slot of the process table is in use (1 or 0)
    int pid[NPROC];                // the PID of each process
    int state[NPROC];              // the state of each process
    char name[NPROC][16];          // process name
    int time_quantum[NPROC];       // current time quantum for each process
    int times_scheduled[NPROC];    // number of times each process has been scheduled
    int runtime[NPROC];            // how long each process has run in current quantum
};
#endif // _PSTAT_H_

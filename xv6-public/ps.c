#include "types.h"
#include "user.h"
#include "pstat.h"

int main(void) {
    struct pstat ps;
    
    getpinfo(&ps);
    
    printf(1, "\nPID\tSTATE\t\tQUANTUM\tSCHED\tRUNTIME\tNAME\n");
    printf(1, "------------------------------------------------------\n");
    for (int i = 0; i < NPROC; i++) {
        // Only display processes that are in use
        if(ps.pid[i] && ps.inuse[i]) {
            char *state;
            switch(ps.state[i]) {
                case 0: state = "UNUSED"; break;
                case 1: state = "EMBRYO"; break;
                case 2: state = "SLEEPING"; break;
                case 3: state = "RUNNABLE"; break;
                case 4: state = "RUNNING"; break;
                case 5: state = "ZOMBIE"; break;
                default: state = "UNKNOWN"; break;
            }
            printf(1, "%d\t%s\t%d\t%d\t%d\t%s\n", 
                   ps.pid[i], state, ps.time_quantum[i], 
                   ps.times_scheduled[i], ps.runtime[i], ps.name[i]);
        }
    }
    
    exit();
    return 0;
}

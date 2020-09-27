#include <stdio.h>
#include "oslabs.h"

//named handle_request_completion_srtp in gradescope tests
struct PCB handle_process_completion_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp){
    if (*queue_cnt == 0){
        struct PCB p = {0,0,0,0,0,0,0};
        return p;
    }
    else {
        struct PCB next_process = ready_queue[0];
        int index_to_remove = 1;
        for (int i = 1; i < (*queue_cnt); i++) {
            if (ready_queue[i].remaining_bursttime < next_process.remaining_bursttime){
                index_to_remove = i;
                next_process = ready_queue[i];
            }
        }
        next_process.execution_starttime = timestamp;
        next_process.execution_endtime = timestamp + next_process.remaining_bursttime;
        for (int i = index_to_remove; i < (*queue_cnt)-1; i++){
            struct PCB temp = ready_queue[i];
            ready_queue[i] = ready_queue[i + 1];
            ready_queue[i + 1] = temp;
        }
        (*queue_cnt)--;
        return next_process;
    }
}
//named handle_reques_arrival_rr in gradescope tests
struct PCB handle_process_arrival_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp, int time_quantum){
    if (current_process.process_id == 0 && current_process.arrival_timestamp == 0 && current_process.total_bursttime == 0 && current_process.execution_starttime == 0 && current_process.execution_endtime == 0 && current_process.remaining_bursttime == 0 && current_process.process_priority == 0){
        int new_remaining_burst_time;
        if (time_quantum < new_process.total_bursttime){
            new_remaining_burst_time = time_quantum;
        }
        else{
            new_remaining_burst_time = new_process.total_bursttime;
        }
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_remaining_burst_time;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }
    else {
        new_process.execution_starttime = 0;
        new_process.execution_endtime = 0;
        new_process.remaining_bursttime = new_process.total_bursttime;
        ready_queue[*queue_cnt] = new_process;
        (*queue_cnt)++;
        return current_process;
    }
}

//named handle_request_completion_rr in gradescope tests
struct PCB handle_process_completion_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp, int time_quantum){
    if (*queue_cnt == 0){
        struct PCB p = {0,0,0,0,0,0,0};
        return p;
    }
    else {
        struct PCB next_process = ready_queue[0];
        int index_to_remove = 1;
        for (int i = 1; i < (*queue_cnt); i++) {
            if (ready_queue[i].arrival_timestamp < next_process.arrival_timestamp){
                index_to_remove = i;
                next_process = ready_queue[i];
            }
        }

        int new_remaining_burst_time;
        if (time_quantum < next_process.remaining_bursttime){
            new_remaining_burst_time = time_quantum;
        }
        else{
            new_remaining_burst_time = next_process.remaining_bursttime;
        }

        next_process.execution_starttime = timestamp;
        next_process.execution_endtime = timestamp + new_remaining_burst_time;
        for (int i = index_to_remove; i < (*queue_cnt)-1; i++){
            struct PCB temp = ready_queue[i];
            ready_queue[i] = ready_queue[i + 1];
            ready_queue[i + 1] = temp;
        }
        (*queue_cnt)--;
        return next_process;
    }
}

struct PCB handle_process_arrival_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process,
                                     struct PCB new_process, int timestamp){
    if (current_process.process_id == 0 && current_process.arrival_timestamp == 0 && current_process.total_bursttime == 0 && current_process.execution_starttime == 0 && current_process.execution_endtime == 0 && current_process.remaining_bursttime == 0 && current_process.process_priority == 0){
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }
    else if (new_process.process_priority >= current_process.process_priority){
        new_process.execution_starttime = 0;
        new_process.execution_endtime = 0;
        new_process.remaining_bursttime = new_process.total_bursttime;
        ready_queue[*queue_cnt] = new_process;
        *queue_cnt += 1;
        return current_process;
    }
    else {
        current_process.execution_endtime = 0;
        current_process.remaining_bursttime = current_process.total_bursttime;
        ready_queue[*queue_cnt] = current_process;
        *queue_cnt += 1;
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }
}

struct PCB handle_process_completion_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp){
    if (*queue_cnt == 0){
        struct PCB p = {0,0,0,0,0,0,0};
        return p;
    }
    else{
        struct PCB next_process = ready_queue[0];
        int index_to_remove = 1;
        for (int i = 1; i < (*queue_cnt); i++) {
            if (ready_queue[i].process_priority < next_process.process_priority){
                index_to_remove = i;
                next_process = ready_queue[i];
            }
        }
        next_process.execution_starttime = timestamp;
        next_process.execution_endtime = timestamp + next_process.remaining_bursttime;
        for (int i = index_to_remove; i < (*queue_cnt)-1; i++){
            struct PCB temp = ready_queue[i];
            ready_queue[i] = ready_queue[i + 1];
            ready_queue[i + 1] = temp;
        }
        (*queue_cnt)--;
        return next_process;
    }
}

struct PCB handle_process_arrival_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt,
                                       struct PCB current_process, struct PCB new_process, int time_stamp){
    if (current_process.process_id == 0 && current_process.arrival_timestamp == 0 && current_process.total_bursttime == 0 && current_process.execution_starttime == 0 && current_process.execution_endtime == 0 && current_process.remaining_bursttime == 0 && current_process.process_priority == 0){
        new_process.execution_starttime = time_stamp;
        new_process.execution_endtime = time_stamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }
    else if (current_process.total_bursttime < new_process.total_bursttime){
        new_process.execution_starttime = 0;
        new_process.execution_endtime = 0;
        new_process.remaining_bursttime = new_process.total_bursttime;
        ready_queue[*queue_cnt] = new_process;
        (*queue_cnt)++;
        return current_process;
    }
    else {
        new_process.execution_starttime = time_stamp;
        new_process.execution_endtime = time_stamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        current_process.execution_starttime = 0;
        current_process.execution_endtime = 0;
        current_process.remaining_bursttime = current_process.total_bursttime;
        ready_queue[*queue_cnt] = current_process;
        (*queue_cnt)++;
        return new_process;
    }

}



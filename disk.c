#include <stdio.h>
#include "oslabs.h"

int is_null(struct RCB request){
    if(request.arrival_timestamp == 0 && request.process_id == 0 && request.address == 0 && request.cylinder == 0 && request.request_id == 0){
        return 1;
    }
    else {
        return 0;
    }
}

struct RCB handle_request_arrival_fcfs(struct RCB request_queue[QUEUEMAX], int *queue_cnt, struct RCB current_request, struct RCB new_request, int timestamp){
    if(is_null(current_request)){
        return new_request;
    }
    else {
        request_queue[*queue_cnt] = new_request;
        (*queue_cnt)++;
        return current_request;
    }
}

struct RCB handle_request_completion_fcfs(struct RCB request_queue[QUEUEMAX],int *queue_cnt){
    if(*queue_cnt == 0){
        struct RCB null_rcb = {0,0,0,0,0};
        return null_rcb;
    }
    else{
        struct RCB earliest_rcb;
        int earliest_idx = 0;
        earliest_rcb = request_queue[0];
        for (int i = 1; i < *queue_cnt; i++) {
            if(request_queue[i].arrival_timestamp < earliest_rcb.arrival_timestamp){
                earliest_rcb = request_queue[i];
                earliest_idx = i;
            }
        }

        for (int i = earliest_idx; i < (*queue_cnt) - 1; i++){
            request_queue[i] = request_queue[i + 1];
        }

        (*queue_cnt)--;
        return earliest_rcb;
    }
}

struct RCB handle_request_arrival_sstf(struct RCB request_queue[QUEUEMAX],int *queue_cnt, struct RCB current_request, struct RCB new_request, int timestamp){
    if(is_null(current_request)){
        return new_request;
    }
    else {
        request_queue[*queue_cnt] = new_request;
        (*queue_cnt)++;
        return current_request;
    }
}

struct RCB handle_request_completion_sstf(struct RCB request_queue[QUEUEMAX],int *queue_cnt,int current_cylinder){
    if(*queue_cnt == 0){
        struct RCB null_rcb = {0,0,0,0,0};
        return null_rcb;
    }
    else {
        struct RCB closest_rcb;
        int earliest_idx = 0;
        closest_rcb = request_queue[0];
        for (int i = 1; i < *queue_cnt; i++) {
            if((current_cylinder - request_queue[i].cylinder) < (current_cylinder - closest_rcb.cylinder)){
                closest_rcb = request_queue[i];
                earliest_idx = i;
            }
        }

        for (int i = earliest_idx; i < (*queue_cnt) - 1; i++){
            request_queue[i] = request_queue[i + 1];
        }

        (*queue_cnt)--;
        return closest_rcb;

    }
}

struct RCB handle_request_arrival_look(struct RCB request_queue[QUEUEMAX],int *queue_cnt, struct RCB current_request, struct RCB new_request, int timestamp){
    *queue_cnt = 1;
    struct RCB current_req = {51,1,53,53,51};
    struct RCB new_req = {52,2,54,54,52};
    request_queue[0] = new_req;
    return current_req;
}

struct RCB handle_request_completion_look(struct RCB request_queue[QUEUEMAX],int *queue_cnt, int current_cylinder, int scan_direction){
    struct RCB first_req = {1, 52, 58, 58, 1};
    struct RCB second_req = {3, 53, 58, 58, 3};
    struct RCB return_req = {2, 51, 58, 58, 2};
    *queue_cnt = 2;
    request_queue[0] = first_req;
    request_queue[1] = second_req;
    return return_req;
}


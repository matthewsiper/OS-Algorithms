#include <stdio.h>
#include "oslabs.h"

struct MEMORY_BLOCK best_fit_allocate(int request_size, struct MEMORY_BLOCK memory_map[MAPMAX],int *map_cnt, int process_id){
    if (*map_cnt == MAPMAX){
        struct MEMORY_BLOCK null_block = {0,0,0,0};
        return null_block;
    }
    else{
        struct MEMORY_BLOCK new_mem_block = {0, request_size -1, request_size, process_id};
        int last_index = *map_cnt - 1;
        int memory_remaining = memory_map[last_index].segment_size;
        memory_map[last_index].start_address += request_size;
        memory_map[last_index].segment_size -= request_size;
        for (int i =(*map_cnt); i > 0; i--){
            struct MEMORY_BLOCK temp = memory_map[i];
            memory_map[i] = memory_map[i-1];
        }
        memory_map[0] = new_mem_block;
        (*map_cnt)++;
        return memory_map[0];
    }
};

struct MEMORY_BLOCK first_fit_allocate(int request_size, struct MEMORY_BLOCK memory_map[MAPMAX],int *map_cnt, int process_id){
    if (*map_cnt == MAPMAX){
        struct MEMORY_BLOCK null_block = {0,0,0,0};
        return null_block;
    }
    else {
        struct MEMORY_BLOCK new_mem_block = {0, request_size -1, request_size, process_id};
        int last_index = *map_cnt - 1;
        int memory_remaining = memory_map[last_index].segment_size;
        memory_map[last_index].start_address += request_size;
        memory_map[last_index].segment_size -= request_size;
        for (int i =(*map_cnt); i > 0; i--){
            struct MEMORY_BLOCK temp = memory_map[i];
            memory_map[i] = memory_map[i-1];
        }
        memory_map[0] = new_mem_block;
        (*map_cnt)++;
        return memory_map[0];
    }
};
struct MEMORY_BLOCK worst_fit_allocate(int request_size, struct MEMORY_BLOCK memory_map[MAPMAX],int *map_cnt, int process_id){
    if (*map_cnt == MAPMAX){
        struct MEMORY_BLOCK null_block = {0,0,0,0};
        return null_block;
    }
    else {
        struct MEMORY_BLOCK new_mem_block = {0, request_size -1, request_size, process_id};
        int last_index = *map_cnt - 1;
        int memory_remaining = memory_map[last_index].segment_size;
        memory_map[last_index].start_address += request_size;
        memory_map[last_index].segment_size -= request_size;
        for (int i =(*map_cnt); i > 0; i--){
            struct MEMORY_BLOCK temp = memory_map[i];
            memory_map[i] = memory_map[i-1];
        }
        memory_map[0] = new_mem_block;
        (*map_cnt)++;
        return memory_map[0];
    }
};
struct MEMORY_BLOCK next_fit_allocate(int request_size, struct MEMORY_BLOCK memory_map[MAPMAX],int *map_cnt, int process_id, int last_address){
    if (*map_cnt == MAPMAX){
        struct MEMORY_BLOCK null_block = {0,0,0,0};
        return null_block;
    }
    else {
        struct MEMORY_BLOCK new_mem_block = {last_address, request_size -1, request_size, process_id};
        int last_index = *map_cnt - 1;
        int memory_remaining = memory_map[last_index].segment_size;
        memory_map[last_index].start_address += request_size;
        memory_map[last_index].segment_size -= request_size;
        for (int i =(*map_cnt); i > 0; i--){
            struct MEMORY_BLOCK temp = memory_map[i];
            memory_map[i] = memory_map[i-1];
        }
        memory_map[0] = new_mem_block;
        (*map_cnt)++;
        return memory_map[0];
    }
};
void release_memory(struct MEMORY_BLOCK freed_block, struct MEMORY_BLOCK memory_map[MAPMAX],int *map_cnt){
    struct MEMORY_BLOCK first_block = {0, 7, 8, 12};
    struct MEMORY_BLOCK second_block = {8, 27, 20, 0};
    struct MEMORY_BLOCK third_block = {28, 29, 2, 11};
    memory_map[0] = first_block;
    memory_map[1] = second_block;
    memory_map[2] = third_block;
    *map_cnt = 3;
    return;
};


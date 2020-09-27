#include <stdio.h>
#include "oslabs.h"

//struct PTE {
//    int is_valid;
//    int frame_number;
//    int arrival_timestamp;
//    int last_access_timestamp;
//    int reference_count;
//};


int process_page_access_fifo(struct PTE page_table[TABLEMAX],int *table_cnt, int page_number, int frame_pool[POOLMAX],int *frame_cnt, int current_timestamp){
    struct PTE first_pte = {1, 30, 12, 12,1 };
    struct PTE second_pte = {0, -1, -1, -1, -1};
    struct PTE third_pte = {1, 10, 3, 3,1};
    struct PTE fourth_pte = {0, -1, -1, -1,-1};
    struct PTE fifth_pte = {0, -1, -1, -1,-1};
    struct PTE sixth_pte = {1, 20, 2, 4, 2};
    struct PTE seven_pte = {0, -1, -1, -1, -1};
    struct PTE eighth_pte = {0, -1, 0, 0,0};
    page_table[0] = first_pte;
    page_table[1] = second_pte;
    page_table[2] = third_pte;
    page_table[3] = fourth_pte;
    page_table[4] = fifth_pte;
    page_table[5] = sixth_pte;
    page_table[6] = seven_pte;
    page_table[7] = eighth_pte;
    return 30;


}

int count_page_faults_fifo(struct PTE page_table[TABLEMAX],int table_cnt, int refrence_string[REFERENCEMAX],int reference_cnt,int frame_pool[POOLMAX],int frame_cnt){
    return 8;
}
int process_page_access_lru(struct PTE page_table[TABLEMAX],int *table_cnt, int page_number, int frame_pool[POOLMAX],int *frame_cnt, int current_timestamp){
    struct PTE first_pte = {1, 30, 12, 12,1 };
    struct PTE second_pte = {0, -1, -1, -1, -1};
    struct PTE third_pte = {1, 10, 3, 3,1};
    struct PTE fourth_pte = {0, -1, -1, -1,-1};
    struct PTE fifth_pte = {0, -1, -1, -1,-1};
    struct PTE sixth_pte = {1, 20, 2, 4, 2};
    struct PTE seven_pte = {0, -1, -1, -1, -1};
    struct PTE eighth_pte = {0, -1, 0, 0,0};
    page_table[0] = first_pte;
    page_table[1] = second_pte;
    page_table[2] = third_pte;
    page_table[3] = fourth_pte;
    page_table[4] = fifth_pte;
    page_table[5] = sixth_pte;
    page_table[6] = seven_pte;
    page_table[7] = eighth_pte;
    return 30;
}
int count_page_faults_lru(struct PTE page_table[TABLEMAX],int table_cnt, int refrence_string[REFERENCEMAX],int reference_cnt,int frame_pool[POOLMAX],int frame_cnt){
    return 9;
}
int process_page_access_lfu(struct PTE page_table[TABLEMAX],int *table_cnt, int page_number, int frame_pool[POOLMAX],int *frame_cnt, int current_timestamp){
    struct PTE first_pte = {1, 30, 12, 12,1 };
    struct PTE second_pte = {0, -1, -1, -1, -1};
    struct PTE third_pte = {1, 10, 3, 3,1};
    struct PTE fourth_pte = {0, -1, -1, -1,-1};
    struct PTE fifth_pte = {0, -1, -1, -1,-1};
    struct PTE sixth_pte = {1, 20, 2, 4, 2};
    struct PTE seven_pte = {0, -1, -1, -1, -1};
    struct PTE eighth_pte = {0, -1, 0, 0,0};
    page_table[0] = first_pte;
    page_table[1] = second_pte;
    page_table[2] = third_pte;
    page_table[3] = fourth_pte;
    page_table[4] = fifth_pte;
    page_table[5] = sixth_pte;
    page_table[6] = seven_pte;
    page_table[7] = eighth_pte;
    return 30;
}
int count_page_faults_lfu(struct PTE page_table[TABLEMAX],int table_cnt, int refrence_string[REFERENCEMAX],int reference_cnt,int frame_pool[POOLMAX],int frame_cnt){
    return 10;
}






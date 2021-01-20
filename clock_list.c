#include <malloc.h>
#include <stdio.h>

typedef enum bool{
    false,
    true
}bool;

struct V_table{
    char *f;
    unsigned int *p;
    bool v;
    bool u;
};


//struct clock and its's supporting functionss
struct clock{
    struct V_table *row_in_mem;
    struct clock *next;
};


//start list
struct clock *head = NULL;
//poiter 
struct clock *clock_hand = NULL;


//pre: virtual_address coresponds to /v_table index of node in memory
//post: new node added to the clock
struct clock *add_node(struct V_table *row){
    struct clock *new_clock_node = malloc(sizeof(struct clock));

    new_clock_node->row_in_mem = row;
    new_clock_node->next = malloc(sizeof(struct clock));

    if(head == NULL){
        head = new_clock_node;
        new_clock_node->next = head;
        clock_hand = head;          //hand starts here
    }
    else{
        struct clock *tmp_node = head;
        while( tmp_node->next != head)
            tmp_node = tmp_node->next;
        tmp_node->next = new_clock_node;
        new_clock_node->next = head;
    }

    return head;
}

//pre: clock_hand is passed
//post: sets new clock_hand psotion
struct clock *advance_clock_hand(struct clock *current_hand){
    //check to see if page is eligeble for evictrion;
    if(current_hand->row_in_mem->u == false){
        current_hand->row_in_mem->v = false;
        return current_hand;
    }
    
    current_hand->row_in_mem->u = false;
    return advance_clock_hand(current_hand->next);
}


void clean_clock(){
    struct clock *current = head->next;

    while(current != head){
        struct clock *next = current->next;
        free(current);
        current = next;
    }

    free(head);
}
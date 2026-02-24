#include <bits/stdc++.h>
#include "p3.h"

#define NUM_JOBS 5

// int main(void){ 
//     Job* ready = nullptr;
//     Job* blocked = nullptr;

//     ready = addToReady(ready, "sree", 30, 10);
//     addToReady(ready, "nate", 10, 20);
//     addToReady(ready, "syd", 10, 10);

//     ready = blockFrontJob(ready, blocked);

//     std::cout << ready->name << " " << ready->next->name << " " << blocked->name << std::endl;

//     return 0; 
// }

// function to find a job, 0 for prev, 1 for next
Job* findJob(Job* head){

    Job* temp = head; 
    if(head == nullptr){
        temp = new Job(); 
        temp->next = nullptr; 
        return temp;
    }

    while(temp->next != nullptr){
        temp = temp -> next; 
    }

    Job* node = new Job();
    node->next = nullptr;

    temp->next = node; 

    return node;
}

Job* findTail(Job* head){
    if (head == nullptr){return nullptr;}

    Job* tail = head; 
    while(tail->next != nullptr){
        tail = tail -> next; 
    }

    return tail; 
}

// Jobs can be added to the Ready list at the back of the list
Job* addToReady(Job* ready, const char name[], int cpuTime, int ioTime){

    // Add new job to the back of the list
    Job* temp = findJob(ready);
    for(int i = 0; i < 16; i++){
        if(name[i] == '\0') {
            temp->name[i] = '\0';
            break;
        }
        temp->name[i] = name[i];
    } 
    temp->cpuLeft = cpuTime;
    temp->ioLeft = ioTime;

    // return head pointer (don't update it unless the head is nullptr)
    return (ready == nullptr) ? temp : ready;
}

// If a job requests I/O, it is removed from the front of the Ready list and moved to the Blocked list. 
Job* blockFrontJob(Job* ready, Job*& blocked){

    Job* temp_r = ready;
    Job* temp_b = findTail(blocked); // find the previous blocked job // most recent
    // return nullptr if ready is nullptr
    if(ready == nullptr){return nullptr;}

    Job* moved = temp_r; // save the old head (NODE TO BE MOVED)
    Job* new_head = temp_r->next;  // save the new head
    moved->next = nullptr; 

    // attach node from Ready List to Blocked List
    if(temp_b == nullptr){
        blocked = moved;
    }
    else{
        temp_b->next = moved;
    }

    // return the new head
    return new_head; 
}

// Function to Simulate 1 time unit
Job* tick(Job* ready, Job*& blocked){


    if(ready != nullptr){
     
        // decrement CPU time of front job of ready list (assume ready is the head pointer)
        (ready->cpuLeft)--;

        // if the time is 0 then remove it from the list
        if(ready->cpuLeft <= 0){
            Job* toDelete = ready; 
            ready = ready->next; // update head pointer
            delete toDelete; // need to deallocated completed job
        }
    }
    Job* temp_b = blocked, *prev_temp_b = nullptr;
    Job* to_add = blocked;
    while(temp_b != nullptr){
        (temp_b -> ioLeft)--;
        if(temp_b -> ioLeft <= 0){
            Job* to_add = temp_b; 

            if(prev_temp_b == nullptr){
                // if the value to add to ready is the head, update head and temp_b;
                blocked = temp_b->next;
                temp_b = blocked;
            }
            else{
                // else relink the list like normal
                prev_temp_b -> next = temp_b -> next; 
                temp_b = prev_temp_b -> next; 
            }
            
            ready = addToReady(ready, to_add->name, to_add->cpuLeft, to_add->ioLeft);
            delete to_add;
        }
        else{
            prev_temp_b = temp_b;
            temp_b = temp_b -> next;
        }
        
    }
        
    return ready; // return head pointer
}

int totalCpuTime(Job* ready, Job* blocked){
      // find the total cpu time by traversing both linked lists and adding time
    Job* temp_r = ready, *temp_b = blocked; 
    int time = 0; 
    while(temp_r != nullptr){
        time += temp_r->cpuLeft;
        temp_r = temp_r->next;
    }
    while(temp_b != nullptr){
        time += temp_b->cpuLeft;
        temp_b = temp_b -> next;
    }

    return time;
}

int countJobs(Job* ready, Job* blocked){
    int jobs = 0;

    Job* temp_r = ready, *temp_b = blocked;
    while(temp_r != nullptr){
        jobs++;
        temp_r = temp_r->next;
    }
        
    while(temp_b != nullptr){
        jobs++;
        temp_b = temp_b -> next;
    }
    return jobs;
}


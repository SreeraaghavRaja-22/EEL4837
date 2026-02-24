#include <bits/stdc++.h>
#include "p3.h"

#define NUM_JOBS 5

int main(void){ 
    return 0; 
}

// function to find a job, 0 for prev, 1 for next
Job* findJob(Job* ready, bool temp_w){
    if(ready == nullptr){return ready;}

    Job* temp, *prev_temp; 
    temp = ready; 
    prev_temp = ready; 

    do{
        prev_temp = temp;
        temp = temp->next;
    }while(temp != nullptr);

    if(!temp_w)
        return prev_temp;
    else
        return temp;
}

// Jobs can be added to the Ready list at the back of the list
Job* addToReady(Job* ready, const char name[], int cpuTime, int ioTime){

    // Add new job to the back of the list
    Job* temp = findJob(ready, 1);
    for(int i = 0; i < sizeof(name) / sizeof(char); i++){
        temp->name[i] = name[i];
    } 
    temp->cpuLeft = cpuTime;
    temp->ioLeft = ioTime;

    // update head pointer 
    temp = ready; 
    temp = temp->next; 
    return temp;
}

// If a job requests I/O, it is removed from the front of the Ready list and moved to the Blocked list. 
Job* blockFrontJob(Job* ready, Job*& blocked){
    Job* temp_r = findJob(ready, 1);
    Job* temp_b = findJob(blocked, 0);
    Job* prev_temp_r = findJob(ready, 0);

    // relink the nodes of the Ready List
    prev_temp_r -> next = temp_r -> next;

    // attach node from Ready List to Blocked List
    if(temp_b == nullptr){temp_b = temp_r;}
    else{temp_b -> next = temp_r;}
     
    // return the job that was just added 
    return temp_r; 
}

// Function to Simulate 1 time unit
Job* tick(Job* ready, Job*& blocked){

    // decrement CPU time of front job of ready list (assume ready is the head pointer)
    --(ready -> cpuLeft);

    // if the time is 0 then remove it from the list
    if(ready->cpuLeft == 0){
        Job* toDelete = ready; 
        ready = ready->next;
        delete toDelete; // need to deallocated completed job, but update head pointer first
    }

    Job* temp_b = blocked, *prev_temp_b = blocked;
    Job* to_add = blocked;
    do{
        --(temp_b -> ioLeft);
        prev_temp_b = temp_b;
        if(temp_b -> ioLeft == 0){
            prev_temp_b -> next = temp_b -> next; // relink 
            to_add = temp_b;
            addToReady(ready, to_add -> name, to_add -> cpuLeft, to_add -> ioLeft);
        }
        temp_b = temp_b -> next;
    }while(temp_b != nullptr);
    

}

int totalCpuTime(Job* ready, Job* blocked){
    // Error Codes (will edit later)
    if(ready == nullptr){return -1;}
    if(blocked == nullptr){return -2;}

    // find the total cpu time by traversing both linked lists and adding time
    Job* temp_r = ready, *temp_b = blocked; 
    int time = 0; 
    do{
        time += temp_r->cpuLeft;
        temp_r = temp_r->next;
    }while(temp_r != nullptr);

    do{
        time += temp_b->cpuLeft;
        temp_b = temp_b -> next;
    }while(temp_b != nullptr);

    return time;
}

int countJobs(Job* ready, Job* blocked){
    // Error codes (will edit later)
    if(ready == nullptr){return -1;}
    if(blocked == nullptr){return -2;}

    int jobs = 0;

    Job* temp_r = ready, *temp_b = blocked;
    do{
        jobs++;
        temp_r = temp_r->next;
    }while(temp_r != nullptr);

    do{
        jobs++;
        temp_b = temp_b -> next;
    }while(temp_b != nullptr);

    return jobs;
}


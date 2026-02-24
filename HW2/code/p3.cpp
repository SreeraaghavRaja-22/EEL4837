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

// add 
Job* addToReady(Job* ready, const char name[], int cpuTime, int ioTime){
    Job* temp = findJob(ready, 1);
    for(int i = 0; i < sizeof(name) / sizeof(char); i++){
        temp->name[i] = name[i];
    } 
    temp->cpuLeft = cpuTime;
    temp->ioLeft = ioTime;

    return temp; 
}

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

Job* tick(Job* ready, Job*& blocked){

}

int totalCpuTime(Job* ready, Job* blocked){
    
    if(ready == nullptr){return -1;}
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
    
}

int countJobs(Job* ready, Job* blocked){

}



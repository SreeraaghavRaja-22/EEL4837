#ifndef P3_H
#define P3_H

struct Job{
    char name[16];  // null-terminated string (max 16 characters)
    int cpuLeft;    // remaining CPU time
    int ioLeft;     // remaining I/O time
    Job* next; 
};

Job* addToReady(Job* ready, const char name[], int cpuTime, int ioTime);
Job* blockFrontJob(Job* ready, Job*& blocked);
Job* tick(Job* ready, Job*& blocked);
int totalCpuTime(Job* ready, Job* blocked);
int countJobs(Job* ready, Job* blocked);
Job* findJob(Job* ready, bool temp_w);

#endif /*P3_H*/
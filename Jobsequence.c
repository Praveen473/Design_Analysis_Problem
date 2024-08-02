#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char id;        
    int deadline;   
    int profit;     
} Job;

// Comparison function for qsort, to sort jobs by profit in decreasing order
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;  // Sort in descending order of profit
}
//using bubblesort to sort in descending order of profit
// void bubbleSort(Job jobs[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (jobs[j].profit < jobs[j + 1].profit) {
//                 // Swap the jobs if they are in the wrong order
//                 Job temp = jobs[j];
//                 jobs[j] = jobs[j + 1];
//                 jobs[j + 1] = temp;
//             }
//         }
//     }
// }

// Find the maximum deadline in the jobs array
int findMaxDeadline(Job jobs[], int n) {
    int maxDeadline = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Job sequencing function to maximize total profit
void jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit in decreasing order
    qsort(jobs, n, sizeof(Job), compare);
    //bubbleSort(jobs, n);
    int maxDeadline = findMaxDeadline(jobs, n);

    int result[maxDeadline];

    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1;
    }

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            // Free slot found
            if (result[j] == -1) {
                result[j] = i;  // Assign job i to this slot
                break;
            }
        }
    }

    // Print the result
    printf("Scheduled jobs for maximum profit:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("Job ID: %c, Deadline: %d, Profit: %d\n",
                   jobs[result[i]].id, jobs[result[i]].deadline, jobs[result[i]].profit);
        }
    }
}

int main() {
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter job ID, deadline, and profit for job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit); 
    }
    jobSequencing(jobs, n);

    return 0;
}

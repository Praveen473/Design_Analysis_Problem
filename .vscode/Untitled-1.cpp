#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Job structure
typedef struct {
    int id;        // Job ID
    int deadline;  // Job deadline
    int profit;    // Job profit
} Job;

// Comparison function for qsort, to sort jobs by profit in decreasing order
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;  // Sort in descending order of profit
}

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

    // Find the maximum deadline to determine the size of the result array
    int maxDeadline = findMaxDeadline(jobs, n);

    // Create an array to store the result of job sequencing
    // Initialize all slots to -1 indicating that they are free
    int result[maxDeadline];
    bool slot[maxDeadline];

    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1;
    }

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            // Free slot found
            if (result[j]==-1) {
                result[j] = i;  // Assign job i to this slot
                //slot[j] = true; // Mark this slot as occupied
                break;
            }
        }
    }

    // Print the result
    printf("Scheduled jobs for maximum profit:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i]!=-1) {
            printf("Job ID: %d, Deadline: %d, Profit: %d\n",
                   jobs[result[i]].id, jobs[result[i]].deadline, jobs[result[i]].profit);
        }
    }
}

int main() {
    // Example jobs
    Job jobs[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}

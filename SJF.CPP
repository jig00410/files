#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// Process structure to hold details about each process
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

// Function to calculate waiting and turnaround times for FCFS
void fcfs(Process processes[], int n) {
    int i;
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    // Calculate waiting time and turnaround time
    for (i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].completion_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // Calculate completion time
    for (i = 0; i < n; i++) {
        processes[i].completion_time = processes[i].arrival_time + processes[i].waiting_time + processes[i].burst_time;
    }
}

// Function to calculate waiting and turnaround times for SJF
void sjf(Process processes[], int n) {
    int i, j, temp;
    Process temp_process;
    
    // Sorting processes based on burst time (Shortest Job First)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                temp_process = processes[i];
                processes[i] = processes[j];
                processes[j] = temp_process;
            }
        }
    }

    // Calculate waiting time and turnaround time for SJF
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].completion_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // Calculate completion time for SJF
    for (i = 0; i < n; i++) {
        processes[i].completion_time = processes[i].arrival_time + processes[i].waiting_time + processes[i].burst_time;
    }
}

// Function to print results of both FCFS and SJF
void printResults(Process processes[], int n) {
    int i;
    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f", total_turnaround_time / n);
}

int main() {
    int n, i, choice;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[MAX_PROCESSES];

    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("\nEnter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    do {
        printf("\nScheduling Algorithms:\n");
        printf("1. FCFS\n2. SJF\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fcfs(processes, n);
                printResults(processes, n);
                break;
            case 2:
                sjf(processes, n);
                printResults(processes, n);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

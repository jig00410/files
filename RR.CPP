#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// Process structure to hold details about each process
typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void roundRobin(Process processes[], int n, int time_quantum) {
    int i, total_time = 0;
    int completed = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time <= time_quantum) {
                    total_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = total_time;
                    processes[i].turnaround_time = processes[i].completion_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    completed++;
                } else {
                    total_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                }
            }
        }
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f", total_turnaround_time / n);
}

int main() {
    int n, i, time_quantum, choice;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[MAX_PROCESSES];

    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("\nEnter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &time_quantum);

    do {
        printf("\nScheduling Algorithms:\n");
        printf("1. Round Robin\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                roundRobin(processes, n, time_quantum);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 2);

    return 0;
}

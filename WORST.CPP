#include <stdio.h>

#define MAX_PARTITIONS 50
#define MAX_PROCESSES 50

void firstFit(int partitions[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES];
    int i, j;

    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    for (i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d (Size %d) -> Partition %d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("Process %d (Size %d) -> Not Allocated\n", i + 1, processes[i]);
    }
}

void bestFit(int partitions[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES];
    int i, j, bestIdx;

    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (i = 0; i < n; i++) {
        bestIdx = -1;
        for (j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                if (bestIdx == -1 || partitions[j] < partitions[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            partitions[bestIdx] -= processes[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    for (i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d (Size %d) -> Partition %d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("Process %d (Size %d) -> Not Allocated\n", i + 1, processes[i]);
    }
}

void worstFit(int partitions[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES];
    int i, j, worstIdx;

    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (i = 0; i < n; i++) {
        worstIdx = -1;
        for (j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                if (worstIdx == -1 || partitions[j] > partitions[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            partitions[worstIdx] -= processes[i];
        }
    }

    printf("\nWorst Fit Allocation:\n");
    for (i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d (Size %d) -> Partition %d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("Process %d (Size %d) -> Not Allocated\n", i + 1, processes[i]);
    }
}

void copyArray(int src[], int dest[], int n) {
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int partitions[MAX_PARTITIONS], processes[MAX_PROCESSES];
    int n, m, choice;
    int originalPartitions[MAX_PARTITIONS];
    int i;

    printf("Enter number of memory partitions: ");
    scanf("%d", &m);

    printf("Enter sizes of partitions:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &partitions[i]);
        originalPartitions[i] = partitions[i]; // Backup
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter sizes of processes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
    }

    do {
        printf("\nMemory Allocation Algorithms:\n");
        printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        copyArray(originalPartitions, partitions, m);  // Reset memory blocks

        switch (choice) {
            case 1:
                firstFit(partitions, m, processes, n);
                break;
            case 2:
                bestFit(partitions, m, processes, n);
                break;
            case 3:
                worstFit(partitions, m, processes, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

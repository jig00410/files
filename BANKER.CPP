#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources;
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];

void calculateNeed() {
    int i, j;
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

int isSafe() {
    int i, j;
    int finish[MAX_PROCESSES];
    int work[MAX_RESOURCES];
    int safeSeq[MAX_PROCESSES];
    int count = 0;

    for (i = 0; i < processes; i++) {
        finish[i] = 0;
    }

    for (i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    while (count < processes) {
        int found = 0;
        for (i = 0; i < processes; i++) {
            if (!finish[i]) {
                int canProceed = 1;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canProceed = 0;
                        break;
                    }
                }

                if (canProceed) {
                    for (j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("\nSystem is NOT in a safe state (Deadlock may occur).\n");
            return 0;
        }
    }

    printf("\nSystem is in a SAFE state.\nSafe sequence: ");
    for (i = 0; i < processes; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 1;
}

int main() {
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resource types: ");
    scanf("%d", &resources);

    printf("\nEnter the Allocation Matrix:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter the Maximum Matrix:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("\nEnter the Available Resources:\n");
    for (i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    calculateNeed();
    isSafe();

    return 0;
}

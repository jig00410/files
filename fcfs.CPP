#include <stdio.h>
#include <stdlib.h>

void FCFS(int requests[], int n, int head) {
    int seek_count = 0;
    printf("\nSeek Sequence (FCFS):\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", requests[i]);
        seek_count += abs(head - requests[i]);
        head = requests[i];
    }
    printf("END\nTotal Seek Operations: %d\n", seek_count);
}

void SCAN(int requests[], int n, int head, int disk_size) {
    int seek_count = 0;
    int direction = 1;  // 1 for right, 0 for left
    int i, j;

    // Sort the requests
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (requests[j] > requests[j+1]) {
                int temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }

    // Find position of head in sorted array
    int idx = 0;
    while (idx < n && requests[idx] < head) idx++;

    printf("\nSeek Sequence (SCAN):\n");

    if (direction) {
        for (i = idx; i < n; i++) {
            printf("%d -> ", requests[i]);
            seek_count += abs(head - requests[i]);
            head = requests[i];
        }
        printf("%d -> ", disk_size - 1);
        seek_count += abs(head - (disk_size - 1));
        head = disk_size - 1;

        for (i = idx - 1; i >= 0; i--) {
            printf("%d -> ", requests[i]);
            seek_count += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("END\nTotal Seek Operations: %d\n", seek_count);
}

void CSCAN(int requests[], int n, int head, int disk_size) {
    int seek_count = 0;
    int i, j;

    // Sort the requests
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (requests[j] > requests[j+1]) {
                int temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }

    int idx = 0;
    while (idx < n && requests[idx] < head) idx++;

    printf("\nSeek Sequence (C-SCAN):\n");

    for (i = idx; i < n; i++) {
        printf("%d -> ", requests[i]);
        seek_count += abs(head - requests[i]);
        head = requests[i];
    }

    printf("%d -> ", disk_size - 1);
    seek_count += abs(head - (disk_size - 1));
    head = 0;
    seek_count += disk_size - 1;

    printf("0 -> ");

    for (i = 0; i < idx; i++) {
        printf("%d -> ", requests[i]);
        seek_count += abs(head - requests[i]);
        head = requests[i];
    }

    printf("END\nTotal Seek Operations: %d\n", seek_count);
}

int main() {
    int n, head, disk_size, choice;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    int* requests = (int*)malloc(n * sizeof(int));
    int* temp = (int*)malloc(n * sizeof(int));

    if (!requests || !temp) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the disk request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &disk_size);

    do {
        printf("\nDisk Scheduling Algorithms:\n");
        printf("1. FCFS\n2. SCAN\n3. C-SCAN\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Copy original requests into temp
        for (int i = 0; i < n; i++)
            temp[i] = requests[i];

        switch (choice) {
            case 1:
                FCFS(temp, n, head);
                break;
            case 2:
                SCAN(temp, n, head, disk_size);
                break;
            case 3:
                CSCAN(temp, n, head, disk_size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    // Free allocated memory
    free(requests);
    free(temp);

    return 0;
}

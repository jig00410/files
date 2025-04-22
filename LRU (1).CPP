#include <stdio.h>
#include <stdlib.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    int i;
    for (i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

void FIFO(int pages[], int n, int capacity) {
    int *frames = (int *)malloc(capacity * sizeof(int));
    int front = 0, rear = 0, count = 0, page_faults = 0;
    int i, j, found;

    for (i = 0; i < capacity; i++) frames[i] = -1;

    printf("\nFIFO Page Replacement:\n");

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[rear] = pages[i];
            rear = (rear + 1) % capacity;
            if (count < capacity) count++;
            page_faults++;
        }

        printf("Frames: ");
        for (j = 0; j < count; j++)
            printf("%d ", frames[j]);
        if (!found) printf(" (Page Fault)");
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
    free(frames);
}

void LRU(int pages[], int n, int capacity) {
    int *frames = (int *)malloc(capacity * sizeof(int));
    int *time = (int *)malloc(capacity * sizeof(int));
    int counter = 0, page_faults = 0;
    int i, j, found, pos;

    for (i = 0; i < capacity; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement:\n");

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = counter++;
                break;
            }
        }

        if (!found) {
            if (i < capacity) {
                pos = i;
            } else {
                pos = findLRU(time, capacity);
            }
            frames[pos] = pages[i];
            time[pos] = counter++;
            page_faults++;
        }

        printf("Frames: ");
        for (j = 0; j < capacity; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
        }
        if (!found) printf(" (Page Fault)");
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
    free(frames);
    free(time);
}

int main() {
    int n, capacity, choice;
    int i;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int *pages = (int *)malloc(n * sizeof(int));
    if (!pages) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    do {
        printf("\nPage Replacement Algorithms:\n");
        printf("1. FIFO\n2. LRU\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                FIFO(pages, n, capacity);
                break;
            case 2:
                LRU(pages, n, capacity);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    free(pages);
    return 0;
}

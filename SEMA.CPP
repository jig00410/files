#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5
#define TRUE 1

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

int mutex = 1;        // Controls access to critical section
int full = 0;         // Counts number of full slots
int empty = BUFFER_SIZE; // Counts number of empty slots

// Semaphore wait
int wait(int s) {
    return --s;
}

// Semaphore signal
int signal(int s) {
    return ++s;
}

void producer() {
    int item;
    if ((mutex == 1) && (empty != 0)) {
        mutex = wait(mutex);
        full = signal(full);
        empty = wait(empty);

        item = rand() % 100; // Random item
        buffer[in] = item;
        printf("Producer produced item: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        mutex = signal(mutex);
    } else {
        printf("Buffer is full! Producer is waiting...\n");
    }
}

void consumer() {
    int item;
    if ((mutex == 1) && (full != 0)) {
        mutex = wait(mutex);
        full = wait(full);
        empty = signal(empty);

        item = buffer[out];
        printf("Consumer consumed item: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        mutex = signal(mutex);
    } else {
        printf("Buffer is empty! Consumer is waiting...\n");
    }
}

int main() {
    int choice;
    int i;  // Declared once and reused

    printf("Producer-Consumer Problem using Semaphores\n");

    while (TRUE) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

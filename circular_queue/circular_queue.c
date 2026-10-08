#include "circular_queue.h"

CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

bool isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

bool isFull(CircularQueue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    queue->size++;
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;

    if (queue->size == 0) {
        queue->front = 0;
        queue->rear = -1;
    }

    return value;
}

int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % MAX_SIZE;
        printf("%d ", queue->items[index]);
    }
    printf("\n");
}

void freeQueue(CircularQueue* queue) {
    free(queue);
}
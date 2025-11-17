#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

Node* new_node(void* data, size_t data_size) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = malloc(data_size);
    if (!node->data) {
        free(node);
        printf("Memory allocation failed\n");
        exit(1);
    }

    memcpy(node->data, data, data_size);
    node->next = NULL;
    return node;
}

typedef struct {
    struct Node* head;
    int size;
    size_t data_size;
} Queue;

Queue* new_queue(size_t data_size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    queue->head = NULL;
    queue->size = 0;
    queue->data_size = data_size;
    return queue;
}

void enqueue(Queue* queue, void* data);
void* dequeue(Queue* queue);
bool is_empty(Queue* queue);
int length(Queue* queue);
void print_queue(Queue* queue);
void free_queue(Queue* queue);

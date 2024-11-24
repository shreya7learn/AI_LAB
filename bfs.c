#include <stdio.h>
#define max_v 100

struct Queue {
    int data[max_v];
    int front;
    int rear;
};

void ini_queue(struct Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isEmpty(struct Queue *queue) {
    return queue->front > queue->rear;
}

void enqueue(struct Queue *queue, int vertex) {
    if (queue->rear >= max_v - 1) {
        printf("Queue overflow\n");
        return;
    }
    queue->data[++queue->rear] = vertex;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1; // Error value
    }
    return queue->data[queue->front++];
}

void bfs(int start, int matrix[max_v][max_v], int visited[], int n) {
    struct Queue queue;
    ini_queue(&queue);
    enqueue(&queue, start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (!isEmpty(&queue)) {
        int vertex = dequeue(&queue);
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (matrix[vertex][i] && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 6;

    int matrix[max_v][max_v] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    int visited[max_v];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int start = 0;

    printf("BFS for the given matrix:\n");
    bfs(start, matrix, visited, n);

    return 0;
}

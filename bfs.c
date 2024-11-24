#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct queue {
    int items[MAX];
    int front;
    int rear;
};

struct queue* createqueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q) {
    int item;
    if (q->front == -1) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
    }
    return item;
}

struct matrixgraph {
    int vertices;
    int matrix[MAX][MAX];
};

void matrixgraph(struct matrixgraph* graph, int ver) {
    graph->vertices = ver;
    for (int i = 0; i < ver; i++) {
        for (int j = 0; j < ver; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}

void bfsMatrix(struct matrixgraph* graph, int startV) {
    int visited[MAX] = {0};
    struct queue* q = createqueue();

    visited[startV] = 1;
    enqueue(q, startV);

    while (q->front != -1) {
        int currentV = dequeue(q);
        printf("%d ", currentV);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->matrix[currentV][i] == 1 && !visited[i]) {
                enqueue(q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    struct matrixgraph Matrix;
    matrixgraph(&Matrix, 6);

    int adj_Matrix[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            Matrix.matrix[i][j] = adj_Matrix[i][j];
        }
    }

    int startV;
    printf("Enter the starting vertex: ");
    scanf("%d", &startV);

    printf("BFS traversal using adjacency matrix: ");
    bfsMatrix(&Matrix, startV);

    return 0;
}

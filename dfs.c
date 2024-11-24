
#include <stdio.h>
#include <stdlib.h>

#define Max_v 100

struct Stack {
    int data[Max_v];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

void push(struct Stack *stack, int vertex) {
    stack->data[++stack->top] = vertex;
}

int pop(struct Stack *stack) {
    return stack->data[stack->top--];
}

void dfsMatrixNonRecursive(int start, int adjacency_matrix[][Max_v], int visited[], int n) {
    struct Stack stack;
    initializeStack(&stack);
    push(&stack, start);
    visited[start] = 1;

    while (!isEmpty(&stack)) {
        int vertex = pop(&stack);
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (adjacency_matrix[vertex][i] && !visited[i]) {
                push(&stack, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adjacency_matrix[Max_v][Max_v]={
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };
   
    int visited[Max_v];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int startingVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startingVertex);
    printf("DFS using Adjacency matrix: ");
    dfsMatrixNonRecursive(startingVertex, adjacency_matrix, visited, n);

    return 0;
}

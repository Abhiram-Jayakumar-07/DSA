#include <stdio.h>
#include <stdlib.h>

struct edgetag {
    int vertex;
    struct edgetag *next;
};

struct graphtag {
    int vertex;
    struct edgetag *start;
};

void initialize(struct graphtag graph[], int n) {
    for (int i = 0; i < n; i++) {
        graph[i].vertex = i;
        graph[i].start = NULL;
    }
}

void addEdge(struct graphtag graph[], int u, int v) {
    struct edgetag *newNode = malloc(sizeof(struct edgetag));
    newNode->vertex = v;
    newNode->next = graph[u].start;
    graph[u].start = newNode;

    newNode = malloc(sizeof(struct edgetag));
    newNode->vertex = u;
    newNode->next = graph[v].start;
    graph[v].start = newNode;
}

void deleteEdge(struct graphtag graph[], int u, int v) {
    struct edgetag *temp = graph[u].start;
    struct edgetag *prev = NULL;
    while (temp) {
        if (temp->vertex == v) {
            if (prev == NULL)
                graph[u].start = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    temp = graph[v].start;
    prev = NULL;
    while (temp) {
        if (temp->vertex == u) {
            if (prev == NULL)
                graph[v].start = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printGraph(struct graphtag graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        struct edgetag *node = graph[i].start;
        while (node != NULL) {
            printf("%d ", node->vertex);
            node = node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n = 5;
    struct graphtag graph[n];

    initialize(graph, n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);

    deleteEdge(graph, 0, 2);

    printGraph(graph, n);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct QNode {
    Point point;
    struct QNode *next;
} QNode, *QNodePtr;

typedef struct Queue {
    QNodePtr front, rear; 
    int size;
} LinkQueue;

int InitQueue(LinkQueue *que)
{
    que->front = NULL;
    que->rear = NULL;
    que->size = 0;
    return 0;
}
int EnQueue(LinkQueue *que, Point point)
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->point.x = point.x;
    p->point.y = point.y;
    p->next = NULL;
    que->size++;

    if (que->front == NULL) {
        que->rear = p;
        que->front = que->rear;
        return 0;
    } else {
        que->rear->next = p;
        que->rear = p;
        return 0;
    }
}

int QueueEmpty(LinkQueue *que)
{
    if(que->front == NULL) {
        return 1;
    }
    return 0;
}

int DeQueue(LinkQueue *que, Point *point)
{
    if (QueueEmpty(que)) {
        return -1;
    }
    QNodePtr p = que->front;
    que->front = que->front->next;
    point->x = p->point.x;
    point->y = p->point.y;
    free(p);

    if (que->front == NULL) {
        que->rear = que->front;
    }
    que->size--;
    return 0;
}

int table[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0, -1}, {0, 1}, {1,-1}, {1,0}, {1,1} };

int shortestPathBinaryMatrix(int grid[][3], int gridSize) {
	if (grid == NULL || gridSize == 0) {
		return 0;
	}
    if (gridSize == 1 && grid[0][0] == 0) {
        return 1;
    }
	if (grid[0][0] || grid[gridSize - 1][gridSize - 1]) {
		return -1;
	}
    LinkQueue que;
    InitQueue(&que);
    Point point = {0, 0};
    EnQueue(&que, point);
    grid[0][0] = 1;
    int path = 1;
    while (!QueueEmpty(&que)) {
        path++;
        int size = que.size;
        while (size--) {
            DeQueue(&que, &point);
            int i;
            for (i = 0; i < 8; i++) {
                int x = point.x + table[i][0];
                int y = point.y + table[i][1];
                if (x == gridSize - 1 && y == gridSize - 1) {
                    return path;
                }
                if (x < 0 || x >= gridSize || y < 0 || y >= gridSize) {
                    continue;
                }
                if (grid[x][y] == 1) {
                    continue;
                }
                grid[x][y] = 1;
                Point cur = {x, y};
                EnQueue(&que, cur);
            }
        }
    }
    return -1;
}
int main()
{
    int grid[3][3] = {{0,0,0}, {1,1,0,}, {1, 1, 0}};
    printf("%d", shortestPathBinaryMatrix(grid, 3));
}
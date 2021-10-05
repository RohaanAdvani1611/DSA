typedef struct queue {
    int front, rear, size;
    int *Q;
}queue;

void initq(queue *q, int len);
int isFullq(queue q);
int isEmptyq(queue q);
void enqueue(queue *q, int item);
int dequeue(queue *q);
void printq(queue q);
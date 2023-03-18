#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    float data[MAX_SIZE];
    int front;
    int rear;
    int size;
    float sum;
} Queue;

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->sum = 0.0f;
}

float enqueue(Queue* q, float value) {
    if (q->size == MAX_SIZE) {
        printf("queue is full %f\n pop front element", q->data[q->front]);
        q->sum -= q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
    q->sum += value;
    float aveFilter = q->sum / q->size;
    printf("push rear element %f，queue：", value);
    if (q->size == 0) {
        // do othing
    } else {
        int i = q->front;
        int n = 0;
        while (n < q->size) {
            printf("%f ", q->data[i]);
            i = (i + 1) % MAX_SIZE;
            n++;
        }
        printf("\n");
    }
    printf("aveFilter = %f\n", aveFilter);
    return aveFilter;
}

void dequeue(Queue* q) {
    if (q->size == 0) {
        return;
    }
    float value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    q->sum -= value;
    printf("pop front element %f\n", value);
    return;
}

float queue_update(Queue* q, float value) {
    if (q->size == MAX_SIZE) {
        dequeue(q);
    }
    return enqueue(q, value);
}

void auto_test() {
    Queue q;
    init_queue(&q);
    float data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    for (int i = 0; i < 10; i++) {
        queue_update(&q, data[i]);
    }
}

int main() {
    auto_test();
    return 0;
}

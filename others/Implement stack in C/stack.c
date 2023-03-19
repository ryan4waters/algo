#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

bool isEmpty(const Stack* s) {
    return s->top == -1;
}

bool isFull(const Stack* s) {
    return s->top == STACK_SIZE - 1;
}

int push(Stack* s, int item) {
    if (isFull(s)) {
        printf("stack overflow\n");
        return -1;
    }
    s->data[++(s->top)] = item;
    printf("pushed %d into stack: ", item);
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
    return 0;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("stack underflow\n");
        return -1;
    }
    int item = s->data[(s->top)--];
    printf("popped %d from stack: ", item);
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
    return item;
}

int peek(const Stack* s) {
    if (isEmpty(s)) {
        printf("stack underflow\n");
        return -1;
    }
    return s->data[s->top];
}

int main() {
    Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    pop(&s);
    peek(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    return 0;
}

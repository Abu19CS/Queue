#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int front = -1, rear = -1;
int queue[MAX];
void push(int val);
int delete_element();
int peek (void);
void display ();

int main () 
{
    int n, val, temp, i = 0;
    printf ("Enter the capacity :");
    scanf("%d",&n);
    temp = n;
    while (temp--) {
        scanf("%d",&val);
        push(val);
    }
    for (int i = 0; i < n; i++) {
        display ();
    }
}

void push (int value) {
    if (rear == MAX - 1) 
    printf ("\nQueue Overflow");
    else if (front == -1 && rear == -1) {
        front = rear = 0;
    }else {
        rear++;
    }queue[rear] = value;
}

int delete_element () {
    int value;
    if (front == -1) {
        printf ("\nQueue Underflow");
        return -1;
    }
    else {
        value = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }return value;
    }
}

int peek () {
    if (front == -1) {
        printf ("\nQueue is Empty");
        return -1;
    }
    else {
        return queue[front];
    }
}

void display () {
    if (front == -1) {
        printf ("\nQueue is Empty");
        exit (1);
    }
    else {
        printf ("%d ", queue[front]);
        front++;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Qnode {
    int data;
    struct Qnode *next;
};

struct Queue {
    struct Qnode *front;
    struct Qnode *rear;
};

struct Queue *q;
struct Qnode *newNode (int );
struct Queue *create_queue (struct Queue *);
struct Queue *insert_element (struct Queue *, int);
struct Queue *delete_element (struct Queue *);
int peek (struct Queue *);
void display (struct Queue *);

int main () 
{
    int n, value;
    q = create_queue (q);
    printf ("Enter the capacity :");
    scanf ("%d",&n);
    printf ("\nEnter the elements of the queue :\n");
    for (int i = 0; i < n; i++) {
        scanf ("%d",&value);
        q = insert_element(q,value);
    }
    printf ("\nThe elements of the Queue : ");
    for (int i = 1; i <= n; i++) {
        q = delete_element (q);
        //printf ("%d ",q -> front -> data);
    }
    return 0;
}

struct Queue *create_queue (struct Queue *q) {
    q = (struct Queue*)malloc(sizeof (struct Queue));
    q -> front = q -> rear = NULL;
    return q;
}
struct Qnode *newNode (int value) {
    struct Qnode *ptr;
    ptr = (struct Qnode*)malloc(sizeof (struct Qnode));
    ptr -> data = value;
    ptr -> next = NULL;
    return ptr;
}

struct Queue *insert_element (struct Queue *q, int value) {
    struct Qnode *ptr = newNode (value);
    if (q -> front == NULL) {
        q -> front = q -> rear = ptr;
    }
    else {
        q -> rear -> next = ptr;
        q -> rear = ptr;
    }return q;
}

struct Queue *delete_element (struct Queue *q) {
    struct Qnode *ptr = q -> front;
    if (q -> front == NULL) {
        q -> rear = NULL;
        printf ("\nQueue is Empty");
        exit (1);
    }
    else {
        q -> front = q -> front -> next;
        printf ("%d ",ptr -> data);
        free(ptr);
    }return q;
}

int peek (struct Queue *q) {
    struct Qnode *ptr = q -> front;
    int value;
    if (ptr == NULL) {
        printf ("\nNothing present in the queue");
        exit (1);
    }
    else {
        value = ptr -> data;
    }return value;
}

void display (struct Queue *q) {
    struct Qnode *ptr = q -> front;
    if (ptr == NULL) {
        printf ("\nList is Empty");
        exit (1);
    }
    else {
        while (ptr != NULL) {
            printf ("%d ",ptr -> data);
            ptr = ptr -> next;
        }
    }
}
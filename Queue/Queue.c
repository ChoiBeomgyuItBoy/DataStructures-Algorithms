//  ----------- Queue implementation in C -----------

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node; 

Node *head; // Reference to the top of the Queue (first added element)
Node *tail; // Reference to the tail of the Queue (last added element)
Node *previous; 

Node *createNewNode(int value)
{
    Node *newNode = malloc(sizeof(Node));

    newNode -> value = value;
    newNode -> next  = NULL;

    return newNode;
}

void enqueue(int value) // Adds an element to the tail 
{
    Node *current = createNewNode(value);

    if(head == NULL)
    {
        head = current;
        tail = current;
        previous = current;
    }
    else
    {
        previous -> next = current;
        tail = current;
        previous = current;
    }
}

void dequeue() // Removes the first added element (First In First Out)
{
    if(head == NULL) { printf("Queue is empty\n"); return; }

    Node *current = head;

    head = current -> next;

    current = NULL;
    free(current);
}

void printQueue() // Prints the Stack
{
    if(head == NULL) { printf("Queue is empty\n"); return; }

    Node *current = head;

    printf("[ ");

    while(current != NULL)
    {
        printf("%d ", current -> value);
        current  = current -> next;
    }

    printf("]\n");
}

int main()
{
    for(int i = 0; i < 10; i++) // Filling Queue with numbers from 1 to 10
    {
        enqueue(i + 1);
    }

    printf("Initial Queue: " ); printQueue();                                 // Output : [ 1 2 3 4 5 6 7 8 9 10 ]
    printf("Head is: %d / Tail is: %d\n", head -> value, tail -> value);      // Head is: 1            Tail is: 10
                                                                              
    for(int i = 0; i < 6; i++) // Deleting first 6 elements of the Queue
    {
        dequeue();
    }

    printf("\nQueue after dequeing: " ); printQueue();                        // Output : [ 7 8 9 10 ]
    printf("Head is: %d / Tail is: %d\n", head -> value, tail -> value);      // Head is: 7            Tail is: 10

    return 0;
}
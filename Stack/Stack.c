//  ----- Queue implementation in C -----

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int value;
    struct Node *next;
} Node;

Node *top; // Reference to the top of the Stack (last element added to it)

Node *createNewNode(int value) 
{
    Node *newNode = malloc(sizeof(Node));

    newNode -> value = value;
    newNode -> next = NULL;

    return newNode;
}

void push(int value) // Adds the element to the top 
{
    Node *current = createNewNode(value);

    if(top == NULL)
    {
        top = current;
    }
    else
    {
        current -> next = top;
        top = current;
    }
}

void pop() // Removes the last added element 
{
    if(top == NULL) { printf("Stack is empty\n"); return; }

    Node *current = top;
    top = current -> next;

    current = NULL;
    free(current);
}

void printQueue() // Prints the Stack
{
    if(top == NULL) { printf("Stack is empty\n"); return; }

    Node *current = top;

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
    for(int i = 0; i < 10; i++) // Filling the Stack with values from 1 to 10
    {
        push(i + 1);
    }

    printf("Original Queue: \n");

    printQueue(); // [ 10 9 8 7 6 5 4 3 2 1 ]

    pop(); pop(); // Popping last 2 elements (10 and 9)

    printf("Queue after pop: \n");

    printQueue(); // [ 8 7 6 5 4 3 2 1 ]

    return 0;
}

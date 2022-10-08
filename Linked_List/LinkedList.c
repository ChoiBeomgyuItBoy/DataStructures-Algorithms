//  ----------- Single Linked List implementation in C -----------

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;  
    struct Node *next;
} Node;

Node *top; // Reference to the top of the List
Node *end; // Reference to the end of the List

Node *createNewNode(int value)
{
    Node *newNode = malloc(sizeof(malloc));

    newNode -> value = value;
    newNode -> next = NULL;

    return newNode;
}

void add(int value) // Adds an element to the end of the List
{
    Node *current = createNewNode(value);

    if(top == NULL)
    {
        top = current;
        end = current;
    }
    else
    {
        end -> next = current;
        end = current;
    }
}

void delete(int value) // Deletes the given element
{
    if(top == NULL){ printf("List is empty"); return; }

    Node *current = top;
    Node *previous = NULL;

    while(current != NULL)
    {
        if(current -> value == value)
        {
            if(previous == NULL) // Deleting the head
            {
                top = current -> next;

                current = NULL;
                free(current);

                return;
            }
            else // Deleting any other element
            {
                previous -> next = current -> next;

                if(previous -> next == NULL){ end = previous; } // If the deleted element was the end, pass 
                                                                // that reference to the previous element
                current = NULL;
                free(current);
                
                return;
            }
        }

        previous = current;
        current = current -> next;
    }

    printf("Element not found\n"); return;
}


void printList() // Prints the List
{
    if(top == NULL){ printf("List is empty"); return; }

    Node *current = top;

    printf("[ ");
    while(current != NULL)
    {
        printf("%d ", current -> value);
        current = current -> next;
    }
    printf("] \n");
}

int main()
{
    for(int i = 0; i < 4; i++)  // Filling list with numbers from 1 to 4
    {
        add(i + 1);
    }

    printf("Initial List: \n");

    printList(); printf("Top is : %d / End is %d\n", top -> value, end -> value);   // Output : [ 1 2 3 4 ]
                                                                                    // Top is : 1 / End is : 4                                                                            
    delete(1);
    delete(2);  // Deleting top, end, and middle element of the list
    delete(4);

    printf("\nList after delete: \n");

    printList(); printf("Top is : %d / End is %d\n", top -> value, end -> value);   // Output : [ 3 ]
                                                                                    // Top is : 3 / End is : 3
    return 0;
}

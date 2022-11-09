//  ----------- Single Linked List implementation in C -----------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *top;
Node *end;

Node *CreateNewNode(int data)
{
  Node *newNode = malloc(sizeof(Node));

  newNode -> data = data;
  newNode -> next = NULL;

  return newNode;
}

void AddToEnd(int data)
{
  Node *currentNode = CreateNewNode(data);

  if(top == NULL) 
  {
    top = currentNode;
    end = currentNode;
  }
  else
  {
    end -> next = currentNode;
    end = currentNode;
  }
}

void AddToTop(int data)
{
  Node *currentNode = CreateNewNode(data);

  if(top == NULL)
  {
    top = currentNode;
    end = currentNode;
  }
  else
  {
    currentNode -> next = top;
    top = currentNode;
  }
}

bool Contains(int data)
{
  if(top == NULL) { return false; }

  Node *currentNode = top;

  while(currentNode != NULL)
  {
    if(currentNode -> data == data)
    {
      return true;
    }
    currentNode = currentNode -> next;
  }

  return false;
}

int Pop(int data)
{
  if(top == NULL) { return -1; }

  Node *currentNode = top;
  Node *previousNode = NULL;

  while(currentNode != NULL)
  {
    if(currentNode -> data == data)
    {
      if(previousNode == NULL)
      {
        top = currentNode -> next;
        return currentNode -> data;

        currentNode = NULL;
        free(currentNode);
      }
      else if(currentNode -> next == NULL)
      {
        end = previousNode;
        previousNode -> next = NULL;
        return currentNode -> data;

        currentNode = NULL;
        free(currentNode);        
      }
      else
      {
        previousNode -> next = currentNode -> next;
        return currentNode -> data;

        currentNode = NULL;
        free(currentNode);
      }
    }

    previousNode = currentNode;
    currentNode = currentNode -> next;
  }

  return -1;
}

int GetIndex(int data)
{
  if(top == NULL) { return -1; }

  Node *currentNode = top;
  int cont = 0;

  while(currentNode != NULL)
  {
    if(currentNode -> data == data)
    {
        return cont;
    }

    cont ++;
    currentNode = currentNode -> next;
  }

  return -1;
}

int GetSize()
{
  if(top == NULL) { return 0; }
  
  Node *currentNode = top;
  int cont = 0;

  while(currentNode != NULL)
  {
    cont++;
    currentNode = currentNode -> next;
  }

  return cont;
}

void Insert(int index, int data)
{
  if(index > GetSize()) { return; }

  Node *nodeToInsert = CreateNewNode(data);
  Node *currentNode = top;
  Node *previousNode = NULL;
  int i = 0;

  while(i <= index)
  {
    if(i == index)
    {
      if(previousNode == NULL)
      {
        nodeToInsert -> next = top;
        top = nodeToInsert;
        return;
      }
      else
      {
        previousNode -> next = nodeToInsert;
        nodeToInsert -> next = currentNode;
        return;
      }
    }

    i++;
    previousNode = currentNode;
    currentNode = currentNode -> next;
  }
}

int GetTop()
{
  if(top == NULL) { return -1; }
  
  return top -> data;
}

int GetEnd()
{
  if(top == NULL) { return -1; }
  
  return end -> data;
}

void PrintList()
{
  if(top == NULL) { return; }
  
  Node *currentNode = top;

  while(currentNode != NULL)
  {
      printf("%d\n", currentNode -> data);
      currentNode = currentNode -> next;
  }
}

int main()
{
  AddToEnd(1); AddToEnd(2); AddToEnd(3);
  AddToTop(-1);

  PrintList();
  
  return 0;
}

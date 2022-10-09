using System;

public class Node // Represents each node as an object 
{
  public Object data;
  public Node next;

  public Node(Object data, Node next)
  {
    this.data = data;
    this.next = next;
  }
}

public class LinkedList<T> // Linked List of Generics (any data type)
{
  private Node top;
  public Object Top { get { return top.data; }} // Getter for the top of the list

  private Node end;
  public Object End { get { return end.data; }} // Getter for the end of the list

  public void AddToEnd(T data) // Adds element to the end of the list
  {
    Node current = new Node(data, null);

    if(top == null)
    {
      top = current;
      end = current;
    }
    else
    {
      end.next = current;
      end = current;
    }
  }

  public void AddToTop(T data) // Adds element to the top of the list
  {
    Node current = new Node(data, null);

    if(top == null)
    {
      top = current;
    }
    else
    {
      current.next = top;
      top = current;
    }
  }

  public bool Contains(T data) // Finds element with Linear Search
  {
    Node current = top;

    while(current != null)
    {
      T currentData = (T) current.data; // Casting object data to the data type of this class

      if(IEquatable<T>.Equals(currentData,data)) // Comparing generics with IEquatable
      {
        return true;
      }

      current = current.next;
    }

    return false;
  }

  public T Pop(T data) // Deletes element of the list and returns it
  {
    Node current = top;
    Node previous = null;

    while(current != null) // Finding element with Linear Search
    {
      if(IEquatable<T>.Equals(current.data,data))
      {
        if(previous == null) // Popping head
        {
          top = current.next;
          
          current = null;
          GC.Collect(); // Deleting the object node in the Garbaje Collection
          
          return data;
        }
        else if(current.next == null) // Popping end
        {
          previous.next = current.next;
          end = previous;
          
          current = null;
          GC.Collect(); // Deleting the object node in the Garbaje Collection
          
          return data;
        }
        else //Popping mid element
        {
          previous.next = current.next;
          
          current = null;
          GC.Collect(); // Deleting the object node in the Garbaje Collection
          
          return data;
        }
      }
      previous = current;
      current = current.next;
    }

    throw new Exception("Element not found"); // Throw Exception if element wasn't found
  } 

  public void Print() // Prints the list
  {
    if(top == null){ return; }

    Node current = top;

    Console.Write("[");
    while(current != null)
    {
      Console.Write($" {current.data} ");
      current = current.next;
    }
    Console.WriteLine("]");
  }
}

public class Program
{
  public static void Main()
  {
    //-----------------------------------------TEST-----------------------------------------
    
    LinkedList<int> intList = new LinkedList<int>(); // Instantiation of LinkedList of type int
    //LinkedList<string> stringList = new LinkedList<string>(); if we wanted to work with strings for example

    intList.AddToEnd(1);
    intList.AddToEnd(2);
    intList.AddToEnd(3);
    intList.AddToTop(0);
    intList.AddToTop(-1);

    Console.WriteLine("Initial List: ");
    intList.Print(); 
    Console.WriteLine($"Top: {intList.Top} / End: {intList.End}");
    Console.WriteLine();

    Console.WriteLine("Popping top and end of list...");
    Console.WriteLine();

    int deleted1 = intList.Pop(3); // Popping end of list and saving it in a variable
    int deleted2 = intList.Pop(-1); // Popping top of list and saving it in a variable

    Console.WriteLine("List after pop: ");
    intList.Print();
    Console.WriteLine($"Top: {intList.Top} / End: {intList.End}");
    Console.WriteLine();
    
    Console.WriteLine($"Popped Element 1: {deleted1}");
    Console.WriteLine($"Popped Element 2: {deleted2}");

    /* 
      Output : 
        Initial List: 
        [ -1  0  1  2  3 ]
        Top: -1 / End: 3
    
        Popping top and end of list...
    
        List after pop: 
        [ 0  1  2 ]
        Top: 0 / End: 2
    
        Popped Element 1: 3
        Popped Element 2: -1
    */
  }
}

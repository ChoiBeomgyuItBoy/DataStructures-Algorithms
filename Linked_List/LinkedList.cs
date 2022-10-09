using System;

public class Node 
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
  public Object Top { get { return top.data; } } // Getter for the top of the list

  private Node end;
  public Object End { get { return end.data; } } // Getter for the end of the list

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

  public void Pop(T data) // Deletes element of the list and returns it
  {
    Node current = top;
    Node previous = null;

    while(current != null)
    {
      if(IEquatable<T>.Equals(current.data,data))
      {
        if(previous == null)
        {
          top = current.next;
          
          current = null;
          GC.Collect();
          
          return;
        }
        else if(current.next == null)
        {
          previous.next = current.next;
          end = previous;
          
          current = null;
          GC.Collect();
          
          return;
        }
        else
        {
          previous.next = current.next;
          
          current = null;
          GC.Collect();
          
          return;
        }
      }
      previous = current;
      current = current.next;
    }

    Console.WriteLine("Element not found"); return;
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
    LinkedList<int> intList = new LinkedList<int>(); // Instantiation of LinkedList

    intList.AddToEnd(1);
    intList.AddToEnd(2);
    intList.AddToEnd(3);
    intList.AddToTop(0);
    intList.AddToTop(-1);

    Console.WriteLine("Initial List: ");
    intList.Print(); 
    Console.WriteLine($"Top: {intList.Top} / End: {intList.End}");
    Console.WriteLine();

    intList.Pop(3); // Deleting end of list
    intList.Pop(-1); // Deleting top of list

    Console.WriteLine("List after pop: ");
    intList.Print();
    Console.WriteLine($"Top: {intList.Top} / End: {intList.End}");
  }
}

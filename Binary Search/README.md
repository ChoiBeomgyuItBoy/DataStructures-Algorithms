# Binary Search (Iterative)
 - Binary Search is a searching algorithm for finding an element's position in a sorted array.
 
 - Half of the array is eliminated during each "step".
 
 - Complexity;
    - Time - (O log n) - the algorithm gets better as the collection grows.
    - Space - (O log n)
    
 - Steps: 
    - Begin with the mid element of the whole array as a search key.
    - If the value of the search key is equal to the target then return an index of the search key.
    - Or if the value of the search key is less than the target in the middle of the interval, narrow the interval to the lower half.
    - Otherwise, narrow it to the upper half.
    - Repeatedly check from the second point until the target is found or the interval is empty.

  ![bePceUMnSG-binary_search_gif](https://user-images.githubusercontent.com/113314204/194691707-0e33563c-d4e9-4941-9f84-09a8909ca199.gif)

# Double Ended Queue (Deque)
## Question:
Consider the implementation of a double ended queue (deque) using an array. Write code for:

1. Enqueue
2. Dequeue

---

## Solution: 
> The source code can be found in [deque.c](/Questions_&_Solutions/deque.c)

Since a deque allows us to add and remove items from both ends of the queue, we have to implement four functions:

1. `addFront(int)`
2. `addBack(int)`
3. `removeFront()`
4. `removeBack()` 

### `addFront(int)`

This function is used to add an integer to the front of the deque. This function is more complicated than the `addBack(int)` function due to the fact that we have to shift all of the elements in the original array to the right one space.

The function starts with a check to see if it is possible to add a new item. If it is not possible, the function returns. The algorithm used to do the shifting will not work if there are two or fewer elements in the queue, so we have to move the elements manually if there are two or less. we have to ensure that we insert the new element at index 0 when done shifting. We finish by incrementing the count by 1.
```c
void addFront(int num) {
    if(count == MAX) return;

    if(count > 2) {        
        for(int i = count - 1; i > 0; i--) {
            deque[i] = deque[i - 1];
        }
    } else if(count == 2) {
        deque[2] = deque[1];
        deque[1] = deque[0];
    } else {
        deque[1] = deque[0];
    }

    deque[0] = num; 

    count++;
}
```

### `addBack(int)`

As previously stated, this function is a much simpler version of `addFront(int)` as we do not need to shift any elements.

We still perform the check to see if it is possible to add an item to the deque. We then insert the new item at the end of the list then increment the count.

```c
void addBack(int num) {
    if(count == MAX) return;
    deque[count++] = num;
}
```
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

### `removeFront()`

This function to remove from the front also involves shifting, but this time shifting to the left. We start off by storing the value we want to remove in the `num` variable. We then perform the shifting and then replace the former last element in the deque with a 0. We then return the `num` that we wanted to remove.

```c
int removeFront() {
    if(count == 0) return 0;
    int num = deque[0];
    for(int i = 0; i < count - 1; i++) {
        deque[i] = deque[i + 1];
    }
    deque[--count] = 0;
    return num;
}
```
### `removeBack()`

This function is very similar to the `removeFront()` function, but it doesn't need to implement the shifting algorithm. We start with a check to ensure that there are, in fact, items in the deque, then we remove the last item, decrement the count while replacing the last item with 0, then returning that number.

```c
int removeBack() {
    if(count == 0) return 0;
    int num = deque[count - 1];
    deque[--count] = 0;
    return num;
}
```
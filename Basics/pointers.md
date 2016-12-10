# Pointers

A **pointer **is a variable that stores the location, or address-of, a variable stored in memory. **Dereferencing** a pointer is the term used to describe getting the value stored at the memory address the pointer holds..

There are two important operators that we must understand when using pointers. The first is the value-at-address operator, represented by the `*` symbol. This symbol is used to declare and to dereference pointers. The second operator is the address-of operator represented by the `&` symbol. The address-of operator is used to get the address of a variable. Here are some example of how to use the two operators:

```c
int *ptr; // declare pointer to an integer
int num = 42;

ptr = &num; // get the address-of num


int numCopy = *ptr; // initialize the value of numCopy to be the value-at-address stored in ptr 
```

Another important rule to remember is that the address-of and value-at-address operators cancel each other out. This allows the following two lines to be identical:
```c
int anotherNumCopy = *(&num);
int anotherNumCopy = num;
```

## NULL Pointers, and Uninitialized Pointers

A NULL pointer is a pointer that does not hold a valid memory address due to the fact that it was initialized pointing to memory address `0` or `NULL`.
```c
int *nullPtr = NULL;
// or
int *nullPtr = 0;
```

Uninitialized pointers are pointers that do not yet hold a memory address. If you try to do anything with an uninitialized pointer, you will get a segmentation fault error.
```c
int *uninitializedPtr;
```

## Pointers to Pointers

A pointer to a pointer is one of the more confusing concepts concerning pointers. Let's consider the following example:
```c
int num = 1;
int *ptr = 0;
int **ptrToPtr;
ptr = &num;
ptrToPtr = &ptr;
```

If you've been following the previous examples, then you should be fine with all of the stuff on lines 1, 2, and 4 (if not go back and review the introductory pointers material). Line 3 is the declaration of a pointer to a pointer. The latter pointer must point to an variable of type `int`. Line 5 is where we tell `ptrToPtr` where to point, i.e. we specify the address that it points to. In this case `ptrToPrt` points to `ptr`, which points to `num`.

We can access the value of num using `ptrToPtr`:
```c
int numCopy = **ptrToPtr;
```
Remember, we are using the value-at-address operator to dereference the pointer twice. This means that we first get the value-at-address of `ptrToPtr` which is the address stored in `ptr`. We then get the value-at-address of `ptr` which gives us the value of `num`.

If you're still unsure of what's going on with pointers, try playing with [this example](/Basics/pointers.c).




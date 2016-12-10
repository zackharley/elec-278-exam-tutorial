# Pointers

A **pointer **is a variable that stores the location, or address-of, a variable stored in memory. **Dereferencing** a pointer is the term used to describe getting the value stored at the memory address the pointer holds..

There are two important operators that we must understand when using pointers. The first is the value-at-address operator, represented by the `*` symbol. This symbol is used to declare and to dereference pointers. The second operator is the address-of operator represented by the `&` symbol. The address-of operator is used to get the address of a variable. Here are some example of how to use the two operators:

```c
int *ptr; // declare an integer pointer
int num = 42;

ptr = &num; 

int numCopy = *ptr;
```

If you're still unsure of what's going on here, try running [this example](/Basics/pointers.c).




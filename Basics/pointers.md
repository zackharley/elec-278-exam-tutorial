# Pointers

A **pointer **is a variable that stores the location, or address-of, a variable stored in memory. **Dereferencing** a pointer is the term used to describe getting the value stored at the memory address the pointer holds..

There are two important operators that we must understand when using pointers. The first is the value-at-address operator, represented by the `*` symbol. This symbol is used to declare and to dereference pointers. The second operator is the address-of operator represented by the `&` symbol. The address-of operator is used to get the address of a variable. Here are some example of how to use the two operators:

```c
int *ptr; // declare pointer to an integer
int num = 42;

ptr = &num; // get the address-of num


int numCopy = *ptr; // initialize the value of numCopy to be the value-at-address stored in ptr 
```

Another important rule to remember is that the address-of and value-at-address operators cancel each other out. This allows the following two lines to be identical.
```c
int anotherNumCopy = *(&num);
int anotherNumCopy = num;
```

If you're still unsure of what's going on with pointers, try running [this example](/Basics/pointers.c).




#include <stdio.h>

int main() {
	int *ptr; // declare pointer to an integer
	int num = 42;

	ptr = &num; // get the address-of num

	int numCopy = *ptr; // initialize the value of numCopy to be the value-at-address stored in ptr 

	/**
	 * Let's print all of the value we have so far. To get the value of ptr
	 * we use the value-at-addres operator. They will all display the number 42.
	 */
	printf("*ptr = %d\n", *ptr);
	printf("num = %d\n", num);
	printf("numCopy = %d\n\n", numCopy);


	/**
	 * Let's examine the memory address of the three variables that we've
	 * created. We see that the address stored in `ptr` and the address-of
	 * num are both the same. Keep this in mind. Since numCopy is a new variable,
	 * it has its own address.
	 */
	printf("ptr = %p\n", ptr);
	printf("&num = %p\n", &num);
	printf("&numCopy = %p\n\n", &numCopy);

	/**
	 * NOTE: if we change the value of num, the value-at-address of ptr
	 * will also change because ptr is pointing at the same address as
	 * num. numCopy will retain the value 42 since it wasn't affected.
	 */
	num = 12;
	printf("*ptr = %d\n", *ptr);
	printf("num = %d\n", num);
	printf("numCopy = %d\n\n", numCopy);

	/**
	 * The next two print statements will be identical since the lines initializing
	 * anotherNumCopy do the exact same thing. This is due to the fact that
	 * the address-of operator and the value-at-address operator cancel each other.
	 */
	int anotherNumCopy = *(&num);
	printf("anotherNumCopy = %d\n", anotherNumCopy);

	anotherNumCopy = num;
	printf("anotherNumCopy = %d\n\n", anotherNumCopy);

	int *nullPtr = NULL; // initialize a null pointer
	int *uninitializedPointer;

	/**
	 * Print the addresses of the null and uninitialized pointers. As specified,
	 * the nullPtr points to 0, while the uninitialized pointer points to some
	 * random address in memory (not useful at all).
	 */
	printf("nullPtr=%p\n", (void *)nullPtr);
	printf("uninitializedPointer=%p\n\n", (void *)uninitializedPointer);

	printf("nullPtr=%d\n", nullPtr); // Always 0
	printf("uninitializedPointer=%d\n\n", uninitializedPointer); // WARNING: may cause a segmentation fault

	/**
	 * Declare and initialize a double pointer to an integer
	 */
	int **ptrToPtr;
	ptrToPtr = &ptr;

	/**
	 * Showing the different ways of accesing the address stored in ptrToPtr,
	 * a.k.a. the address-of ptr.
	 */
	printf("ptrToPtr = %p\n", ptrToPtr);
	printf("&ptr = %p\n\n", &ptr);
	// Question: Why does this not work?
	// printf("&&num = %p\n\n", &&num);

	/**
	 * Showing the different ways of accesing the address stored in ptr,
	 * a.k.a. the address-of num.
	 */
	printf("*ptrToPtr = %p\n", *ptrToPtr);
	printf("ptr = %p\n", ptr);
	printf("&num = %p\n\n", &num);

	/**
	 * Showing the different ways of accesing the value stored in num.
	 */
	printf("**ptrToPtr = %d\n", **ptrToPtr);
	printf("*ptr = %d\n", *ptr);
	printf("num = %d\n\n", num);	

	return 0;
}
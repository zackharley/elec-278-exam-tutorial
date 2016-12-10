int *ptr; // declare an integer pointer
int num = 42;

ptr = &num; 

int numCopy = *ptr;

/**
 * Let's examine the memory address of the three variables that we've
 * created.
 */
printf("%04x", ptr);
printf("%04x", &num);
printf("%04x", &numCopy);
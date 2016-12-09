# Hashing
##Question:
Suppose you wanted to take the data in an INI file and build a table in memory to hold the variable names and their current values.  You will want to look up names of variables  in your table and determine the current value associated with that name.  For example, you would look up the string "Language" and the value returned would be "English". Design and implement a hash table that would be useful for this problem.  You may assume that there are never more than 256 names.  You will have to decide on a hash function to convert variable names to indexes. ADDITION – Add code to your insert to determine the number of collisions that have occurred as you entered data into your table.

---

##Solution: 

> The source code can be seen in [hashing.c](hashing.c)

In the question we are given a few key pieces of information that we can take advantage of right from the start. The first is the assumption that there will never be more that 256 variable names (or "keys"). This means that our hash table only needs to hold at most 256 entries. We can define a constant to make use of the maximum size in the code:
```c
#define TABLE_SIZE 256
```
We also need to understand how INI files are structured, which is explored in the next section.

### Loading from the INI file

The first thing we must know, is what the format of the INI file is. INI files are filled with key-value pairs separated by the "=" symbol. 
```ini
key=value
```
The INI file containing our key value pairs is called [hashing.ini](hashing.ini).

When we pull these key-value pairs out of the INI file, we'll need to store them somehow, so we can create a new `struct` to hold them:

```c
typedef struct Pair {
	char *key;
	char *value;
} Pair;
```
Now that we've defined the structure, we can begin to read data from the INI file. We will need to read the file in line-by-line and split the line into a key and a value. After that will use the `insert()` function to add the data pulled from the file to the hash table, but more on that later.

To begin reading from the file, we first need to define a pointer to a file:
```c
FILE *fp;
```
We also need variables to store the buffer for the current line, the key, and the value, respectively:
```c
char str[BUFFER_SIZE];
char *key;
char *value;
```

We can create a pointer to a file using the following code:
```c
fp = fopen(FILENAME, "r");
```

The `fopen` function takes a string that contains the file name and the file permissions (we have specified `"r"` for read) as inputs and returns a pointer to a file. We can then use `fgets` to read the file line-by-line:
```c
while(fgets(str, BUFFER_SIZE, fp) != NULL) {
      key = strtok(str, search);
      value = strtok(NULL, "\n");
      insert(key, value);
  }
```

What the above code does is *tokenize* the string containing the current line. It separates the input string into a key and a value on either side of the "=" symbol. 

Finally, we need to close the input stream:
```c
fclose(fp);
```

### The Hashing Function
When creating a hashing function it is important to understand what the purpose of the hashing function is. The hashing function is meant to take a key and map it to a valid index in the hash table.

The way that I've chosen to implement the hashing function in this case is to generate integer values for each of first three characters in the key. We then multiply those three characters together and use the product mod the size of the hash table, to get a valid index. 

The integer values for the characters are generated using ASCII character values. All of the keys in the INI file contain only lowercase letters. This means that when determining the character values for the first three characters in the key, we only have to worry about the lowercase alphabet ASCII values.

![An ASCII Table](http://www.asciitable.com/index/asciifull.gif)
For example, if we want to generate values for the first three letters in the key `albert`, which is the first key in our INI file, what we have to do is:
```c
int characterValue = character - 'a' + 1;
```
for `'a'`, `'l'`, and `'b'`.

The calculations, performed in the `calculateCharacterValue()` function give:
```c
'a' - 'a' + 1; // 97 - 97 + 1 = 1
'l' - 'a' + 1; // 108 - 97 + 1 = 12
'b' = 'a' + 1; // 98 - 97 + 1 = 2
```

As previously stated, we can then use these character values to find our hash index:
```c
characterValue1 * characterValue2 * characterValue3 % TABLE_SIZE; // 1 * 12 * 2 % 256 = 24
```

The hash function then returns the index which can be used to perform operations on the hash table.

### Inserting into the table

Insertion involves several steps:
1. Create a new Pair and populating it
2. Determine the hash index based off of the key
3. Find the correct index to insert the Pair
4. Insert the pair

To create a new Pair, we follow the same convention as we do for creating a new Node in a linked list or a new Node in a tree, with some minor changes due to the fact that we're storing strings rather than integers:
```c
Pair *pair = (Pair *) malloc(sizeof(Pair));
pair->key = malloc(sizeof(char) * (strlen(key) + 1));
pair->value = malloc(sizeof(char) * (strlen(value) + 1));
strcpy(pair->key, key);
strcpy(pair->value, value);
```
On the first line we initialize a pointer to a new Pair, pointing it to the address of the memory allocated by `malloc`. Lines two and three allocate enough memory to store the key and value supplied to the `insert` function. Lines copy the strings stored at the address of `key` and address of `value` and set the values of `pair->key` and `key->value` to their respective input, thus creating our new Pair.

Using our hash function, we can determine the hash index for our supplied key. We will use a while loop to ensure that we are not overwriting any existing pointers, inserting the pointer to our new pair at the first open index.

```c
int hashIndex = hash(key);

while(hashArray[hashIndex] != NULL && strcmp(hashArray[hashIndex]->key, "") != 0) {
    ++hashIndex;
    hashIndex %= TABLE_SIZE; // wrap around to front of table
}

hashArray[hashIndex] = pair;
```
Also, to answer the addition to the question, we can count the number of collisions by comparing the original hash index to the actual insertion index for each Pair we insert into the hash table, i.e. For `albert`, the hash index would be 24; if we ended up inserting the Pair containing `albert` at index 26, we can say that a collision has occurred because the original index and the insertion index don't match:
```c
int hashIndex = hash(key);
int originalIndex = hashIndex;

...

if(hashIndex != originalIndex) {
    collisions++;
}
```

### Searching
Searching the table for a specific key is a fairly simple process. We start of by determining the hash index for the key we are searching for using our hash function.

Next me 

### Removing from the table

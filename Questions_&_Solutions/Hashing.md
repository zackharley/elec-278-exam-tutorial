# Hashing
##Question:
Suppose you wanted to take the data in an INI file and build a table in memory to hold the variable names and their current values.  You will want to look up names of variables  in your table and determine the current value associated with that name.  For example, you would look up the string "Language" and the value returned would be "English". Design and implement a hash table that would be useful for this problem.  You may assume that there are never more than 256 names.  You will have to decide on a hash function to convert variable names to indexes. ADDITION – Add code to your insert to determine the number of collisions that have occurred as you entered data into your table.

---

##Solution: 

In the question we are given a few key pieces of information that we can take advantage of right from the start. The first is the assumption that there will never be more that 256 variable names (or "keys"). This means that our hash table only needs to hold at most 256 entries. We can define a constant to make use of the maximum size in the code:
```c
#define TABLE_SIZE 256
```

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
Now 

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
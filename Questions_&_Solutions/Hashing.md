# Hashing
**Question:** Suppose you wanted to take the data in an INI file and build a table in memory to hold the variable names and their current values.  You will want to look up names of variables  in your table and determine the current value associated with that name.  For example, you would look up the string "Language" and the value returned would be "English". Design and implement a hash table that would be useful for this problem.  You may assume that there are never more than 256 names.  You will have to decide on a hash function to convert variable names to indexes. ADDITION – Add code to your insert to determine the number of collisions that have occurred as you entered data into your table.

**Solution:** 

The first thing we must know, is what the format of the INI file is. INI files are filled with key-value pairs separated by the "=" symbol. The INI file containing our key value pairs is called [hashing.ini](hashing.ini).










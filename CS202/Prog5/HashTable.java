/* Kunio Comey
 * CS202
 * Program 5
 * HashTable.java
 *
 * This will be a hash table that stores the data optimized for search and
 * retrieve.
 */

package com.company;

public class HashTable extends Util {
    protected List [] array;
    protected int size;

    //Default Constructor
    public HashTable() {
        size = 257;
        array = new List[size];
        int counter = 0;
        init(counter);
    }

    //Helper function to initialize the array with new lists.
    public void init(int counter) {
        if(counter == size) return;
        array[counter] = new List();
        init(++counter);
    }

    //Constructor with an integer passed in to set the table size.
    public HashTable(final int temp) {
        size = temp;
        array = new List[size];
    }

    //Function to insert a data item into the hash table after performing
    //the hash function.
    public void insert(final Data toInsert) {
        String key = toInsert.passTitle();
        int index = hashFunc(key);
        array[index].insert(toInsert);
    }

    //Function to search for a data item in the hash table.
    public void search() {
        System.out.print("\nPlease enter your search for title: ");
        String key = input.nextLine();
        int index = hashFunc(key);
        array[index].search(key);
    }

    //Function to preform a hash function and return an integer value.
    private int hashFunc(final String key) {
        String tempKey = key.toLowerCase();
        int sum = 0;
        for(int i = 0; i < tempKey.length(); ++i) {
            sum += tempKey.charAt(i) * i;
        }
        sum %= size;
        return sum;
    }

    //Display function used for debugging purposes.
    public void display() {
        int index = 0;
        display(index);
    }

    //Display function recursive.
    public void display(int index) {
        if(index == size) return;
        if(array[index].display() != 0)
            System.out.println("\nIndex: " + index);
        display(++index);
    }
}

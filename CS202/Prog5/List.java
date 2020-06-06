//Kunio Comey
//CS202
//Program 5
//List.java

//List class to manage the linked list. This will be held in
//the tree node field as the data.

package com.company;
import java.util.Scanner;
import java.io.*;
public class List {
    protected ListNode head;

    //Default constructor
    public List() {
        head = null;
    }

    //Copy constructor
    public List(final List copy) {
        if(copy.head != null) {
            head = new ListNode(copy.head);
        }
        else head = null;
    }

    //Constructor with a Data passed in.
    public List(final Data temp) {
        head = new ListNode(temp);
    }

    //Function to insert a new ListNode into the list.
    //Will insert at head.
    public void insert(final Data temp) {
        ListNode hold = head;
        head = new ListNode(temp);
        head.setNext(hold);
    }

    //Display function as the wrapper.
    public int display() {
        if(head == null) return 0;
        display(head);
        return 1;
    }

    //Recursive display function
    public void display(ListNode head) {
        if(head == null) return;
        head.display();
        display(head.getNext());
    }

    //Connects the string compare function to the data at the
    //head of the list.
    public int compare(final Data toComp) {
        //Note that this base case should not be invoked since
        //we will have a check to see if head is null in the
        //tree node class. This will be invoked after we check
        //if head is null.
        if(head == null) return 0;
        return head.compare(toComp);
    }

    //Checks the list to see if it is empty.
    public boolean isEmpty() {
        if(head == null) return true;
        return false;
    }

    //Clears the list in case we need to "delete" the data.
    public void clear() {
        head = null;
    }

    //Function to search the list for a matching string value (case does not apply).
    //Need this wrapper so that client can't directly call the recursive method.
    public void search(final String toSearch) {
        if(head == null) {
            System.out.println("\nList is empty...");
            return;
        }
        search(head, toSearch);
    }

    //Recursive function to search for a matching data with the same name.
    private void search(ListNode head, final String toSearch) {
        if(head == null) {
            return;
        }
        if(head.compare(toSearch) == 0) {
            System.out.println("\nMatch found! ");
            head.display();
        }
        search(head.getNext(), toSearch);
    }

    //Writing to an external data file wrapper function.
    public BufferedWriter write(BufferedWriter out) throws IOException{
        if(head == null) return out;
        return write(head, out);
    }

    //Recursive function to write each of the contents of the list node's data.
    private BufferedWriter write(ListNode head, BufferedWriter out) throws IOException{
        if(head == null) return out;
        out = head.write(out);
        return write(head.getNext(), out);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Data temp = new Data();
        List test = new List();
        char again;

        do {
            temp.build();
            test.insert(temp);
            System.out.print("\nAgain? (y/n): ");
            again = input.next().charAt(0);
        } while(again == 'y');

        test.display();
        List copy = new List(test);
        System.out.println("\nCopy list contents:");
        copy.display();

        System.out.println("\nClearing list");
        test.clear();
        test.display();

    }
}

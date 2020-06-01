//Kunio Comey
//CS202
//Program 4
//List.java

//List class to manage the linked list. This will be held in
//the tree node field as the data.

package com.company;
import java.util.Scanner;
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
    public void display() {
        if(head == null) return;
        display(head);
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

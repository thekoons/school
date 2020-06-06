//Kunio Comey
//CS202
//Program 5
//ListNode.java

//Class to represent a List Node for the linear linked list.

package com.company;
public class ListNode extends Data {
    protected ListNode next;

    //Default Constructor
    public ListNode() {
        next = null;
    }

    //Copy Constructor
    public ListNode(final ListNode copy) {
        super(copy);
        if(copy.next != null)
            next = new ListNode(copy.next);
        else next = null;
    }

    //Constructor passing in Data as an argument.
    public ListNode(final Data copy) {
        super(copy);
        next = null;
    }

    //This function will set the next pointer to the ListNode
    //passed in.
    public void setNext(final ListNode temp) {
        next = temp;
    }

    //Get next function to return the next ListNode.
    public ListNode getNext() {
        return next;
    }
}

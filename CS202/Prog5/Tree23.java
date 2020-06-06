/* Kunio Comey
 * CS202
 * Program 5
 * Tree23.java
 *
 * This is the 2-3 Tree for implementing a balanced tree. All of this
 * will be using recursion so that we don't need to have a class tree
 * that contains this. This will act as both the node and the tree itself.
 */

package com.company;
import java.util.Scanner;
import java.io.*;
public class Tree23 {
    protected List [] dat;
    protected Tree23 [] ptr;

    //Default Constructor
    public Tree23() {
        dat = new List[3];
        ptr = new Tree23[4];
        int counter = 0;
        init(counter);
    }

    //Helper function for the default constructor to initialize.
    public void init(int counter) {
        if(counter == 3) return;
        dat[counter] = new List();
        init(++counter);

    }

    //Constructor to create a tree with a list passed in as an argument.
    public Tree23(final List insert) {
        dat = new List[3];
        dat[0] = new List(insert);
        dat[1] = new List();
        dat[2] = new List();
        ptr = new Tree23[4];
    }


    //Wrapper insert function for the client to call.
    public void insert() {
        Data temp = new Data();
        temp.build();
        insert(temp);
        if(isFull()) {
            split();
        }
    }

    //Function to read from an external data file.
    public void read(final Data temp) {
        insert(temp);
        if(isFull()) {
            split();
        }
    }

    //Wrapper function for the display function
    public void display() {
        if(dat[0].isEmpty()) {
            System.out.println("\n2-3 Tree is empty");
            return;
        }

        if(ptr[0] != null) ptr[0].display();
        dat[0].display();

        if(ptr[1] != null) ptr[1].display();
        dat[1].display();

        if(ptr[2] != null) ptr[2].display();
    }

    //Recursive insert function.
    public void insert(final Data temp) {
        //These three if statements will incur a return statement
        //to prevent the recursive call.

        //If this is the first item to be inserted into the
        //tree
        if(dat[0].isEmpty()) {
            dat[0].insert(temp);
            return;
        }

        if(isMatch(temp)) return;

        if(isLeaf()) {
            //Perform insertion here.
            insertHere(temp);
            return;
        }

        //Here compare the data and return the index that we are
        //going to traverse to next.
        int nextIndex = traverseNext(temp);

        //Here have a recursive call to the next child pointer.
        Tree23 child = ptr[nextIndex];
        child.insert(temp);

        //Then check if the child is full from here.
        //      If it is, commence the split function from the child.
        //      Then, commence the merge function to this node. Keep on
        //      using the index used from the traverseNext function to
        //      implement this merge and split.
        if(child.isFull()) {
            child.split();
            merge(nextIndex);
        }

        //Quick note:
        //Checking the child pointer to see if the node is full should always
        //occur on the way back from the recursive call so that we can merge it
        //from there.
    }

    //Function for when we are at a leaf and what to insert the data in the current
    //node.
    private void insertHere(final Data temp) {
        //Using the traverse next function since it does a compare as well.
        int toInsert = traverseNext(temp);

        if(toInsert == 0) {
            dat[2] = dat[1];
            dat[1] = dat[0];
            dat[0] = new List(temp);

            /* Causing bugs.
             * Bugs are caused due to the shared references being cleared.

            dat[0].clear();
            dat[0].insert(temp);
             */
        }

        else if(toInsert == 1) {
            dat[2] = dat[1];
            dat[1] = new List(temp);

            /* Causing bugs
            dat[1].clear();
            dat[1].insert(temp);
             */
        }

        else {
            dat[2] = new List(temp);
            /* Causing bugs
            dat[2].clear();
            dat[2].insert(temp);
             */
        }
    }

    //Function to merge the child node with the current node
    //given the traversed index from the insert function.
    private void merge(int index) {
        if(index == 0) {
            //Setting up the data.
            dat[2] = dat[1];
            dat[1] = dat[0];
            dat[0] = ptr[0].dat[0];

            //Setting up the children.
            ptr[3] = ptr[2];
            ptr[2] = ptr[1];
            ptr[1] = ptr[0].ptr[1];
            ptr[0] = ptr[0].ptr[0];
        }

        else if(index == 1) {
            //Setting up the data.
            dat[2] = dat[1];
            dat[1] = ptr[1].dat[0];

            //Setting up the children.
            ptr[3] = ptr[2];
            ptr[2] = ptr[1].ptr[1];
            ptr[1] = ptr[1].ptr[0];
        }

        else {
            //Setting up the data
            dat[2] = ptr[2].dat[0];

            //Setting up the children
            ptr[3] = ptr[2].ptr[1];
            ptr[2] = ptr[2].ptr[0];
        }
    }

    //Returning the index for where we need to traverse
    //to next.
    private int traverseNext(final Data temp) {
        //If the temp is less than the data in index 0, return 0.
        if(dat[0].compare(temp) > 0) {
            return 0;
        }
        //If the temp is greater than data in index 0 and there is no
        //data in index 1, return 1.
        if(dat[0].compare(temp) < 0 && dat[1].isEmpty()) {
            return 1;
        }
        //If previous cases failed, check if temp is less than index 1
        //to return a 1.
        if(dat[1].compare(temp) > 0) {
            return 1;
        }
        //If temp is the greatest data item, return 2.
        return 2;
    }

    //Wrapper function for the recursive isMatch.
    private boolean isMatch(final Data temp) {
        int counter = 0;
        return isMatch(temp, counter);
    }

    //Checking if the node is a has matches to temp and inserting
    //it there. This function is the recursive implementation started
    //from the wrapper.
    private boolean isMatch(final Data temp, int index) {
        if(index == 3) return false;
        if(dat[index].isEmpty()) return false;
        if(dat[index].compare(temp) == 0) {
            dat[index].insert(temp);
            return true;
        }
        ++index;
        return isMatch(temp, index);
    }

    //Checking if the node is a leaf node.
    private boolean isLeaf() {
        //Just need to check the first child since a node
        //will always need 2 children for it to be a parent.
        if(ptr[0] == null) return true;
        return false;
    }

    //This function will check if the last data slot is filled
    //in order to determine if the node is meant for this spot.
    private boolean isFull() {
        if(!dat[2].isEmpty()) return true;
        return false;
    }

    //Function to split a node, placing its children nodes into the
    //newly created children nodes.
    private void split() {
        //Creating new nodes to place in the left and right.
        Tree23 newLeft = new Tree23(dat[0]);
        Tree23 newRight = new Tree23(dat[2]);

        //Setting the lefts and rights of new nodes to the
        //previous nodes children.
        newLeft.ptr[0] = ptr[0];
        newLeft.ptr[1] = ptr[1];
        newRight.ptr[0] = ptr[2];
        newRight.ptr[1] = ptr[3];

        //Setting up the left and right of this node to the
        //new left and new right nodes.
        ptr[0] = newLeft;
        ptr[1] = newRight;
        ptr[2] = null;
        ptr[3] = null;

        //Setting up the data so the current node only has one
        //data member.
        dat[0] = dat[1];
        dat[1] = new List();
        dat[2] = new List();
    }

    //Writing to external data file using in order traversal.
    public BufferedWriter write(BufferedWriter out) throws IOException{
        //Checking left for null pointer.
        if(ptr[0] != null) {
            //Calling the recursive write function for the left
            //child.
            out = ptr[0].write(out);
        }
        //Writing for the lower portion of this tree node.
        out = dat[0].write(out);

        //Repeating the process for the middle child and the upper
        //data portion for this node.
        if(ptr[1] != null) {
            out = ptr[1].write(out);
        }
        out = dat[1].write(out);

        //Repeating the process for the right child.
        if(ptr[2] != null) {
            out = ptr[2].write(out);
        }

        //Returning the writer back up the stack frames.
        return out;
    }

    public static void main(String[] args) {
        Tree23 tree = new Tree23();
        Scanner input = new Scanner(System.in);
        char again;
        do
        {
            tree.insert();
            System.out.print("\nAgain? (y/n): ");
            again = input.next().charAt(0);

        } while(again == 'y');

        tree.display();
    }
}

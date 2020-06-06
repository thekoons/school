//Kunio Comey
//CS202
//Program 5
//Shopping.java

//This is the derived class dealing with a post specifically dealing with
//shopping.

package com.company;
import java.nio.Buffer;
import java.util.Scanner;
import java.io.*;
public class Shopping extends Post {
    protected String store;
    protected int maxItems;

    //Default constructor.
    public Shopping() {
        store = new String();
        maxItems = 0;
    }

    //Copy constructor function.
    public Shopping(final Shopping copy) {
        super(copy);
        store = new String(copy.store);
        maxItems = copy.maxItems;
    }

    //Read function for kick starting the base class read and
    //the reading in to the fields store and maxItems.
    public void read() {
        super.read();
        System.out.println("\nEnter store name visiting: ");
        store = input.nextLine();
        System.out.println("\nEnter estimated max number items you can ship: ");
        maxItems = input.nextInt();
        input.nextLine();
    }

    public Scanner read(Scanner in) {
        in = super.read(in);
        store = in.nextLine();
        maxItems = in.nextInt();
        in.nextLine();
        return in;
    }

    public BufferedWriter write(BufferedWriter out) throws IOException {
        out = super.write(out);
        out.newLine();
        out.append(store);
        out.newLine();
        out.append(String.valueOf(maxItems));
        return out;
    }

    //Display function for kick starting the base class display and
    //then displaying the store and maxItems fields.
    public void display() {
        super.display();
        System.out.println("Store shopping at: " + store +
                "\nEstimated number of items able to ship: " + maxItems);
    }

    /*
    public static void main(String [] args) {
        Post test = new Shopping();
        test.read();
        test.display();
        Post copy = new Shopping((Shopping) test);
        if(copy.compare(test) == 0)
            System.out.println("\nCompare function works!");
    }
     */
}


//Kunio Comey
//CS202
//Program 4
//Misc.java

//This class will deal with posts that doesn't fit Shopping or Housework
//posts.

package com.company;
import java.util.Scanner;
public class Misc extends Post {
    protected String desc;

    //Default constructor
    public Misc() {
        desc = new String();
    }

    //Copy constructor
    public Misc(final Misc copy) {
        super(copy);
        desc = new String(copy.desc);
    }

    //Function to read the super class fields and the string description.
    public void read() {
        super.read();
        System.out.println("Enter in general description for post: ");
        desc = input.nextLine();
    }

    //Function to display the super class fields and the string description.
    public void display() {
        super.display();
        System.out.println("Description: " + desc);
    }
}

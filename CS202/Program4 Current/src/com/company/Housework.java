//Kunio Comey
//CS202
//Program 4
//Housework.java

//This class will handle a post related to housework.

package com.company;
import java.util.Scanner;
public class Housework extends Post {
    protected String specialty;

    //Default constructor
    public Housework() {
        specialty = new String();
    }

    //Copy Constructor
    public Housework(final Housework copy) {
        super(copy);
        specialty = new String(copy.specialty);
    }

    //Function to read the super class fields and the string specialty.
    public void read() {
        super.read();
        System.out.println("Enter in housework specialty: ");
        specialty = input.nextLine();
    }

    //Function to display the super class fields and the string specialty.
    public void display() {
        super.display();
        System.out.println("Housework specialty: " + specialty);
    }
}

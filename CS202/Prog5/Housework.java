//Kunio Comey
//CS202
//Program 5
//Housework.java

//This class will handle a post related to housework.

package com.company;
import java.util.Scanner;
import java.io.*;
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

    //Function to read in from external data file.
    public Scanner read(Scanner in) {
        in = super.read(in);
        specialty = in.nextLine();
        return in;
    }

    //Function to write to an external data file.
    public BufferedWriter write(BufferedWriter out) throws IOException {
        out = super.write(out);
        out.newLine();
        out.append(specialty);
        return out;
    }

    //Function to display the super class fields and the string specialty.
    public void display() {
        super.display();
        System.out.println("Housework specialty: " + specialty);
    }
}

//Kunio Comey
//CS202
//Program 5
//Data.java

//This class will hold the data for the linked list node and
//deal with RTTI operations.

package com.company;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.Buffer;
import java.util.Scanner;
public class Data extends Util {
    protected Post dat;

    //Default constructor
    public Data() {
        dat = null;
    }

    //Copy constructor using "RTTI" with the instance
    //of operator.
    public Data(final Data copy) {
        if(copy.dat instanceof Shopping) {
            dat = new Shopping((Shopping)copy.dat);
        }
        else if(copy.dat instanceof Housework) {
            dat = new Housework((Housework)copy.dat);
        }
        else if(copy.dat instanceof Misc) {
            dat = new Misc((Misc)copy.dat);
        }
    }

    //Build function for when we want to create the data with
    //user input.
    public void build() {
        //Making a menu interface to read in which object type the
        //user would like to create.
        int choice = 0;
        System.out.print("\nMenu for data: " +
                "\n1\t---\tCreate Shopping Post" +
                "\n2\t---\tCreate Housework Post" +
                "\n3\t---\tCreate Miscellaneous Post" +
                "\nEnter integer choice here (1-3): ");
        //Reading in the user's choice.
        choice = input.nextInt();
        input.nextLine();

        //Having a switch statement to create a specific object based
        //off of the user's choice.
        switch (choice) {
            case 1:
                dat = new Shopping();
                dat.read();
                break;
            case 2:
                dat = new Housework();
                dat.read();
                break;
            case 3:
                dat = new Misc();
                dat.read();
                break;
            //If the user inputs and incorrect value, it will call this
            //function again.
            default:
                System.out.println("\nInvalid input. Try again.");
                build();
                break;
        }
    }

    //Read function with a Post reference passed in.
    public int read(final Post temp) {
        if(temp == null) return 0;

        //Using "RTTI" to copy the contents of temp into dat.
        if(temp instanceof Shopping) {
            dat = new Shopping((Shopping)temp);
        }
        else if(temp instanceof Housework) {
            dat = new Housework((Housework)temp);
        }
        else if(temp instanceof Misc) {
            dat = new Misc((Misc)temp);
        }
        return 1;
    }

    //Read function with a Data object passed in as an
    //argument
    public int read(final Data temp) {
        return read(temp.dat);
    }

    //Write function for external data file dealing with reflection
    //operations to write out the correct integer corresponding to
    //which data type dat is and then calling dat's write function.
    public BufferedWriter write(BufferedWriter out) throws IOException {
        if(dat == null) return out;

        out.newLine();
        if(dat instanceof Shopping) {
            out.append("1");
        }
        else if(dat instanceof Housework) {
            out.append("2");
        }
        else if(dat instanceof Misc) {
            out.append("3");
        }

        return dat.write(out);
    }

    //Function to display the list node data.
    public void display() {
        if(dat != null) dat.display();
    }

    //Function to compare the data passed in to this class's
    //dat field.
    public int compare(final Data temp) {
        return dat.compare(temp.dat);
    }

    //Function to compare the data with a string passed in.
    public int compare(final String temp) {
        return dat.compare(temp);
    }

    //Pass the title back to search function to initiate key value.
    public String passTitle() {
        return dat.passTitle();
    }

    //Function to call its data's
    public Scanner read(Scanner util) {
        return dat.read(util);
    }
}


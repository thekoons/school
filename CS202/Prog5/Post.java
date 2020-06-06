//Kunio Comey
//CS202
//Program 5
//Post.java

//This class will be the base class for the post class hierarchy.

package com.company;
import java.util.Scanner;
import java.io.*;
public abstract class Post extends Util {
    protected String title;
    protected String author;
    protected String phoneNum;
    protected String date;

    //Default constructor
    public Post() {
        title = new String();
        author = new String();
        phoneNum = new String();
        date = new String();
    }

    //"Copy" Constructor
    public Post(final Post copy) {
        title = new String(copy.title);
        author = new String(copy.author);
        phoneNum = new String(copy.phoneNum);
        date = new String(copy.date);
    }

    //Function to read in contents from an external data file.
    public Scanner read(Scanner in) {
        title = in.nextLine();
        author = in.nextLine();
        phoneNum = in.nextLine();
        date = in.nextLine();
        return in;
    }

    //Function to prompt and read in the fields of the class.
    public void read() {
        System.out.println("\nEnter in post title: ");
        title = input.nextLine();
        System.out.println("Enter in author (you) name: ");
        author = input.nextLine();
        System.out.println("Enter phone number here: ");
        phoneNum = input.nextLine();
        System.out.println("Enter in the date: ");
        date = input.nextLine();
    }

    //Function to write to an external data file.
    public BufferedWriter write(BufferedWriter out) throws IOException {
        //Writing all of the fields of the post class to the external data file.
        out.newLine();
        out.append(title);

        out.newLine();
        out.append(author);

        out.newLine();
        out.append(phoneNum);

        out.newLine();
        out.append(date);

        return out;
    }

    //Display function
    public void display() {
        System.out.println("\nTitle: " + title +
                "\nAuthor: " + author +
                "\nPhone number: " + phoneNum +
                "\nDate posted: " + date);
    }

    //Compare function to just return the compare integer value
    //of the titles.
    public int compare(final Post toComp) {
        return this.title.compareToIgnoreCase(toComp.title);
    }

    //Compare function to compare the string value passed in to
    //the title of the post.
    public int compare(final String toComp) {
        return this.title.compareToIgnoreCase(toComp);
    }

    public String passTitle() {
        return title;
    }
}


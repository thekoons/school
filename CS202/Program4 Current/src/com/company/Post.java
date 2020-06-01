//Kunio Comey
//CS202
//Program 4
//Post.java

//This class will be the base class for the post class hierarchy.

package com.company;
import java.util.Scanner;
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
}


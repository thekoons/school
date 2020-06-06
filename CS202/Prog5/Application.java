/* Kunio Comey
 * CS202
 * Program 5
 * Application.java
 *
 * This is the application class that will deal with most of the user
 * interface. It will be a simple terminal menu prompting and reading
 * integers for user choices. Based on these integer values, it will call
 * a specific function to manipulate the program.
 *
 * May need to change the read file path directory. Wasn't sure how to implement
 * and was running out of time.
 *
 * Write function does not exists unfortunately.
 */

package com.company;
import java.io.*;
import java.util.Scanner;
public class Application extends Util{
    protected int userChoice;
    protected Tree23 tree;
    protected HashTable table;

    //Default Constructor which will initialize and then read
    //from an external data file.
    public Application() {
        System.out.println("\nLoading Application");
        userChoice = 0;
        tree = new Tree23();
        table = new HashTable();

        //Try reading from the file, and catch a file not found exception.
        try {
            read();
        }
        catch(FileNotFoundException lost) {
            System.out.println("\nCould not read file... file not found");
        }
    }

    //Menu function to output choices for user to choose from.
    public int menu() throws FileNotFoundException {
        System.out.print("\nWelcome to the Neighbor Helper Program!" +
                "\nHere are your options: " +
                "\n1\t---\tCreate a post" +
                "\n2\t---\tDisplay posts" +
                "\n3\t---\tSearch posts" +
                "\n0\t---\tQuit" +
                "\nEnter your choice here (0-5): ");
        userChoice = input.nextInt(); input.nextLine();
        if(userChoice < 0 || userChoice > 5) {
            menu();
        }

        //Will return the choice in case the user wants to do this again.
        return choices();
    }

    //Having choices prompt and read in the choices.
    public int choices() throws FileNotFoundException {
        Data temp = new Data();

        switch(userChoice) {
            //Choice will exit the program
            case 0:
                System.out.println("\nExiting Program..." +
                        "\n\nGoodbye!");
                break;

            //Will insert a new post into the tree.
            case 1:
                temp.build();
                tree.read(temp);
                table.insert(temp);
                break;

            //Will display the posts from the tree in alphabetical order.
            case 2:
                tree.display();
                break;

            //Function to search the hash table for a matching search term.
            case 3:
                table.search();
                break;

            //Will read from an external data file.
            case 4:
                //Make a read function throughout the hierarchy.
                try {
                    read();
                }
                catch(FileNotFoundException lost) {
                    System.out.println("\nFile not found");
                }
                break;

            //Will write to an external data file.
            case 5:
                //Make a write function throughout the hierarchy.
                System.out.println("\nSorry writing is still being worked on.");
                break;

            //This case shouldn't happen, but just in case it's here.
            default:
                System.out.println("\nSomehow you broke the program...");
        }

        //Returns the user choice in case we need to do this again.
        return userChoice;
    }

    //Application write function to go into the tree and write the contents of
    //tree out to the external data file.
    public void write() throws IOException {
        //Creating the file object connected to the file.txt file.
        File myfile = new File("file.txt");
        FileWriter writer = new FileWriter(myfile);
        BufferedWriter out = new BufferedWriter(writer);

        out.write("Kunio Comey");
        out = tree.write(out);
        out.close();
    }

    //Function to read in the application contents via external text file.
    public void read() throws FileNotFoundException {
        //Not sure how to rework this to allow for reading on a different file ecosystem.
        //File myfile = new File("C:\\Users\\kunio\\IdeaProjects\\school\\CS202\\Program4 Current\\src\\com\\company\\file.txt");
        //File myfile = new File("/home/kunio/IdeaProjects/Program4 Current/src/com/company/file.txt");
        //File myfile = new File("test.txt");

        File myfile = new File("file.txt");
        Post post = null;
        int check = 0;

        //Loop to read through the program.
        Scanner in = new Scanner(myfile);

        //Reading the first line since this will be the name of the external data file.
        in.nextLine();
        while(in.hasNext()) {
            check = in.nextInt();
            in.nextLine();

            //If a one was read, create a new shopping object.
            if(check == 1) {
                post = new Shopping();
                in = post.read(in);
            }

            //If a two was read, create a new housework object.
            else if(check == 2) {
                post = new Housework();
                in = post.read(in);
            }

            //If it was a three, then create a new miscellaneous.
            else {
                post = new Misc();
                in = post.read(in);
            }

            //Creating a temporary data to insert it into the
            //tree and the hashtable.
            Data toInsert = new Data();
            toInsert.read(post);
            tree.read(toInsert);
            table.insert(toInsert);
        }
    }

    //Function that will run the whole program and rerun it if the user chooses
    //to run it again.
    public void run() throws FileNotFoundException {
        //If the user chooses a 0 for user choice, then the class will try to
        //execute a write to an external data file and then return out of the
        //recursive loop.
        if(menu() == 0) {
            //Try catch block in case we have an io exception thrown out of the write
            //function.
            try {
                write();
            }
            catch(IOException brokenWrite) {
                System.out.println("\nIO Exception thrown... Writer not working");
            }
            return;
        }
        //Recursive call to perform this all over again if the user choice is not 0.
        run();
    }

    public static void main(String[] args) throws FileNotFoundException {
        Application myApp = new Application();
        myApp.run();
    }
}

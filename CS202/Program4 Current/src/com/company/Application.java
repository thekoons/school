/* Kunio Comey
 * CS202
 * Program 4
 * Application.java
 *
 * This is the application class that will deal with most of the user
 * interface. It will be a simple terminal menu prompting and reading
 * integers for user choices. Based on these integer values, it will call
 * a specific function to manipulate the program.
 */

package com.company;
public class Application extends Util{
    protected int userChoice;
    protected Tree23 tree;

    public Application() {
        userChoice = 0;
        tree = new Tree23();
    }

    public int menu() {
        System.out.print("\nWelcome to the Neighbor Helper Program!" +
                "\nHere are your options: " +
                "\n1\t---\tCreate a post" +
                "\n2\t---\tDisplay posts" +
                "\n3\t---\tRead from file" +
                "\n4\t---\tWrite to file" +
                "\n0\t---\tQuit" +
                "\nEnter your choice here (0-4): ");
        userChoice = input.nextInt(); input.nextLine();
        if(userChoice < 0 || userChoice > 4) {
            menu();
        }

        //Will return the choice in case the user wants to do this again.
        return choices();
    }

    public int choices() {
        switch(userChoice) {
            //Choice will exit the program
            case 0:
                System.out.println("\nExiting Program..." +
                        "\n\nGoodbye!");
                break;

            //Will insert a new post into the tree.
            case 1:
                tree.insert();
                break;

            //Will display the posts from the tree in alphabetical order.
            case 2:
                tree.display();
                break;

            //Will read from an external data file.
            case 3:
                //Make a read function throughout the hierarchy.
                break;

            //Will write to an external data file.
            case 4:
                //Make a write function throughout the hierarchy.
                break;

            //This case shouldn't happen, but just in case it's here.
            default:
                System.out.println("\nSomehow you broke the program...");
        }

        //Returns the user choice in case we need to do this again.
        return userChoice;
    }

    public void run() {
        if(menu() == 0) return;
        run();
    }

    public static void main(String[] args) {
        Application myApp = new Application();
        myApp.run();
    }
}

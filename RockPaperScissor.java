import java.util.Scanner;
import java.util.Random;

public class RockPaperScissor {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Random ran = new Random();
        System.out.println("\t\t1 - Rock");
        System.out.println("\t\t2 - Paper");
        System.out.println("\t\t3 - Scissor");
        System.out.print("Your Turn : ");
        int you = input.nextInt();
        int com = ran.nextInt(4) + 1;
        System.out.println("Computer - " + com);
        System.out.println("\t\t***************");
        System.out.print("You - ");
        switch (you) {
            case 1 -> System.out.println("Rock");
            case 2 -> System.out.println("Paper");
            case 3 -> System.out.println("Scissor");
            default -> System.out.println("Enter Valid Selection");
        }
        System.out.print("Computer - ");
        switch (com) {
            case 1 -> System.out.println("Rock");
            case 2 -> System.out.println("Paper");
            case 3 -> System.out.println("Scissor");
            default -> System.out.println("---");
        }

        if (you == 1) {
            if (com == 1) {
                System.out.println("\t\tDraw");
            } else if (com == 2) {
                System.out.println("\t\tComputer Wins.");
                System.out.println("\t\tBetter Luck Next Time :)");
            } 
            else {
                System.out.println("\t\tYou Won.........");
            }
        } 
        else if (you == 2) {
            if (com == 1) {
                System.out.println("\t\tYou Won.........");
            } else if (com == 2) {
                System.out.println("\t\tDraw");
            } 
            else {
                System.out.println("\t\tComputer Wins.");
                System.out.println("\t\tBetter Luck Next Time :)");
            }
        }
        else{
            if (com == 1) {
                System.out.println("\t\tComputer Wins.");
                System.out.println("\t\tBetter Luck Next Time :)");
            } else if (com == 2) {
                System.out.println("\t\tYou Won.........");
            } 
            else {
                System.out.println("\t\tDraw");
            }
        }

        System.out.println("\t***************");

        input.close();
    }
}
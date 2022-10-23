import java.util.Scanner;
import Converters.*;

public class Main {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        DistanceConverter di = new DistanceConverter();
        CurrencyConverter cur = new CurrencyConverter();
        TimeConverter tim = new TimeConverter();
        
        System.out.println("\n*** Converters ***");
        System.out.println("1. Distance Converter.");
        System.out.println("2. Time Converter.");
        System.out.println("3. Currency Converter.");
        System.out.println("0. Exit.");

        while(true)
        {
            System.out.print("\nEnter option: ");
            int opt = sc.nextInt();
            sc.nextLine();
            
            if (opt == 0) {
                System.out.println("\nProgram ended.");
                System.exit(0);
            }

            int val;
            switch(opt)
            {
                case 1:
                    System.out.print("Enter value: ");
                    val = sc.nextInt();
                    sc.nextLine();
                    System.out.println(val + " KILOMETER(S) = " + di.kilometerToMeter(val) + " METER(S)");
                    System.out.println(val + " METER(S) = " + di.meterToKilometer(val) + " KILOMETER(S)");
                    System.out.println(val + " KILOMETER(S) = " + di.kilometerToMiles(val) + " MILE(S)");
                    System.out.println(val + " MILE(S) = " + di.milesToKilometer(val) + " KILOMETER(S)");
                    break;
                case 2:
                    System.out.print("Enter value: ");
                    val = sc.nextInt();
                    sc.nextLine();
                    System.out.println(val + " HOUR(S) = " + tim.hoursToMinutes(val) + " MINUTE(S)");
                    System.out.println(val + " MINUTE(S) = " + tim.minutesToHours(val) + " HOUR(S)");
                    System.out.println(val + " HOUR(S) = " + tim.hoursToSeconds(val) + " SECOND(S)");
                    System.out.println(val + " SECOND(S) = " + tim.secondsToHours(val) + " HOUR(S)");
                    break;
                case 3:
                    System.out.print("Enter value: ");
                    val = sc.nextInt();
                    sc.nextLine();
                    System.out.println(val + " INR = " + cur.inrToDollar(val) + " DOLLAR");
                    System.out.println(val + " DOLLAR = " + cur.dollarToInr(val) + " INR");
                    System.out.println(val + " INR = " + cur.inrToEuro(val) + " EURO");
                    System.out.println(val + " EURO = " + cur.euroToInr(val) + " INR");
                    System.out.println(val + " INR = " + cur.inrToYen(val) + " YEN");
                    System.out.println(val + " YEN = " + cur.yenToInr(val) + " INR");
                    break;
                default:
                    System.out.println("Incorrect option.");
                    break;
            }
        }
    }
}

/*
Note:
    To create a package:
        (i) Put classes to be packaged in a Package folder 
        (w/ only .class (or) .java + .class files)
        (ii) In every class, use 'package <package_name>;'
        (iii) From 'Main.java' folder, do 'javac -d . <package_name>/<class_name>.java' 
        for every class in Package folder.
        (iv) Use 'import <package_name>.*' to import all classes in package.
*/

/*
Note: 'goto' in C = 'label' in Java (Syntax: 'break <label_name>';)
       & 'label' MUST be before break statement.

*/

/*
IntelliJ Shortcuts:
    'psvm' = 'public static void main(String[] args) {}'
    'sout' = 'System.out.println();'
*/

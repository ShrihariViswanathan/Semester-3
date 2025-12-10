package CIE;
import java.util.Scanner;


public class Internals extends Personal{




    // Stores CIE marks for 5 courses (out of 50).
    protected int marks[] = new int[5];


    public void inputCIEmarks(Scanner s) {
        // Using the passed shared Scanner instance.
        System.out.println("\n--- Entering CIE Marks (out of 50) ---");
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter CIE mark for Course " + (i + 1) + " (max 50): ");
            while (!s.hasNextInt()) {
                System.out.println("Invalid input. Please enter a number: ");
                s.next();
            }
            marks[i] = s.nextInt();
            // Basic validation
            if (marks[i] < 0 || marks[i] > 50) {
                System.out.println("Warning: Mark is outside the 0-50 range. Continuing...");
            }
        }
        s.nextLine(); // Consume newline
    
}
}

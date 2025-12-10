package SEE;

import CIE.Internals;
import java.util.Scanner;

/**
 * Derived from Internals, stores Semester End Examination (SEE) marks and calculates final marks.
 */
public class Externals extends Internals {

    // This array stores SEE marks (out of 100).
    protected int marks[] = new int[5];       
    // Stores the final calculated marks (out of 100).
    protected int finalMarks[] = new int[5];  



    /**
     * Reads SEE marks for 5 courses using the provided Scanner object.
     * @param s The shared Scanner instance.
     */
    public void inputSEEmarks(Scanner s) {
        System.out.println("\n--- Entering SEE Marks (out of 100) ---");
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter SEE mark for Course " + (i + 1) + " (max 100): ");
            while (!s.hasNextInt()) {
                System.out.println("Invalid input. Please enter a number: ");
                s.next();
            }
            // 'this.marks' refers to the SEE marks array
            this.marks[i] = s.nextInt(); 
            // Basic validation
            if (this.marks[i] < 0 || this.marks[i] > 100) {
                System.out.println("Warning: Mark is outside the 0-100 range. Continuing...");
            }
        }
        s.nextLine(); // Consume newline
    }

    /**
     * Calculates final marks using the formula: Final = CIE Mark + (SEE Mark / 2).
     */
    public void calculateFinalMarks() {
        System.out.println("Calculating final marks...");
        for (int i = 0; i < 5; i++) {
            // super.marks refers to the CIE marks array from the Internals class.
            int cie = super.marks[i];
            // this.marks refers to the SEE marks array from the Externals class.
            int see = this.marks[i];
            
            // Final Mark (out of 100) = CIE (50) + (SEE/2) (50)
            this.finalMarks[i] = cie + (see / 2);
            
            // Cap the final mark at 100
            if (this.finalMarks[i] > 100) {
                this.finalMarks[i] = 100;
            }
        }
    }

    /**
     * Displays all student details and the final calculated marks.
     */
    public void displayFinalMarks() {
        System.out.println("\n======================================");
        System.out.println(" Final Marks Report");
        System.out.println("======================================");
        // Explicitly call inherited method from Student class
        super.displayStudentDetails(); 
        
        System.out.println("\nCourse | CIE (50) | SEE (100) | Final (100)");
        System.out.println("------------------------------------------");
        for (int i = 0; i < 5; i++) {
            // Accessing CIE marks (super.marks) and SEE marks (this.marks)
            System.out.printf(" %d | %d | %d | %d\n",
                (i + 1), super.marks[i], this.marks[i], this.finalMarks[i]);
        }
        System.out.println("======================================");
    }
}

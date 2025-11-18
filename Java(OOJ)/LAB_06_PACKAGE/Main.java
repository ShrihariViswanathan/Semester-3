import SEE.Externals;
import java.util.Scanner;

/**
 * Main class to demonstrate the package structure, inheritance, 
 * and calculation of final marks for n students.
 * FIX: The single Scanner 's' is now passed to all input methods 
 * to prevent input stream corruption.
 */
class Main {
    public static void main(String args[]) {
        // Only one Scanner object is created here to manage System.in
        Scanner s = new Scanner(System.in); 
        int n = 0;

        System.out.println("--- Student Mark Calculation System ---");
        System.out.print("Enter the number of students (n): ");
        if (s.hasNextInt()) {
            n = s.nextInt();
            if (n <= 0) {
                System.out.println("Number of students must be positive. Setting n to 1.");
                n = 1;
            }
        } else {
            System.out.println("Invalid input. Setting number of students to 1.");
            n = 1;
        }

        s.nextLine(); // Consume the rest of the line after reading n

        // Array to hold n instances of the Externals class
        Externals students[] = new Externals[n];

        for (int i = 0; i < n; i++) {
            System.out.println("\n--- Entering details for Student " + (i + 1) + " of " + n + " ---");
            
            students[i] = new Externals(); 

            // 2. Input student details - PASSING the Scanner
            students[i].inputStudentDetails(s);

            // 3. Input CIE marks - PASSING the Scanner
            students[i].inputCIEmarks(s);

            // 4. Input SEE marks - PASSING the Scanner
            students[i].inputSEEmarks(s);
        }

        System.out.println("\n**************************************");
        System.out.println("          FINAL RESULTS REPORT        ");
        System.out.println("**************************************");

        for (int i = 0; i < n; i++) {
            // 5. Calculate Final marks
            students[i].calculateFinalMarks();

            // 6. Display Final marks
            students[i].displayFinalMarks();
        }

        s.close(); // Close the main scanner resource ONLY once
    }
}
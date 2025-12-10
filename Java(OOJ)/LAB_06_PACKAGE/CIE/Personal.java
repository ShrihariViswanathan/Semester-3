package CIE;
import java.util.Scanner;

public class Personal {


    protected String usn = ""; 
    protected String name = ""; 
    protected int sem;

    public void inputStudentDetails(Scanner s) {
        // Using the passed shared Scanner instance.
        System.out.print("Enter Student USN: ");
        this.usn = s.nextLine();
        System.out.print("Enter Student Name: ");
        this.name = s.nextLine();
        System.out.print("Enter Semester: ");
        // Ensure input is an integer
        while (!s.hasNextInt()) {
            System.out.println("Invalid input. Please enter a number for the Semester: ");
            s.next(); // Consume invalid input
        }
        this.sem = s.nextInt();
        s.nextLine(); // Consume newline for safety
    }


    public void displayStudentDetails() {
        System.out.println("Student USN: " + usn);
        System.out.println("Student Name: " + name);
        System.out.println("Semester: " + sem);
    
}

}

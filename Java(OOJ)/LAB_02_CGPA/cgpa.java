import java.util.Scanner;

class Subject {
    int subjectMarks;
    int credits;
    int grade;
}

class Student {
    String name;
    String usn;
    double SGPA;
    Scanner s;
    Subject[] subject;

    // Constructor
    Student() {
        s = new Scanner(System.in);
        subject = new Subject[8];  // 8 subjects
        for (int i = 0; i < 8; i++) {
            subject[i] = new Subject();
        }
    }

    // Method to get student's name and USN
    void getStudentDetails() {
        System.out.print("Student Name: ");
        name = s.nextLine();
        System.out.print("USN: ");
        usn = s.nextLine();
    }

    // Method to read marks and credits and calculate grades
    void getMarks() {
        for (int i = 0; i < 8; i++) {
            System.out.println("Enter Details for Subject " + (i + 1));
            
            // Input marks
            System.out.print("Marks (0-100): ");
            subject[i].subjectMarks = s.nextInt();
            while(subject[i].subjectMarks < 0 || subject[i].subjectMarks > 100) {
                System.out.println("Invalid marks! Please enter marks between 0 and 100.");
                System.out.print("Marks (0-100): ");
                subject[i].subjectMarks = s.nextInt();
            }

            // Input credits
            System.out.print("Credits: ");
            subject[i].credits = s.nextInt();
            while(subject[i].credits <= 0) {
                System.out.println("Invalid credits! Please enter positive credits.");
                System.out.print("Credits: ");
                subject[i].credits = s.nextInt();
            }

            // Calculate grade based on marks
            subject[i].grade = (subject[i].subjectMarks / 10) + 1;

            // If marks > 100, grade capped at 10 (already checked but just in case)
            if (subject[i].grade == 11)
                subject[i].grade = 10;

            // If marks < 40, grade set to 0 (fail)
            if (subject[i].subjectMarks < 40)
                subject[i].grade = 0;
        }
    }

    // Calculate SGPA
    void computeSGPA() {
        int effectiveScore = 0;
        int totalCredits = 0;

        for (int i = 0; i < 8; i++) {
            effectiveScore += (subject[i].grade * subject[i].credits);
            totalCredits += subject[i].credits;
        }

        SGPA = (double) effectiveScore / (double) totalCredits;
    }

    // Display student details and SGPA
    void display() {
        System.out.println("\nStudent Details:");
        System.out.println("Name: " + name);
        System.out.println("USN: " + usn);
        System.out.printf("SGPA: %.2f\n", SGPA);

        
        System.out.println();
        System.out.println();

    }
    
}

class cgpa{
    public static void main(String[] args) {
        
        Student students[] = new Student[2];
        for (int i = 0; i < 2; i++){
            students[i] = new Student();
            students[i].getStudentDetails();
            students[i].getMarks();
            students[i].computeSGPA();
            students[i].display();
        }

    }
}

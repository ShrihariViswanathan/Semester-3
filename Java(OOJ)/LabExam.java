import java.util.Scanner;

interface Bank{
    double calculateInterest();
    void getDetails();
}

class Canara implements Bank{
    double principalAmount;
    String Name;
    float roi = 0.045f;
    int Age;
    int Year;
    String PAN;
    double interest;

    Canara(String n, int a, String p){
        Name = n;
        Age = a;
        PAN = p;
    }

    Scanner scan = new Scanner(System.in);
    
    public double calculateInterest(){
        System.out.print("Principal Amount: ");
        principalAmount = scan.nextDouble();

        System.out.println("Years: ");
        Year = scan.nextInt();

        double Interest = (Year * principalAmount * roi) / 100;

        return Interest;
    }
    
    //modified calculateInterest for overloading 
    int calculateInterest(double principalAmount, int Year){
        this.principalAmount = principalAmount;

        this.Year = Year;

        double Interest = (Year * principalAmount * roi) / 100;

        return (int)Interest;
    }

    public void getDetails(){
        interest = calculateInterest(1000, 25);
        System.out.println("Name: " + Name);
        System.out.println("Age: " + Age);
        System.out.println("PAN: " + PAN);
        System.out.println("Principal Amount: " + principalAmount);
        System.out.println("Years: " + Year);
        System.out.println("ROI: " + roi);
        System.out.println("Interest Gained: " + interest);
    }
}


class SBI implements Bank{
    String First_name;
    String Last_name;
    int age;
    String Aadhar;
    float roi = 0.0525f;
    int Year;
    double principalAmount;
    double interest;

    Scanner scan = new Scanner(System.in);
    
    SBI(String fn, String ln, int Age, String aadhar){
        First_name = fn;
        Last_name = ln;
        age = Age;
        Aadhar = aadhar;
    }

    public double calculateInterest(){
        System.out.print("Principal Amount: ");
        principalAmount = scan.nextDouble();

        System.out.print("Years: ");
        Year = scan.nextInt();

        double Interest = (Year * principalAmount * roi) / 100;

        return Interest;
    }

    public void getDetails(){
        interest = calculateInterest(2000, 100);
        System.out.println("FIrst_name: " + First_name);
        System.out.println("Last_name: " + Last_name);
        System.out.println("Age: " + age);
        System.out.println("Principal Amount: " + principalAmount);
        System.out.println("Years: " + Year);
        System.out.println("ROI: " + roi);
        System.out.println("Interest Gained: " + interest);
    }

    //modified calculateInterest for overloading 
    int calculateInterest(double principalAmount, int Year){
        this.principalAmount = principalAmount;

        this.Year = Year;

        double Interest = (Year * principalAmount * roi) / 100;

        return (int)Interest;
    }
}


public class LabExam {
    public static void main(String[] args) {
        System.out.println("Enter a bank: ");
        System.out.println("1. Canara");
        System.out.println("2. SBI");
        System.out.print("Enter choice: ");

        Scanner scan = new Scanner(System.in);

        int choice= scan.nextInt();
        scan.nextLine();

        if (choice == 1){
            System.out.println("Canara Bank: ");
            
            System.out.println("Name: ");
            String name = scan.nextLine();

            System.out.println("PAN: ");
            String PAN = scan.nextLine();

            System.out.println("Age: ");
            int age = scan.nextInt();

            Canara c = new Canara(name, age, PAN);
            c.getDetails();

        }

        else if (choice == 2){
            System.out.println("SBI Bank: ");
            
            System.out.println("First Name: ");
            String fn = scan.nextLine();

            System.out.println("Last Name: ");
            String ln = scan.nextLine();

            System.out.println("Aadhar: ");
            String aadhar = scan.nextLine();

            System.out.println("Age: ");
            int age = scan.nextInt();

            SBI s = new SBI(fn, ln, age, aadhar);
            s.getDetails();

        }

        else{
            System.out.println("Invalid choice");
        }
    }

}


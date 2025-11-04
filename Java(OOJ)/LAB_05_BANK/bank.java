import java.util.Scanner;

class Account{
    String customerName;
    int accountNumber;
    String accountType;
    double balance;

    Scanner sc = new Scanner(System.in);

    void input(){
        System.out.print("Enter Customer Name: ");
        customerName = sc.nextLine();

        System.out.print("Enter Account Number: ");
        accountNumber = sc.nextInt();
        sc.nextLine();
    }


    void deposit(){
        System.out.print("Enter amount to deposit: ");
        double amount = sc.nextDouble();

        balance += amount;
        System.out.println("Amount deposited Successfully");
    }


    void displayBalance(){
        System.out.println("Current Balance: " + balance);
    }

    void withdraw(){
        System.out.print("Enter amount to withdraw: ");
        double amount = sc.nextDouble();
        
        if(amount <= balance){
            balance -= amount;
            System.out.println("You have " + amount + " rupees");
            System.out.println("Transaction Successful");
            checkMinBalance();
        }

        else{
            System.out.println("Insufficient balance");
        }
    }

    void checkMinBalance(){
        
    }

}



class Savings extends Account{
    final double interestRate = 0.05;
    Savings() {
        accountType = "Savings";
    }

    void computeInterest(){
        System.out.print("Enter no.of Years: ");
        double years = sc.nextDouble();

        double interest = balance * Math.pow((1 + interestRate), years) - balance;
        balance += interest;

        System.out.println("Interest Added: " + interest);
    }  

}


class Current extends Account{
    final double serviceCharge = 100;
    final double minBalance = 1000;

    Current() {
        accountType = "Current";
    }


    @Override
    void checkMinBalance(){
        if (balance < minBalance){
            balance -= serviceCharge;
            System.out.println("Balance < minBalance");
            System.out.print("Penalty of " + serviceCharge + " is imposed");
        }
    }    

}


public class bank {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter account type (Savings/Current): ");
        String accountType = sc.nextLine();

        Account account = null;

        if (accountType.trim().equalsIgnoreCase("Savings")) {
            account = new Savings();
        } else if (accountType.equalsIgnoreCase("Current")) {
            account = new Current();
        } else {
            System.out.println("Invalid account type.");
            return;
        }

        account.input();

        while (true) {
            printMenu();
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    account.deposit();
                    break;
                case 2:
                    account.withdraw();
                    break;
                case 3:
                    account.displayBalance();
                    break;
                case 4:
                    if (account instanceof Savings) {
                        ((Savings) account).computeInterest();
                    } 
                    
                    else {
                        System.out.println("Compute Interest not available for Current accounts.");
                    }
                    break;
                case 5:
                    System.out.println("Exiting the bank system.");
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    public static void printMenu() {
        System.out.println("\n1. Deposit");
        System.out.println("2. Withdraw");
        System.out.println("3. Display Balance");
        System.out.println("4. Compute Interest (Only for Savings accounts)");
        System.out.println("5. Exit");
    }

}






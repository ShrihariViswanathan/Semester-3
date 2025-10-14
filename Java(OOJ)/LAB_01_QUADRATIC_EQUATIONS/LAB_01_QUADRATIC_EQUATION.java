/*Develop a Java program that prints all real solutions to the quadratic
equation ax2+bx+c = 0. Read in a, b, c and use the quadratic formula. If
the discriminate b2-4ac is negative, display a message stating that there
are no real solutions.*/

import java.util.Scanner;

class QUADRATIC_EQUATION{
public static void main(String args[]){
    double a;
    double b;
    double c;
    
    Scanner scan = new Scanner(System.in);
    

    System.out.print("a: ");
    a = scan.nextDouble();

    System.out.print("b: ");
    b = scan.nextDouble();

    System.out.print("c: ");
    c = scan.nextDouble();

    double disc = (b*b) - (4*a*c);

    if (disc > 0){
        System.out.println("The solutions are real");
        double alpha = (-b + Math.pow(disc, 1/2))/ (2 * a);
        double beta = (-b - Math.pow(disc, 1/2)) / (2 * a);
        System.out.println("Alpha: " + alpha);
        System.out.println("Beta: " + beta);
    }

    if (disc == 0){
        System.out.println("The solutions are equal");
        double sol = (-b) / (2*a);
        System.out.println("Beta: " + sol);
        System.out.println("Alpha: " + sol);

    }

    if (disc < 0 ){
        System.out.println("The roots are imaginary");
    }



    scan.close();
        
    
    }


}

import java.util.Scanner;

class Input {
    Scanner sc = new Scanner(System.in);

    int getInt(String message) {
        System.out.print(message);
        return sc.nextInt();
    }
}

abstract class Shape extends Input {
    int a, b;
    abstract void printArea();
}

class Rectangle extends Shape {
    void input() {
        a = getInt("Enter length: ");
        b = getInt("Enter breadth: ");
    }

    void printArea() {
        System.out.println("Area of rectangle: " + (a * b));
        System.out.println();
    }
}

class Triangle extends Shape {
    void input() {
        a = getInt("Enter base value: ");
        b = getInt("Enter height value:");
    }

    void printArea() {
        System.out.println("Area of Triangle: " + (0.5 * a * b));
        System.out.println();
    }
}

class Circle extends Shape {
    void input() {
        a = getInt("Enter the radius: ");
    }

    void printArea() {
        System.out.println("Area of Circle: " + (3.14159265 * a * a));
        System.out.println();
    }
}

public class abstractClass {
    public static void main(String args[]) {
        Rectangle r = new Rectangle();
        r.input();
        r.printArea();

        Triangle t = new Triangle();  
        t.input();
        t.printArea();

        Circle c = new Circle();
        c.input();
        c.printArea();
    }
}

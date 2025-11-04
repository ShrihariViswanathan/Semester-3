import java.util.Scanner;

class Book{
    String name;
    String author;
    double price;
    int numPages;

    Book(String name, String author, double price, int numPages){
        this.name = name;
        this.author = author;
        this.price = price;
        this.numPages = numPages;
    }


    public String toString(){
        String name, author, price, numPages;
        name = "Book name: " + this.name + "\n";
        author = "Author name: " + this.author + "\n";
        price = "Price: " + this.price + "\n";
        numPages = "Number of pages: " + this.numPages + "\n";

        return name + author + price + numPages;
    }

} //end of class


class Books{
    public static void main(String args[]){

    Scanner s = new Scanner(System.in);

    int n; 
    String name; 
    String author; 
    double price; 
    int numPages;

    System.out.print("No.of Books: ");
    n = s.nextInt();
        s.nextLine();

    Book b[];
    b = new Book[n];

    for (int i = 0; i < n; i++){
         //name
        
         System.out.print("Name of Book " + (i+1));
        name = s.nextLine();

        System.out.print("Author of Book " + (i + 1));
        author = s.nextLine();

        System.out.print("Price of Book " + (i + 1));
        price = s.nextDouble();

        System.out.print("No.of Pages for Book " + (i + 1)) ;
        numPages = s.nextInt();

        b[i] = new Book(name, author, price, numPages);     
    }


    for (int i = 0; i < b.length; i++){
        System.out.println(b[i]);
    }

    }
}




import java.util.Scanner;

class WrongAge extends Exception{
    WrongAge(String message){
        super(message);
    }
}

class Father{
    float fatherAge;

    Father(float fatherAge){
        try{
            if (fatherAge < 0)
                throw new WrongAge("Father cant be less than zero years old");
            this.fatherAge = fatherAge;

        } catch (WrongAge e){
            System.out.println("Error: " + e);
        }

    }
}

class Son extends Father{
    float sonAge;

    Son(float fatherAge, float sonAge){
        super(fatherAge);
        try{
            if (sonAge >= fatherAge)
                throw new WrongAge("Son's age cannot be greater than father's age");
            this.sonAge = sonAge;

        } catch(WrongAge e){
            System.out.println("Error: " + e);
        }
    }

    Son (float fatherAge){
        super(fatherAge);
    }
}


public class LAB_07_EXCEPTION{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        Son s1;

        System.out.print("Enter father age: ");
        float fatherAge = sc.nextFloat();
        if (fatherAge < 0){
            s1 =  new Son(fatherAge);
            System.exit(0);
        }

        System.out.print("Enter Son age: ");
        float sonAge = sc.nextFloat();
        s1 = new Son(fatherAge, sonAge);
    }

}
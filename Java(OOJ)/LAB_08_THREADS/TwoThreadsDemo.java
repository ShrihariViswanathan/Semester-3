class CollegeThread implements Runnable {
    public void run() {
        try {
            while(true) {
                System.out.println("BMS College of Engineering");
                Thread.sleep(10000); // 10 seconds
            }
        } catch(InterruptedException e) {
            System.out.println("CollegeThread interrupted");
        }
    }
}

class CSEThread implements Runnable {
    public void run() {
        try {
            while(true) {
                System.out.println("CSE");
                Thread.sleep(2000); // 2 seconds
            }
        } catch(InterruptedException e) {
            System.out.println("CSEThread interrupted");
        }
    }
}

public class TwoThreadsDemo {
    public static void main(String[] args) {
        Thread t1 = new Thread(new CollegeThread());
        Thread t2 = new Thread(new CSEThread());

        t1.start();
        t2.start();
    }
}

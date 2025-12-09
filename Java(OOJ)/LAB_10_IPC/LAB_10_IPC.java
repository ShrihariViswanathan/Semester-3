class Q {
    int n;
    boolean valueSet = false;

    // Function 1: Consumer gets data
    synchronized int get() {
        while(!valueSet) {
            try { wait(); } catch(InterruptedException e) {}
        }
        System.out.println("Got: " + n);
        valueSet = false;
        notify();
        return n;
    }

    // Function 2: Producer puts data
    synchronized void put(int n) {
        while(valueSet) {
            try { wait(); } catch(InterruptedException e) {}
        }
        this.n = n;
        valueSet = true;
        System.out.println("Put: " + n);
        notify();
    }
}

class Producer implements Runnable {
    Q q;
    Producer(Q q) { this.q = q; new Thread(this, "Producer").start(); }

    // Function 3: Producer thread run
    public void run() {
        for(int i=1; i<=5; i++) q.put(i);
    }
}

class Consumer implements Runnable {
    Q q;
    Consumer(Q q) { this.q = q; new Thread(this, "Consumer").start(); }

    // Function 4: Consumer thread run
    public void run() {
        for(int i=1; i<=5; i++) q.get();
    }
}


public class LAB_10_IPC {
    // Function 5: main method
    public static void main(String[] args) {
        System.out.println("=== Interprocess Communication Demo ===");
        Q q = new Q();
        new Producer(q);
        new Consumer(q);

        try { Thread.sleep(3000); } catch(Exception e) {}

    }
}
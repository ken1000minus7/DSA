/**
 * Concurreny -> managing multiple tasks at the same time, each task gets a time slice
 * Parallelism -> carrying out multiple tasks at the same time, not task has to wait, everything happening at the same time
 */

public class Multithreading {
    public static void main(String[] args) {
        Thready thread1 = new Thready();
        AnotherThready runnable = new AnotherThready();
        Thread thread2 = new Thread(runnable);
        Thread thread3 = new Thread(new Runnable() {

            @Override
            public void run() {
                for(int i = 100; i < 105; i++) {
                    System.out.println(i);
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
            
        });

        thread1.start();
        thread2.start();
        thread3.start();
    }
    
}

// by extending thread
class Thready extends Thread {
    @Override
    public void run() {
        for(int i = 0; i < 5; i++) {
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// using runnable interface
class AnotherThready implements Runnable {

    @Override
    public void run() {
        for(int i = 10; i <= 15; i++) {
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

}
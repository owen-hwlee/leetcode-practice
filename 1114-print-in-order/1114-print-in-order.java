class Foo {

    // Same instance of Foo passed to 3 different threads
    // Therefore static variable is not required, instance variable suffices
    private volatile int printCount = 1;
    
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized (this) {
            while (printCount != 1) {
                wait();
            }
            
            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            ++printCount;
            notifyAll();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized (this) {
            while (printCount != 2) {
                wait();
            }
            
            // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            ++printCount;
            notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized (this) {
            while (printCount != 3) {
                wait();
            }
            
            // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
            ++printCount;
            notifyAll();
        }
    }
}
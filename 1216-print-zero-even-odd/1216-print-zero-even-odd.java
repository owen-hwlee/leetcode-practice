class ZeroEvenOdd {
    private int n;
    private volatile boolean isZeroPrinted = false;
    private volatile boolean isOdd = true;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; ++i) {
            synchronized(this) {
                while (isZeroPrinted) {
                    wait();
                }
                
                printNumber.accept(0);
                isOdd = i % 2 == 0;
                isZeroPrinted = true;

                notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            synchronized(this) {
                while (!isZeroPrinted || isOdd) {
                    wait();
                }
                
                printNumber.accept(i);
                isZeroPrinted = false;
                notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            synchronized(this) {
                while (!isZeroPrinted || !isOdd) {
                    wait();
                }
                
                printNumber.accept(i);
                isZeroPrinted = false;
                notifyAll();
            }
        }
    }
}
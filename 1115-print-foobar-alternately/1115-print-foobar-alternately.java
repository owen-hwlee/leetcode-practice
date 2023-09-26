class FooBar {
    private int n;
    private volatile boolean isFooPrinted = false;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(this) {
                while (isFooPrinted) {
                    wait();
                }
                
        	    // printFoo.run() outputs "foo". Do not change or remove this line.
        	    printFoo.run();
                isFooPrinted = true;
                notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(this) {
                while (!isFooPrinted) {
                    wait();
                }
                
        	    // printBar.run() outputs "bar". Do not change or remove this line.
        	    printBar.run();
                isFooPrinted = false;
                notifyAll();
            }
        }
    }
}
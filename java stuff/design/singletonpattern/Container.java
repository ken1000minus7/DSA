package singletonpattern;

public class Container {
    private boolean empty;
    private static volatile Container instance;

    private Container() {
        this.empty = true;
    }

    /*
    Global point of access for the instance

    Can end up creating 2 instances in case of multithreaded environments
    Solutions
    1. Make method synchronized, this has performance overhead
    2. Eager initialization, not good for resource heavy objects
    3. Double-checked locking (done below)
    4. Dont do anything and hope nothing breaks :)

    Multiple instances can also be created if there r multiple class loaders or garbage collector removes the current instance (happens in older java versions)
     */
    public static Container getInstance() {
        if(instance == null) {
            synchronized(Container.class) {
                if(instance == null) {
                    instance = new Container();
                }
            }
        }
        return instance;
    }

    public boolean isEmpty() {
        return this.empty;
    }

    public void setEmpty(boolean empty) {
        this.empty = empty;
    }
}

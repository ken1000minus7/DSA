package design.simuduck;

public abstract class Duck {

    /**
     * 1. Separating things that change from things that dont
     * Moving the fly and quack behaviour to different classes to allow changes in them without affecting the duck class
     * 
     * 2. Programming to interfaces instead of implementations, duck no longer needs to worry about what kind of flybehaviour it is
     * It can directly use the fly behaviour to fly
     * 
     * 3. FAVOR COMPOSITION OVER INHERITANCE
     */
    protected FlyBehaviour flyBehaviour;
    protected QuackBehaviour quackBehaviour;


    public abstract void info();

    public void flyDuck() {
        flyBehaviour.fly();
    }

    public void quackDuck() {
        quackBehaviour.quack();
    }

    /**
     * We can also dynamically change the implementation of fly 
     * Wouldnt be possible if we had the implementation in duck itself
     */
    public void setFlyBehaviour(FlyBehaviour flyBehaviour) {
        this.flyBehaviour = flyBehaviour;
    }

    public void setQuackBehaviour(QuackBehaviour quackBehaviour) {
        this.quackBehaviour = quackBehaviour;
    }
}

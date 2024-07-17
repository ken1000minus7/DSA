package simuduck;


/**
 * STRATEGY PATTERN
 * 
 * The Strategy Pattern defines a family of algorithms, encapsulates each one, and makes them interchangeable. 
 * Strategy lets the algorithm vary independently from clients that use it.
 */
public class Simduck {
    public static void main(String[] args) {
        Duck duck = new RubberDucky();
        duck.flyDuck();
        duck.quackDuck();
    }
}

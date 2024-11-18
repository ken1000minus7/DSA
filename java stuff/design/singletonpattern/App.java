package singletonpattern;

/*
    SINGLETON PATTERN
    Ensures only one instance of a class is created and provides global access point for accessing the instance
    A singleton class manages its initialization itself
    Makes use of a private constructor, static variable for the instance and static method
 */
public class App {
    public static void main(String[] args) {
        Container container = Container.getInstance();
        if(container.isEmpty()) {
            container.setEmpty(false);
            System.out.println("Filled container");
        }
    }
}

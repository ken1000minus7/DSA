package decoratorpattern;

/*
 * Decorators attach additional responsibilities to a class dynamically, we can extend functionality without using inheritance (composition over inheritance principle)
 * 
 * Open closed principle - Classes should be open for extension but closed for modification
 * 
 * Decorators have they same type as the components they decorate
 */

public class Starbuzz {
    public static void main(String[] args) {
        // Better way to initialize using factory or builder pattern
        Beverage beverage = new Frappe();
        beverage = new Mocha(beverage);
        beverage = new Mocha(beverage);
        beverage = new Whip(beverage);
        System.out.println(beverage.getDescription() + " " + beverage.getCost());
    }
}

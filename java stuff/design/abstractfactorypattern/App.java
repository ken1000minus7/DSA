package abstractfactorypattern;

import abstractfactorypattern.stores.ChicagoPizzaStore;
import abstractfactorypattern.stores.NYPizzaStore;
import abstractfactorypattern.stores.PizzaStore;

/*
    ABSTRACT FACTORY PATTERN
    Create an interface for creating a family of objects without specifying their concrete classes
    It relies on compositions, object creation is done in the factory methods of the concrete factory classes

    DEPENDENCY INVERSION PRINCIPLE
    Both high level and low level components should depend on abstractions and not concrete classes

    Inversion cause a pizza depends on the abstract ingredient class and the concrete ingredient classes implement the abstract ingredient class and so are dependent on it
 */
public class App {
    public static void main(String[] args) {
        PizzaStore pizzaStore = new NYPizzaStore();
        pizzaStore.orderPizza("cheese");

        pizzaStore = new ChicagoPizzaStore();
        pizzaStore.orderPizza("veg");
    }
}

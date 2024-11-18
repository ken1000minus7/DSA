package factorymethodpattern;

import factorymethodpattern.stores.ChicagoPizzaStore;
import factorymethodpattern.stores.NYPizzaStore;
import factorymethodpattern.stores.PizzaStore;

/*
    Factory patterns are used to encapsulate object creation
    Simple factory moves the object creation to another object

    FACTORY METHOD PATTERN
    Create an interface for object creation, but let subclasses decide what concrete classes to instantiate
    It relies on inheritance, object creation is left to the subclasses
 */
public class App {
    public static void main(String[] args) {
        PizzaStore pizzaStore = new NYPizzaStore();
        pizzaStore.orderPizza("cheese");

        pizzaStore = new ChicagoPizzaStore();
        pizzaStore.orderPizza("veg");
    }
}

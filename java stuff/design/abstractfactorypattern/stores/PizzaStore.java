package abstractfactorypattern.stores;

import abstractfactorypattern.pizzas.Pizza;

public abstract class PizzaStore {

    /*
    This method calls factory method for object creation, it never needs to know what objects are actually being created
     */
    public Pizza orderPizza(String type) {
        Pizza pizza = createPizza(type);
        pizza.prepare();
        return pizza;
    }

    /*
    This method is responsible for object creation and is known as factory method
    Subclasses will add their own implementations to it for object creation
     */
    public abstract Pizza createPizza(String type);
}

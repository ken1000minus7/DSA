package factorymethodpattern.stores;

import factorymethodpattern.pizzas.ChicagoCheesePizza;
import factorymethodpattern.pizzas.ChicagoVegPizza;
import factorymethodpattern.pizzas.Pizza;

public class ChicagoPizzaStore extends PizzaStore {
    @Override
    public Pizza createPizza(String type) {
        if(type.equals("cheese")) {
            return new ChicagoCheesePizza();
        }
        return new ChicagoVegPizza();
    }
}

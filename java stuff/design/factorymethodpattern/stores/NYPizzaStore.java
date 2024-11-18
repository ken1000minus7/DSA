package factorymethodpattern.stores;

import factorymethodpattern.pizzas.NYCheesePizza;
import factorymethodpattern.pizzas.NYVegPizza;
import factorymethodpattern.pizzas.Pizza;

public class NYPizzaStore extends PizzaStore {
    @Override
    public Pizza createPizza(String type) {
        if(type.equals("cheese")) {
            return new NYCheesePizza();
        }
        return new NYVegPizza();
    }
}

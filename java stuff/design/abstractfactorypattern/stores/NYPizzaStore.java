package abstractfactorypattern.stores;

import abstractfactorypattern.factory.IngredientFactory;
import abstractfactorypattern.factory.NYIngredientFactory;
import abstractfactorypattern.pizzas.CheesePizza;
import abstractfactorypattern.pizzas.Pizza;
import abstractfactorypattern.pizzas.VegPizza;

public class NYPizzaStore extends PizzaStore {
    @Override
    public Pizza createPizza(String type) {
        IngredientFactory ingredientFactory = new NYIngredientFactory();
        if(type.equals("cheese")) {
            return new CheesePizza(ingredientFactory);
        }
        return new VegPizza(ingredientFactory);
    }
}

package abstractfactorypattern.stores;

import abstractfactorypattern.factory.ChicagoIngredientFactory;
import abstractfactorypattern.factory.IngredientFactory;
import abstractfactorypattern.pizzas.CheesePizza;
import abstractfactorypattern.pizzas.VegPizza;
import abstractfactorypattern.pizzas.Pizza;

public class ChicagoPizzaStore extends PizzaStore {
    @Override
    public Pizza createPizza(String type) {
        IngredientFactory ingredientFactory = new ChicagoIngredientFactory();
        if(type.equals("cheese")) {
            return new CheesePizza(ingredientFactory);
        }
        return new VegPizza(ingredientFactory);
    }
}

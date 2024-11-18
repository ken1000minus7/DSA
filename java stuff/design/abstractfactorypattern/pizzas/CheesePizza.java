package abstractfactorypattern.pizzas;

import abstractfactorypattern.factory.IngredientFactory;
import abstractfactorypattern.ingredients.Cheese;
import abstractfactorypattern.ingredients.Crust;

public class CheesePizza implements Pizza {

    private Cheese cheese;
    private Crust crust;

    public CheesePizza(IngredientFactory ingredientFactory) {
        this.cheese = ingredientFactory.createCheese();
        this.crust = ingredientFactory.createCrust();
    }

    @Override
    public void prepare() {
        System.out.println("Preparing Cheese Pizza with " + cheese.getName() + " and " + crust.getName());
    }
}

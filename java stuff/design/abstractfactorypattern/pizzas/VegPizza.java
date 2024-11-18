package abstractfactorypattern.pizzas;

import abstractfactorypattern.factory.IngredientFactory;
import abstractfactorypattern.ingredients.Cheese;
import abstractfactorypattern.ingredients.Crust;

public class VegPizza implements Pizza {
    private Cheese cheese;
    private Crust crust;

    public VegPizza(IngredientFactory ingredientFactory) {
        this.cheese = ingredientFactory.createCheese();
        this.crust = ingredientFactory.createCrust();
    }

    @Override
    public void prepare() {
        System.out.println("Preparing Veg Pizza with " + cheese.getName() + " and " + crust.getName());
    }
}

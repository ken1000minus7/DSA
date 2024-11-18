package abstractfactorypattern.factory;

import abstractfactorypattern.ingredients.Cheese;
import abstractfactorypattern.ingredients.Crust;

public interface IngredientFactory {
    Cheese createCheese();
    Crust createCrust();
}

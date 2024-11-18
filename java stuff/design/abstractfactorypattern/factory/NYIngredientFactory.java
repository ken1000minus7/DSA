package abstractfactorypattern.factory;

import abstractfactorypattern.ingredients.Cheese;
import abstractfactorypattern.ingredients.Crust;
import abstractfactorypattern.ingredients.NYCheese;
import abstractfactorypattern.ingredients.ThinCrust;

public class NYIngredientFactory implements IngredientFactory{
    @Override
    public Cheese createCheese() {
        return new NYCheese();
    }

    @Override
    public Crust createCrust() {
        return new ThinCrust();
    }
}

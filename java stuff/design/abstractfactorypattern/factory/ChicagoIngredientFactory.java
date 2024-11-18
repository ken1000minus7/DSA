package abstractfactorypattern.factory;

import abstractfactorypattern.ingredients.Cheese;
import abstractfactorypattern.ingredients.ChicagoCheese;
import abstractfactorypattern.ingredients.Crust;
import abstractfactorypattern.ingredients.ThickCrust;

public class ChicagoIngredientFactory implements IngredientFactory{
    @Override
    public Cheese createCheese() {
        return new ChicagoCheese();
    }

    @Override
    public Crust createCrust() {
        return new ThickCrust();
    }
}

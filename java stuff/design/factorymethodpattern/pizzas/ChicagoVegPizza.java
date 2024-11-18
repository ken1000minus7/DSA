package factorymethodpattern.pizzas;

public class ChicagoVegPizza implements Pizza {
    @Override
    public void prepare() {
        System.out.println("Preparing Chicago Veg Pizza");
    }
}

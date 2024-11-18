package factorymethodpattern.pizzas;

public class NYCheesePizza implements Pizza {
    @Override
    public void prepare() {
        System.out.println("Preparing NY Cheese Pizza");
    }
}

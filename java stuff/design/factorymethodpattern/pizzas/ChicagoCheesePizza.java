package factorymethodpattern.pizzas;

public class ChicagoCheesePizza implements Pizza {
    @Override
    public void prepare() {
        System.out.println("Preparing Chicago Cheese Pizza");
    }
}

package factorymethodpattern.pizzas;

public class NYVegPizza implements Pizza {
    @Override
    public void prepare() {
        System.out.println("NYVegPizza preparation");
    }
}

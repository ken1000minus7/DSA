package decoratorpattern;

public class Mocha extends Condiment {
    private Beverage beverage;

    Mocha(Beverage beverage) {
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Mocha";
    }

    @Override
    public double getCost() {
        return beverage.getCost() + 2.8;
    }
}

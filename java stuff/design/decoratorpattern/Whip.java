package decoratorpattern;

public class Whip extends Condiment {

    private Beverage beverage;

    Whip(Beverage beverage) {
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Whip";
    }

    @Override
    public double getCost() {
        return beverage.getCost() + 1.4;
    }
    
}

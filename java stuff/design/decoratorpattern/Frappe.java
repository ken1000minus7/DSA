package decoratorpattern;

public class Frappe extends Beverage {
    @Override
    public double getCost() {
        return 10.5;
    }

    @Override
    public String getDescription() {
        return "Frappe drink";
    }
}

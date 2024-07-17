package decoratorpattern;

public abstract class Beverage {
    public String getDescription() {
        return "Unknown beverage";
    }
    public abstract double getCost();
}

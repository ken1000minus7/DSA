package observerpattern;

public class CurrentConditionDisplay implements Observer, DisplayElement {
    private float temperature;
    private float humidity;
    private Subject subject;

    public CurrentConditionDisplay(Subject s) {
        this.subject = s;
        this.subject.registerObserver(this);
    }

    @Override
    public void display() {
        System.out.println("Temperature " + temperature + ", humidity " + humidity);
    }

    @Override
    public void update(float temp, float humidity, float pressure) {
        this.temperature = temp;
        this.humidity = humidity;
        display();
    }
}

package observerpattern;

public class OtherDisplay implements Observer, DisplayElement {
    private Subject subject;

    public OtherDisplay(Subject s) {
        this.subject = s;
        this.subject.registerObserver(this);
    }

    @Override
    public void display() {
        System.out.println("YO");
    }

    @Override
    public void update(float temp, float humidity, float pressure) {
        // Anything u wanna do with the updated data
        display();
    }
}

package observerpattern;
/*
 * The Observer Pattern defines a one-to-many dependency between objects so that when one object changes state, all of its dependents are notified and updated automatically.
 * 
 * Strive for loosely coupled design between objects that interact
 * The subject only cares about the observer interface implementation so is not concerned with the concrete class
 * We can add or remove observers easily without having to change the code
 * 
 * There's built in obersver and observable as well but it's now deprecated
 */

public interface Subject {
    void registerObserver(Observer o);
    void removeObserver(Observer o);
    void notifyObservers();
}

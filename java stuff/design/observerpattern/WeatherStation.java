package observerpattern;

public class WeatherStation {
    public static void main(String[] args) {
        WeatherData weatherData = new WeatherData();
        CurrentConditionDisplay currentConditionDisplay = new CurrentConditionDisplay(weatherData);
        OtherDisplay otherDisplay = new OtherDisplay(weatherData);
        weatherData.setMeasurements(10, 2, 3);
        weatherData.setMeasurements(13, 2, 3);
        weatherData.setMeasurements(18, 2, 3);
    }
}

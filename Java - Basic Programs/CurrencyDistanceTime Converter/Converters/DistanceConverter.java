package Converters;

public class DistanceConverter
{
    public double meterToKilometer (int meter) {
        return (meter / (double) 1000);
    }
    public double meterToKilometer (float meter) {
        return (meter / (double) 1000);
    }
    public double meterToKilometer (double meter) {
        return (double) (meter / (double) 1000);
    }

    public double kilometerToMeter (int kilometer) {
        return (kilometer * (double) 1000);
    }
    public double kilometerToMeter (float kilometer) {
        return (kilometer * (double) 1000);
    }
    public double kilometerToMeter (double kilometer) {
        return (kilometer * (double) 1000);
    }

    public double milesToKilometer (int miles) {
        return (miles * (double) 1.60934);
    }
    public double milesToKilometer (float miles) {
        return (miles * (double) 1.60934);
    }
    public double milesToKilometer (double miles) {
        return (miles * (double) 1.60934);
    }
    
    public double kilometerToMiles (int kilometer) {
        return (kilometer / (double) 1.60934);
    }
    public double kilometerToMiles (float kilometer) {
        return (kilometer / (double) 1.60934);
    }
    public double kilometerToMiles (double kilometer) {
        return (kilometer / (double) 1.60934);
    }
}
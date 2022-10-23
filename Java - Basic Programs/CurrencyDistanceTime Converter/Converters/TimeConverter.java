package Converters;

public class TimeConverter {
    public double hoursToMinutes(int hours) {
        return (hours * (double) 60);
    }
    public double hoursToMinutes(float hours) {
        return (hours * (double) 60);
    }
    public double hoursToMinutes(double hours) {
        return (hours * (double) 60);
    }
    
    public double minutesToHours(int minutes) {
        return (minutes / (double) 60);
    }
    public double minutesToHours(float minutes) {
        return (minutes / (double) 60);
    }
    public double minutesToHours(double minutes) {
        return (minutes / (double) 60);
    }
    
    public double hoursToSeconds(int hours) {
        return (hours * (double) 60 * 60);
    }
    public double hoursToSeconds(float hours) {
        return (hours * (double) 60 * 60);
    }
    public double hoursToSeconds(double hours) {
        return (hours * (double) 60 * 60);
    }
    
    public double secondsToHours(int seconds) {
        return (seconds / ((double) 60 * 60));
    }
    public double secondsToHours(float seconds) {
        return (seconds / ((double) 60 * 60));
    }
    public double secondsToHours(double seconds) {
        return (seconds / ((double) 60 * 60));
    }
}

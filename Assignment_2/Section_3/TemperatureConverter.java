class TemperatureConverter {
    private int count = 0; // No manual memory allocation

    public double[] convert(double temp, boolean toCelsius) {
        count++;
        double result = toCelsius ? (temp - 32) * 5 / 9 : (temp * 9 / 5) + 32;
        return new double[]{result, count}; // Memory is managed by GC
    }

    public static void main(String[] args) {
        TemperatureConverter converter = new TemperatureConverter();
        double[] result1 = converter.convert(100, true);
        System.out.println("Converted: " + result1[0] + ", Calls: " + (int)result1[1]);

        double[] result2 = converter.convert(0, false);
        System.out.println("Converted: " + result2[0] + ", Calls: " + (int)result2[1]);
    }
}

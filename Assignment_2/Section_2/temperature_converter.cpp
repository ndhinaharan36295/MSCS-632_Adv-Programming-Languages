#include <iostream>
#include <functional>

std::function<std::pair<double, int>(double, bool)> temperatureConverter() {
    int count = 0;  // Enclosed variable

    return [count](double temp, bool toCelsius = true) mutable {
        count++;  // Modifying enclosed variable
        return toCelsius
            ? std::make_pair((temp - 32) * 5 / 9, count)  // Convert to Celsius
            : std::make_pair((temp * 9 / 5) + 32, count);  // Convert to Fahrenheit
    };
}

int main() {
    auto convertTemp = temperatureConverter();
    auto result1 = convertTemp(100, true);

    std::cout << "100 degrees F is " << result1.first << " C"
    << std::endl;

    auto result2 = convertTemp(0, false);
    std::cout << "0 degrees C is " << result2.first << " F"
    << std::endl;

    return 0;
}

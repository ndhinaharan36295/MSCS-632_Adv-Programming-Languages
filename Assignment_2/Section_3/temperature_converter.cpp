#include <iostream>

class TemperatureConverter {
private:
    int* count; // Dynamically allocated memory

public:
    TemperatureConverter() {
        count = new int(0); // Allocating memory for count
    }

    ~TemperatureConverter() {
        delete count; // Freeing memory
    }

    std::pair<double, int> convert(double temp, bool toCelsius) {
        (*count)++;
        double result = toCelsius ? (temp - 32) * 5.0 / 9.0 : (temp * 9.0 / 5.0) + 32.0;
        return {result, *count};
    }
};

int main() {
    TemperatureConverter* converter = new TemperatureConverter(); // Allocating object dynamically

    auto result1 = converter->convert(100, true);
    std::cout << "Converted: " << result1.first << ", Calls: " << result1.second << std::endl;

    auto result2 = converter->convert(0, false);
    std::cout << "Converted: " << result2.first << ", Calls: " << result2.second << std::endl;

    delete converter; // Freeing allocated object
    return 0;
}

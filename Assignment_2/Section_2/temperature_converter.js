function temperatureConverter() {
    let count = 0;  // Enclosed variable

    return function convert(temp, toCelsius = true) {
        count++;  // Modifying enclosed variable
        return toCelsius
            ? [(temp - 32) * 5 / 9, count]  // Convert to Celsius
            : [(temp * 9 / 5) + 32, count]; // Convert to Fahrenheit
    };
}

const convertTemp = temperatureConverter();
console.log(`100 degrees F is ${convertTemp(100, true)[0]} C`)
console.log(`0 degrees C is ${convertTemp(0, false)[0]} F`)

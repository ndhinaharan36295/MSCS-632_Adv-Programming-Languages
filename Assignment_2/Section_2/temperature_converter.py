def temperature_converter():
    count = 0  # Enclosed variable

    def convert(temp, to_celsius=True):
        nonlocal count  # Accessing the enclosing variable
        count += 1
        if to_celsius:
            return (temp - 32) * 5 / 9, count  # Convert to Celsius
        else:
            return (temp * 9 / 5) + 32, count  # Convert to Fahrenheit

    return convert

convert_temp = temperature_converter()
print(f"100 degrees F is {convert_temp(100, True)[0]} C")
print(f"0 degrees C is {convert_temp(0, False)[0]} F")

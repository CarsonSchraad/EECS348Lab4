#include <stdio.h>

// Converts Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

// Converts Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Converts Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Converts Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Converts Fahrenheit to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

// Converts Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Categorize the provided temperature and provide an advisory
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Advisory: Stay indoors if possible and bundle up!!\n");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Advisory: Dress warm and stay indoors when possible\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Advisory: Its a perfect day!! Go be outside\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Advisory: Dress light and drink water.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Advisory: Stay hyrdrated and don't go outside when possible.\n");
    }
}

int main() {
    char type, target;
    float temp;

    // Obtain temperature type in the form (F, C, K)
    do {
        printf("Enter the temperature type (F, C, K): ");
        scanf(" %c", &type);
    } while (type != 'F' && type != 'C' && type != 'K');

    // Obtain temperature and handle bad input
    do {
        printf("Enter the temperature: ");
        scanf("%f", &temp);
        if (type == 'K' && temp < 0) {
            printf("Error: Kelvin temperature cannot be below 0.\n");
        }
    } while (type == 'K' && temp < 0);

    // Obtain target type and handle bad input
    do {
        printf("Convert to (F, C, K): ");
        scanf(" %c", &target);
        if (target == type) {
            printf("Error: Cannot convert between the same temperature type.\n");
        }
    } while ((target != 'F' && target != 'C' && target != 'K') || target == type);

    float convertedTemp;
    float tempCelsius;

    // Conversion logic
    if (type == 'F') {
        if (target == 'C') {
            convertedTemp = fahrenheit_to_celsius(temp);
            printf("Temperature in Celsius: %.2f\n", convertedTemp);
            tempCelsius = convertedTemp;
        } else if (target == 'K') {
            convertedTemp = fahrenheit_to_kelvin(temp);
            printf("Temperature in Kelvin: %.2f\n", convertedTemp);
            tempCelsius = fahrenheit_to_celsius(temp);
        }
    } else if (type == 'C') {
        if (target == 'F') {
            convertedTemp = celsius_to_fahrenheit(temp);
            printf("Temperature in Fahrenheit: %.2f\n", convertedTemp);
        } else if (target == 'K') {
            convertedTemp = celsius_to_kelvin(temp);
            printf("Temperature in Kelvin: %.2f\n", convertedTemp);
        }
        tempCelsius = temp;
    } else if (type == 'K') {
        if (target == 'F') {
            convertedTemp = kelvin_to_fahrenheit(temp);
            printf("Temperature in Fahrenheit: %.2f\n", convertedTemp);
            tempCelsius = kelvin_to_celsius(temp);
        } else if (target == 'C') {
            convertedTemp = kelvin_to_celsius(temp);
            printf("Temperature in Celsius: %.2f\n", convertedTemp);
            tempCelsius = convertedTemp;
        }
    }

    // Categorize temperature
    categorize_temperature(tempCelsius);

    return 0;
}
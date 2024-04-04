#include <stdio.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float fahrenheitToKelvin(float fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvinToFahrenheit(float kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

int main() {
    int choice;
    float temp, fahrenheit, kelvin, celsius;

    printf("Choose the unit you want to convert: \n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%d", &choice);

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    switch(choice) {
        case 1:
            fahrenheit = celsiusToFahrenheit(temp);
            kelvin = celsiusToKelvin(temp);
            printf("Temperature in Fahrenheit: %f\n", fahrenheit);
            printf("Temperature in Kelvin: %f\n", kelvin);
            break;
        case 2:
            celsius = fahrenheitToCelsius(temp);
            kelvin = fahrenheitToKelvin(temp);
            printf("Temperature in Celsius: %f\n", celsius);
            printf("Temperature in Kelvin: %f\n", kelvin);
            break;
        case 3:
            celsius = kelvinToCelsius(temp);
            fahrenheit = kelvinToFahrenheit(temp);
            printf("Temperature in Celsius: %f\n", celsius);
            printf("Temperature in Fahrenheit: %f\n", fahrenheit);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
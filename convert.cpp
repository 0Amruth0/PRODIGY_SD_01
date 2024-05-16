#include <bits/stdc++.h>

using namespace std;

vector<double> convert_temperature(double temperature, char unit) {
    vector<double> result;

    switch (toupper(unit)) {
        case 'C':
            result.push_back(temperature * 9.0 / 5 + 32);
            result.push_back(temperature + 273.15);
            break;
        case 'F':
            result.push_back((temperature - 32) * 5.0 / 9);
            result.push_back(temperature + 459.67 * 5/9); 
            break;
        case 'K':
            result.push_back(temperature - 273.15);
            result.push_back(temperature * 9.0 / 5 - 32);
            break;
        default:
            cout << "Invalid unit. Please enter 'C', 'F', or 'K'." << endl;
            return result; 
    }

    return result;
}

int main() {
    double temperature;
    char unit;

    cout << "Enter temperature: ";
    cin >> temperature;

    cout << "Enter unit (C, F, or K): ";
    cin >> unit;

    vector<double> converted_temps = convert_temperature(temperature, unit);

    if (!converted_temps.empty()) {
        cout << setprecision(2) << fixed;
        cout << temperature << unit << " is equivalent to:" << endl;
        if (toupper(unit) == 'C'){
            cout << "- " << converted_temps[0] << " degrees Fahrenheit" << endl;
            cout << "- " << converted_temps[1] << " degrees Kelvin" << endl;
        } 
        else if (toupper(unit) == 'F'){
            cout << "- " << converted_temps[0] << " degrees Celsius" << endl;
            cout << "- " << converted_temps[1] << " degrees Kelvin" << endl;
        } 
        else if (toupper(unit) == 'K'){
            cout << "- " << converted_temps[0] << " degrees Celsius" << endl;
            cout << "- " << converted_temps[1] << " degrees Fahrenheit" << endl;
        }
    }

    return 0;
}
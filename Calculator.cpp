#include <bits/stdc++.h>
using namespace std;

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double square(double a);
double squareRoot(double a);
double exponentiate(double base, double exponent);

int main() {
    double number_1, number_2, result = 0;
    char operation;
    char continue_Calculations;

    do {
        cout << "                   === Welcome to the Advanced Calculator ===                  " << endl;

        
        cout << "Enter the first number: ";
        cin >> number_1;

       
        cout << "Choose an operation:" << endl;
        cout << "1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n";
        cout << "4. Division (/)\n5. Square (x^2)\n6. Square Root (sqrt)\n7. Exponentiation (x^n)\n";
        cout << "Enter the corresponding number of the operation: ";
        cin >> operation;

        
        switch (operation) {
            case '1':
                cout << "Enter the second number: ";
                cin >> number_2;
                result = add(number_1, number_2);
                break;
            case '2':
                cout << "Enter the second number: ";
                cin >> number_2;
                result = subtract(number_1, number_2);
                break;
            case '3':
                cout << "Enter the second number: ";
                cin >> number_2;
                result = multiply(number_1, number_2);
                break;
            case '4':
                cout << "Enter the second number: ";
                cin >> number_2;
                if (number_2 != 0) {
                    result = divide(number_1, number_2);
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            case '5':
                result = square(number_1);
                break;
            case '6':
                if (number_1 >= 0) {
                    result = squareRoot(number_1);
                } else {
                    cout << "Error: Cannot calculate square root of a negative number." << endl;
                }
                break;
            case '7':
                cout << "Enter the exponent: ";
                double exponent;
                cin >> exponent;
                result = exponentiate(number_1, exponent);
                break;
            default:
                cout << "Invalid operation. Please choose a valid operation." << endl;
                break;
        }

        if (!isnan(result)) {
            cout << "Result: " << result << endl;

           
            char storeInMemory;
            cout << "Do you want to store this result in memory? (y/n): ";
            cin >> storeInMemory;

            if (storeInMemory == 'y' || storeInMemory == 'Y') {
                result = result; 
                cout << "Result stored in memory." << endl;
            }
        }

        
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continue_Calculations;

    } while (continue_Calculations == 'y' || continue_Calculations == 'Y');

    cout << "Thanks for using the calculator!" << endl;
}


double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double square(double a) {
    return a * a;
}

double squareRoot(double a) {
    return sqrt(a);
}

double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}

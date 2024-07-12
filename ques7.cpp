#include <iostream>

using namespace std;

int sumOfDigits(int n) {
 
    if (n < 10)
        return n;
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int number;
    cout << "Enter a number : ";
    cin >> number;
    cout << "Sum of digits of " << sumOfDigits(number) << " is: "<< endl;

    return 0;
}

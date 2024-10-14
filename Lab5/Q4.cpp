#include <bits/stdc++.h>
using namespace std;

double f_prime(double x, double y) {
    return x*exp(3.0*x-2.0*y);
}

double f_actual(double x) {
    return (1.0/5.0)*x*exp(3.0*x) - (1.0/25.0)*exp(3.0*x) + (1.0/25.0)*exp(-2.0*x);
}

double Error(double t, double y, double h) {
    return abs(f_actual(t) - y);
}

double Euler_Method(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    int step = 0;
    while (x < xn) {
        y = y + h * f_prime(x, y);  
        x = x + h;            
        step++;
        cout << step << "\t " << x << "\t " << y << endl; 
    }
    return y;
}

int main() {
    double x0 = 0.0;  
    double y0 = 0.0;  
    double h = 0.5;   
    double xn = 1.0;  
    double y=Euler_Method(x0, y0, h, xn);
    cout << "Approximate value of y(1) is " << y << endl;
    cout << "Actual value of y(1) is " << f_actual(1) << endl;
    cout << "Error is " << Error(1, y, h) << endl;

    return 0;
}
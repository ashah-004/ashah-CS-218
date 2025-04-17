#include <bits/stdc++.h>
using namespace std;


double f (double x, double a){
    return((x*x)/log(x))+(a*x);
}

double findX(double a){
    double left = 1.000001, right = 2, diff = 1e-6;

    while(right-left > diff){
        double leftMin = left + (right-left)/3.0;
        double rightMin = right - (right-left)/3.0;

        if(f(leftMin, a) < f(rightMin, a)){
            right = rightMin;
        }else{
            left = leftMin;
        }
    }

    return left;
}

int main () {
    double a;
    cin >> a;

    double xMin = findX(a);
    double functionMin = f(xMin, a);

    cout << fixed << setprecision(9) << functionMin << endl;

    return 0;
}
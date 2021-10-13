//
// Created by s20151 on 13.10.2021.
//
#include <vector>
#include <functional>
#include <iostream>

using namespace std;



int main(){

    auto three_hump_camel_function = [](vector<double> v) {
        double x = v.at(0), y = v.at(1);
        return 2*(pow(x,2)) - 1.05*(pow(x,4)) + (pow(x,6)/6) + x*y + pow(y,2);
    };

    auto three_hump_camel_function_domain = [](vector<double> v) {
        return (abs(v[0]) <= 5) && (abs(v[1]) <= 5);
    };

    auto bukin_function_n6 = [](vector<double> v) {
        double x = v.at(0), y = v.at(1);
        return 100* sqrt(abs(y-(0.01* pow(x,2))))+0.01* abs(x+10);
    };

    auto bukin_function_n6_domain = [](vector<double> v) {
        return (v[0] >= -15) && (v[0]<= -5) && (abs(v[1]) <= 3);
    };
}

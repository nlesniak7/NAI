//
// Created by s20151 on 13.10.2021.
//
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <random>
#include <vector>

using namespace std;

ostream& operator<<(ostream& o, vector<double> v){
    for (auto e : v) {
        o << std::fixed << std::setprecision(5) << "\t" << e;
    }
    return o;
}

vector<double> operator+(vector<double> a, vector<double> b){
    for (int i = 0; i < a.size(); i++) {
        a[i] += b[i];
    }
    return a;
}

random_device rd;  //Will be used to obtain a seed for the random number engine
mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

vector<double> hill_climbing(function<double(vector<double>)> f, function<bool(vector<double>)> f_domain, vector<double> p0, int iterations){
    auto p = p0;
    uniform_int_distribution<> distrib(0, p.size() - 1);
    uniform_real_distribution<> distrib_r(-0.1, 0.1);

    if (!f_domain(p)) throw std::invalid_argument("The p0 point must be in domain");
    for (int i = 0; i < iterations; i++) {
        auto p2 = p;

        p[distrib(gen)] += distrib_r(gen);
        double y2 = f(p2);
        if (y2 < f(p)) {
            p = p2;
        }
    }
    return p;
}

auto three_hump_camel_function = [](vector<double> v) {
    double x = v.at(0), y = v.at(1);
    return 2*(pow(x,2)) - 1.05*(pow(x,4)) + (pow(x,6)/6) + x*y + pow(y,2);
};

auto three_hump_camel_function_domain = [](vector<double> v) {
    return (abs(v[0]) <= 5) && (abs(v[1]) <= 5);
};

auto eggholder_function = [](vector<double> v) {
    double x = v.at(0), y = v.at(1);
    return -1*(y+47) * sin(sqrt(abs(x/2+(y+47))))
    - x * sin(sqrt(abs(x-(y+47))));
};

auto eggholder_function_domain = [](vector<double> v) {
    return (abs(v[0]) <= 512) && (abs(v[1]) <= 512);
};

int main(){
    int user_input = 0;
    cout<<"Pick function: 1 - Three hump camel function, 2 - Eggholder function"<<endl;
    cin>>user_input;
    while(user_input!=1 && user_input!=2){
        cout<<"Pick 1 or 2"<<endl;
        cin>>user_input;
    }
    int iterations = 0;
    cout<<"Iterations amount: "<<endl;
    cin>> iterations;
    while(iterations<1){
        cout<<"Iterations amount must be bigger than 0";
        cin>>iterations;
    }
    if(user_input==1){
        uniform_real_distribution<> distrib_r(-5, 5);
        vector<double> three_hump_p0 = {
                distrib_r(gen),
                distrib_r(gen),
        };
        auto r = hill_climbing(three_hump_camel_function, three_hump_camel_function_domain, three_hump_p0, iterations);
        cout<< r << " >>> " << three_hump_camel_function(r)<<endl;
    }else{
        uniform_real_distribution<> distrib_r(-512, 512);
        vector<double> eggholder_function_p0 = {
                distrib_r(gen),
                distrib_r(gen),
        };
        auto r = hill_climbing(eggholder_function, eggholder_function_domain, eggholder_function_p0, iterations);
        cout<< r << " >>> " << eggholder_function(r)<<endl;
    }

}

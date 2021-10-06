#include <iostream>
#include <tuple>
#include <functional>

auto obliczenia = [](auto f1, auto f2, int n) {
    int max_x = f1(0);
    int max_y = f2(max_x);
    for(int i=1; i<n; i++){
        int x = f2(i);
        int y = f2(x);
        if (y > max_y) {
            max_x = y;
            max_y = y;
        }
    }
    int pkt[2] = {max_x, max_y};
    return pkt;
};

std::function<int(int)> f1 = [](int x){ return x; };
std::function<int(int)> f2 = [](int x){ return x; };

int main() {

    return 0;
}
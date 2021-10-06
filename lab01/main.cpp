#include <iostream>
#include <tuple>
#include <functional>

auto obliczenia = [](auto f1, auto f2, int n) {
    using namespace std;
    int max_x = f1(0);
    int max_y = f2(max_x);
    for(int i=1; i<n; i++){
        int x = f2(i);
        int y = f1(x);
        if (y > max_y) {
            max_x = x;
            max_y = y;
        }
    }
    int pkt[2] = {max_x, max_y};
    cout<<pkt[0] << ":" << pkt[1]<<endl;
    return pkt;
};

std::function<int(int)> f1 = [](int x){ return 20-abs(x); };
std::function<int(int)> f2 = [](int i){ return (2*(i%2)-1)*i/2; };

int main() {
    obliczenia(f1,f2,5);
    return 0;
}
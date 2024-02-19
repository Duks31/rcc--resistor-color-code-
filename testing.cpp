#include <iostream>

using namespace std;

struct Point{
    int x = 3;
    double y = 34.2;
};

int main(){
    struct Point p;

    cout << p.x << endl;
    cout << p.y << endl;
}
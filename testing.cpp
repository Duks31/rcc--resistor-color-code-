#include <iostream>
#include <unordered_map>

using namespace std;

struct Point{
    int x = 3;
    double y = 34.2;
};

int main(){
    // struct Point p;

    // cout << p.x << endl;
    // cout << p.y << endl;

    unordered_map<string, int> umap = {
        {"Geek", 1},
        {"For", 2},
        {"Geeks", 3}	
    };

    for (auto x : umap)
        cout << x.first << " " << x.second 
        << endl;

    return 0;
}
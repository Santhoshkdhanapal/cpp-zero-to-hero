#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v = {5, 3, 2, 1, 4};

    // Sort vector (by default in ascending order)
    sort(v.begin(), v.end());

    for (int i : v)
        cout << i << " ";
    return 0;
}
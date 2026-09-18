#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40};

    // Using iterator to traverse the vector
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " "; 

    return 0;
}
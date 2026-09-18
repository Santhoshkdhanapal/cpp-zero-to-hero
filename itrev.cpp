#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    // Defining a reverse iterator pointing to the last element
    auto it = vec.rbegin();

    // Iterating the vector in reverse
    while (it != vec.rend())
    {
        cout << *it << " ";
        ++it;
    }

    return 0;
}
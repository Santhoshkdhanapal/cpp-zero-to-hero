#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    // Normal iterator
    cout << "Forward iteration: ";
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Constant iterator
    cout << "Forward (read-only) iteration: ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iterator
    cout << "Reverse iteration: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
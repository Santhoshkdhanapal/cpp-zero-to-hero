#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(10);
    q.push(5);

    // Accessing the front and back elements
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // Removing an element from the front
    q.pop();

    cout << "Front element after pop: " << q.front() << endl;

    return 0;
}
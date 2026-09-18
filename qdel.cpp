#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    // Insert elements into the queue
    q.push(3);
    q.push(4);
    q.push(5);

    // Remove the front element
    q.pop();

    // Print and remove the remaining elements
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
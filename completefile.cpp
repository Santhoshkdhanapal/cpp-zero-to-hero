#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Open a file in read mode
    ifstream file("GFG.txt");
    string s;

    // Read string from the file
    getline(file, s);

    cout << "Read String: " << s;

    return 0;
}
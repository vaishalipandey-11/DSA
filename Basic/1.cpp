
// Basic Input/Output

/*#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;             // Input
    cout << a << endl;    // Output
    return 0;
}*/

// Data Types
// Primitive: int, float, double, char, bool
// Derived: array, string, vector, pair
// User-defined: struct, class

// Conditionals and Loops

/*   if (condition) {
    // code
} else if (condition) {
    // code
} else {
    // code
}

for (int i = 0; i < n; ++i) {
    // code
}

while (condition) {
    // code
}

do {
    // code
} while (condition);
*/

// Functions

/*
int add(int a, int b) {
    return a + b;
}
*/

// Function overloading
/*
int max(int a, int b) { return (a > b) ? a : b; }
float max(float a, float b) { return (a > b) ? a : b; }
*/

// Pointers
/*
int x = 5;
int* p = &x;       // Pointer to x
cout << *p;        // Dereferencing
*/

// Arrays

/*
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; ++i) {
    cout << arr[i];
}
*/

// Vectors (Dynamic Arrays)

/*
#include <vector>
vector<int> v;
v.push_back(1);       // Add element
v.pop_back();         // Remove last element
cout << v.size();     // Get size

for (int i : v) {
    cout << i;        // Range-based loop
}
*/

// Pairs and Tuples

/*
#include <utility>
pair<int, int> p = {1, 2};
cout << p.first << " " << p.second;

#include <tuple>
tuple<int, int, int> t = {1, 2, 3};
cout << get<0>(t);
*/

// Strings

/*
#include <string>
string s = "hello";
s += " world";
cout << s.length();
*/
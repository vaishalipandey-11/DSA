// 1.1 Vectors
/*
#include <vector>
vector<int> v = {1, 2, 3};
v.push_back(4);               // Add 4 to the end
v.pop_back();                 // Remove last element
cout << v.size();             // Size of the vector
cout << v[0];                 // Access element
v.clear();                    // Remove all elements

// Iterating
for (int x : v) cout << x;    // Range-based loop
for (auto it = v.begin(); it != v.end(); ++it) cout << *it;

*/

// 1.2 Deque
/*
#include <deque>
deque<int> dq;
dq.push_back(1);             // Add to back
dq.push_front(2);            // Add to front
dq.pop_back();               // Remove from back
dq.pop_front();              // Remove from front

*/

// 1.3 List

/*
#include <list>
list<int> lst = {1, 2, 3};
lst.push_back(4);            // Add to end
lst.push_front(0);           // Add to front
lst.pop_back();              // Remove from end
lst.pop_front();             // Remove from front

// Iterating
for (int x : lst) cout << x;
lst.reverse();               // Reverse the list
lst.sort();                  // Sort the list

*/

// 1.4 Sets
/*
#include <set>
set<int> s = {1, 2, 3};
s.insert(4);                 // Insert
s.erase(2);                  // Remove element
cout << s.count(3);          // Check presence (1 or 0)
cout << *s.begin();          // Smallest element

*/

// Multiset(Allows duplicate elements.)
/*
#include <set>
multiset<int> ms = {1, 2, 2, 3};
ms.insert(2);                // Add duplicate
ms.erase(ms.find(2));        // Erase one occurrence

*/

// 1.5 Maps (Key-value pairs, sorted by key.)

/*
#include <map>
map<int, string> mp;
mp[1] = "one";
mp[2] = "two";
cout << mp[1];               // Access value by key

// Iterating
for (auto &p : mp) cout << p.first << " " << p.second;

*/

// Multimap(Allows duplicate keys)
/*
#include <map>
multimap<int, string> mmp;
mmp.insert({1, "one"});
mmp.insert({1, "uno"});      // Duplicate key
*/

// 1.6 Priority Queue (Heap-based structure for quick max/min retrieval.)

/*
// max heap
#include <queue>
priority_queue<int> pq;
pq.push(10);
pq.push(5);
cout << pq.top();            // Largest element (10)
pq.pop();                    // Remove largest

//min heap
priority_queue<int, vector<int>, greater<int>> pq_min;
pq_min.push(10);
pq_min.push(5);
cout << pq_min.top();        // Smallest element (5)
pq_min.pop();                // Remove smallest

*/

// 1.7 Stack(LIFO structure (Last In, First Out).)

/*
#include <stack>
stack<int> st;
st.push(1);                  // Push element
st.pop();                    // Remove top element
cout << st.top();            // Access top element
cout << st.size();           // Stack size
*/

// 1.8 Queue (FIFO structure (First In, First Out).)

/*
#include <queue>
queue<int> q;
q.push(1);                   // Add element
q.pop();                     // Remove front
cout << q.front();           // Front element
*/

// 1.9 Unordered Containers (Unordered versions of sets and maps for faster average O(1) operations.)

/*
#include <unordered_set>
unordered_set<int> us = {1, 2, 3};
us.insert(4);

#include <unordered_map>
unordered_map<int, string> um;
um[1] = "one";
*/

/**/

/**/

/**/

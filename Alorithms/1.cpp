// 2. Algorithms


//2.1 Sorting

/*
#include <algorithm>
vector<int> v = {3, 1, 2};
sort(v.begin(), v.end());            // Ascending
sort(v.rbegin(), v.rend());          // Descending

*/

//2.2 Searching

/*
#include <algorithm>
vector<int> v = {1, 2, 3, 4, 5};
if (binary_search(v.begin(), v.end(), 3)) cout << "Found";

*/

//2.3 Minimum/Maximum
/*
#include <algorithm>
cout << min(10, 20);
cout << max(10, 20);

*/

//2.4 Permutations
/*
#include <algorithm>
string s = "abc";
do {
    cout << s << endl;
} while (next_permutation(s.begin(), s.end()));

*/

//2.5 Lower/Upper Bound
// (Lower Bound: Smallest index where val >= key
// Upper Bound: Smallest index where val > key
// )
/*
#include <algorithm>
vector<int> v = {1, 2, 2, 3};
auto lb = lower_bound(v.begin(), v.end(), 2); // Points to first 2
auto ub = upper_bound(v.begin(), v.end(), 2); // Points to 3

*/

//3. Utilities
// 3.1 Pair
/*
#include <utility>
pair<int, int> p = {1, 2};
cout << p.first << " " << p.second;
*/

//3.2 Tuple
/*
#include <tuple>
tuple<int, int, int> t = {1, 2, 3};
cout << get<0>(t);
*/

//4. Common Patterns
// Custom Comparator
// (For sorting)
/*
#include <algorithm>
bool cmp(int a, int b) {
    return a > b;            // Descending order
}

sort(v.begin(), v.end(), cmp);

*/

//Frequency Count

/*
#include <map>
map<int, int> freq;
for (int x : v) freq[x]++;

*/

//Two-Pointer Technique

/*
int i = 0, j = n - 1;
while (i < j) {
    if (arr[i] + arr[j] == target) {
        // Do something
    }
    i++;
    j--;
}

*/

//
/*
*/

//
/*
*/

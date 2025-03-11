/*
# Space Complexity Cheat Sheet

# 1. Basic Operations
- Variable allocation: O(1)
- Arithmetic operations: O(1)
- Recursion: O(n) for depth of recursion

# 2. Arrays and Lists
- Static array: O(n) where n is the size of the array
- Dynamic array (resizing): O(n) for resizing operations
- Linked list (singly/doubly): O(n)

# 3. Strings
- String (in memory): O(n), where n is the string length
- String concatenation (naive): O(n) - can be optimized

# 4. Hash Tables
- Hash Map/Hash Set: O(n) where n is the number of elements in the map/set
- Hash table overhead: O(m), where m is the number of buckets in the table

# 5. Trees
- Binary Tree (unbalanced): O(n) for storing nodes
- Balanced Binary Search Tree (BST) (AVL, Red-Black Tree): O(n)
- Binary Heap: O(n)

# 6. Graphs
- Adjacency Matrix: O(V^2), where V is the number of vertices (for dense graphs)
- Adjacency List: O(V + E), where V is the number of vertices and E is the number of edges (for sparse graphs)

# 7. Stacks and Queues
- Stack (using linked list): O(n) where n is the number of elements
- Queue (using linked list): O(n)

# 8. Recursion
- Recursion stack space: O(n) for depth of recursive calls (if using tail recursion, space complexity can be optimized)
- Example: Merge Sort (Recursive) - O(n) space for the recursion stack

# 9. Dynamic Programming
- 1D DP array: O(n) where n is the size of the problem space
- 2D DP array: O(n * m) where n and m are dimensions of the problem
- Optimized DP (space reduction): O(1) or O(n) depending on whether previous states are stored

# 10. Sorting Algorithms
- Merge Sort: O(n) for extra space used during merging
- Quick Sort: O(log n) for space used in recursion (best case), O(n) for stack space in worst case
- Heap Sort: O(1) since it sorts in place

# 11. Other Important Notes
- **In-place algorithm**: An algorithm that uses O(1) extra space (e.g., Bubble Sort, Insertion Sort)
- **Out-of-place algorithm**: An algorithm that requires O(n) extra space (e.g., Merge Sort, Counting Sort)
*/
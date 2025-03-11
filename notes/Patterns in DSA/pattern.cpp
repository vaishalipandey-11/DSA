// 1. Sliding Window Pattern


// Efficiently handle problems with contiguous subarrays or substrings.

// Example: Maximum Sum Subarray of Size K

                /*
                int maxSumSubarray(vector<int>& arr, int k) {
                    int maxSum = 0, windowSum = 0;
                    int n = arr.size();
                    for (int i = 0; i < n; i++) {
                        windowSum += arr[i];
                        if (i >= k - 1) {
                            maxSum = max(maxSum, windowSum);
                            windowSum -= arr[i - (k - 1)];
                        }
                    }
                    return maxSum;
                }
                */



// 2. Two Pointers Pattern
// Solve problems involving sorted arrays, or when you need to find pairs/triplets.

// Example: Two Sum (Sorted Array)
            /*
            bool twoSum(vector<int>& nums, int target) {
                int left = 0, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum == target) return true;
                    if (sum < target) left++;
                    else right--;
                }
                return false;
            }
            */



//  3. Fast and Slow Pointer Pattern (Tortoise and Hare)
// Detect cycles in linked lists or arrays.

// Example: Cycle Detection in Linked List          
            /*
            bool hasCycle(ListNode* head) {
                ListNode *slow = head, *fast = head;
                while (fast && fast->next) {
                    slow = slow->next;
                    fast = fast->next->next;
                    if (slow == fast) return true;
                }
                return false;
            }
            */



//  4. Merge Intervals Pattern
// Solve problems involving overlapping intervals.

// Example: Merge Overlapping Intervals

            /*
            vector<vector<int>> merge(vector<vector<int>>& intervals) {
                sort(intervals.begin(), intervals.end());
                vector<vector<int>> merged;
                for (auto& interval : intervals) {
                    if (merged.empty() || merged.back()[1] < interval[0])
                        merged.push_back(interval);
                    else
                        merged.back()[1] = max(merged.back()[1], interval[1]);
                }
                return merged;
            }
            */



// 5. Cyclic Sort Pattern
// Handle problems with numbers in a specific range, like 1 to N.

// Example: Find Missing Number
                /*
                int missingNumber(vector<int>& nums) {
                    int i = 0, n = nums.size();
                    while (i < n) {
                        if (nums[i] < n && nums[i] != nums[nums[i]])
                            swap(nums[i], nums[nums[i]]);
                        else
                            i++;
                    }
                    for (int i = 0; i < n; i++) {
                        if (nums[i] != i) return i;
                    }
                    return n;
                }
                */



//  6. Backtracking Pattern
// Solve problems that require all possible combinations, subsets, or permutations.

// Example: N-Queens Problem
                /*
                void solveNQueens(int col, vector<string>& board, vector<vector<string>>& res, vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag, int n) {
                    if (col == n) {
                        res.push_back(board);
                        return;
                    }
                    for (int row = 0; row < n; row++) {
                        if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) {
                            board[row][col] = 'Q';
                            leftRow[row] = lowerDiag[row + col] = upperDiag[n - 1 + col - row] = 1;
                            solveNQueens(col + 1, board, res, leftRow, upperDiag, lowerDiag, n);
                            board[row][col] = '.';
                            leftRow[row] = lowerDiag[row + col] = upperDiag[n - 1 + col - row] = 0;
                        }
                    }
                }
                */

                            

//    7. Binary Search Pattern
// Efficiently find elements in sorted arrays.

// Example: Search in Rotated Sorted Array

            /*
            int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                 int mid = left + (right - left) / 2;
                    if (nums[mid] == target) return mid;
                    if (nums[left] <= nums[mid]) {
                     if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                        else left = mid + 1;
                    } else {
                        if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                        else right = mid - 1;
                    }
                }
                return -1;
            }
            */             




//  8. Dynamic Programming Pattern
//    Solve problems by breaking them into subproblems and storing intermediate results.

// Example: Longest Common Subsequence
                /*
                int longestCommonSubsequence(string text1, string text2) {
                int m = text1.size(), n = text2.size();
                vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
                for (int i = 1; i <= m; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (text1[i - 1] == text2[j - 1])
                            dp[i][j] = 1 + dp[i - 1][j - 1];
                        else
                            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
                return dp[m][n];
            }
            */   




//  9. Greedy Pattern
// Make local optimal choices to solve the problem.

// Example: Minimum Number of Platforms         
            /*
            int findPlatform(int arr[], int dep[], int n) {
                sort(arr, arr + n);
                sort(dep, dep + n);
                int platforms = 1, maxPlatforms = 1, i = 1, j = 0;
                while (i < n && j < n) {
                    if (arr[i] <= dep[j]) {
                        platforms++;
                        i++;
                    } else {
                        platforms--;
                        j++;
                    }
                    maxPlatforms = max(maxPlatforms, platforms);
                }
                return maxPlatforms;
            }
            */ 


//  10. Topological Sort Pattern
// Used for ordering in directed acyclic graphs (DAG).

// Example: Course Schedule          
            /*
            bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                vector<int> indegree(numCourses, 0);
                vector<vector<int>> adj(numCourses);
                for (auto& pre : prerequisites) {
                    adj[pre[1]].push_back(pre[0]);
                    indegree[pre[0]]++;
                }
                queue<int> q;
                for (int i = 0; i < numCourses; i++)
                    if (indegree[i] == 0) q.push(i);
                int count = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    count++;
                    for (int neighbor : adj[node]) {
                        indegree[neighbor]--;
                        if (indegree[neighbor] == 0) q.push(neighbor);
                    }
                }
                return count == numCourses;
            }
            */

// 11. Divide and Conquer Pattern
// Break a problem into smaller subproblems, solve them independently, and combine their results.

// Example: Merge Sort
            /*
            void merge(vector<int>& arr, int left, int mid, int right) {
                vector<int> temp(right - left + 1);
                int i = left, j = mid + 1, k = 0;
                while (i <= mid && j <= right) {
                    if (arr[i] <= arr[j]) temp[k++] = arr[i++];
                    else temp[k++] = arr[j++];
                }
                while (i <= mid) temp[k++] = arr[i++];
                while (j <= right) temp[k++] = arr[j++];
                for (int i = 0; i < temp.size(); i++) arr[left + i] = temp[i];
            }

            void mergeSort(vector<int>& arr, int left, int right) {
                if (left >= right) return;
                int mid = left + (right - left) / 2;
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);
                merge(arr, left, mid, right);
            }

            */




  //12. Matrix Traversal Pattern
// Handle problems involving traversal or pathfinding in 2D grids.

// Example: Flood Fill Algorithm
                /*
                void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
                    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != color)
                        return;
                    image[x][y] = newColor;
                    dfs(image, x + 1, y, color, newColor);
                    dfs(image, x - 1, y, color, newColor);
                    dfs(image, x, y + 1, color, newColor);
                    dfs(image, x, y - 1, color, newColor);
                }

                vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
                    if (image[sr][sc] != newColor)
                        dfs(image, sr, sc, image[sr][sc], newColor);
                    return image;
                }

                */         


 //13. Union-Find (Disjoint Set Union) Pattern
        // Used for connected components, cycle detection, and Kruskal’s MST.

        // Example: Detect Cycle in Undirected Graph

            /*
            int findParent(int node, vector<int>& parent) {
                if (node == parent[node]) return node;
                return parent[node] = findParent(parent[node], parent);
            }

            bool unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
                int pu = findParent(u, parent);
                int pv = findParent(v, parent);
                if (pu == pv) return false;
                if (rank[pu] > rank[pv]) parent[pv] = pu;
                else if (rank[pu] < rank[pv]) parent[pu] = pv;
                else {
                    parent[pv] = pu;
                    rank[pu]++;
                }
                return true;
            }

            */         



 //14. Bit Manipulation Pattern
    // Solve problems using binary operations.

    // Example: Subsets (Power Set)
        /*
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            int n = nums.size();
            for (int i = 0; i < (1 << n); i++) {  // 2^n subsets
                vector<int> subset;
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) subset.push_back(nums[j]);
                }
                res.push_back(subset);
            }
            return res;
        }

        */         



 //15. Monotonic Stack Pattern
// Used for problems like "next greater element."

// Example: Next Greater Element
            /*
            vector<int> nextGreaterElements(vector<int>& nums) {
                vector<int> res(nums.size(), -1);
                stack<int> st;
                for (int i = 0; i < 2 * nums.size(); i++) {
                    while (!st.empty() && nums[st.top()] < nums[i % nums.size()]) {
                        res[st.top()] = nums[i % nums.size()];
                        st.pop();
                    }
                    if (i < nums.size()) st.push(i);
                }
                return res;
            }

            */         






 //16. BFS and DFS Pattern
        // Handle problems like shortest path, connected components, or graph traversal.

        // Example: Shortest Path in Unweighted Graph
                /*
                vector<int> shortestPath(vector<vector<int>>& edges, int n, int start) {
                    vector<vector<int>> adj(n);
                    for (auto& edge : edges) {
                        adj[edge[0]].push_back(edge[1]);
                        adj[edge[1]].push_back(edge[0]);
                    }
                    vector<int> dist(n, -1);
                    queue<int> q;
                    q.push(start);
                    dist[start] = 0;
                    while (!q.empty()) {
                        int node = q.front();
                        q.pop();
                        for (int neighbor : adj[node]) {
                            if (dist[neighbor] == -1) {
                                dist[neighbor] = dist[node] + 1;
                                q.push(neighbor);
                            }
                        }
                    }
                    return dist;
                }

                */         




 //17. Kadane’s Algorithm
    // Find maximum/minimum subarray sums in O(n).

    // Example: Maximum Subarray Sum

                /*
                int maxSubArray(vector<int>& nums) {
                    int maxSum = nums[0], currSum = nums[0];
                    for (int i = 1; i < nums.size(); i++) {
                        currSum = max(nums[i], currSum + nums[i]);
                        maxSum = max(maxSum, currSum);
                    }
                    return maxSum;
                }

                */         




 //18. Prefix Sum and Difference Array
// Optimize range queries or updates.

// Example: Range Sum Query
                /*
                vector<int> prefixSum(vector<int>& nums) {
                    vector<int> prefix(nums.size(), 0);
                    prefix[0] = nums[0];
                    for (int i = 1; i < nums.size(); i++) {
                        prefix[i] = prefix[i - 1] + nums[i];
                    }
                    return prefix;
                }

                int rangeSum(vector<int>& prefix, int l, int r) {
                    return l == 0 ? prefix[r] : prefix[r] - prefix[l - 1];
                }

                */         


 //19. Top-Down and Bottom-Up DP
        // Used to solve overlapping subproblems.

        // Example: Fibonacci Sequence (Top-Down)


        /*int fib(int n, vector<int>& dp) {
            if (n <= 1) return n;
            if (dp[n] != -1) return dp[n];
            return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
        }

        */         


 //20. Tree Traversal Pattern
    // Preorder, Inorder, Postorder, Level-order traversal.

    // Example: Level-Order Traversal
            /*
            vector<vector<int>> levelOrder(TreeNode* root) {
                vector<vector<int>> res;
                if (!root) return res;
                queue<TreeNode*> q;
                q.push(root);
                while (!q.empty()) {
                    int size = q.size();
                    vector<int> level;
                    for (int i = 0; i < size; i++) {
                        TreeNode* node = q.front();
                        q.pop();
                        level.push_back(node->val);
                        if (node->left) q.push(node->left);
                        if (node->right) q.push(node->right);
                    }
                    res.push_back(level);
                }
                return res;
            }

            */         





 //
  /*
  */         





 //
  /*
  */         




 //
  /*
  */         
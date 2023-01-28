# DFS

## Problem list

* Subset
  * [78. Subsets](https://leetcode.com/problems/subsets/)
  * [90. Subsets II](https://leetcode.com/problems/subsets-ii/)

* Combination
  * [77. Combinations](https://leetcode.com/problems/combinations/)
  * [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
  * [39. Combination Sum](https://leetcode.com/problems/combination-sum/)
  * [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)
  * [216. Combination Sum III](https://leetcode.com/problems/combination-sum-iii/)

* Permutation
  * [46. Permutations](https://leetcode.com/problems/permutations/)
  * [47. Permutations II](https://leetcode.com/problems/permutations-ii/)

* Cutting
  * [131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)
  * [93. Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)

* Checkerboard
  * [51. N-Queens](https://leetcode.com/problems/n-queens/)
  * [37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)

* Island
  * [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)
  * [1254. Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/)
  * [1020. Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)
  * [695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
  * [1905. Count Sub Islands](https://leetcode.com/problems/count-sub-islands/)
  * [694. Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands/)

* Others
  * [491. Non-decreasing Subsequences](https://leetcode.com/problems/non-decreasing-subsequences/)
  * [332. Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)

## Subset

The subset problem can be divided into two categories based on whether the elements of the target array have duplicate parts:

1. The elements of the target array are completely different
2. the target array is partially duplicated

The pruning of the subset problem is a de-duplication operation for case 2, and there are three ways to de-duplicate (note that first sorting of the candidate array).

1. `set`

```
unordered_set<int> uset;
for (int i = startidx; i < nums.size(); ++i) {
    if (uset.find(nums[i]) != uset.end()) continue;
    uset.insert(nums[i]);
    tmp.push_back(nums[i]);
    dfs(nums, i + 1);
    tmp.pop_back();
}
```

2. `used` array

```
for (int i = startidx; i < nums.size(); ++i) {
    if ((i > 0) && (nums[i] == nums[i - 1]) && (used[i - 1] == false)) continue;
    tmp.push_back(nums[i]);
    used[i] = true;
    dfs(nums, i + 1, used);
    used[i] = false;
    tmp.pop_back();
}
```

3. `if` (without `used` array)

```
for (int i = startidx; i < nums.size(); ++i) {
    if ((i > startidx) && (nums[i] == nums[i - 1])) {
    	continue;
    }
    tmp.push_back(nums[i]);
    dfs(nums, i + 1);
    tmp.pop_back();
}
```

## Combination

Similar to the subset problem, the `candidates` array of the combination problem can be divided into two categories with/without duplicate elements, but the combination problem also considers whether the `k` value (the size of the subarray `tmp`) is given and whether the `candidates` array elements can be reused, etc.

* For `candidates` array elements whether there are duplicates and how many times they can be used
When the `candidates` array contains duplicate elements (Each element of the `candidates` array can only be used a maximum of 1 time by the `tmp` array, otherwise the duplication of the elements of the `candidates` array itself is meaningless), you must use `sort + de-duplication`, in this case, the de-duplication operation is the same as in the subset problem. And when the `tmp` array can use any element of the `candidates` array multiple times, then use `sort + prune i`.

* For `startidx` and `i`.
Combination problem for path exploration at a node, **start position `startidx` (generally `startidx`, `startidx` is required for single array combinations,  but not required for multi-array combinations, see [17. Letter combinations](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)) == recursively pass `startidx == i + 1` (any element is used at most once) or `i` (any element is used an unlimited number of times, and `i` is pruned at the end of the loop condition)**. Specifically, when the `candidates` array does not contain duplicate elements and the `tmp` array has no limit on the number of times the elements of the candidates array can be used, the `startidx` passed in recursively should be `i` so that the loop starts from `startidx` after entering recursion, not from `0`, for the following reasons.

<img src="difference.png">

The case where any element is used at most once (`startidx==i+1`) is not repeated, for the same reason.

* For K.
The value of K is given or not directly affects pruning (the for-loop termination condition, i.e. the range of `i`): `;i<candidates.size()-k+tmp.size()+1;`
But pruning of the i range operation does not affect the end condition. If [39. Combination Sum](https://leetcode.com/problems/combination-sum/) and [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) add the constraint `k`, don't forget to fix the end condition.

## Permutation

Similarly, permutation problems can be divided into two categories based on whether the elements within thecandidates array are repeated or not, but differ from combination problems with the following characteristics.

* Each level is searched from `0` instead of `startidx`
* need `used` array to record which elements have been put in the `tmp` array

*talk is cheap:*

For the array of non-duplicate elements `candidates`

```
for (int i = 0; i < candidates,size(); ++i) {
    if (used[i]) continue;
    tmp.emplace_back(candidates[i]);
    used[i] = true;
    dfs(…);
    used[i] = false;
    tmp.pop_back();
}
```

For the array of duplicate elements `candidates`.

```
sort();
for() {
    if ((i > 0) && (candidates[i] == candidates[i-1]) && (used[i-1] == false) continue;
    if (!used[i]) {
        tmp.emplace_back(candidates[i]);
        used[i] = true;
        dfs();
        used[i] = false;
        tmp.pop_back();
    }
}
```

## Cutting

The cutting problem deals with strings in general. The cutting problem has two difficulties, the first is to abstract it into a combination problem, and the second is the understanding of the cutting interval division(`startidx` and `i`). Once the abstraction and interval division are done, it is not difficult to write the following recursive backtracking code framework.

```
dfs(…,idx) {
    …//Leaf node: end condition + result collection
    for(int i = idx; i < s.size(); ++i){
        if (!isValid(a, startidx, i)) continue; // pruning operations, determine whether the pre-order substring [startidx,i] satisfies the condition
        … // pre-order
        dfs(…, i + 1);
        … // post-order
    }
}
```

The cutting conditions given in the problems can be transformed into pruning operations (palindromes, ip, etc.). The introduction of judgments or operations on strings often weakens the difficulty of the problems, and specific code implementations are not displayed here.

## Checkerboard

### N Queens

The search for the entire board is performed from left to right and from top to bottom. The downward traversal of nodes all starts at `0` and stops at `N-1`, i.e. `i∈[0,N)`. The depth of the recursion, i.e. `startidx`, is also `[0,N)`. After confirming the width and depth of the traversal, the dfs entry can also be confirmed, that is: `chessbox + N + startidx`.

Still remember how the cutting problem is pruned? Yes, similar to the cut problem, the N queen problem is also based on the conditions of the node preorder traversal to pruning, and different with cutting problem: the cutting problem pruning judgment is only for the preorder substring itself, while the N queen pruning is required to observe the path.

It is not difficult to write the following core code.

```
dfs(){
    if (startidx == N) {
        res.emplace_back(chessbox);
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!isValid()) continue; // pruning operations, determine whether the pre-order position [startidx,i] satisfies the condition
        chessbox[startidx, i] = ’Q’;
        dfs(…, startidx + 1);
        chessbox[startidx][i] = ’.’;
    }
}
```

Pruning implementation.

```
bool isValid(){
    for (){if () return false;} // rows
    for (){if () return false;} // column
    for (){if () return false;} // top left corner
    for (){if () return false;} // top right corner
    return true;
}
```

### Sudoku Solver

After solving the N Queens problem, can we write the answer to Sudoku Solver? Listed here are the two ways of recursion by row traversal and two-dimensional recursion (row + column).

#### Core code

1. Iteration by rows

```
bool dfs(vector<vector<char>>& board, int i, int j) {
    if (j == 9) {
        return dfs(board, i + 1, 0);
    }
    if (i == 9) {return true;}
    if (board[i][j] != '.') {
        return dfs(board, i, j + 1);
    }
    for (char val = '1'; val <= '9'; ++val) {
        if (!isValid(board, i, j, val)) continue;
        board[i][j] = val;
        if(dfs(board, i, j + 1)) return true;
        board[i][j] = '.';
    }
    return false;
}
```

2. 2-D deep search

```
bool dfs() {
    for (int i = 0; i < 9; ++i) { // row
        for (int j = 0; j <9; ++j) { // colunm
            if (board[i][j] != '.') continue;
            for (char val = '1'; val <= '9'; ++val) { // determine whether [i, j] could write down `val`
            	if (isValid(i, j, val, board)) {
                    board[i][j] = val; // write down `val`
                    if (dfs(board)) return true; // return immediately
                    board[i][j] = '.'; // backtrace，erase `val`
                }
            }
            return false; // all fail
        }
    }
    return true;
}
```

#### pruning

* plain pruning:

```
bool isValid(){
    for (int i = 0; i < 9; i) {if (board[row][i] == val) return false;} // row
    for (int j = 0; j < 9; j) {if (board[j][col] == val) return false;} // column
    for (int sr=row/3*3;sr< row/3*3+3;++sr) { // 3x3块
    	for (int sc = col / 3 * 3; sc < col / 3 * 3 + 3; ++sc) {
    		if(board[sr][sc] == val) return false;
    	}
    }
    return true;
}
```

* Optimized pruning:

```
bool isValid(){
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == val) return false;
        if(board[i][col] == val) return false;
        if(board[row][i] == val) return false;
        if(board[row/3*3+i/3][col/3*3+i%3] == val) return false;
    }
    return true;
}
```

## Island

The island problem is mainly to solve 1) number and 2) area problems, and one of the most important ideas to face the island problem is the "flooding idea". The emergence of flooding can eliminate the maintenance of `used` arrays.

### Number of Islands

Introductory island problem, write the framework of this problem

```
int solve() {
    for () { // row
        for() { // column
            if (grid[i][j] == 0) continue;
            ++res;
            dfs(grid, i, j);
        }
    }
}

int dfs(grid, row, col) { // "flooding idea"
    if (…) return; // out of range
    if (grid[row][col] == 0) return;
    grid[row][col] = 0;
    dfs();
    dfs();
    dfs();
    dfs();
}
```

### Number of Closed Islands

Compared to the previous problem, it's easy to see that the islands that were on the boundary are not counted, so it's straightforward to build on the previous problem by flooding the islands on the boundary first. If you understand the code of the previous problem, you will see that the flooding recursion is to flood a small area of islands, so we need to use the same recursion to "solve" the islands at the boundary, killing two birds with one stone.

```
int solve() {
    for () { // up and down
        dfs(, 0, i);
        dfs(, grid.size() - 1, i);
    }
    for() { // left-right
        dfs(, j, 0);
        dfs(, j, grid[0].size());
    }
    …
}
```

### Number of Enclaves

After understanding the problem, you will find that this problem is to find the area of all closed islands. To find the closed islands, you should first think of "removing the edges", and then think about how to calculate the area. Yes, after removing the edges, the sum of the remaining land is the enclave, isn't it? That's right, it is the total number of land in the two-dimensional array after iterating through "removing the edges" operation. The exact code is not displayed here.


### Max Area of Island

After finding the sum of the area of closed islands, how do you find the maximum area of an island? If you remember what was said above about "flooding all of a small island", then calculating the amount of land on a single island is not a problem.

```
dfs() {
    for() {
        for() {
            if (grid[i][j] == 0) continue;
            singleislandcover=dfs(grid, i, j);
            res=max(res, singleislandcover);
        }
    }
}

int dfs() {
    if (…) return 0;
    grid[r][c] = 0;
    return dfs() + dfs() + dfs() + dfs() + 1;
}
```

## Others

To be continued...

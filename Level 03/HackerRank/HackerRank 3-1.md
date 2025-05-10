# LeetCode OJ - PhaseName `30 problems`

## Minimum Absolute Difference in an Array

Problem Link: https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minimumAbsoluteDifference(int arr_cnt, int* arr) {
    qsort(arr, arr_cnt, sizeof(int), cmp);
    
    int min_diff = INT_MAX;
    for(int i = 0; i < arr_cnt; i++) {
        int diff = abs(arr[i] - arr[i+1]);
        if(diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min_diff = INT_MAX;
    for(int i = 0; i < arr.size() - 1; i++) {
        int cur_diff = abs(arr[i] - arr[i+1]);
        if(cur_diff < min_diff)
            min_diff = cur_diff;
    }
    return min_diff;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def minimumAbsoluteDifference(arr):
    arr.sort()
    min_diff = float('inf')
    for i in range(len(arr)-1):
        cur_diff = abs(arr[i] - arr[i+1])
        if cur_diff < min_diff:
            min_diff = cur_diff
            
    return min_diff
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static int minimumAbsoluteDifference(List<Integer> arr) {
        int[] nums = arr.stream().mapToInt(Integer::intValue).toArray();
        Arrays.sort(nums);
        
        int min_diff = Integer.MAX_VALUE;
        for(int i = 0; i < nums.length - 1; i++) {
            int diff = Math.abs(nums[i] - nums[i+1]);
            if(diff < min_diff) 
                min_diff = diff;
        }
        return min_diff;
    }
}
```
</details> 

## Marc's Cakewalk
Problem Link: https://www.hackerrank.com/challenges/marcs-cakewalk/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

long marcsCakewalk(int calorie_cnt, int* calorie) {
    qsort(calorie, calorie_cnt, sizeof(int), cmp);
    long total = 0;
    for(int i = 0; i < calorie_cnt; i++)
        total += (long)(pow(2, i)) * calorie[i];
        
    return total;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
long marcsCakewalk(vector<int> calorie) {
    sort(calorie.rbegin(), calorie.rend());
    long total = 0;
    for(int i = 0; i < calorie.size(); i++)
        total += pow(2, i) * calorie[i];
    return total;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def marcsCakewalk(c):
    c.sort(reverse=True)
    total = 0
    for i in range(len(c)):
        total += (2 ** i) * c[i]
    return total
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static long marcsCakewalk(List<Integer> calorie) {
        Collections.sort(calorie, Collections.reverseOrder());

        long total = 0;
        for (int i = 0; i < calorie.size(); i++) {
            total += (long) Math.pow(2, i) * calorie.get(i);
        }
        return total;
    }
}
```

</details>

## Grid Challenge
Problem Link: https://www.hackerrank.com/challenges/grid-challenge/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

char* gridChallenge(int grid_cnt, char** grid) {
    for(int i = 0; i < grid_cnt; i++)
        qsort(grid[i], strlen(grid[i]), sizeof(char), cmp);
        
    int col_cnt = strlen(grid[0]);
    for(int col = 0; col < col_cnt; col++)  
        for(int r = 1; r < grid_cnt; r++)
            if (grid[r][col] < grid[r - 1][col])
                return "NO";
                
    return "YES";
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
string gridChallenge(vector<string> grid) {
    int n = grid.size();
    if (n == 0) return "YES";
    
    for(auto& row : grid) {
        sort(row.begin(), row.end());
    }
    
    for(int c = 0; c < grid[0].size(); c++)
        for(int r = 1; r < n; r++) 
            if (grid[r][c] < grid[r-1][c])
                return "NO";
                
    return "YES";
}
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def gridChallenge(grid):
    grid = [''.join(sorted(r)) for r in grid]
    
    for col in range(len(grid[0])):
        for r in range(1, len(grid)):
            if grid[r][col] < grid[r-1][col]:
                return "NO"
                
    return "YES"
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static String gridChallenge(List<String> grid) {
        int n = grid.size();
        if (n == 0) return "YES";

        for (int i = 0; i < n; i++) {
            char[] chars = grid.get(i).toCharArray();
            java.util.Arrays.sort(chars);
            grid.set(i, new String(chars));
        }

        int cols = grid.get(0).length();
        for (int col = 0; col < cols; col++) {
            for (int row = 1; row < n; row++) {
                if (grid.get(row).charAt(col) < grid.get(row - 1).charAt(col)) {
                    return "NO";
                }
            }
        }
        return "YES";
    }
}
```

</details>

## luck balance
Problem Link: https://www.hackerrank.com/challenges/luck-balance/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int luckBalance(int k, int contests_rows, int contests_columns, int** contests) {
    int total = 0;
    int* important = (int*)malloc(contests_rows * sizeof(int));
    int impCount = 0;

    for (int i = 0; i < contests_rows; i++) {
        int luck = contests[i][0];
        int importance = contests[i][1];

        if (importance == 1) {
            important[impCount++] = luck;
        } else {
            total += luck;  
        }
    }

    qsort(important, impCount, sizeof(int), cmp);

    for (int i = 0; i < impCount; i++) {
        if (i < k) {
            total += important[i];
        } else {
            total -= important[i];
        }
    }

    free(important);
    return total;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def luckBalance(k, contests):
    total = 0
    important = []
    
    for luck, importance in contests:
        if importance == 1:
            important.append(luck)
        else:
            total += luck
            
    important.sort(reverse=True)
    for i in range(len(important)):
        if i < k:
            total += important[i]
        else:
            total -= important[i]

    return total
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static int luckBalance(int k, List<List<Integer>> contests) {
        int total = 0;
        List<Integer> imp = new ArrayList<>();
        
        for(List<Integer> c : contests) {
            int luck = c.get(0);
            int imp_cnt = c.get(1);
            
            if(imp_cnt == 1)
                imp.add(luck);
            else
                total += luck;
        }
        imp.sort(Collections.reverseOrder());
        for(int i = 0; i < imp.size(); i++) {
            if(i < k) {
                total += imp.get(i);
            } else {
                total -= imp.get(i);
            }
        }
        return total;
    }
}
```

</details>

## Maximum Perimeter Triangle
Problem Link: https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
} 
 
int* maximumPerimeterTriangle(int sticks_count, int* sticks, int* result_count) {
    qsort(sticks, sticks_count, sizeof(int), cmp);
    
    for(int i = 0; i < sticks_count - 2; i++) {
        if (sticks[i] < sticks[i + 1] + sticks[i + 2]) {
            int* res = (int*)malloc(3 * sizeof(int));
            res[0] = sticks[i + 2];
            res[1] = sticks[i + 1];
            res[2] = sticks[i];
            *result_count = 3;
            return res;
        }
    }
    
    int* result = (int*)malloc(sizeof(int));
    result[0] = -1;
    *result_count = 1;
    return result;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    sort(sticks.rbegin(), sticks.rend());
    for(int i = 0; i < sticks.size() - 2; i++) 
        if(sticks[i] < sticks[i+1] + sticks[i+2])
            return {sticks[i+2], sticks[i+1], sticks[i]};
    return {-1}; 
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def maximumPerimeterTriangle(sticks):
    sticks.sort(reverse=True)
    for i in range(len(sticks) - 2):
        if sticks[i] < sticks[i + 1] + sticks[i + 2]:
            return [sticks[i + 2], sticks[i + 1], sticks[i]]
    return [-1]
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static List<Integer> maximumPerimeterTriangle(List<Integer> sticks) {
        sticks.sort(Collections.reverseOrder());
        
        for(int i = 0; i < sticks.size() - 2; i++) {
            int a = sticks.get(i);
            int b = sticks.get(i+1);
            int c = sticks.get(i+2);
            if (a < b + c) 
                return Arrays.asList(c, b, a);
        }
        return Arrays.asList(-1);
    }
}
```

</details>

## Beautiful Pairs
Problem Link: https://www.hackerrank.com/challenges/beautiful-pairs/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int beautifulPairs(int A_count, int* A, int B_count, int* B) {
    int freq[1001] = {0};
    int cnt = 0;
    for(int i = 0; i < A_count; i++) 
        freq[A[i]]++;
        
    for(int i = 0; i < B_count; i++) 
        if (freq[B[i]] > 0) {
            cnt++;
            freq[B[i]]--;
        }
        
    if(cnt == A_count)
        return cnt - 1;
    else 
        return cnt + 1;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
int beautifulPairs(vector<int> A, vector<int> B) {
    unordered_map<int, int> freq;
    int cnt = 0;
    
    for(int num : A)
        freq[num]++;
        
    for(int num : B) 
        if(freq[num] > 0) {
            cnt++;
            freq[num]--;
        }
        
    if(cnt == A.size())
        return cnt - 1;
    else 
        return cnt + 1;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def beautifulPairs(A, B):
    freq = Counter(A)
    cnt = 0
    
    for num in B:
        if freq[num] > 0:
            cnt += 1
            freq[num] -= 1
            
    if cnt == len(A):
        return cnt - 1
    else:
        return cnt + 1
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static int beautifulPairs(List<Integer> A, List<Integer> B) {
        Map<Integer, Integer> freq = new HashMap<>();
        int cnt = 0;
        
        for(int num : A) 
            freq.put(num, freq.getOrDefault(num, 0) + 1);
            
        for(int num : B) 
            if (freq.getOrDefault(num, 0) > 0) {
                cnt++;
                freq.put(num, freq.get(num) - 1);
            }
            
        if (cnt == A.size())
            return cnt - 1;
        else
            return cnt + 1;
    }
}
```

</details>

## Sherlock and The Beast
Problem Link: https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
void decentNumber(int n) {
    int fives = n;
    while (fives % 3 != 0)
        fives -= 5;
    
    if(fives < 0)
        printf("-1\n");
    else {
        for(int i = 0; i < fives; i++) printf("5");
        for(int i = 0; i < n - fives; i++) printf("3");
        printf("\n");
    }
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
void decentNumber(int n) {
    int fives = n;
    while (fives % 3 != 0)
        fives -= 5;
    
    if(fives < 0)
        cout << "-1" << endl;
    else {
        for(int i = 0; i < fives; i++)
            cout << "5";
        for(int i = 0; i < n - fives; i++)
            cout << "3";
        cout << endl;
    }
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def decentNumber(n):
    fives = n
    while fives % 3 != 0:
        fives -= 5
    
    if fives < 0:
        print("-1")
    else:
        print("5" * fives + "3" * (n - fives))
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static void decentNumber(int n) {
        int fives = n;
        while (fives % 3 != 0)
            fives -= 5;
        
        if (fives < 0)
            System.out.println("-1");
        else {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < fives; i++)
                sb.append("5");
            for(int i = 0; i < n - fives; i++)
                sb.append("3");
            System.out.println(sb.toString());
        }
    }
}
```

</details>

## Priyanka and Toys
Problem Link: https://www.hackerrank.com/challenges/priyanka-and-toys/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int toys(int w_count, int* w) {
    qsort(w, w_count, sizeof(int), cmp);
    int boxes = 1;
    int first_toy = w[0];
    
    for(int i = 1; i < w_count; i++) {
        if(w[i] > first_toy + 4) {
            boxes ++;
            first_toy = w[i];
        }
    }
    return boxes;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
int toys(vector<int> w) {
    sort(w.begin(), w.end());
    int boxes = 1;
    int first_toy = w[0];
    for(int weight : w)
        if(weight > first_toy + 4) {
            boxes++;
            first_toy = weight;
        }
    return boxes;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def toys(w):
    w.sort()
    boxes = 1
    first_toy = w[0]
    
    for weight in w:
        if weight > first_toy + 4:
            boxes += 1
            first_toy = weight
    
    return boxes
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static int toys(List<Integer> w) {
        Collections.sort(w);
        int boxes = 1;
        int first_toy = w.get(0);
        
        for (int weight : w) {
            if (weight > first_toy + 4) {
                boxes ++;
                first_toy = weight;
            }
        }
        return boxes;
    }
}
```

</details>

## Largest Permutation
Problem Link: https://www.hackerrank.com/challenges/largest-permutation/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int* largestPermutation(int k, int arr_count, int* arr, int* result_count) {
    int* value_to_index = (int*)malloc((arr_count + 1) * sizeof(int));
    for(int i = 0; i < arr_count; i++)
        value_to_index[arr[i]] = i;
        
    int cur_max = arr_count;
    int swaps = 0, i = 0;
    
    while (swaps < k && i < arr_count) {
        if(arr[i] != cur_max) {
            int target_idx = value_to_index[cur_max];
            int temp = arr[i];
            arr[i] = arr[target_idx];
            arr[target_idx] = temp;
            
            value_to_index[arr[target_idx]] = target_idx;
            value_to_index[arr[i]] = i;
            
            swaps++;
        }
        i++;
        cur_max--;
    }
    
    *result_count = arr_count;
    return arr;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
vector<int> largestPermutation(int k, vector<int> arr) {
    unordered_map<int, int> value_and_idx;
    for(int i = 0; i < arr.size(); i++)
        value_and_idx[arr[i]] = i;
        
    int n = arr.size();
    int cur_max = n;
    int swaps = 0;
    int i = 0;
    
    while(swaps < k && i < arr.size()) {
        if(arr[i] != cur_max) {
            int target_idx = value_and_idx[cur_max];
            swap(arr[i], arr[target_idx]);
            swap(value_and_idx[arr[i]], value_and_idx[arr[target_idx]]);
            swaps++;
        }
        i++;
        cur_max--;
    }
    return arr;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def largestPermutation(k, arr):
    value_to_index = {val: idx for idx, val in enumerate(arr)}
    n = len(arr)
    cur_max = n
    i = 0
    
    while k > 0 and i < n:
        if arr[i] != cur_max:
            target_idx = value_to_index[cur_max]
            arr[i], arr[target_idx] = arr[target_idx], arr[i]
            value_to_index[arr[target_idx]] = target_idx
            value_to_index[arr[i]] = i
            k -= 1
        i += 1
        cur_max -= 1
    
    return arr
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static List<Integer> largestPermutation(int k, List<Integer> arr) {
        int n = arr.size();
        Map<Integer, Integer> value_to_index = new HashMap<>();
        for (int i = 0; i < n; i++)
            value_to_index.put(arr.get(i), i);
            
        int cur_max = n;
        int i = 0;
        
        while (k > 0 && i < n) {
            if(arr.get(i) != cur_max) {
                int target_idx = value_to_index.get(cur_max);
                Collections.swap(arr, i, target_idx);
                value_to_index.put(arr.get(target_idx), target_idx);
                value_to_index.put(arr.get(i), i);
                k--;
            }
            i++;
            cur_max--;
        }
        return arr;
    }
}
```

</details>

## Mark and Toys
Problem Link: https://hackerrank.com/challenges/mark-and-toys/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maximumToys(int prices_count, int* prices, int k) {
    qsort(prices, prices_count, sizeof(int), cmp);
    int cnt = 0;
    int total = 0;
    
    for (int i = 0; i < prices_count; i++) {
        if (total + prices[i] <= k) {
            total += prices[i];
            cnt ++;
        }
        else 
            break;
    }
    return cnt;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int cnt = 0;
    int total = 0;
    
    for(int p : prices) {
        if(total + p <= k) {
            total += p;
            cnt++;
        }
        else
            break;
    }
    return cnt;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def maximumToys(prices, k):
    prices.sort()
    cnt = 0
    total = 0
    
    for p in prices:
        if total + p <= k:
            total += p
            cnt += 1
        else:
            break
            
    return cnt
```

</details>

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static int maximumToys(List<Integer> prices, int k) {
        Collections.sort(prices);
        int cnt = 0;
        int total = 0;
        
        for (int p : prices) {
            if(total + p <= k) {
                total += p;
                cnt++;
            } 
            else
                break;
        }
        return cnt;
    }
}
```

</details>

## Jim and the Orders
Problem Link: https://hackerrank.com/challenges/jim-and-the-orders/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
typedef struct {
    int finish;
    int idx;
} order;

int cmp(const void *a, const void *b) {
    order *oa = (order*)a;
    order *ob = (order*)b;
    if (oa ->finish == ob ->finish)
        return oa ->idx - ob ->idx;
    return oa ->finish - ob ->finish;
}

int* jimOrders(int orders_rows, int orders_columns, int** orders, int* result_count) {
    order* orderTimes = malloc(orders_rows * sizeof(order));
    for(int i = 0; i < orders_rows; i++) {
        orderTimes[i].finish = orders[i][0] + orders[i][1];
        orderTimes[i].idx = i + 1;
    }
    
    qsort(orderTimes, orders_rows, sizeof(order), cmp);
    
    int *res = malloc(orders_rows * sizeof(int));
    for(int i = 0; i < orders_rows; i++) 
        res[i] = orderTimes[i].idx;
        
    free(orderTimes);
    *result_count = orders_rows;
    return res;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
vector<int> jimOrders(vector<vector<int>> orders) {
    vector<pair<int, int>> order_times;
    
    for(int i = 0; i < orders.size(); i++) {
        int finish_time = orders[i][0] + orders[i][1];
        order_times.push_back({finish_time, i+1});
    }
    
    sort(order_times.begin(), order_times.end(),
    [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first == b.first) 
            return a.second < b.second;
        return a.first < b.first;
    });
    
    vector<int> result;
    for(auto& p : order_times) {
        result.push_back(p.second);
    }
    
    return result; 
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def jimOrders(orders):
    orderTimes = []
    
    for i, (order, prep) in enumerate(orders):
        finish = order + prep
        orderTimes.append((finish, i + 1))
        
    orderTimes.sort()
    
    res = [idx for _, idx in orderTimes]
    return res
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static List<Integer> jimOrders(List<List<Integer>> orders) {
        List<int[]> orderTimes = new ArrayList<>();
        
        for(int i = 0; i < orders.size(); i++) {
            int finish = orders.get(i).get(0) + orders.get(i).get(1);
            orderTimes.add(new int[]{finish, i + 1});
        }
        
        orderTimes.sort((a, b) -> {
            if (a[0] == b[0])
                return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });
        
        List<Integer> res = new ArrayList<>();
        for (int[] order : orderTimes)
            res.add(order[1]);
        
        return res;
    }
}
```

</details>

## Permuting Two Arrays
Problem Link: https://hackerrank.com/challenges/two-arrays/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int cmp_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    qsort(A, A_count, sizeof(int), cmp_asc);
    qsort(B, B_count, sizeof(int), cmp_desc);
    
    for(int i = 0; i < A_count; i++)
        if (A[i] + B[i] < k)
            return "NO";
    
    return "YES";
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
string twoArrays(int k, vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for(int i = 0; i < A.size(); i++) {
        if(A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def twoArrays(k, A, B):
    A.sort()
    B.sort(reverse=True)

    for a, b in zip(A, B):
        if a + b < k:
            return "NO"
    return "YES"
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static String twoArrays(int k, List<Integer> A, List<Integer> B) {
        Collections.sort(A);
        B.sort(Collections.reverseOrder());
        
        for(int i = 0; i < A.size(); i++) 
            if (A.get(i) + B.get(i) < k)
                return "NO";
                
        return "YES";
    }
}
```

</details>

## Candies
Problem Link: https://hackerrank.com/challenges/candies/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
long candies(int n, int arr_count, int* arr) {
    int* candy = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        candy[i] = 1;
        
    for(int i = 1; i < n; i++)
        if(arr[i] > arr[i - 1])
            candy[i] = candy[i - 1] + 1;
            
    for(int i = n - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1] && candy[i] <= candy[i + 1])
            candy[i] = candy[i + 1] + 1;
            
    long total = 0;
    for(int i = 0; i < n; i++)
        total += candy[i];
        
    free(candy);
    return total;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
long candies(int n, vector<int> arr) {
    vector<int> candy(n, 1);
    for(int i = 1; i < n; i++) 
        if(arr[i] > arr[i-1])
            candy[i] = candy[i-1] + 1;
    for(int i = n -2; i >= 0; i--)
        if(arr[i] > arr[i+1] && candy[i] <= candy[i+1])
            candy[i] = candy[i+1] + 1;
    
    long total = 0;
    for(int c : candy)
        total += c;
    
    return total;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def candies(n, arr):
    candy = [1] * n
    for i in range(1,n):
        if arr[i] > arr[i-1]:
            candy[i] = candy[i-1] + 1
            
    for i in range(n-2, -1, -1):
        if arr[i] > arr[i+1] and candy[i] <= candy[i+1]:
            candy[i] = candy[i+1] + 1
    return sum(candy)
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static long candies(int n, List<Integer> arr) {
        int[] candy = new int[n];
        Arrays.fill(candy, 1);
        
        for(int i = 1; i < n; i++)
            if (arr.get(i) > arr.get(i - 1))
                candy[i] = candy[i - 1] + 1;
                
        for (int i = n - 2; i >= 0; i--) 
            if (arr.get(i) > arr.get(i + 1) && candy[i] <= candy[i + 1])
                candy[i] = candy[i + 1] + 1;
                
        long total = 0;
        for (int c  : candy)
            total += c;
            
        return total;
    }
}
```

</details>

## Greedy Florist
Problem Link: https://hackerrank.com/challenges/greedy-florist/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int getMinimumCost(int k, int c_count, int* c) {
    qsort(c, c_count, sizeof(int), cmp);
    
    int cost = 0;
    for(int i = 0; i < c_count; i++)
        cost += (i / k + 1) * c[i];
    
    return cost; 
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
int getMinimumCost(int k, vector<int> c) {
    sort(c.begin(), c.end(), greater<int>());
    int cost = 0;
    for(int i = 0; i < c.size(); i++) 
        cost += (i / k + 1) * c[i];
        
    return cost;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def getMinimumCost(k, c):
    c.sort(reverse=True)
    cost = 0
    for i, price in enumerate(c):
        cost += (i // k + 1) * price;
    return cost
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
static int getMinimumCost(int k, int[] c) {
        Arrays.sort(c);
        int cost = 0;
        int n = c.length;
        
        for(int i = 0; i < n; i++) {
            cost += (i / k + 1) * c[n - i - 1];
        }
        return cost;
    }
```

</details>

## Max Min
Problem Link: https://hackerrank.com/challenges/angry-children/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int), cmp);
    
    int min_diff = INT_MAX;
    for(int i = 0; i <= arr_count - k; i++) {
        int diff = arr[i + k - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int res = INT_MAX;
    
    for(int i = 0; i <= arr.size() - k; i++) {
        int x = arr[i+k-1] - arr[i];
        res = min(res, x);
    }
    return res;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def maxMin(k, arr):
    arr.sort()
    res = float('inf')
    
    for i in range (len(arr) - k + 1):
        x = arr[i+k-1] - arr[i]
        res = min(res, x)
    
    return res
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static int maxMin(int k, List<Integer> arr) {
        Collections.sort(arr);
        int min_diff = Integer.MAX_VALUE;
        
        for (int i = 0; i <= arr.size() - k; i++) {
            int diff = arr.get(i + k - 1) - arr.get(i);
            if (diff < min_diff)
                min_diff = diff;
        }
        return min_diff;
    }
}
```

</details>

## Goodland Electricity
Problem Link: https://hackerrank.com/challenges/pylons/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}

int pylons(int k, int arr_count, int* arr) {
    int res = 0;
    int i = 0;

    while (i < arr_count) {
        int pos = -1;
        int st = min(i + k - 1, arr_count - 1);
        int end = max(i - k + 1, 0);

        for (int j = st; j >= end; j--) {
            if (arr[j] == 1) {
                pos = j;
                break;
            }
        }

        if (pos == -1) return -1;  
        res++;                     
        i = pos + k;              
    }

    return res;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
int pylons(int k, vector<int> arr) {
    int n = arr.size();
    int res = 0;
    int i = 0;
    while (i < n) {
        int pos = -1;
        int st = min(i + k -1, n - 1);
        int end = max(i - k + 1, 0);
        
        for(int j = st; j >= end; j--) {
            if(arr[j] == 1) {
                pos = j;
                break;
            }
        }
        
        if (pos == -1) return -1;
        res++;
        
        i = pos + k;
    }
    return res;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def pylons(k, arr):
    n = len(arr)
    res = 0
    i = 0
    
    while i < n:
        pos = -1
        st = min(i + k - 1, n - 1)
        end = max(i - k + 1, 0)
        
        for j in range(st, end-1, -1):
            if arr[j] == 1:
                pos = j
                break
                
        if pos == -1:
            return -1
        
        res += 1
        i = pos + k
    
    return res
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static int pylons(int k, List<Integer> arr) {
        int n = arr.size();
        int res = 0, i = 0;
        
        while (i < n) {
            int pos = -1;
            int st = Math.min(i + k - 1, n - 1);
            int end = Math.max(i - k + 1, 0);
            
            for (int j = st; j >= end; j--) 
                if (arr.get(j) == 1) {
                    pos = j;
                    break;
                }
                
            if (pos == -1)
                return -1;
                
            res++;
            i = pos + k;
        }
        return res;
    }
}
```

</details>

## Cloudy Day
Problem Link: https://www.hackerrank.com/challenges/cloudy-day/problem

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
typedef struct{
    long loc;
    long pop;
} Town;

typedef struct {
    long pos;
    int id;
} Event;

int cmp_event (const void *a, const void *b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    return (e1 ->pos > e2 ->pos) - (e1 ->pos < e2 ->pos);
}

int cmp_town(const void *a, const void *b) {
    Town* t1 = (Town*)a;
    Town* t2 = (Town*)b;
    return (t1 ->loc > t2 ->loc) - (t1 ->loc < t2 ->loc);
}

long maximumPeople(int p_count, long* p, int x_count, long* x, int y_count, long* y, int r_count, long* r) {
    int n = p_count, m = y_count;
    Town* towns = malloc(n * sizeof(Town));
    for(int i = 0; i < n; i++) {
        towns[i].loc = x[i];
        towns[i].pop = p[i];
    }
    qsort(towns, n, sizeof(Town), cmp_town);
    
    Event* cloud_st = malloc(m * sizeof(Event));
    Event* cloud_end = malloc(m * sizeof(Event));
    for(int i = 0; i < m; i++) {
        cloud_st[i] = (Event) {y[i] - r[i], i};
        cloud_end[i] = (Event) {y[i] + r[i], i};
    }
    qsort(cloud_st, m, sizeof(Event), cmp_event);
    qsort(cloud_end, m, sizeof(Event), cmp_event);
    
    char* is_active = calloc(m, sizeof(char));
    long* cloud_covered = calloc(m, sizeof(long));
    long sunny = 0;
    
    int s = 0, e = 0;
    int active_cnt = 0;
    int cur_cloud = -1;
    for(int i = 0; i < n; i++) {
        long loc = towns[i].loc, pop = towns[i].pop;
        while(s < m && cloud_st[s].pos <= loc) {
            int cid = cloud_st[s++].id;
            is_active[cid] = 1;
            active_cnt++;
            if (active_cnt == 1) 
                cur_cloud = cid;
            else 
                cur_cloud = -1;
        }
        while(e < m && cloud_end[e].pos < loc) {
            int cid = cloud_end[e++].id;
            is_active[cid] = 0;
            active_cnt--;
            if (active_cnt == 1) 
                for(int j = 0; j < m; j++) 
                    if(is_active[j]) {
                        cur_cloud = j;
                        break;
                    }
                    
            else if(active_cnt == 0) 
                cur_cloud = -1;
            else 
                cur_cloud = -2;
        }
        
        if(active_cnt == 0) 
            sunny += pop;
        else if (active_cnt == 1 && cur_cloud >= 0) 
            cloud_covered[cur_cloud] += pop;
    }
    
    long ress = 0;
    for(int i = 0; i < m; i++)
        if(cloud_covered[i] > ress)
            ress = cloud_covered[i];
            
    free(towns);
    free(cloud_st);
    free(cloud_end);
    free(is_active);
    free(cloud_covered);
    return sunny + ress;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
long maximumPeople(vector<long> p, vector<long> x, vector<long> y, vector<long> r) {
    int n = p.size();
    int m = y.size();
    
    vector<pair<long, long>> towns(n);
    for(int i = 0; i < n; i++)
        towns[i] = {x[i], p[i]};
    sort(towns.begin(), towns.end());
    
    vector<pair<long, int>> cloud_st, cloud_end;
    for(int i = 0; i < m; i++) {
        cloud_st.emplace_back(y[i] - r[i], i);
        cloud_end.emplace_back(y[i] + r[i], i);
    }
    sort(cloud_st.begin(), cloud_st.end());
    sort(cloud_end.begin(), cloud_end.end());
    
    set<int> active;
    long sunny = 0;
    vector<long> cloud_covered(m, 0);
    
    int s = 0, e = 0;
    for (auto& [loc, pop] : towns) {
        while (s < m && cloud_st[s].first <= loc) 
            active.insert(cloud_st[s++].second);
            
        while (e < m && cloud_end[e].first < loc)
            active.erase(cloud_end[e++].second);
            
        if (active.empty()) sunny += pop;
        else if (active.size() == 1) {
            int c = *active.begin();
            cloud_covered[c] += pop;
        }
    }
    
    long ress = 0;
    for(long cc : cloud_covered) ress = max(ress, cc);
    return sunny + ress;
}
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
def maximumPeople(p, x, y, r):
    towns = sorted(zip(x, p))
    cloud_st = sorted((y[i] - r[i], i) for i in range(len(y)));
    cloud_end = sorted((y[i] + r[i], i) for i in range(len(y)));
    
    s = e = 0
    m = len(y)
    active = set()
    sunny = 0
    cloud_covered = [0] * m
    
    for loc, pop in towns:
        while s < m and cloud_st[s][0] <= loc:
            active.add(cloud_st[s][1])
            s += 1
        while e < m and cloud_end[e][0] < loc:
            active.discard(cloud_end[e][1])
            e += 1
        
        if not active:
            sunny += pop
        elif len(active) == 1:
            cid = next(iter(active))
            cloud_covered[cid] += pop
        
    return sunny + max(cloud_covered, default=0)
```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Result {
    public static long maximumPeople(List<Long> p, List<Long> x, List<Long> y, List<Long> r) {
        int n = p.size();
        int m = y.size();
        
        List<long[]> towns = new ArrayList<>();
        for (int i = 0; i < n; i++)
            towns.add(new long[]{x.get(i), p.get(i)});
        towns.sort(Comparator.comparingLong(a ->a[0]));
        
        List<long[]> cloud_st = new ArrayList<>();
        List<long[]> cloud_end = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            cloud_st.add(new long[]{y.get(i) - r.get(i), i});
            cloud_end.add(new long[]{y.get(i) + r.get(i), i});
        }
        cloud_st.sort(Comparator.comparingLong(a ->a[0]));
        cloud_end.sort(Comparator.comparingLong(a ->a[0]));
        
        Set<Integer> active = new HashSet<>();
        long[] cloud_covered = new long[m];
        long sunny = 0;
        int s = 0, e = 0;
        for(long[] town : towns) {
            long loc = town[0], pop = town[1];
            while (s < m && cloud_st.get(s)[0] <= loc)
                active.add((int) cloud_st.get(s++)[1]);
            while (e < m && cloud_end.get(e)[0] < loc)
                active.remove((int) cloud_end.get(e++)[1]);
                
            if(active.isEmpty()) sunny += pop;
            else if (active.size() == 1) {
                int cid = active.iterator().next();
                cloud_covered[cid] += pop;
            }
        }
        long ress = 0;
        for (long cc : cloud_covered)
            ress = Math.max(ress, cc);
            
        return sunny + ress;
    }
}
```
</details>

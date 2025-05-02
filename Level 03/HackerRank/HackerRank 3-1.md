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
public static int minimumAbsoluteDifference(List<Integer> arr) {
        Collections.sort(arr);
        int min_diff = Integer.MAX_VALUE;

        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = Math.abs(arr.get(i) - arr.get(i + 1));
            if (diff < min_diff) {
                min_diff = diff;
            }
        }

        return min_diff;
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
public static long marcsCakewalk(List<Integer> calorie) {
        Collections.sort(calorie, Collections.reverseOrder());

        long total = 0;
        for (int i = 0; i < calorie.size(); i++) {
            total += (long) Math.pow(2, i) * calorie.get(i);
        }

        return total;
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

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

## ProblemName
Problem Link: ProblemLink

<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/golang.png"></img></picture>
<details>
    <summary>Go Solution</summary>

```go

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>
<picture><img align="right" width="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/csharp.png"></img></picture>
<details>
    <summary>C# Solution</summary>

```c#

```

</details>

# LeetCode OJ - Interviews Questions 1 <br> Array and String `20 problems`

## Majority Element
Problem Link: https://leetcode.com/problems/majority-element

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def majorityElement(self, nums):
        cnt = 0
        comp_num = nums[0]

        for i in range (len(nums)):
            if cnt == 0:
                comp_num = nums[i]

            if nums[i] == comp_num:
                cnt += 1
            else:
                cnt -= 1
        
        return comp_num
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int majorityElement(int[] nums) {
        int cnt = 0, comp_num = nums[0];
        for(int num : nums) {
            if(cnt == 0) comp_num = num;
            if(num == comp_num) cnt += 1;
            else cnt -= 1;
        }
        return comp_num;    
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int majorityElement(int* nums, int numsSize) {
    int cnt = 0, comp_num = nums[0];
    for(int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if(cnt == 0) comp_num = num;
        if(num == comp_num) cnt += 1;
        else cnt -= 1;
    }
    return comp_num;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = size(nums);
        int cnt = 0, comp_num = nums[0];
        for(int& num : nums) {
            if(cnt == 0)
                comp_num = num;
            
            if(num == comp_num)     
                cnt += 1;
            else
                cnt -= 1;
        }
        return comp_num;
    }
};
```

</details>
<br>

## Jump Game
Problem Link: https://leetcode.com/problems/jump-game

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def canJump(self, nums):
        target = len(nums) - 1
        for i in range (target, -1, -1):
            if i + nums[i] >= target:
                target = i

        return target == 0
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public boolean canJump(int[] nums) {
        int target = nums.length - 1;
        for(int i = nums.length - 2; i >= 0; i--) {
            if(i + nums[i] >= target) target = i;
        }
        return (target == 0);
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
bool canJump(int* nums, int numsSize) {
    int target = numsSize - 1;
    for(int i = numsSize - 2; i >= 0; i--) {
        if(i + nums[i] >= target) target = i;
    }
    return (target == 0);
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int target = size(nums) - 1;
        for(int i = size(nums) - 2; i >= 0; i--) 
            if(i + nums[i] >= target)
                target = i;

        return (target == 0);
    }
};
```

</details>
<br>

## product of array except self
Problem Link: https://leetcode.com/problems/product-of-array-except-self

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def productExceptSelf(self, nums):
        res = [1] * (len(nums))

        prefix = 1
        for i in range (len(nums)):
            res[i] = prefix
            prefix *= nums[i]

        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]

        return res
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        Arrays.fill(res, 1);

        int prefix = 1;
        for (int i = 0; i < nums.length; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) 
        res[i] = 1;

    int prefix = 1;
    for (int i = 0; i < numsSize; i++) {
        res[i] = prefix;
        prefix *= nums[i];
    }

    int postfix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        res[i] *= postfix;
        postfix *= nums[i];
    }

    *returnSize = numsSize;
    return res;
}
```

</details>

<picture><img align="right" width="40" height="40" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res (size(nums), 1);

        int prefix = 1;
        for(int i = 0; i < size(nums); i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for(int i = size(nums) - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
};
```

</details>
<br>

## search a 2d matrix ii
Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
# O(rows * log(cols))
class Solution(object):
    def searchMatrix(self, matrix, target):
        def binary_search(row, target):
            l, r = 0, len(row) - 1
            while l <= r:
                mid = (l + r) // 2

                if row[mid] == target:
                    return True;
                elif target < row[mid]:
                    r = mid - 1
                elif target > row[mid]:
                    l = mid + 1

            return False

        for row in matrix:
            if(binary_search(row, target)):
                return aTrue

        return False

# O(rows + cols)
class Solution(object):
    def searchMatrix(self, matrix, target):
        rows, cols = len(matrix), len(matrix[0])
        row, col = 0, cols - 1

        while row < rows and col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                col -= 1
            else:
                row += 1

        return False           
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
// O(rows * log(cols)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int[] row : matrix) 
            if (binarySearch(row, target)) 
                return true;
        return false;
    }

    private boolean binarySearch(int[] row, int target) {
        int l = 0, r = row.length - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (row[mid] == target) 
                return true;
            else if (target < row[mid]) 
                r = mid - 1;
            else if (target > row[mid]) 
                l = mid + 1;
        }
        return false;
    }
}

// O(rows + cols)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int row = 0, col = cols - 1;

        while(row < rows && col >= 0) {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
// O(rows * log(cols)
bool binary_search(int* row, int rowSize, int target) {
    int l = 0, r = rowSize - 1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (row[mid] == target) 
            return true;
        else if (target < row[mid]) 
            r = mid - 1;
        else if (target > row[mid]) 
            l = mid + 1;
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    for (int i = 0; i < matrixSize; i++) 
        if (binary_search(matrix[i], matrixColSize[i], target)) 
            return true;

    return false;
}

// O(rows + cols)
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int row = 0, col = cols - 1;

    while(row < rows && col >= 0) {
        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col] > target)
            col--;
        else
            row++;
    }
    return false;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
// O(rows * log(cols)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       for(const auto& row : matrix) {
        if(binary_search(row, target)) 
            return true;
       }
       return false;
    }

private:
    bool binary_search(const vector<int>& row, int target) {
        int l = 0, r = size(row) - 1;
        while(l <= r) {
            int mid = (l + r) / 2;

            if(row[mid] == target)
                return true;
            else if(target < row[mid])
                r = mid - 1;
            else if(target > row[mid]) 
                l = mid + 1;
        }
        return false;
    }
};

// O(rows + cols)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = size(matrix);
        int cols = size(matrix[0]);
        int row = 0, col = cols - 1;

        while(row < rows && col >= 0) {
            if(matrix[row][col] == target)  
                return true;
            else if(matrix[row][col] > target)
                col --;
            else if(matrix[row][col] < target)
                row ++;
        }

        return false;
    }
};
```

</details>
<br>

## spiral matrix
Problem Link: https://leetcode.com/problems/spiral-matrix

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def spiralOrder(self, matrix):
        m, n = len(matrix), len(matrix[0])
        res = []
        top, down, right, left = 0, m - 1, n - 1, 0
        dir = 0 
        
        while (top <= down and left <= right):
            if dir == 0:
                for i in range(left, right + 1):
                    res.append(matrix[top][i])
                top += 1

            elif dir == 1:
                for i in range (top, down + 1):
                    res.append(matrix[i][right])
                right -= 1

            elif dir == 2:
                for i in range (right, left - 1, -1):
                    res.append(matrix[down][i])
                down -= 1;

            elif dir == 3:
                for i in range (down, top - 1, -1):
                    res.append(matrix[i][left])
                left += 1
            
            dir = (dir + 1) % 4
        return res
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int m = matrix.length, n = matrix[0].length;
        int top = 0, down = m - 1, left = 0, right = n - 1;
        int dir = 0;

        while (top <= down && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++)
                    res.add(matrix[top][i]);
                top++;
            } else if (dir == 1) {
                for (int i = top; i <= down; i++)
                    res.add(matrix[i][right]);
                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left; i--)
                    res.add(matrix[down][i]);
                down--;
            } else if (dir == 3) {
                for (int i = down; i >= top; i--)
                    res.add(matrix[i][left]);
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = matrixColSize[0];
    int* res = malloc(m * n * sizeof(int));
    *returnSize = m * n;
    int top = 0, down = m - 1, left = 0, right = n - 1;
    int dir = 0, idx = 0;

    while (top <= down && left <= right) {
        if (dir == 0) {
            for (int i = left; i <= right; i++)
                res[idx++] = matrix[top][i];
            top++;
        } 
        
        else if (dir == 1) {
            for (int i = top; i <= down; i++)
                res[idx++] = matrix[i][right];
            right--;
        } 
        
        else if (dir == 2) {
            for (int i = right; i >= left; i--)
                res[idx++] = matrix[down][i];
            down--;
        } 
        
        else if (dir == 3) {
            for (int i = down; i >= top; i--)
                res[idx++] = matrix[i][left];
            left++;
        }
        dir = (dir + 1) % 4;
    }

    return res;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix[0]);
        vector <int> res;
        int top = 0, down = m - 1, right = n - 1, left = 0; 
        int dir = 0;
        /*
        o --> from left to right
        1 --> from top to down
        2 --> from right to left
        3 --> from down to top
        */

        while(top <= down && left <= right) {
            if(dir == 0) {
                for(int i = left; i <= right; i++) 
                    res.emplace_back(matrix[top][i]);
                top ++;
            }
            else if(dir == 1) {
                for(int i = top; i <= down; i++) 
                    res.emplace_back(matrix[i][right]);
                right --;
            }
            else if(dir == 2) {
                for(int i = right; i >= left; i--) 
                    res.emplace_back(matrix[down][i]);
                down --;
            }
            else if(dir == 3) {
                for(int i = down; i >= top; i--) 
                    res.emplace_back(matrix[i][left]);
                left ++;
            }

            dir = (dir + 1) % 4;
        }
        return res;
    }
};
```

</details>
<br>

## rotate image
Problem Link: https://leetcode.com/problems/rotate-image

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def rotate(self, matrix):
        n = len(matrix)
        for i in range (n):
            for j in range (i, n):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
        
        for i in range (n):
            left, right = 0, n - 1
            while (left <= right):
                temp = matrix[i][left]
                matrix[i][left] = matrix[i][right]
                matrix[i][right] = temp
                left += 1
                right -= 1
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // reverse each row
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    // transpose
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    // reverse each row
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        int n = size(matrix);
        for(int i = 0; i < n; i++) 
            for(int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        // reverse
        for(int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                swap(matrix[i][left], matrix[i][right]);
                left ++;
                right --;
            }
        }
    }
};
```

</details>
<br>

## set matrix zeroes
Problem Link: https://leetcode.com/problems/set-matrix-zeroes

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def setZeroes(self, matrix):
        m, n = len(matrix), len(matrix[0])
        first_row_zero = first_col_zero = False

        for i in range (m):
            if matrix[i][0] == 0:
                first_col_zero = True;

        for j in range (n):
            if matrix[0][j] == 0:
                first_row_zero = True;

        for i in range (1, m):
            for j in range (1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range (1, m):
            for j in range (1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if first_col_zero:
            for i in range (m):
                matrix[i][0] = 0

        if first_row_zero:
            for j in range (n):
                matrix[0][j] = 0        
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean firstRowZero = false, firstColZero = false;

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                firstColZero = true;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
                firstRowZero = true;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (firstColZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;

        if (firstRowZero)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    bool firstRowZero = false, firstColZero = false;

    for (int i = 0; i < m; i++)
        if (matrix[i][0] == 0)
            firstColZero = true;

    for (int j = 0; j < n; j++)
        if (matrix[0][j] == 0)
            firstRowZero = true;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    if (firstColZero)
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;

    if (firstRowZero)
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
// O(1) memory complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix[0]);
        bool first_row_zero = false, first_col_zero = false;

        for(int i = 0; i < m; i++) 
            if(matrix[i][0] == 0)
                first_col_zero = true;

        for(int j = 0; j < n; j++)
            if(matrix[0][j] == 0)
                first_row_zero = true;

        for(int i = 1; i < m; i++) 
            for(int j = 1; j < n; j++) 
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        for(int i = 1; i < m; i++) 
            for(int j = 1; j < n; j++) 
                if(matrix[i][0] == 0 or matrix[0][j] == 0) 
                    matrix[i][j] = 0;

        if(first_col_zero) 
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;

        if(first_row_zero) 
            for(int j = 0; j < n; j++) 
                matrix[0][j] = 0;
    }
};

// ----------------------------------------------------------------------------------------
// O(m + n) memory complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix[0]);
        vector <int> zero_rows (m, 0);
        vector <int> zero_cols (n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) 
                    zero_rows[i] = zero_cols[j] = 1;
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(zero_rows[i] || zero_cols[j])
                    matrix[i][j] = 0;
            }
        }
    }
};
// -----------------------------------------------------------------------------------------
// O(m*n) memory complexity
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix[0]);
        bool zero_rows = false, zero_cols = false;
        vector<vector<int>> copy = matrix;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(copy[i][j] == 0) {
                    for(int k = 0; k < m; k++)
                        matrix[k][j] = 0;
                    for(int k = 0; k < n; k++)
                        matrix[i][k] = 0;
                }
            }
        }
    }
};
```

</details>
<br>

## add two numbers
Problem Link: https://leetcode.com/problems/add-two-numbers

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        head = ListNode()
        curr = head
        carry = 0

        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            val = v1 + v2 + carry
            carry = val // 10
            val = val % 10

            curr.next = ListNode(val)
            curr = curr.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return head.next
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode curr = head;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int v1 = (l1 != null) ? l1.val : 0;
            int v2 = (l2 != null) ? l2.val : 0;

            int val = v1 + v2 + carry;
            carry = val / 10;
            val %= 10;

            curr.next = new ListNode(val);
            curr = curr.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        return head.next;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* curr = head;
    int carry = 0;

    while (l1 || l2 || carry) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;

        int val = v1 + v2 + carry;
        carry = val / 10;
        val %= 10;

        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = val;
        curr->next->next = NULL;
        curr = curr->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    struct ListNode* result = head->next;
    free(head);
    return result;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        int carry = 0;

        while(l1 or l2 or carry) {
            int v1 = l1 ? l1 -> val : 0;
            int v2 = l2 ? l2 -> val : 0;
            
            int val = v1 + v2 + carry;
            carry = val / 10;
            val %= 10;

            curr -> next = new ListNode(val);
            curr = curr -> next;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        return head -> next;
    }
};
```

</details>
<br>

## sort colors
Problem Link: https://leetcode.com/problems/sort-colors

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def sortColors(self, nums):
        def heapify(arr, size, root):
            j = -1
            while root != j:
                j = root
                left_idx = 2 * root + 1
                right_idx = 2 * root + 2
                if left_idx < size and arr[left_idx] > arr[root]:
                    root = left_idx
                if right_idx < size and arr[right_idx] > arr[root]:
                    root = right_idx
                arr[root], arr[j] = arr[j], arr[root]

        def build_heap(arr, size):
            for i in range (size // 2 - 1, -1, -1):
                heapify(arr, size, i)
        
        def heap_sort(arr, size):
            build_heap(arr, size)
            for i in range(size - 1, -1, -1):
                arr[0], arr[i] = arr[i], arr[0]
                heapify(arr, i, 0)

        heap_sort(nums, len(nums))
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public void sortColors(int[] nums) {
        heapSort(nums);
    }

    private void heapify(int[] arr, int size, int root) {
        int j = -1;
        while (root != j) {
            j = root;
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            if (left < size && arr[left] > arr[root])
                root = left;
            if (right < size && arr[right] > arr[root])
                root = right;
            swap(arr, root, j);
        }
    }

    private void buildHeap(int[] arr, int size) {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(arr, size, i);
    }

    private void heapSort(int[] arr) {
        int size = arr.length;
        buildHeap(arr, size);
        for (int i = size - 1; i >= 0; i--) {
            swap(arr, 0, i);
            heapify(arr, i, 0);
        }
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int size, int root) {
    int j = -1;
    while (root != j) {
        j = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        
        if (left < size && arr[left] > arr[root])
            root = left;
        if (right < size && arr[right] > arr[root])
            root = right;
        swap(&arr[root], &arr[j]);
    }
}

void buildHeap(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
}

void sortColors(int* nums, int numsSize) {
    buildHeap(nums, numsSize);
    for (int i = numsSize - 1; i >= 0; i--) {
        swap(&nums[0], &nums[i]);
        heapify(nums, i, 0);
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        heap_sort(nums, size(nums));
    }

private:
    void heapify(vector<int> &arr, int size_, int root) {
        int j = -1;
        while (root != j) {
            j = root;
            int left_idx  = 2 * root + 1;
            int right_idx = 2 * root + 2;
            if (left_idx < size_ and arr[left_idx] > arr[root])
                root = left_idx;
            if (right_idx < size_ and arr[right_idx] > arr[root])
                root = right_idx;
            swap(arr[root], arr[j]);
        }
    }

    void build_heap(vector<int>& arr, int size_) {
        for(int i = size_ / 2 - 1; i >= 0; i--)
            heapify(arr, size_, i);
    }

    void heap_sort(vector<int>& arr, int size_) {
        build_heap(arr, size_);
        for(int i = size_ - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
```

</details>
<br>

## find the duplicate number
Problem Link: https://leetcode.com/problems/find-the-duplicate-number

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def findDuplicate(self, nums):
        slow_ptr, fast_ptr = 0, 0
        for i in range (len(nums)):
            slow_ptr = nums[slow_ptr]
            fast_ptr = nums[nums[fast_ptr]]
            if slow_ptr == fast_ptr :
                break;

        slow_ptr_2 = 0
        for i in range (len(nums)):
            slow_ptr = nums[slow_ptr]
            slow_ptr_2 = nums[slow_ptr_2]
            if slow_ptr == slow_ptr_2:
                break;

        return slow_ptr
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int slow2 = 0;
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int findDuplicate(int* nums, int numsSize) {
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    int slow2 = 0;
    while (slow != slow2) {
        slow = nums[slow];
        slow2 = nums[slow2];
    }
    return slow;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
// Using Floyd's algorithm for cycle detection O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow_ptr = 0, fast_ptr = 0;
        for(int i = 0; i < size(nums); i++) {
            slow_ptr = nums[slow_ptr];
            fast_ptr = nums[nums[fast_ptr]];
            if (slow_ptr == fast_ptr)
                break;
        }

        int slow_ptr_2 = 0;
        for(int i = 0; i < size(nums); i++) {
            slow_ptr = nums[slow_ptr];
            slow_ptr_2 = nums[slow_ptr_2];
            if (slow_ptr == slow_ptr_2)
                break;
        }

        return slow_ptr;
    }
};
```

</details>
<br>

## first missing positive
Problem Link: https://leetcode.com/problems/first-missing-positive

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)

        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        return n + 1
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }

        for (int i = 0; i < n; i++) 
            if (nums[i] != i + 1) 
                return i + 1;

        return n + 1;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    for (int i = 0; i < numsSize; i++) 
        if (nums[i] != i + 1) 
            return i + 1;

    return numsSize + 1;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) 
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) 
                swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < n; ++i) 
            if (nums[i] != i + 1) 
                return i + 1;

        return n + 1;
    }
};
```

</details>
<br>

## best time to buy and sell stock
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def maxProfit(self, prices):
        min_price = float('inf')
        max_profit = 0

        for price in prices:
            if price < min_price:
                min_price = price
            elif price - min_price > max_profit:
                max_profit = price - min_price
        
        return max_profit
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) 
                minPrice = price;
            else if (price - minPrice > maxProfit) 
                maxProfit = price - minPrice;
        }

        return maxProfit;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int maxProfit(int* prices, int pricesSize) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) 
            minPrice = prices[i];
        else if (prices[i] - minPrice > maxProfit) 
            maxProfit = prices[i] - minPrice;
    }

    return maxProfit;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) 
                minPrice = price;
            else if (price - minPrice > maxProfit) 
                maxProfit = price - minPrice;
        }

        return maxProfit;
    }
};
```

</details>
<br>

## missing number
Problem Link: https://leetcode.com/problems/missing-number

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def missingNumber(self, nums):
        n = len(nums)
        total = n * (n + 1) // 2
        sum = 0

        for num in nums:
            sum += num

        return total - sum
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int total = n * (n + 1) / 2;
        int sum = 0;

        for (int num : nums) 
            sum += num;

        return total - sum;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int total = n * (n + 1) / 2;
    int sum = 0;

    for (int i = 0; i < n; i++) 
        sum += nums[i];

    return total - sum;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;

        for (int num : nums) 
            sum += num;

        return total - sum;
    }
};
```

</details>
<br>

## find all numbers disappeared in an array
Problem Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def findDisappearedNumbers(self, nums):
        for i in range(len(nums)):
            index = abs(nums[i]) - 1
            if nums[index] > 0:
                nums[index] = -nums[index]

        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int index = Math.abs(nums[i]) - 1;
            if (nums[index] > 0) 
                nums[index] = -nums[index];
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) 
            if (nums[i] > 0) 
                result.add(i + 1);

        return result;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) 
            nums[index] = -nums[index];
    }

    int count = 0;
    for (int i = 0; i < numsSize; i++) 
        if (nums[i] > 0) 
            count++;

    int* result = (int*)malloc(count * sizeof(int));
    int j = 0;
    for (int i = 0; i < numsSize; i++) 
        if (nums[i] > 0) 
            result[j++] = i + 1;

    *returnSize = count;
    return result;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) 
                nums[index] = -nums[index];
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) 
            if (nums[i] > 0) 
                result.push_back(i + 1);

        return result;
    }
};
```

</details>
<br>

## squares of a sorted array
Problem Link: https://leetcode.com/problems/squares-of-a-sorted-array

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            res.append(num*num)
        return sorted(res)
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) 
            res[i] = nums[i] * nums[i];
    
        Arrays.sort(res);
        return res;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) 
        res[i] = nums[i] * nums[i];
    
    qsort(res, numsSize, sizeof(int), compare);
    *returnSize = numsSize;
    
    return res;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for(int &num : nums){
            res.push_back(num*num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```

</details>
<br>

## convert 1d array into 2d array
Problem Link: https://leetcode.com/problems/convert-1d-array-into-2d-array

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m * n:
            return []
        return [original[i * n : (i + 1) * n] for i in range(m)]
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if (original.length != m * n) return new int[0][0];
        
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                res[i][j] = original[i * n + j];

        return res;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    if (originalSize != m * n) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** res = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) 
            res[i][j] = original[i * n + j];
    }

    return res;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m * n) return {};
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
                res[i][j] = original[i * n + j];
        
        return res;
    }
};
```

</details>
<br>

## find all duplicates in an array
Problem Link: https://leetcode.com/problems/find-all-duplicates-in-an-array

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            idx = abs(num) - 1
            if nums[idx] < 0:
                res.append(abs(num))
            else:
                nums[idx] *= -1
        return res
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int num : nums) {
            int idx = Math.abs(num) - 1;
            if (nums[idx] < 0) res.add(Math.abs(num));
            else nums[idx] *= -1;
        }
        return res;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) res[(*returnSize)++] = abs(nums[i]);
        else nums[idx] *= -1;
    }

    return res;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int &num : nums) {
            int idx = abs(num) - 1;
            if(nums[idx] < 0) res.emplace_back(abs(num));
            else nums[idx] *= -1;
        }
        return res;
    }
};
```

</details>
<br>

## fruit into baskets
Problem Link: https://leetcode.com/problems/fruit-into-baskets

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        counter = defaultdict(int)
        l = maxi = 0
        for r, fruit in enumerate(fruits):
            counter[fruit] += 1

            while len(counter) > 2:
                counter[fruits[l]] -= 1
                if counter[fruits[l]] == 0:
                    del counter[fruits[l]]
                l += 1

            maxi = max(maxi, r - l + 1)
        
        return maxi
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int totalFruit(int[] fruits) {
        int l = 0, maxi = 0;
        HashMap<Integer, Integer> counter = new HashMap<>();
        
        for (int r = 0; r < fruits.length; r++) {
            counter.put(fruits[r], counter.getOrDefault(fruits[r], 0) + 1);
            
            while (counter.size() > 2) {
                counter.put(fruits[l], counter.get(fruits[l]) - 1);
                if (counter.get(fruits[l]) == 0) 
                    counter.remove(fruits[l]);
                
                l++;
            }
            
            maxi = Math.max(maxi, r - l + 1);
        }
        
        return maxi;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
#define MAX_FRUITS 100000
int totalFruit(int* fruits, int fruitsSize) {
    int l = 0, maxi = 0;
    int counter[MAX_FRUITS] = {0};
    int unique = 0;

    for (int r = 0; r < fruitsSize; r++) {
        if (counter[fruits[r]] == 0) 
            unique++;
        counter[fruits[r]]++;

        while (unique > 2) {
            counter[fruits[l]]--;
            if (counter[fruits[l]] == 0) 
                unique--;
            l++;
        }

        if (r - l + 1 > maxi) 
            maxi = r - l + 1;
    }

    return maxi;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
// hashmap + sliding window
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, maxi = 0;
        unordered_map<int, int> counter;
        for(int r = 0; r < size(fruits); r++) {
            counter[fruits[r]]++;

            while(size(counter) > 2) {
                counter[fruits[l]]--;
                
                if(counter[fruits[l]] == 0)
                    counter.erase(fruits[l]);
                
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};
```

</details>
<br>

## 3sum closest
Problem Link: https://leetcode.com/problems/3sum-closest

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums.sort()
        closest = float('inf')
        
        for i in range(n - 2):
            l, r = i + 1, n - 1
            while l < r:
                cur = nums[i] + nums[l] + nums[r]
                if abs(cur - target) < abs(closest - target):
                    closest = cur
                
                if cur < target:
                    l += 1
                elif cur > target:
                    r -= 1
                else:
                    return cur
        
        return closest
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closest = nums[0] + nums[1] + nums[2];
        int n = nums.length;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int cur = nums[i] + nums[l] + nums[r];
                if (Math.abs(cur - target) < Math.abs(closest - target)) 
                    closest = cur;
                
                if (cur < target) l++;
                else if (cur > target) r--;
                else  return cur;
            }
        }
        return closest;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            int cur = nums[i] + nums[l] + nums[r];
            if (abs(cur - target) < abs(closest - target)) 
                closest = cur;
            
            if (cur < target) l++;
            else if (cur > target) r--;
            else return cur;
        }
    }
    return closest;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
// Two pointers + Greedy
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = size(nums);
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int cur = nums[i] + nums[l] + nums[r];
                if(abs(cur - target) < abs(closest - target)) 
                    closest = cur;
                if(cur < target) l++;
                else if(cur > target) r--;
                else return cur;
            }
        }
        return closest;
    }
};
```

</details>
<br>

## subarray product less than k
Problem Link: https://leetcode.com/problems/subarray-product-less-than-k

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        l, prod, cnt = 0, 1, 0

        for r in range(len(nums)):
            prod *= nums[r]
            while prod >= k:
                prod /= nums[l]
                l += 1

            cnt += r - l + 1
        
        return cnt
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;
        int l = 0, prod = 1, cnt = 0;
        
        for (int r = 0; r < nums.length; r++) {
            prod *= nums[r];
            while (prod >= k) 
                prod /= nums[l++];
            cnt += r - l + 1;
        }
        return cnt;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k <= 1) return 0;
    int l = 0, prod = 1, cnt = 0;
    
    for (int r = 0; r < numsSize; r++) {
        prod *= nums[r];
        while (prod >= k) 
            prod /= nums[l++];
        cnt += r - l + 1;
    }
    return cnt;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
// Sliding window
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int l = 0, prod = 1, cnt = 0;
        
        for(int r = 0; r < size(nums); r++) {
            prod *= nums[r];
            while (prod >= k)
                prod = prod / nums[l++];
            
            cnt = cnt + r - l + 1;
        }
        return cnt;
    }
};
```

</details>
<br>

## count unique characters of all substrings of a given string
Problem Link: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def uniqueLetterString(self, s: str) -> int:
        n = len(s)
        prev = [-1] * n
        next = [n] * n
        
        last = {}
        for i in range(n):
            c = s[i]
            if c in last:
                prev[i] = last[c]
            
            last[c] = i

        last = {}
        for i in range(n - 1, -1, -1):
            c = s[i]
            if c in last:
                next[i] = last[c]
            
            last[c] = i

        res = 0
        for i in range(n):
            res += (i - prev[i]) * (next[i] - i)

        return res
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int uniqueLetterString(String s) {
        int n = s.length();
        int[] prev = new int[n];
        int[] next = new int[n];
        HashMap<Character, Integer> last = new HashMap<>();

        for(int i = 0; i < n; i++) {
            char c= s.charAt(i);
            prev[i] = last.getOrDefault(c, -1);
            last.put(c, i);
        }
        last.clear();

        for(int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);
            next[i] = last.getOrDefault(c, n);
            last.put(c, i);
        }

        long res = 0;
        for(int i = 0; i < n; i++) 
            res += (long)(i - prev[i]) * (next[i] - i);

        return (int)res;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int uniqueLetterString(char* s) {
    int n = strlen(s);
    int* prev = (int*) malloc (n * sizeof(int));
    int* next = (int*) malloc (n * sizeof(int));
    int last[26];

    for(int i = 0; i < 26; i++) last[i] = -1;
    for(int i = 0; i < n; i++) {
        char c = s[i];
        prev[i] = last[c - 'A'];
        last[c - 'A'] = i;
    }

    for(int i = 0; i < 26; i++) last[i] = n;
    for(int i = n - 1; i >= 0; i--) {
        char c = s[i];
        next[i] = last[c - 'A'];
        last[c - 'A'] = i;
    }

    long long res = 0;
    for(int i = 0; i < n; i++) 
        res += (long long)(i - prev[i]) * (next[i] - i);

    free(prev);
    free(next);
    return (int)res;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = size(s);
        vector<int> prev(n, -1);
        vector<int> next(n, n);
        unordered_map<char, int> last;

        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(last.count(c)) 
                prev[i] = last[c];
            
            last[c] = i;
        }
        last.clear();

        for(int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if(last.count(c))
                next[i] = last[c];
            
            last[c] = i;
        }
        
        long long res = 0;
        for(int i = 0; i < n; i++)
            res += 1LL * (i - prev[i]) * (next[i] - i);

        return res;
    }
};
```

</details>
<br>

## course schedule iii
Problem Link: https://leetcode.com/problems/course-schedule-iii

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x : x[1])
        maxi = []
        total_time = 0

        for i, j in courses:
            total_time += i
            heapq.heappush(maxi, -i)

            while total_time > j:
                removed_course = -heapq.heappop(maxi)
                total_time -= removed_course
        
        return len(maxi)
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        PriorityQueue<Integer> maxi = new PriorityQueue<>((a, b) -> b - a);
        int total_time = 0;

        for(int [] course : courses) {
            int i = course[0];
            int j = course[1];
            total_time += i;
            maxi.offer(i);

            while(total_time > j) {
                int removed_course = maxi.poll();
                total_time -= removed_course;
            }
 
        }
        return maxi.size();
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
int compare(const void* a, const void* b) {
    int* courseA = *(int**)a;
    int* courseB = *(int**)b;
    return courseA[1] - courseB[1];
}

typedef struct {
    int* heap;
    int capacity;
    int size
}max_heap;

max_heap* create(int capacity) {
    max_heap* heap = (max_heap*)malloc(sizeof(max_heap));
    heap ->heap = (int*)malloc(capacity * sizeof(int));
    heap ->capacity = capacity;
    heap ->size = 0;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(max_heap* heap, int idx) {
    int largest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    if(l < heap->size && heap->heap[l] > heap->heap[largest])
        largest = l;
    if(r < heap->size && heap->heap[r] > heap->heap[largest])
        largest = r;

    if(largest != idx) {
        swap(&heap->heap[idx], &(heap->heap[largest]));
        max_heapify(heap, largest);
    }
}

void insert(max_heap* heap, int val) {
    if(heap->size == heap->capacity){
        heap->capacity *= 2;
        heap->heap = (int*)realloc(heap->heap, heap->capacity * sizeof(int));
    }
    heap->heap[heap->size++] = val;
    int i = heap->size - 1;

    while(i != 0 && heap->heap[(i-1)/2] < heap->heap[i]) {
        swap(&heap->heap[i], &heap->heap[(i-1)/2]);
        i = (i - 1) / 2;
    }
}

int get_max(max_heap* heap) {
    if(heap->size <= 0) return -1;
    int maxi = heap->heap[0];
    heap->heap[0] = heap->heap[--heap->size];
    max_heapify(heap, 0);
    return maxi;
}

void free_heap(max_heap* heap) {
    free(heap->heap);
    free(heap);
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    qsort(courses, coursesSize, sizeof(int*), compare);
    max_heap* max_heap = create(coursesSize);   
    int total_time = 0;

    for(int k = 0; k < coursesSize; k++) {
        int i = courses[k][0];
        int j = courses[k][1];
        total_time += i;
        insert(max_heap, i);

        while(total_time > j) {
            int removed_course = get_max(max_heap);
            total_time -= removed_course;
        }
    }

    int res = max_heap->size;
    free_heap(max_heap);
    return res;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(), c.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> max_heap;
        int total_time = 0;

        for(auto& course : c) {
            int i = course[0];
            int j = course[1];
            total_time += i;
            max_heap.push(i);

            while(total_time > j) {
                int removed_course = max_heap.top();
                max_heap.pop();
                total_time -= removed_course;
            }
        }
        return size(max_heap);
    }
};
```

</details>
<br>

## meeting rooms
Problem Link: https://leetcode.com/problems/meeting-rooms

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
# TODO
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
// TODO
```

</details>
<br>

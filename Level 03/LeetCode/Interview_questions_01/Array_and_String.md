<details>
  <summary><strong><a href=https://leetcode.com/problems/majority-element/>majority element</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  // O(n^2) solution
  class Solution {
  public:
      int majorityElement(vector<int>& nums) {
          int n = size(nums);
          int times = size(nums) / 2, num;
          for(int i = 0; i < n - 1; i++) {
              int cnt = 1;
              for(int j = i + 1; j < n; j++) {
                  if(nums[i] == nums[j]) {
                      cnt++;
                  }
              }
              if(cnt > times) {
                  num = nums[i];
                  break;
              }
          }   
          return num;
      }
  };

  // O(n) solution
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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/jump-game>Jump Game</a></strong></summary>
  
  <summary>C++ solution</summary>

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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/product-of-array-except-self>product of array except self</a></strong></summary>
  
  <summary>C++ solution</summary>

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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/search-a-2d-matrix-ii>search a 2d matrix ii</a></strong></summary>
  
  <summary>C++ solution</summary>

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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/spiral-matrix>spiral matrix</a></strong></summary>
  
  <summary>C++ solution</summary>

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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/rotate-image>rotate image</a></strong></summary>
  
  <summary>C++ solution</summary>

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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/set-matrix-zeroes>set matrix zeroes</a></strong></summary>
  
  <summary>C++ solution</summary>

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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/add-two-numbers>add two numbers</a></strong></summary>
  
  <summary>C++ solution</summary>

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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/sort-colors>sort colors</a></strong></summary>
  
  <summary>C++ solution</summary>

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

  <summary>Python solution</summary>

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

<details>
  <summary><strong><a href=https://leetcode.com/problems/find-the-duplicate-number>find the duplicate number</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/first-missing-positive>first missing positive</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/best-time-to-buy-and-sell-stock>best time to buy and sell stock</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/missing-number>missing number</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array>find all numbers disappeared in an array</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/squares-of-a-sorted-array>squares of a sorted array</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/convert-1d-array-into-2d-array>convert 1d array into 2d array</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/find-all-duplicates-in-an-array>find all duplicates in an array</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/fruit-into-baskets>fruit into baskets</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/3sum-closest>3sum closest</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/subarray-product-less-than-k>subarray product less than k</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string>count unique characters of all substrings of a given string</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/course-schedule-iii>course schedule iii</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>

<details>
  <summary><strong><a href=https://leetcode.com/problems/meeting-rooms>meeting rooms</a></strong></summary>
  
  <summary>C++ solution</summary>

  ```cpp
  ```

  <summary>Python solution</summary>

  ```python
  ```
</details>
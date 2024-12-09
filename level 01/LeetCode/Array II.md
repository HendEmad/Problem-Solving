<details>
  <summary><strong><a href="https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/">1031. Maximum Sum of Two Non-Overlapping Subarrays</a></strong></summary>

```cpp
class Solution {
public:
    int n;
    // Using sliding window approach
    int findMaxSum(vector<int>& arr, int len, int s, int e) {
        int sum = 0, ans = 0;
        for(int i = s; i < s + len; i++)
            sum += arr[i];
        
        int i = s, j = i + len;
        while(j <= e) {
            ans = max(ans, sum);
            sum += arr[j];
            sum -= arr[i];
            i++;
            j++;
        }

        ans = max(ans, sum);
        return ans;
    }

    int findSecondSubarraySum(vector<int>& arr, int start, int end, int len) {
        int left = INT_MIN, right = INT_MIN;
        if(start >= len)
            left = findMaxSum(arr, len , 0, start - 1);
        
        if(n - end - 1 >= len)
            right = findMaxSum(arr, len, end + 1, n - 1);

        return max(left, right);
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        n = nums.size();
        int sum1 = 0, sum2 = 0, ans = INT_MIN;

        for(int i = 0; i < firstLen; i++)
            sum1 += nums[i];
        
        int j = firstLen - 1, i = 0;
        while(j < n) {
            sum2 = findSecondSubarraySum(nums, i, j, secondLen);
            ans = max(ans, (sum1 + sum2));
            j++;
            if(j < n)
                sum1 += nums[j];
            sum1 -= nums[i];
            i++;    
        }
        ans = max(ans, (sum1 + sum2));
        return ans;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/matrix-diagonal-sum/description/">1572. Matrix Diagonal Sum</a></strong></summary>

```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum1 = 0, sum2 = 0;

        for(int i = 0; i < n; i++) {
            sum1 += mat[i][i];
            sum2 += mat[i][n - i - 1];
        }

        if(n % 2 != 0) 
            sum2 -= mat[n / 2][n / 2];

        return sum1 + sum2;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/maximum-population-year/description/">1854. Maximum Population Year</a></strong></summary>

```cpp
class Solution {
public:
    // using sweep line algorithm
    int maximumPopulation(vector<vector<int>>& logs) {
        int populationChanges[101] = {0};

        for(const auto &log : logs) {
            int birth = log[0];
            int death = log[1];
            populationChanges[birth - 1950] ++;
            if(death <= 2050) 
                populationChanges[death - 1950] --;
        }

        int maxPopulation = 0, currentPopulation = 0, earliestYear = 1950;
        for(int year = 1950; year <= 2050; year++) {
            currentPopulation += populationChanges[year - 1950];
            if(currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                earliestYear = year;
            }
        }

        return earliestYear;
    }
};

// Another solution
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       map <int, int> populationChanges; // year: population

       for(const auto &log : logs) {
            int birth = log[0];
            int death = log[1];
            populationChanges[birth] ++;
            populationChanges[death] --;
       }

       int maxPopulation = 0, currentPopulation = 0, earliestYear = 1950;
       for(const auto &entry : populationChanges) {
        currentPopulation += entry.second;
        if(currentPopulation > maxPopulation) {
            maxPopulation = currentPopulation;
            earliestYear = entry.first; 
        }
       }
       return earliestYear;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/">1464. Maximum Product of Two Elements in an Array</a></strong></summary>

```cpp
// solution 1: time complexity = O(n^2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int ans = (nums[i] - 1) * (nums[j] - 1);
                result = max(result, ans);
            }
        }
        return result;
    }
};

// Solution 2: time complexity = O(n log(n))
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
    } 
};

// Solution 3: O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for(int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            }
            else if(num > max2)
                max2 = num;
        }
        return (max1 - 1) * (max2 - 1);
    } 
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/best-sightseeing-pair/description/">1014. Best Sightseeing Pair</a></strong></summary>

```cpp
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // part1 = values[i] + i
        // part2 = values[j] - j
        int part1 = values[0] + 0;
        int maxScore = 0;

        for(int j = 1; j < size(values); j++) {
            maxScore = max(maxScore, part1 + values[j] - j);
            part1 = max(part1, values[j] + j);
        }

        return maxScore;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/third-maximum-number/description/">414. Third Maximum Number</a></strong></summary>

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1 = nums[0], max2 = max1, max3 = max1;
        for(int num : nums) {
            if(num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if((num > max2 && num < max1) || max1 == max2) {
                if(max2 != max1)
                    max3 = max2;
                max2 = num;
            }
            else if((num > max3 && num < max1 && num < max2) || max3 == max2 || max3 == max1)
                max3 = num;
        }
        
        if(max1 > max2 && max2 > max3)
            return max3;
        else
            return max1;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/description/">1450. Number of Students Doing Homework at a Given Time</a></strong></summary>

```cpp
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int count = 0;
        for(int i = 0; i < size(startTime); i++) {
            int start_time = startTime[i];
            int end_time = endTime[i];
            if(queryTime >= start_time && queryTime <= end_time)
                count++;
        }
        return count;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/">1304. Find N Unique Integers Sum up to Zero</a></strong></summary>

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector <int> result;
        if(n % 2 != 0)
            result.emplace_back(0);

        for(int i = 1; i <= n/2; i++) {
            result.emplace_back(i);
            result.emplace_back(-i);
        }

        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/">1742. Maximum Number of Balls in a Box</a></strong></summary>

```cpp
class Solution {
public:
    int sum(int n){
        int s = 0;
        while(n > 0){
            s += (n % 10);
            n /= 10;
        }
        return s;
    }

    int countBalls(int lowLimit, int highLimit) {
        vector <int> box(10000, 0);
        int result = INT_MIN;

        for(int i = lowLimit; i <= highLimit; i++) {
            int boxNum = sum(i);
            box[boxNum] ++;
            result = max(result, box[boxNum]);
        }
        return result;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/height-checker/description/">1051. Height Checker</a></strong></summary>

```cpp
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector <int> expected = heights;
        sort(expected.begin(), expected.end());

        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != expected[i])
                count++;
        }
        return count;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/spiral-matrix-ii/description/">59. Spiral Matrix II</a></strong></summary>

```cpp
// O(n^2) solution
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int total = n * n, cell_num = 0;
        int first_row = 0, last_row = n - 1, first_col = 0, last_col = n - 1;
        vector <vector <int>> mat(n, vector<int>(n, 0));

        while(cell_num < total) {
            // fill the first row from left to right
            for(int i = first_col; cell_num < total && i <= last_col; i++) 
                mat[first_row][i] = ++cell_num;
            first_row ++;

            // fill the last column from up to down
            for(int i = first_row; cell_num < total && i <= last_row; i++) 
                mat[i][last_col] = ++cell_num;
            last_col --;

            // fill the last row from left to right
            for(int i = last_col; cell_num < total && i >= first_col; i--) 
                mat[last_row][i] = ++cell_num;
            last_row --;

            // fill the first column from down to up
            for(int i = last_row; cell_num < total && i >= first_row; i--)
                mat[i][first_col] = ++cell_num;
            first_col ++;
        }
        return mat;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/">1700. Number of Students Unable to Eat Lunch</a></strong></summary>

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue <int> students_queue;
        for(int i = 0; i < size(students); i++) 
            students_queue.push(students[i]);

        int i = 0, cnt = 0;
        while(size(students_queue) > 0 and cnt != size(students_queue)) {
            if(students_queue.front() == sandwiches[i]) {
                cnt = 0;
                i ++;
                students_queue.pop();
            }
            else {
                students_queue.push(students_queue.front());
                students_queue.pop();
                cnt ++;
            }
        }
        return size(students_queue);
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/available-captures-for-rook/description/">999. Available Captures for Rook</a></strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini = INT_MAX;
        vector <vector <int>> res;
        sort(arr.begin(), arr.end());

        for(int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < mini) {
                mini = diff;
                res.clear();
            }
            if(diff == mini) {
                res.push_back({arr[i-1], arr[i]});    
            }
        }
        return res;
    }
};
```
</details>

<details>
  <summary><strong><a href="https://leetcode.com/problems/mean-of-array-after-removing-some-elements/description/">1619. Mean of Array After Removing Some Elements</a></strong></summary>

```cpp
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int min_max_to_remove = 0.05 * arr.size();
        sort(arr.begin(), arr.end());

        arr.erase(arr.begin(), arr.begin() + min_max_to_remove);
        arr.erase(arr.end() - min_max_to_remove, arr.end());

        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }

        double mean = double(sum) / arr.size();
        return mean;
    }
};
```
</details>
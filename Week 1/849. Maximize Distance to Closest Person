class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maxDistance = 0;
        int left = -1;
        int right = 0;

        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) 
                left = i;
            else {
                while ((right < n && seats[right] == 0) || right < i) 
                    ++right;
                

                int leftDistance = left == -1 ? n : i - left;
                int rightDistance = right == n ? n : right - i;
                int distance = std::min(leftDistance, rightDistance);
                maxDistance = std::max(maxDistance, distance);
            }
        }

        return maxDistance;
    }
};

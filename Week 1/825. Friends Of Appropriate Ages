class Solution {
public:
    int numFriendRequests(std::vector<int>& ages) {
        int count = 0;
        unordered_map<int, int> ageCount;

        for (int age : ages) 
            ++ageCount[age];

        for (auto& person1 : ageCount) {
            for (auto& person2 : ageCount) {
                int age1 = person1.first;
                int age2 = person2.first;
                int count1 = person1.second;
                int count2 = person2.second;

                if (age2 <= 0.5 * age1 + 7) 
                    continue;
                
                if (age2 > age1) 
                    continue;
                
                if (age2 > 100 && age1 < 100) 
                    continue;

                if (age1 == age2) 
                    count += count1 * (count2 - 1);
                else 
                    count += count1 * count2;
            }
        }

        return count;
    }
};

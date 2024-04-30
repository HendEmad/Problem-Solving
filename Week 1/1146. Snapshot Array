class SnapshotArray {
private:
    vector <unordered_map<int, int>> listOfVersions;

public:
    // Solution using list of hash maps
    SnapshotArray(int length) {
        listOfVersions.emplace_back();    
    }
    
    void set(int index, int val) {
        int snapId = listOfVersions.size() - 1;
        listOfVersions[snapId][index] = val;
    }
    
    int snap() {
        listOfVersions.emplace_back();
        return listOfVersions.size() - 2;
    }
    
    int get(int index, int snapId) {
        for(int i = snapId; i >= 0; i--){
            if(listOfVersions[i].count(index))
                return listOfVersions[i][index];
        }
        return 0;
    }
};

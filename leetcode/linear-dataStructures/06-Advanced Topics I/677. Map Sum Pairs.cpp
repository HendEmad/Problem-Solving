class TrieNode {
public:
    int value;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() : value(0) {}
};

class MapSum {
private:
    TrieNode* root;
    unordered_map<string, int> keyValue;

public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int delta = val - keyValue[key];
        keyValue[key] = val;
        
        TrieNode* curr = root;
        for (char ch : key) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
            curr->value += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) {
                return 0;
            }
            curr = curr->children[ch];
        }
        return curr->value;
    }
};
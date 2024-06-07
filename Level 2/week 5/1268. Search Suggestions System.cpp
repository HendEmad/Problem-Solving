class TrieNode {
public:
    vector<TrieNode*> children;
    vector<string> suggestions;
    
    TrieNode() : children(26, nullptr) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->suggestions.push_back(word);
            sort(node->suggestions.begin(), node->suggestions.end());
            if (node->suggestions.size() > 3) {
                node->suggestions.pop_back();
            }
        }
    }
    
    vector<string> search(const string& prefix) {
        TrieNode* node = root;
        vector<string> result;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                return result;
            }
            node = node->children[idx];
        }
        return node->suggestions;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (const string& product : products) {
            trie.insert(product);
        }
        
        vector<vector<string>> result;
        string prefix = "";
        for (char ch : searchWord) {
            prefix += ch;
            result.push_back(trie.search(prefix));
        }
        
        return result;
    }
};
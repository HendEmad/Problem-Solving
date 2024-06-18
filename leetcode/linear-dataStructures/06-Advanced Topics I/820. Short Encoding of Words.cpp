class Solution {
public:
    struct Trie {
     unordered_map<char, Trie*> childs;   
    };
    Trie* root = nullptr;
    int cnt_sharp = 0;
    int cnt_char = 0;
    Solution() : root(new Trie()) {};


    void buildSuffixTrie(string word) {
      auto current = root;
      for (int i = word.size() - 1; i >= 0; i--) {
        char c = word[i];
        if (current->childs.find(c) != current->childs.end()) {
           current = current->childs[c];
        } else {
            if (current->childs.find('*') != current->childs.end()) {
              current->childs.erase('*');
              cnt_char -= (word.size() - i - 1);
              cnt_sharp--;
            }
            current->childs[c] = new Trie();
            current = current->childs[c];
        }
        cnt_char++;
      }
      if (current->childs.size() == 0) {
        current->childs['*'] = nullptr;
        cnt_sharp++;
      } else {
         cnt_char -= word.size();
      }

    }

   

    int minimumLengthEncoding(vector<string>& words) {
        
        for (const auto & word : words) {
            buildSuffixTrie(word);
        }



      return cnt_char + cnt_sharp;
    }
};
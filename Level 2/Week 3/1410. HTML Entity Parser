class Solution {
public:
    string entityParser(string text) {
        int n = text.size();
        string ans = "";
        int i = 0;

        while (i < n) {
            if (i+6 < n && text.substr(i, 7) == "&frasl;") {
                ans += "/";
                i += 7;
            }
            else if(i+5 < n && (text.substr(i, 6) == "&quot;" || text.substr(i, 6) == "&apos;")) {
                if (text.substr(i, 6) == "&quot;")
                    ans += '"';
                else
                    ans += "'";
                i += 6;
            }
            else if(i+4 < n && text.substr(i, 5) == "&amp;") {
                ans += "&";
                i += 5;
            }
            else if(i+3 < n && (text.substr(i, 4) == "&gt;" || text.substr(i, 4) == "&lt;")) {
                if (text.substr(i, 4) == "&gt;")
                    ans += ">";
                else
                    ans += "<";
                i += 4;
            }
            else {
                ans += text[i];
                i++;
            }
        }
        return ans;
    }
};

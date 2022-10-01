// Name: SARAVANAN S
// Github id: sarav18302


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) 
            return false;;
        map<string, int> h;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
       return false;
        
    }
};

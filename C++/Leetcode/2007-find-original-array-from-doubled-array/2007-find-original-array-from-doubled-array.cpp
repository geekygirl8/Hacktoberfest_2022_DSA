class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        vector<int> newvec;
        int n = c.size();
        if(n%2 == 1){
            return {}; 
        }
        unordered_map<int, int> mp;
        sort(c.begin(), c.end());
        for(int i = 0;i < n; i++){
            mp[c[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mp[c[i]] == 0){
                continue;
            }
            if(mp[c[i]*2] == 0){
                return {};
            }
            newvec.push_back(c[i]);
            mp[c[i]]--;
            mp[c[i]*2]--;
        }
        return newvec;
    }
};
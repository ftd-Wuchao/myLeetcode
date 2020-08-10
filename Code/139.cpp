class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        unordered_map<string, bool> my_map;
        int max_size = 0;
        for(auto s:wordDict){
            my_map[s] = true;
            max_size = max(max_size, int(s.size()));
        }
        
        dp[0] = true;
        for(int i=1; i<=s.size(); i++){
            for(int j=i-1; j>=0 && j>=i-max_size; j--){
                dp[i] =  dp[j] && my_map[s.substr(j,i-j)];
                if(dp[i]) break;
            }
        }
        return dp[s.size()];
    }
};
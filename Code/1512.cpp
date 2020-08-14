class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,vector<int>> ump;
        vector<vector<int>>  res;
        for(int i=0; i<nums.size(); i++){
            if(ump.count(nums[i])){
                for(auto index:ump[nums[i]]) res.push_back({index,i});
                ump[nums[i]].push_back(i);
            }else{
                ump[nums[i]].push_back(i);
            }
        }
        return res.size();
    }
};
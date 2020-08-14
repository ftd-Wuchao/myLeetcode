class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int count=0,res=0;
        m[0] =-1;
        for(int i=0; i<nums.size(); i++){
            count += (nums[i]==1? 1:-1);
            if(m.count(count)) res = max(res, i-m[count]);
            else m[count] = i;
        }
        return res;
    }
};
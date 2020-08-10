class Solution {
public:
    int dfs(vector<string>& arr,int start, int map){
        if(start >= arr.size()) return 0;
        int cur_map=0;
        for(char c:arr[start]){
            if(cur_map & (1<<(c-'a'))){
                return dfs(arr, start+1,  map);
            }
            cur_map |= 1<<(c-'a');
        }
        if((cur_map & map) == 0)
            return max(int(arr[start].size())+dfs(arr, start+1,  map | cur_map), dfs(arr, start+1,  map));
        else 
            return dfs(arr, start+1,  map);
    }
    int maxLength(vector<string>& arr) {
        return dfs(arr,0, 0);
    }
};
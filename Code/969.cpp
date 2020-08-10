class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ret;

        for(int i=A.size()-1; i>=0; i--){
            int index=i;
            for(int j=i-1; j>=0; j--){
                if(A[index]<A[j]) index=j;
            }
            
            reverse(A.begin(),A.begin()+index+1);
            ret.push_back(index+1);
            reverse(A.begin(),A.begin()+i+1);
            ret.push_back(i+1);
            
        }
        return ret;
    }
};
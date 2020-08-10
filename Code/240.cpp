class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        int row=matrix.size()-1, col=0;
        while(1){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target){
                col++;
                if(col==matrix[0].size()) return false;
            }
            else{
                row--;
                if(row<0) return false;
            }
        }
        return false;
    }
};
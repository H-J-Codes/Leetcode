class Solution {
public:
    bool searchInRow(vector<vector<int>>&matrix,int target, int row){
        int n=matrix[0].size();
        int st=0,end=n-1;
        while(st<=end){
            int mid=st + (end-st)/2;
            if(target>matrix[row][mid]){
                st=mid+1;
            }
            else if(target<matrix[row][mid]){
                end=mid-1;
            }
            else{
                return true;
            }
        }
        return false;

    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int stR=0,endR=m-1;
        while(stR<=endR){
            int midR=stR + (endR-stR)/2;
            if(target>=matrix[midR][0] && target<=matrix[midR][n-1]){
                return searchInRow(matrix, target, midR);
            }
            else if(target<=matrix[midR][0]){
                endR=midR-1;
            }
            else{
                stR=midR+1;
            }
        }
        return false;
    }
    
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_cost=0;
        int total_gas=0;
        int st=0;
        int cg=0;
        for(int i =0;i<n;i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
            cg+=gas[i]-cost[i];
            if(cg<0){
                cg=0;
                st=i+1;
            }
        }
        if(total_gas<total_cost)return -1;
        return st;
    }

};

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());

        int v = 0;
        long long m = 0;
        for(int i=cost.size()-1; i>=0; i--){
            if(v==2){
                v = 0;
            } else{
                m += cost[i];  
                v++;
            }
        }
        return m;
    }
};
class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int s = arr.size();

        for(int i=0; i<s; i++){
            if(arr[i] == 0){
                bool emptyleft = (i == 0 || arr[i-1] == 0);
                bool emptyright = (i == s - 1 || arr[i+1] == 0);
                
                if(emptyleft && emptyright){
                    arr[i] = 1;
                    n--;

                    if(n <= 0) return true;
                }
            }
        }

       return n <= 0;
    }
};
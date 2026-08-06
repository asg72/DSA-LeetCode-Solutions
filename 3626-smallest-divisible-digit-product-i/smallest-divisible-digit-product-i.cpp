class Solution {
public:
    int smallestNumber(int n, int t) {
       int res = n;

       for(int i=0; i<10; i++){
            int digitProduct = 1;

            res = n;

            while(res > 0){
            digitProduct *= res % 10;
            res /= 10;
            }

            if(digitProduct % t == 0) return n;
            else n++;
       } 
            return 0;
    }
};
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int num = n;
        while(n>0){
            sum += n%10;
            product *= n%10;

            n/=10;
        }

        if(num%(sum+product) == 0){
            return true;
        } else return false;
    }
};
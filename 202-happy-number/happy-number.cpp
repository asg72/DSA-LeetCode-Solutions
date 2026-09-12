class Solution {
public:
    int isNumHappy(int n){
        int sum = 0;
        while(n > 0){
            int d = n % 10;
            n = n / 10;
            sum += d*d;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        while(fast != 1){
            slow = isNumHappy(slow);
            fast = isNumHappy(fast);
            fast = isNumHappy(fast);

            if(fast == slow && slow != 1){
                return false;
            }
        }    

        return true;
    }
};
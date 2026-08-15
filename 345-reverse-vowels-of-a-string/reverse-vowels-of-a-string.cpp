class Solution {
public:
    bool isVowel(char ch){
        return string("aeiouAEIOU").find(ch) != string::npos;
    }

    string reverseVowels(string s) {
        int st = 0;
        int end = s.size()-1;

        while(st<end){
        char stChar = s[st];
        char endChar = s[end];

if(isVowel(stChar) && isVowel(endChar)){
swap(s[st],s[end]);
st++;end--;
} else if(!isVowel(stChar)){
st++;
} else if(!isVowel(endChar)){
end--;
} else{
    st++;end--;
}
     
    }
        return s;

    }
};
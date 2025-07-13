class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    long long countVowels(string word) {
        int n=word.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(isvowel(word[i])){
                int l=i;
                int r=n-i-1;
                cnt+=(long long)(l+1)*(r+1);
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int wstart=0;
        int maxlen=0;
        set<char>st;
        while(i<n){
            if(st.find(s[i])!=st.end()){
                while(wstart<i && st.find(s[i])!=st.end()){
                    st.erase(s[wstart]);
                    wstart++;
                }
            }
            else{
                st.insert(s[i]);
                int a=st.size();
                maxlen=max(maxlen,a);
                i++;
            }
        }
        return maxlen;
    }
};
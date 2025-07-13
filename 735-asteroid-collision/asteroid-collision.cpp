class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int i=0;
        int n=asteroids.size();
        while(i<n){
            if((st.empty())){
                st.push(asteroids[i]);
                i++;
            }
            else if(asteroids[i]<0 && (!st.empty()) && st.top()>0 && abs(st.top())>abs(asteroids[i])){
                i++;
            }
            else if(asteroids[i]<0 && (!st.empty()) && st.top()>0 && abs(st.top())<abs(asteroids[i])){
                st.pop();
            }
            else if(asteroids[i]<0 && (!st.empty()) && st.top()<0){
                st.push(asteroids[i]);
                i++;
            }
            else if(asteroids[i]<0 && (!st.empty()) && st.top()>0 && abs(st.top())==abs(asteroids[i])){
                st.pop();
                i++;
            }
            else{
                st.push(asteroids[i]);
                i++;
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
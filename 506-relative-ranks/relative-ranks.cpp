class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<int>pq;
        for(auto i:score){
            pq.push(i);
        }
        map<int,string>mp;
        vector<string>ans;
        int cnt=0;
        while(!pq.empty()){
            int t=pq.top();
            pq.pop();
            cnt++;
            mp[t]=to_string(cnt);
        }
        for(int i=0;i<n;i++){
            if(mp[score[i]]=="1"){
                ans.push_back("Gold Medal");
            }
            else if(mp[score[i]]=="2"){
                ans.push_back("Silver Medal");
            }
            else if(mp[score[i]]=="3"){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(mp[score[i]]);
            }
        }
        return ans;
    }
};
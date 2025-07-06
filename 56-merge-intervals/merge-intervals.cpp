class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        //for last intervals
        ans.push_back({start,end});
        return ans;
    }
};




























// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         if (intervals.empty()) {
//             return {};
//         }
        
//         // Sort the intervals based on the start time
//         sort(intervals.begin(), intervals.end());

//         vector<vector<int>> ans;
//         int n = intervals.size();
//         int start = intervals[0][0];
//         int end = intervals[0][1];

//         for (int i = 1; i < n; ++i) {
//             if (intervals[i][0] <= end) {
//                 // If intervals overlap, merge them
//                 end = max(end, intervals[i][1]);
//             } else {
//                 // If they don't overlap, add the previous interval to the answer
//                 ans.push_back({start, end});
//                 start = intervals[i][0];
//                 end = intervals[i][1];
//             }
//         }

//         // Add the last interval
//         ans.push_back({start, end});
//         return ans; 
//     }
// };
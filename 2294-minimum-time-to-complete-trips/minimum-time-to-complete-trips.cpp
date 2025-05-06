class Solution {
    bool isfun(vector<int>& time, int totalTrips,long long t){
        long long ans=0;
        for(int i=0;i<time.size();i++){
            ans=ans+t/time[i];
        }
        if(ans>=totalTrips){
            return true;
        }
        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long mini=*min_element(time.begin(),time.end());
        long long l=1;
        long long r=mini*totalTrips;
        while(l<r){
            long long mid=l+(r-l)/2;
            if(isfun(time,totalTrips,mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};











// class Solution {
// public:
//     long long minimumTime(vector<int>& time, int totalTrips) {
//         int n=time.size();
//         long long t=1;
//         while(true){
//             long long ans=0;
//             for(int i=0;i<n;i++){
//                 ans=ans+t/time[i];
//             }
//             if(ans>=totalTrips){
//                 return t;
//             }
//             t++;
//         }
//         return t;
//     }
// };
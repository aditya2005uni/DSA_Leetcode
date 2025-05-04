class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int st=0;
        int en=n-1;
        int c=0;
        while(st<=en){
            int m=people[en]+people[st];
            if(m>limit){
                en--;
                c++;
            }
            else{
                st++;
                en--;
                c++;
            }
        }
        return c;
    }
};

















//class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         int n=people.size();
//         sort(people.begin(),people.end());
//         int st=0;
//         int en=n-1;
//         int c=0;
//         while(en>=st){
//             int mid=people[st]+people[en];
//             if(mid>limit){
//                 en--;
//                 c++;
//             }
//             if(mid<=limit){
//                 st++;
//                 en--;
//                 c++;
//             }

//         }
//         return c;
//     }
// };
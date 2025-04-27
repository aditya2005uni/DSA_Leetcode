/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=lists.size();
        for(auto i:lists){
            while(i!=nullptr){
                pq.push(i->val);
                i=i->next;
            }
        }
        ListNode*ans=new ListNode(0);
        ListNode*temp=ans;
        while(!pq.empty()){
            temp->next=new ListNode(pq.top());
            pq.pop();
            temp=temp->next;
        }
        return ans->next;
    }
};































//class Solution {
//     ListNode* fun(ListNode*l1, ListNode*l2){
//         if(l1==nullptr){
//             return l2;
//         }
//         if(l2==nullptr){
//             return l1;
//         }
//         if(l1->val<=l2->val){
//             l1->next=fun(l1->next,l2);
//             return l1;
//         }
//         else{
//             l2->next=fun(l1,l2->next);       
//             return l2;
//         }
//     }
//     ListNode* merge(int s,int e,vector<ListNode*>& lists){
//         if(s>e){
//             return nullptr;
//         }
//         if(s==e){
//             return lists[s];
//         }
//         int mid=s+(e-s)/2;
//         ListNode* l1=merge(s,mid,lists);
//         ListNode* l2=merge(mid+1,e,lists);
//         return fun(l1,l2);
//     }
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         // ListNode* ans=nullptr;
//         // for(auto i:lists){
//         //     ans=fun(ans,i);
//         // }
//         // return ans;
//         int k=lists.size();
//         if(k==0){
//             return nullptr;
//         }
//         return merge(0,k-1,lists);
//     }
// };

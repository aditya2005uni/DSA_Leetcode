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
    ListNode* middle(ListNode* head){
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode*l1,ListNode*r1){
        if(l1==nullptr && r1!=nullptr){
            return r1;
        }
        if(l1!=nullptr && r1==nullptr){
            return l1;
        }
        ListNode*ans=new ListNode(0);
        ListNode*curr=ans;
        while(l1!=nullptr && r1!=nullptr){
            if(l1->val<r1->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=r1;
                r1=r1->next;
            }
            curr=curr->next;
        }
        if(l1 != nullptr){
            curr->next = l1;
        }
        else {
            curr->next = r1;
        }
        return ans->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*midd=middle(head);
        ListNode*newhead=midd->next;
        midd->next=nullptr;
        
        ListNode*left=sortList(head);
        ListNode*right=sortList(newhead);
        return merge(left,right);
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(ListNode* New, ListNode* l1, ListNode* l2,int Carry){
        if(l1==NULL && l2==NULL && Carry==0) return;
        else if(l1==NULL && l2==NULL){
            New->next = new ListNode(Carry);
        }
        else if(l1==NULL){
            int sum = l2->val+Carry;
            New->next = new ListNode(sum%10);
            dfs(New->next, l1, l2->next, sum/10);
        }
        else if(l2==NULL){
            int sum = l1->val+Carry;
            New->next = new ListNode(sum%10);
            dfs(New->next, l1->next, l2, sum/10);
        }
        else{
            int sum = l1->val+l2->val+Carry;
            New->next = new ListNode(sum%10);
            dfs(New->next, l1->next, l2->next, sum/10);
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(-1);
        dfs(temp, l1, l2, 0);
        head = temp->next;
        delete temp;
        return head;
    }
private:
    ListNode* head;
};
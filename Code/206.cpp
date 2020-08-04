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
	ListNode* dfs(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* node = dfs(head->next);
		head->next->next = head;
		head->next = NULL;
		return node;
	}

	ListNode* reverseList(ListNode* head) {
		return dfs(head);
	}
};

//diedai
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* curr = head;
		while (curr != NULL) {
			ListNode* next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
		}
		return pre;
	}
};
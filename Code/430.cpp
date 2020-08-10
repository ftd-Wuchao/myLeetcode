/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return head;
        Node* node = head;
        stack<Node*> s;
        while(node->next !=NULL || !s.empty() || node->child !=NULL){
            if(node->next == NULL && node->child ==NULL){
                Node* p= s.top();
                s.pop();
                node->next = p;
                p->prev = node;
                node = node->next;
            }
            else if(node->next != NULL && node->child ==NULL){
                node = node->next;
            }
            else if(node->next != NULL && node->child !=NULL){
                s.push(node->next);
                node->next = node->child;
                node->next->prev = node;
                node->child = NULL;
                node = node->next;
            }else if(node->next == NULL && node->child !=NULL){
                node->next = node->child;
                node->next->prev = node;
                node->child = NULL;
                node = node->next;
            }
        }

        return head;
    }
};
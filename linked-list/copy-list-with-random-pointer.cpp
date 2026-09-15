/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>m;
        Node* newNode=new Node(head->val);
        m[head] = newNode;
        Node* oldTemp=head->next;
        Node* newTemp=newNode;
        while(oldTemp!=NULL){
            Node* copyNode=new Node(oldTemp->val);
            m[oldTemp]=copyNode;
            newTemp->next=copyNode;
            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }
        oldTemp=head, newTemp=newNode;
        while(oldTemp!=NULL){
            newTemp->random=m[oldTemp->random];
            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }
        return newNode;
    }
};

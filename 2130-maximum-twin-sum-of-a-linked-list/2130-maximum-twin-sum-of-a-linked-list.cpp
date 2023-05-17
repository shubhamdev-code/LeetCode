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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head; 
        
        ListNode* currNode = head; 
        ListNode* nextNode = head->next; 
        ListNode* tmp = nullptr; 
        
        currNode->next = nullptr; 
        while(nextNode){
            tmp = nextNode->next; 
            nextNode->next = currNode; 
            currNode = nextNode; 
            nextNode = tmp; 
        }
        
        return currNode; 
    }
    
    int pairSum(ListNode* head) {
        ListNode* slow = head; ListNode* fast = head; 
        while(fast && fast->next){
            fast = fast->next->next; 
            slow = slow->next; 
        }
        
        ListNode* end = reverseList(slow); 
        int ans = 0; 
        while(head && end){
            ans = max(ans, end->val + head->val); 
            head = head->next; 
            end = end->next; 
        }
        return ans;
    }
};
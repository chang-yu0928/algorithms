#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *slow = head, *fast = head, *prev = slow;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        if(slow != head) root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
    
    int main() {
    	return 0;
    }
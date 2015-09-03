#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare
{
    bool operator()(const ListNode *node1, const ListNode *node2) {
        return node1->val > node2->val;
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> que;
        ListNode *dummy = new ListNode(0), *tail = dummy;
        int len = lists.size();
        for(int i = 0;i < len;i ++) {
            if(lists[i]) que.push(lists[i]);
        }
        while(!que.empty()) {
            ListNode *curr = que.top();
            que.pop();
            tail->next = curr;
            tail = tail->next;
            if(curr->next) que.push(curr->next);
        }
        return dummy->next;
    }
    
    int main() {
    	ListNode *list1 = new ListNode(1);
    	list1->next = new ListNode(3);
    	list1->next->next = new ListNode(5);
    	list1->next->next->next = new ListNode(7);
    	list1->next->next->next->next = new ListNode(9);
    	
    	ListNode *list2 = new ListNode(2);
    	list2->next = new ListNode(4);
    	list2->next->next = new ListNode(6);
    	list2->next->next->next = new ListNode(8);
    	
    	vector<ListNode *> lists;
    	lists.push_back(list1);
    	lists.push_back(list2);
    	lists.push_back(NULL);
    	
    	ListNode *result = mergeKLists(lists);
    	while(result) {
    		cout<<result->val<<" ";
    		result = result->next;
    	}
    	cout<<endl;
    	return 0;
    }
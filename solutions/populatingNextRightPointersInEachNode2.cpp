#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        TreeLinkNode *prev = NULL, *node = root, *first = NULL;
        while(node) {
            if(node->left) {
                if(!prev) {
                    prev = node->left;
                    first = node->left;
                } else {
                    prev->next = node->left;
                    prev= node->left;
                }
            }
            if(node->right) {
                if(!prev) {
                    prev = node->right;
                    first = node->right;
                } else {
                    prev->next = node->right;
                    prev = node->right;
                }
            }
            node = node->next;
        }
        if(prev) prev->next = NULL;
        connect(first);
    }
    
    int main() {
    	TreeLinkNode *root = new TreeLinkNode(1);
    	root->left = new TreeLinkNode(2);
    	root->right = new TreeLinkNode(3);
    	root->left->left = new TreeLinkNode(4);
    	root->left->right = new TreeLinkNode(5);
    	root->right->right = new TreeLinkNode(7);
    	connect(root);
    	TreeLinkNode *list2 = root->left;
    	TreeLinkNode *list3 = root->left->left;
    	while(root) {
    		cout<<root->val<<" ";
    		root = root->next;
    	}
    	cout<<endl;
    	while(list2) {
    		cout<<list2->val<<" ";
    		list2 = list2->next;
    	}
    	cout<<endl;
    	while(list3) {
    		cout<<list3->val<<" ";
    		list3 = list3->next;
    	}
    	cout<<endl;
    	return 0;
    }
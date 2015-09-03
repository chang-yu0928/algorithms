#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int n): val(n), left(NULL), right(NULL) {}
};

void printTreeLevel(TreeNode *root) {
	if(root == NULL) {
		cout<<"tree is empty!"<<endl;
		return;
	}
	queue<TreeNode *> container;
	TreeNode *guard = new TreeNode(0);
	container.push(root);
	container.push(guard);
	while(!container.empty()) {
		TreeNode *temp = container.front();
		container.pop();
		if(temp->left != NULL) {
			container.push(temp->left);
		}
		if(temp->right != NULL) {
			container.push(temp->right);
		}
		if(temp == guard) {
			if(!container.empty()) {
				container.push(guard);
			}
			cout<<endl;
		}else {
			cout<<temp->val<<" ";
		}
	}
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->right->left = new TreeNode(7);
	printTreeLevel(root);
	return 0;
}
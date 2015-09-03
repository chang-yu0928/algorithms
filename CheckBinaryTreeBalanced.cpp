#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int m): val(m), left(NULL), right(NULL) {}
};

class Tree {
	TreeNode *root;
	
	//if the subTree is balanced, retuen a positive integer of maxheight.
	//if the subtree is not balanced. retuen a negative integer.
	int check(TreeNode *subTree){
		if(subTree == NULL){
			return 0;
		}
		int leftHeight = 0;
		int rightHeight = 0;
		if(subTree->left != NULL){
			leftHeight = check(subTree->left) + 1;
		}
		if(subTree->right != NULL){
			rightHeight = check(subTree->right) + 1;
		}
		if(leftHeight != -1 && rightHeight != -1 && leftHeight - rightHeight <= 1 && leftHeight - rightHeight >= -1){
			return max(leftHeight, rightHeight);
		}
		return -1;
	}
	
	void deleteNode(TreeNode *subTree){
		if(subTree == NULL) return;
		deleteNode(subTree->left);
		deleteNode(subTree->right);
		delete subTree;
	}
	
public:
	Tree(){
		root = NULL;
	}
	Tree(int val){
		root = new TreeNode(val);
	}
	~Tree(){
		deleteNode(root);
	}
	
	TreeNode *getRoot(){
		return root;
	}
	
	bool checkBalance(){
		if(check(root) != -1){
			return true;
		}
		return false;
	}
};

int main(){
	Tree test;
	// test.getRoot()->left = new TreeNode(2);
	// test.getRoot()->right = new TreeNode(3);
	// test.getRoot()->left->left = new TreeNode(4);
	// test.getRoot()->left->right = new TreeNode(5);
	//test.getRoot()->left->right->left = new TreeNode(6);
	cout<<test.checkBalance()<<endl;
	return 0;
}
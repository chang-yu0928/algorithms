#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Tree {
	TreeNode *root;
	
	void deleteNode(TreeNode *subTree){
		if(subTree == NULL) return;
		deleteNode(subTree->left);
		deleteNode(subTree->right);
		delete subTree;
	}
	
	void printTreeTra(TreeNode *subTree){
		if(subTree->left != NULL){
			printTreeTra(subTree->left);
		}
		cout<<subTree->val<<" "<<endl;
		if(subTree->right != NULL){
			printTreeTra(subTree->right);
		}
	}
public:
	Tree(){
		root = NULL;
	}
	Tree(int x){
		root = new TreeNode(x);
	}
	~Tree(){
		deleteNode(root);
	}
	
	void insert(int element){
		if(root == NULL){
			root = new TreeNode(element);
			return;
		}
		TreeNode *temp = root;
		while(temp != NULL){
			if(element > temp->val){
				if(temp->right != NULL){
					temp = temp->right;
				}else{
					temp->right = new TreeNode(element);
				}
			}else{
				if(temp->left != NULL){
					temp = temp->left;
				}else{
					temp->left = new TreeNode(element);
				}
			}
		}
	}
	
	void printTree(){
		printTreeTra(root);
		cout<<endl;
	}
};

int main(){
	
}
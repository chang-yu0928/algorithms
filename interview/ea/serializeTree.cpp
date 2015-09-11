#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int n) : val(n), left(NULL), right(NULL) {}
};

struct NTreeNode {
    int val;
    vector<NTreeNode *> children;
    NTreeNode(int n) : val(n) {}
};

/*For binary tree*/
string binaryTreeSerialize(TreeNode *root) {
    stack<TreeNode *> sta;
    string res;
    TreeNode *curr, *guard = new TreeNode(0);;
    int i;
    sta.push(root);
    while(!sta.empty()) {
        curr = sta.top();
        sta.pop();
        if(curr == guard) {
            res += "#";
            continue;
        }
        res += "(" + to_string(curr->val) +")";
        if(curr->right) sta.push(curr->right);
        else sta.push(guard);
        if(curr->left) sta.push(curr->left);
        else sta.push(guard);
    }
    cout<<res<<endl;
    for(i = res.size() - 1;i >= 0;i --) {
        if(res[i] != '#') break;
    }
    res.erase(i + 1, res.size() - i);
    return res;
}

TreeNode *deSerialize(string s) {
    stack<pair<TreeNode *, bool> > sta;
    TreeNode *head = NULL, *node = NULL;
    pair<TreeNode *, bool> curr;
    int num = 0, sign = 1;
    for(int i = 0;i < s.size();i ++) {
        if(sta.empty()) {
            if(s[i] == '(') {
                sign = 1;
                num = 0;
            } else if(s[i] == ')') {
                head = new TreeNode(sign * num);
                curr.first = head;
                curr.second = false;
                sta.push(curr);
            } else {
                if(s[i] == '-') {
                    sign = -1;
                    continue;
                }
                num = num * 10 + (s[i] - '0');
            }
        } else {
            curr = sta.top();
            if(s[i] == '#') {
                if(curr.second) sta.pop();
                else curr.second = true;
            } else {
                if(s[i] == '(') {
                    num = 0;
                    sign = 1;
                } else if(s[i] == ')') {
                    if(curr.second) {
                        sta.pop();
                        node = new TreeNode(sign * num);
                        curr.first->right = node;
                        sta.push(make_pair(node, false));
                    } else {
                        node = new TreeNode(sign * num);
                        curr.first->left = node;
                        sta.push(make_pair(node, false));
                        curr.second = true;
                    }
                } else {
                    if(s[i] == '-') {
                        sign = -1;
                        continue;
                    }
                    num = num * 10 + (s[i] - '0');
                }
            }
        }
    }
    return head;
}

/*for NTree*/
//TODO: design for NTree.


void printTree(TreeNode *node) {
    if(node == NULL) return;
    cout<<node->val<<" ";
    printTree(node->left);
    printTree(node->right);
}

int main() {
    TreeNode *root = new TreeNode(11);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-331);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    printTree(root);
    cout<<endl;
    string res = binaryTreeSerialize(root);
    cout<<res<<endl;

    TreeNode *node = deSerialize(res);
    printTree(node);
    cout<<endl;
    return 0;
}

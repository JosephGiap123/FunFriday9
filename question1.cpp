#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x){
		left = right = nullptr;
		val = x;
	}
};

TreeNode* search(TreeNode* cur, int val){
	if(val == cur->val) return cur;
	if(val > cur->val)
		return search(cur->right, val);
	return search(cur->left, val);
}

TreeNode* insert(TreeNode* cur, int val){
	if(!cur) return new TreeNode(val);
	if(val > cur->val)
		cur->right = insert(cur->right, val);
	else
		cur->left = insert(cur->left, val);
	return cur;
}


void inOrderPrint(TreeNode* cur){
	if(!cur) return;
	inOrderPrint(cur->left);
	cout << cur->val << " ";
	inOrderPrint(cur->right);
}

int main(){
	TreeNode* root = new TreeNode(5);
	root = insert(root, 6);
	root = insert(root, 9);
	root = insert(root, 4);
	root = insert(root, 1);
	root = insert(root, 3);
	inOrderPrint(root);
	cout << endl;

	inOrderPrint(search(root, 4));
	cout << endl;
	return 0;
}
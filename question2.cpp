#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x){
		left = right = nullptr;
		val = x;
	}
};


TreeNode* insert(TreeNode* cur, int val){
	if(!cur) return new TreeNode(val);
	if(val > cur->val)
		cur->right = insert(cur->right, val);
	else
		cur->left = insert(cur->left, val);
	return cur;
}


void inOrderVector(TreeNode* cur, vector<int>& v){
	if(!cur) return;
	inOrderVector(cur->left, v);
	v.push_back(cur->val);
	inOrderVector(cur->right, v);
}

void inOrderPrint(TreeNode* cur){
	if(!cur) return;
	inOrderPrint(cur->left);
	cout << cur->val << " ";
	inOrderPrint(cur->right);
}

bool findTarget(TreeNode* cur, int target){
	vector<int> sortedArr;
	inOrderVector(cur, sortedArr);

	//after vector made just do regular two sum.
	int i = 0;
	int j = sortedArr.size()-1;
	while(i < j){
		if((sortedArr[i] + sortedArr[j]) > target)
			j--;
		else if((sortedArr[i] + sortedArr[j]) < target)
			i++;
		else
			return true;
	}	
	return false;
}

int main(){
	TreeNode* root = new TreeNode(5);
	root = insert(root, 3);
	root = insert(root, 6);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 7);

	inOrderPrint(root);
	cout << endl;

	cout << findTarget(root, 9) << endl;
	cout << findTarget(root, 28) << endl;
	return 0;
}
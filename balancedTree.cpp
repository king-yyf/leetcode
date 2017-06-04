#include<cstdio>
using namespace std;
#define ABS(a) (a) > 0 ? (a) : (-a) 
#define MAX(a,b) (a) > (b) ? (a) : (b)
struct TreeNode{
	char val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(char v):val(v),left(NULL),right(NULL){}
};

int balancedHeight(TreeNode * root){
	if(root == NULL) return 0;
	int left = balancedHeight(root->left);
	int right = balancedHeight(root->right);
	
	if(left < 0 || right < 0 || ABS(left - right) > 1) 
		return -1;
	return MAX(left, right) + 1;
}
bool isBalanced(TreeNode * root){
	return balancedHeight(root) >= 0;
}

void createTree(TreeNode * &root, char date[], int n, int & index){
	if(index >= n){
		return ;
	}
	char c = date[index++];
	if(c == '#') root = NULL;
	else{
		root = new TreeNode(c);
		createTree(root->left, date, n, index);
		createTree(root->right, date, n, index);
	}
}

void preorder(TreeNode * root){
	if(!root) return;
	printf("%c",root->val);
	preorder(root->left);
	preorder(root->right);
}
int main(){
	char date[11] = {'a','b','#','#','c','#','#'};
	TreeNode * root;
	int index = 0;
	createTree(root, date, 7,index);
	preorder(root);
	printf("\n");
	bool ok = isBalanced(root);
	if(ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}
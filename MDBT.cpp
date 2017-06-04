#include<cstdio>
#define MAX(a,b) (a) > (b) ? (a) : (b)
struct TreeNode{
	char val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(char v):val(v),left(NULL),right(NULL){}
};
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
int maxDepth(TreeNode * root){
	if(root == NULL) return 0;
	return MAX(maxDepth(root->left), maxDepth(root->right)) + 1;
}
int main(){
	//char date[] = "abd##ef###cg###\0";
	//char date[11] = {'a','b','#','#','c','#','#'};
	char date[100];
	scanf("%s",date);
	TreeNode * root;
	int index = 0;
	createTree(root, date, 15, index);
	int ans = maxDepth(root);
	printf("%d\n",ans);
}
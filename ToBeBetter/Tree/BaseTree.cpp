﻿#include "BaseTree.h"

BaseTree::BaseTree() :_root(nullptr), _height(0) {
	cout << "Base Tree construct" << endl;
}

BaseTree::~BaseTree() {
	//cout<<"Base Tree Destroy"<<endl;
}

BaseTree::BaseTree(std::initializer_list<int> list) {
	_root = nullptr;
	_height = 0;
	for (auto item : list) {
		TreeNode* node = new TreeNode(item);
		this->binaryTreeInsert(*node);
	}
}

BaseTree BaseTree::binaryTreeInsert(TreeNode& node) {
	TreeNode *cur = _root;

	if (_root == nullptr) {
		_root = &node;
	}
	else {
		cur = _root;
		while (cur) {
			if (node.val > cur->val) {
				if (!cur->right) {
					cur->right = &node;
					return *this;
				}
				cur = cur->right;
			}
			else {
				if (!cur->left) {
					cur->left = &node;
					return *this;
				}
				cur = cur->left;
			}
		}
	}

	return *this;
}

//中序遍历
void BaseTree::infixOrder(TreeNode* root) {
	TreeNode* cur = root;
	if (cur != nullptr) {
		infixOrder(cur->left);
		cout << cur->val << "->";
		infixOrder(cur->right);
	}
	else {
		cout << "null->";
	}
}
//前序遍历
void BaseTree::preOrder(TreeNode* root) {
	TreeNode* cur = root;
	if (cur != nullptr) {
		cout << cur->val << "->";
		infixOrder(cur->left);
		infixOrder(cur->right);
	}
}

//后续遍历
void BaseTree::postOrder(TreeNode* root) {
	TreeNode* cur = root;
	if (cur != nullptr) {
		infixOrder(cur->left);
		infixOrder(cur->right);
		cout << cur->val << "->";
	}
}

/*
94. 二叉树的中序遍历
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
	\
	 2
	/
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

vector<int> BaseTree::inorderTraversal(TreeNode* root) {

#if 1
	if (root != nullptr) {
		inorderTraversal(root->left);
		_infixRet.push_back(root->val);
		inorderTraversal(root->right);
	}
#endif
	return _infixRet;
}

/*
面试题68 - II. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 
 
说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。

思路1：打印路径：
例如：如图所示, 若p是节点5， q是节点4
root 到 p 的路径 3 5
root 到 q 的路径 3 5 2 4

思路2：递归

*/
TreeNode* BaseTree::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	//如果当前节点为空，直接返回
	//如果当前节点为左节点，退回到上一层
	//如果当前节点为右节点，退回到上一层
	if (root==nullptr || root == p || root == q)
		return root;

	auto left = lowestCommonAncestor(root->left, p, q);
	auto right = lowestCommonAncestor(root->right, p, q);

	//如果左边找不到任何值，说明已经到底了，需要从右边开始找
	if (!left)
		return right;
	if (!right)
		return left;
	
	return root;
}
/*
95. 不同的二叉搜索树 II
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3
*/

vector<TreeNode*> generate_trees(int start, int end) {
	vector<TreeNode*> ret;
	if (start > end)
		ret.push_back(nullptr);


	//因为序列已经有序，所以我们知道 start~i-1 这部分是左子树，i+1~end 是右子树
	for (int i = start; i <= end; i++) {
		vector<TreeNode*> ltree = generate_trees(start, i - 1);
		vector<TreeNode*> rtree = generate_trees(i + 1,end);

		//将左右子树拼接成树,用栈来理解存放 Ltree & Rtree的过程
		for (auto lt : ltree) 
		{
			for (auto rt : rtree) 
			{
				TreeNode* cur_tree = new TreeNode(i);
				cur_tree->left = lt;
				cur_tree->right = rt;
				ret.push_back(cur_tree);
			}
		}
	}

	return ret;
}
vector<TreeNode*> BaseTree::generateTrees(int n) {
	vector<TreeNode*> ret;

	if (n == 0)
		return ret;
	ret = generate_trees(1, n);
	return ret;
}

/*
109. Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],  //排序好的序列，相当于中序遍历的结果？

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

	  0
	 / \
   -3   9
   /   /
 -10  5

思路：二叉树的中序遍历，从链表中来构建二叉树
*/
BaseTree BaseTree::sortedListToBST(ListNode* head) {
	return *this;
}

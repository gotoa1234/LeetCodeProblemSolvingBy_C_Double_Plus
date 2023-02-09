#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution106
{
#pragma region Paste to execute 
	/*
	#include "Medium\0106.Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp"
	using namespace Solution106;
	using namespace std;

	int main()
	{
		Solution106::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal useClass;
		Solution106::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal::Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.buildTree(getTestModel.inorder, getTestModel.postorder);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.buildTree(getTestModel.inorder, getTestModel.postorder);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 從中序和後序遍歷構建二叉樹
	/// </summary>
	class Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal
	{
#pragma region Model
	public:
		//Definition for singly-linked list.
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
			TreeNode() : val(0), left(nullptr), right(nullptr) {}
			TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
			TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
		};
	public:
		class Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model
		{
		public:
			vector<int> inorder;
			vector<int> postorder;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：同105題但問題該成 後序 + 中序 找出唯一二元樹
		///                後序:由根節點開始，往左節點深入，只有當左節與右節點走過或者Null時，才記錄節點
		///       Runtime :  16 ms Beats 85 %
		///  Memory Usage :26.4 MB Beats 47.44 %
		/// </summary>
		unordered_map<int, int> _inOrderHashMap;
		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
			for (int index = 0; index < inorder.size(); index++)
				_inOrderHashMap[inorder[index]] = index;

			return FindRightNode(postorder, 0, postorder.size(), inorder,0, inorder.size());
		}
		TreeNode* FindRightNode(vector<int>& postorder, int pS, int pE,vector<int>& inorder,int iS, int iE)
		{
			if (pS == pE)
				return nullptr;
			TreeNode* currentNode = new TreeNode(postorder[pE - 1]);
			int findInorderEndIndex = _inOrderHashMap[currentNode->val];
			int splitLeftNum = findInorderEndIndex - iS;
			currentNode -> left = FindRightNode(postorder,                  pS, pS + splitLeftNum,
				                                  inorder,                  iS, findInorderEndIndex);
			currentNode ->right = FindRightNode(postorder,       pS + splitLeftNum , pE - 1,
                                    			  inorder, findInorderEndIndex + 1 ,     iE);
			return currentNode;
		}
		
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model GetTestData001(void)
		{
			Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model result;
			result.inorder = { 9,3,15,20,7 };
			result.postorder = { 9,15,7,20,3 };
			return result;//expect: [3,9,20,null,null,15,7]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model GetTestData002(void)
		{
			Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_Model result;
			result.inorder = { -1 };
			result.postorder = { -1 };
			return result;//expect: [-1]
		};
#pragma endregion TestData
	};
}

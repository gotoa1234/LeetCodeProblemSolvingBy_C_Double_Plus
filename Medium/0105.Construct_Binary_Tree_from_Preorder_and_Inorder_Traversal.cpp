#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution105
{
#pragma region Paste to execute 
	/*
	#include "Medium\0105.Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp"
	using namespace Solution105;
	using namespace std;

	int main()
	{
		Solution105::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal useClass;
		Solution105::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal::Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.buildTree(getTestModel.preorder, getTestModel.inorder);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.buildTree(getTestModel.preorder, getTestModel.inorder);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 從前序和中序遍歷構造二叉樹
	/// </summary>
	class Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal
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
		class Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model
		{
		public:
			vector<int> preorder;
			vector<int> inorder;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：前序:由根節點開始，往左節點深入，經過的節點紀錄
		///                中序:由根節點開始，往左節點深入，只有當左節點走過或者Null時，記錄此節點
		///                題目給定兩棵樹(前序+中序) 組成原始的樹長什麼樣
		///                利用HashTable紀錄前序對應到中序索引位置
		///                每次以當前的節點往下切分兩顆樹，利用HashTable可得知前序節點對應中序節點的位置
		/// 
		///       Runtime :  16 ms Beats 86.57 %
		///  Memory Usage :26.3 MB Beats 50.14 %
		/// </summary>
		unordered_map<int, int> _inOrderValueToIndexHashTable;
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			
			//1. 建立前序值對應中序位置
			for (int index = 0; index < inorder.size(); index++)
				_inOrderValueToIndexHashTable[inorder[index]] = index;
			
			return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
		}

		TreeNode* buildTreeHelper(
			vector<int>& preorder, int preorderStartIndex, int preorderEndIndex, 
		    vector<int>& inorder,  int inorderStartIndex,  int inorderEndIndex)
		{
			//2-1. 切割出的樹，前序索引到終點，可回傳nullptr
			if (preorderStartIndex == preorderEndIndex)
				return nullptr;

			//2-2. 建立此節點的結構
			int selfPreOrderNodeValue = preorder[preorderStartIndex];
			TreeNode* currentNode = new TreeNode(selfPreOrderNodeValue);

			//3-1. 找出該"前序值"對應"中序索引"，切割出樹的起迄
			int splitInOrderEndIndex = _inOrderValueToIndexHashTable[selfPreOrderNodeValue];
			int leftNum = splitInOrderEndIndex - inorderStartIndex;//切割出的中序還有幾格可進行(由左至右)
			//3-2. 左節點:           preorderStartIndex + 1 => 前序下一步的起點    preorderStartIndex + leftNum + 1 => 前序下一步的終點
			//                            inorderStartIndex => 中序下一步的終點                     inOrderEndIndex => 中序下一步的終點
			currentNode->left = buildTreeHelper(preorder, preorderStartIndex + 1, preorderStartIndex + leftNum + 1, 
				                                 inorder,      inorderStartIndex,             splitInOrderEndIndex);
			//3-3. 右節點:preorderStartIndex + leftNum + 1 => 前序下一步的起點   preorderEndIndex => 前序下一步終點
		    //                         inOrderEndIndex + 1 => 中序下一步的起點    inorderEndIndex => 中序下一步終點
			currentNode->right = buildTreeHelper(preorder, preorderStartIndex + leftNum + 1, preorderEndIndex, 
				                                  inorder,         splitInOrderEndIndex + 1, inorderEndIndex);
			//4. 回傳自己的節點，且下面的節點皆已建構完成
			return currentNode;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model GetTestData001(void)
		{
			Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model result;			
			result.preorder = { 3, 9, 20, 15, 7 };
			result.inorder = { 9, 3, 15, 20, 7 };
			return result;//expect: [3, 9, 20, null, null, 15, 7]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model GetTestData002(void)
		{
			Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model result;
			result.preorder = {-1};
			result.inorder = {-1};
			return result;//expect: [-1]
		};
#pragma endregion TestData
	};
}

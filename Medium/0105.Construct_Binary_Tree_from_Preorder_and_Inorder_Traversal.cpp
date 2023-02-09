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
	/// �q�e�ǩM���ǹM���c�y�G�e��
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
		///          ����G�e��:�Ѯڸ`�I�}�l�A�����`�I�`�J�A�g�L���`�I����
		///                ����:�Ѯڸ`�I�}�l�A�����`�I�`�J�A�u�����`�I���L�Ϊ�Null�ɡA�O�����`�I
		///                �D�ص��w��ʾ�(�e��+����) �զ���l����������
		///                �Q��HashTable�����e�ǹ����줤�ǯ��ަ�m
		///                �C���H��e���`�I���U����������A�Q��HashTable�i�o���e�Ǹ`�I�������Ǹ`�I����m
		/// 
		///       Runtime :  16 ms Beats 86.57 %
		///  Memory Usage :26.3 MB Beats 50.14 %
		/// </summary>
		unordered_map<int, int> _inOrderValueToIndexHashTable;
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			
			//1. �إ߫e�ǭȹ������Ǧ�m
			for (int index = 0; index < inorder.size(); index++)
				_inOrderValueToIndexHashTable[inorder[index]] = index;
			
			return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
		}

		TreeNode* buildTreeHelper(
			vector<int>& preorder, int preorderStartIndex, int preorderEndIndex, 
		    vector<int>& inorder,  int inorderStartIndex,  int inorderEndIndex)
		{
			//2-1. ���ΥX����A�e�ǯ��ި���I�A�i�^��nullptr
			if (preorderStartIndex == preorderEndIndex)
				return nullptr;

			//2-2. �إߦ��`�I�����c
			int selfPreOrderNodeValue = preorder[preorderStartIndex];
			TreeNode* currentNode = new TreeNode(selfPreOrderNodeValue);

			//3-1. ��X��"�e�ǭ�"����"���ǯ���"�A���ΥX�𪺰_��
			int splitInOrderEndIndex = _inOrderValueToIndexHashTable[selfPreOrderNodeValue];
			int leftNum = splitInOrderEndIndex - inorderStartIndex;//���ΥX�������٦��X��i�i��(�ѥ��ܥk)
			//3-2. ���`�I:           preorderStartIndex + 1 => �e�ǤU�@�B���_�I    preorderStartIndex + leftNum + 1 => �e�ǤU�@�B�����I
			//                            inorderStartIndex => ���ǤU�@�B�����I                     inOrderEndIndex => ���ǤU�@�B�����I
			currentNode->left = buildTreeHelper(preorder, preorderStartIndex + 1, preorderStartIndex + leftNum + 1, 
				                                 inorder,      inorderStartIndex,             splitInOrderEndIndex);
			//3-3. �k�`�I:preorderStartIndex + leftNum + 1 => �e�ǤU�@�B���_�I   preorderEndIndex => �e�ǤU�@�B���I
		    //                         inOrderEndIndex + 1 => ���ǤU�@�B���_�I    inorderEndIndex => ���ǤU�@�B���I
			currentNode->right = buildTreeHelper(preorder, preorderStartIndex + leftNum + 1, preorderEndIndex, 
				                                  inorder,         splitInOrderEndIndex + 1, inorderEndIndex);
			//4. �^�Ǧۤv���`�I�A�B�U�����`�I�Ҥw�غc����
			return currentNode;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model GetTestData001(void)
		{
			Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal_Model result;			
			result.preorder = { 3, 9, 20, 15, 7 };
			result.inorder = { 9, 3, 15, 20, 7 };
			return result;//expect: [3, 9, 20, null, null, 15, 7]
		};

		/// <summary>
		/// ���ո��2
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

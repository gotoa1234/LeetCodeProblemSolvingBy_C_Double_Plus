#include <iostream>
#include <vector>
using namespace std;

namespace Solution108
{
#pragma region Paste to execute 
	/*
	#include "Easy\0108.Convert_Sorted_Array_to_Binary_Search_Tree.cpp"
	using namespace Solution108;
	using namespace std;

	int main()
	{
		Solution108::Convert_Sorted_Array_to_Binary_Search_Tree useClass;
		Solution108::Convert_Sorted_Array_to_Binary_Search_Tree::Convert_Sorted_Array_to_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.sortedArrayToBST(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.sortedArrayToBST(getTestModel.nums);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �N�ƧǼƲ��ഫ���G�e�j����
	/// </summary>
	class Convert_Sorted_Array_to_Binary_Search_Tree
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
		class Convert_Sorted_Array_to_Binary_Search_Tree_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�Q�ΤG���j�M�k�A���������`�I���ڸ`�I�A���ɷ|���Φ����B�k������A
		///                �M�᭫�ƧQ�λ��j�~��i��G�����ΡA�Y���Ϋ�L�k��ȡA����nullptr
		///       Runtime :   7 ms Beats 98.42 %
		///  Memory Usage :21.4 MB Beats 81.81 %
		/// </summary>
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			return sortedArrayToBST(nums, 0, nums.size() - 1);
		}

		TreeNode* sortedArrayToBST(vector<int>& nums, int startIndex, int endIndex) 
		{
			//Ĳ�onull����O�_�I�j����I�A�b�G���j�M�����i���j�� (EX:1/2��)
			if (startIndex > endIndex) 
				return nullptr;
			//1. �G���j�M����
			int mid = startIndex + (endIndex- startIndex) / 2;
			//2-1. mid �O�ۤv�T�w�F
			TreeNode* root = new TreeNode(nums[mid]);
			//2-2. ���`�I�~��]���b��
			root->left = sortedArrayToBST(nums, startIndex, mid - 1); 
			//2-3. �k�`�I�~��]�k�b��
			root->right = sortedArrayToBST(nums, mid + 1, endIndex);
			return root;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Convert_Sorted_Array_to_Binary_Search_Tree_Model GetTestData001(void)
		{
			Convert_Sorted_Array_to_Binary_Search_Tree_Model result;
			result.nums = { -10, -3, 0, 5, 9 };
			return result;//expect:  [0, -3, 9, -10, null, 5]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Convert_Sorted_Array_to_Binary_Search_Tree_Model GetTestData002(void)
		{
			Convert_Sorted_Array_to_Binary_Search_Tree_Model result;
			result.nums = { 1, 3 };
			return result;//expect: [3, 1]
		};
#pragma endregion TestData
	};
}

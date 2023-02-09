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
	/// 將排序數組轉換為二叉搜索樹
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
		///          思路：利用二分搜尋法，取中間的節點做根節點，此時會分割成左、右兩顆樹，
		///                然後重複利用遞迴繼續進行二分切割，若切割後無法賦值，視為nullptr
		///       Runtime :   7 ms Beats 98.42 %
		///  Memory Usage :21.4 MB Beats 81.81 %
		/// </summary>
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			return sortedArrayToBST(nums, 0, nums.size() - 1);
		}

		TreeNode* sortedArrayToBST(vector<int>& nums, int startIndex, int endIndex) 
		{
			//觸發null條件是起點大於終點，在二分搜尋中不可切隔時 (EX:1/2時)
			if (startIndex > endIndex) 
				return nullptr;
			//1. 二分搜尋切割
			int mid = startIndex + (endIndex- startIndex) / 2;
			//2-1. mid 是自己確定了
			TreeNode* root = new TreeNode(nums[mid]);
			//2-2. 左節點繼續跑左半部
			root->left = sortedArrayToBST(nums, startIndex, mid - 1); 
			//2-3. 右節點繼續跑右半部
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

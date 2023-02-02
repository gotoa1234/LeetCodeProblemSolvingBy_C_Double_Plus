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
		///          ����G
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			return {};
		}


#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Convert_Sorted_Array_to_Binary_Search_Tree_Model GetTestData001(void)
		{
			Convert_Sorted_Array_to_Binary_Search_Tree_Model result;
			result.nums = { -10, -3, 0, 5, 9 };
			return result;//expect:  [0, -3, 9, -10, null, 5]
		};

		/// <summary>
		/// ���ո��2
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

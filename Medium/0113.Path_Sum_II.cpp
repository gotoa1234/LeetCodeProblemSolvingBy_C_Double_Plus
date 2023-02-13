#include <iostream>
#include <vector>
using namespace std;

namespace Solution113
{
#pragma region Paste to execute 
	/*
	#include "Medium\0113.Path_Sum.cpp"
	using namespace Solution113;
	using namespace std;

	int main()
	{
		Solution113::Path_Sum useClass;
		Solution113::Path_Sum::Path_Sum_II_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.pathSum(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.pathSum(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 路徑加總2
	/// </summary>
	class Path_Sum
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
		class Path_Sum_II_Model
		{
		public:
			TreeNode* root;
			int targetSum;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
			return {};
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Path_Sum_II_Model GetTestData001(void)
		{
			Path_Sum_II_Model result;
			result.targetSum = 22;
			result.root = new TreeNode(5);
			result.root->left = new TreeNode(4);
			result.root->right = new TreeNode(8);

			result.root->left->left = new TreeNode(11);
			//result.root->left->right = new TreeNode();
			result.root->left->left->left = new TreeNode(7);
			result.root->left->left->right = new TreeNode(2);

			result.root->right->left = new TreeNode(13);
			result.root->right->right = new TreeNode(4);

			result.root->right->left->left = new TreeNode(1);
			return result;//expect:  [[5,4,11,2],[5,8,4,5]]			
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Path_Sum_II_Model GetTestData002(void)
		{
			Path_Sum_II_Model result;
			result.root = new TreeNode(1);
			result.root->left = new TreeNode(2);
			result.root->right = new TreeNode(3);
			result.targetSum = 5;
			return result;//expect: []
		};


		/// <summary>
		/// 測試資料3
		/// </summary>   
		Path_Sum_II_Model GetTestData003(void)
		{
			Path_Sum_II_Model result;
			result.targetSum = 0;
			return result;//expect: []
		};

#pragma endregion TestData
	};
}

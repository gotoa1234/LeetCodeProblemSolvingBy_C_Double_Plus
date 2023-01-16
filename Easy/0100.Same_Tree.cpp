#include <iostream>
#include <vector>
using namespace std;

namespace Solution100
{
#pragma region Paste to execute 
	/*
	#include "Easy/0100.Recover_Binary_Search_Tree.cpp"
	using namespace Solution100;
	using namespace std;

	Solution100::Recover_Binary_Search_Tree useClass;
	Solution100::Recover_Binary_Search_Tree::Recover_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.inorderTraversal(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.inorderTraversal(getTestModel.root);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.inorderTraversal(getTestModel.root);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 同一棵樹
	/// </summary>
	class Recover_Binary_Search_Tree
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
		class Recover_Binary_Search_Tree_Model
		{
		public:
			TreeNode* p;
			TreeNode* q;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路： 
		///       Runtime: 
		///  Memory Usage :
		/// </summary>
	    bool isSameTree(TreeNode* p, TreeNode* q) {
         return {};
        }
	
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Recover_Binary_Search_Tree_Model GetTestData001(void)
		{
			Recover_Binary_Search_Tree_Model result;
			vector<int> l1Vectors{};
            l1Vectors = { 1,2,3};
			result.p = new TreeNode(1);
			result.p->left = new TreeNode(2);
			result.p->right = new TreeNode(3);
			return result;//expect: [1,3,2]
			vector<int> l2Vectors{};
            l2Vectors = { 1,2,3};
			result.q = new TreeNode(1);
			result.q->left = new TreeNode(2);
			result.q->right = new TreeNode(3);
            return result;//expect: true
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Recover_Binary_Search_Tree_Model GetTestData002(void)
		{
			Recover_Binary_Search_Tree_Model result;
			vector<int> l1Vectors{};
            l1Vectors = { 1,2};
			result.p = new TreeNode(1);
			result.p->left = new TreeNode(2);
			vector<int> l2Vectors{};
            l2Vectors = { 1,0,2};
			result.q = new TreeNode(1);
			result.q->left = new TreeNode(0);
			result.q->right = new TreeNode(2);
            return result;//expect: false
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Recover_Binary_Search_Tree_Model GetTestData003(void)
		{
			Recover_Binary_Search_Tree_Model result;
			vector<int> l1Vectors{};
            l1Vectors = { 1,2,1};
			result.p = new TreeNode(1);
			result.p->left = new TreeNode(2);
			result.p->right = new TreeNode(1);
			vector<int> l2Vectors{};
            l2Vectors = { 1,1,2};
			result.q = new TreeNode(1);
			result.q->left = new TreeNode(1);
			result.q->right = new TreeNode(2);
            return result;//expect: false
		};
	 private:
#pragma endregion TestData
	};
}

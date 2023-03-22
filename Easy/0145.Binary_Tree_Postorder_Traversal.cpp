#include <iostream>
#include <vector>
using namespace std;

namespace Solution145
{
#pragma region Paste to execute 
	/*
	#include "Easy\0145.Binary_Tree_Postorder_Traversal.cpp"
	using namespace Solution145;
	using namespace std;


	int main()
	{
		Solution145::Binary_Tree_Postorder_Traversal useClass;
		Solution145::Binary_Tree_Postorder_Traversal::Binary_Tree_Postorder_Traversal_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.preorderTraversal(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.preorderTraversal(getTestModel.root);

		getTestModel = useClass.GetTestData003();
		auto result3 = useClass.preorderTraversal(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// ¤G¤e¾ð«e§Ç¹M¾ú
	/// </summary>
	class Binary_Tree_Postorder_Traversal
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
		class Binary_Tree_Postorder_Traversal_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          «ä¸ô¡G
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		vector<int> preorderTraversal(TreeNode* root) {
			return{};
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Binary_Tree_Postorder_Traversal_Model GetTestData001(void)
		{
			Binary_Tree_Postorder_Traversal_Model result;
			TreeNode* root = new TreeNode(1);
			root->left = nullptr;
			root->right = new TreeNode(2);
			root->right->left = new TreeNode(3);
			result.root = root;
			return result;//expect: [3,2,1]
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Binary_Tree_Postorder_Traversal_Model GetTestData002(void)
		{
			Binary_Tree_Postorder_Traversal_Model result;
			TreeNode* root = nullptr;
			result.root = root;
			return result;//expect: []
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Binary_Tree_Postorder_Traversal_Model GetTestData003(void)
		{
			Binary_Tree_Postorder_Traversal_Model result;
			TreeNode* root = new TreeNode(1);
			result.root = root;
			return result;//expect: [1]
		};
	private:
#pragma endregion TestData
	};
}

#include <iostream>
#include <vector>
using namespace std;

namespace Solution94
{
#pragma region Paste to execute 
	/*
	#include "Easy/0094.Binary_Tree_Inorder_Traversal.cpp"
	using namespace Solution94;
	using namespace std;

	int main()
	{
	Solution94::Recover_Binary_Search_Tree useClass;
	Solution94::Recover_Binary_Search_Tree::Recover_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.inorderTraversal(getTestModel.root);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.inorderTraversal(getTestModel.root);

	getTestModel = useClass.GetTestData003();
	auto result3 = useClass.inorderTraversal(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �G�e�𤤧ǹM��
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
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G ���ǳW�h: �� -> �� -> �k
		///       Runtime :   0 ms Beats   100 %
		///  Memory Usage : 8.2 MB Beats 91.99 %
		/// </summary>
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> result;
			//1. �N�`�I��J
			FindMiidleSearch(root, result);
			return result;
        }

		void FindMiidleSearch(TreeNode* node, vector<int>& result)
		{
		    //3. �Y�]�i���`�I��null�ɫh�����U��
			if (node != nullptr)
			{
			    //2-1 ����`�I���]
				FindMiidleSearch(node->left, result);
				result.push_back(node->val);
				//2-2 �A�]�k��`�I
				FindMiidleSearch(node->right, result);
			}
		}
	
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Recover_Binary_Search_Tree_Model GetTestData001(void)
		{
			Recover_Binary_Search_Tree_Model result;
			result.root = new TreeNode(1);
            //result.root->left = new TreeNode(0);
			result.root->right = new TreeNode(2);
			result.root->right->left = new TreeNode(3);
            return result;//expect: [1,3,2]
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Recover_Binary_Search_Tree_Model GetTestData002(void)
		{
			Recover_Binary_Search_Tree_Model result{};
            return result;//expect:  [ ]
		};

		/// <summary>
		/// ���ո��3
		/// </summary>   
		Recover_Binary_Search_Tree_Model GetTestData003(void)
		{
			Recover_Binary_Search_Tree_Model result;
			vector<int> l1Vectors{};
			result.root = new TreeNode(1);
            return result;//expect:  [1 ]
		};
	 private:

#pragma endregion TestData
	};
}
#include <iostream>
#include <vector>
using namespace std;

namespace Solution104
{
#pragma region Paste to execute 
	/*
	#include "Easy\0104.Maximum_Depth_of_Binary_Tree.cpp"
	using namespace Solution104;
	using namespace std;


	int main()
	{
		Solution104::Maximum_Depth_of_Binary_Tree useClass;
		Solution104::Maximum_Depth_of_Binary_Tree::Maximum_Depth_of_Binary_Tree_Model getTestModel = useClass.GetTestData001();
		auto result1 = useClass.maxDepth(getTestModel.root);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.maxDepth(getTestModel.root);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �G�e�𪺳̤j�`��
	/// </summary>
	class Maximum_Depth_of_Binary_Tree
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
		class Maximum_Depth_of_Binary_Tree_Model
		{
		public:
			TreeNode* root;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          ����G�Q�λ��j�N���`�I�P�k�`�I�`�ר��^�A�̤j�����Ӭ��̪��`��
		///       Runtime :   8 ms Beats 78.51 %
		///  Memory Usage :18.8 MB Beats 92.42 %
		/// </summary>
		int maxDepth(TreeNode* root) {
			if (root == nullptr)
				return 0;
			int leftNodeDepth = maxDepth(root->left);
			int rightNodeDepth = maxDepth(root->right);
			//����+1 �]���ڸ`�I���1�h
			return max(leftNodeDepth, rightNodeDepth) + 1;
		}

#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// ���ո��1
		/// </summary>        
		Maximum_Depth_of_Binary_Tree_Model GetTestData001(void)
		{
			Maximum_Depth_of_Binary_Tree_Model result;
			TreeNode* root = new TreeNode(3);
			root->left = new TreeNode(9);
			root->right = new TreeNode(20);

			/*root->left->left = new TreeNode();
			root->left->right = new TreeNode();*/

			root->right->left = new TreeNode(15);
			root->right->right = new TreeNode(7);
			result.root = root;
			return result;//expect: 3			
		};

		/// <summary>
		/// ���ո��2
		/// </summary>   
		Maximum_Depth_of_Binary_Tree_Model GetTestData002(void)
		{
			Maximum_Depth_of_Binary_Tree_Model result;
			TreeNode* root = new TreeNode(1);
			/*root->left = new TreeNode();*/
			root->right = new TreeNode(2);
			result.root = root;
			return result;//expect: 2
		};
	private:
#pragma endregion TestData
	};
}

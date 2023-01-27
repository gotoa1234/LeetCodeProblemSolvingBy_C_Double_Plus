#include <iostream>
#include <vector>
using namespace std;

namespace Solution100
{
#pragma region Paste to execute 
	/*
    #include "Easy\0100.Same_Tree.cpp"
    using namespace Solution100;
    using namespace std;
    
    
    int main()
    {
    	Solution100::Recover_Binary_Search_Tree useClass;
    	Solution100::Recover_Binary_Search_Tree::Recover_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
    	auto result1 = useClass.isSameTree(getTestModel.p, getTestModel.q);
    
    	getTestModel = useClass.GetTestData002();
    	auto result2 = useClass.isSameTree(getTestModel.p, getTestModel.q);
    
    	getTestModel = useClass.GetTestData003();
    	auto result3 = useClass.isSameTree(getTestModel.p, getTestModel.q);
    
    }
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// �P�@�ʾ�
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
		///          ����G�Q�λ��j����Ӹ`�I���c�P�ȬO�_�ۦP�A���ۦP��^false
		///       Runtime:  0 ms Beats 100 %
		///  Memory Usage :10 MB Beats 51 %
		/// </summary>
	    bool isSameTree(TreeNode* p, TreeNode* q) 
		{
			//1. �`�I���c�ۦP��^true
			if (p == NULL && q == NULL)
				return true;
			//2. �`�I���c���ۦP��^false
			if ((p != NULL && q == NULL) ||
				(p == NULL && q != NULL)
				)
				return false;
			//3. �ˬd�U�@�`�I���c/�ȬO�_�ۦP
			bool isLeftNodeSame = isSameTree(p->left, q->left);
			bool isRightNodeSame = isSameTree(p->right, q->right);
			//4. �ۦP��^true
			if (isLeftNodeSame && isRightNodeSame && p->val == q->val)
				return true;
			//5. ���ۦP��^false
			return false;
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
		/// ���ո��2
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
		/// ���ո��3
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

#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution173
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0173.Binary_Search_Tree_Iterator.cpp"
    using namespace Solution173;

    int main()
    {
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 
    /// </summary>
    class BSTIterator
    {
#pragma region Model
    public:
        //Definition for singly-linked list.
        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };
    public:
        class Binary_Tree_Right_Side_View_Model
        {
        public:
            TreeNode* root;
            TreeNode* p;
            TreeNode* q;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路：中序排序依序放進到Vector中，然後用一個索引紀錄當前next的位置。
        ///      Runtime：  28 ms Beats 82.96 %
        /// Memory Usage：25.4 MB Beats 10.51 %
        /// </summary>
        /// <returns></returns>
    public:
        vector<TreeNode*> _inorder;
        int index{};
        BSTIterator(TreeNode* root) {
            index = 0;
            traversal(root);
        }
        
        //2. 每次取值index +1
        int next() {
            index++;
            return _inorder[index - 1]->val;
        }

        //3. 判斷是否index 走到底，沒有表示還有next (hasNext)
		bool hasNext() {
			return index < _inorder.size()
		         ? true
		         : false;
		}

        //1. 先建立中序排序的資料
        void traversal(TreeNode* root) {
            if (root == NULL) {
                return;
            }
            traversal(root->left);
            _inorder.push_back(root);
            traversal(root->right);
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        void Test01()
        {
/*
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
*/
        
        
        }
#pragma endregion TestData
    };
}
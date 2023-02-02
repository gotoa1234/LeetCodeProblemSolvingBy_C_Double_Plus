#include <iostream>
#include <vector>
using namespace std;

namespace Solution109
{
#pragma region Paste to execute 
    /*
    #include "Medium\0109.Convert_Sorted_List_to_Binary_Search_Tree.cpp"
    using namespace Solution109;
    using namespace std;

    Solution109::Convert_Sorted_List_to_Binary_Search_Tree useClass;
    Solution109::Convert_Sorted_List_to_Binary_Search_Tree::Convert_Sorted_List_to_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
    vector<vector<int>> result = useClass.sortedListToBST(getTestModel.head);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 將排序列表轉換為二叉搜索樹
    /// </summary>
    class Convert_Sorted_List_to_Binary_Search_Tree
    {
#pragma region Model
    public:
        //Definition for singly-linked list.
        struct ListNode {
            int val;
            ListNode* next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode* next) : val(x), next(next) {}
        };
        struct TreeNode {
            int val;
            TreeNode* left;
            TreeNode* right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        };
    public:
        class Convert_Sorted_List_to_Binary_Search_Tree_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路  :
        ///      Runtime : 
        /// Memory Usage : 

        TreeNode* sortedListToBST(ListNode* head) {
            return {};
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Convert_Sorted_List_to_Binary_Search_Tree_Model GetTestData001(void)
        {
            Convert_Sorted_List_to_Binary_Search_Tree_Model result;
            result.head = new ListNode(-10);
            result.head->next = new ListNode(-3);
            result.head->next->next = new ListNode(0);
            result.head->next->next->next = new ListNode(5);
            result.head->next->next->next->next = new ListNode(9);
            return result;//Expect : [0, -3, 9, -10, null, 5]
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Convert_Sorted_List_to_Binary_Search_Tree_Model GetTestData002(void)
        {
            Convert_Sorted_List_to_Binary_Search_Tree_Model result;
            return result;//Expect : [ ]
        };
    private:
        TreeNode* ConstructNodes(vector<int>& inputDatas)
        {
            /*   *int val;
               *TreeNode* left;
               *TreeNode* right;
               *TreeNode() : val(0), left(nullptr), right(nullptr) {}
               *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
               *TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}*/
            TreeNode* nodeHeads = NULL;
            TreeNode* treeLevelHeads = NULL;
            bool switchLevel = true;
            for (auto& myItem : inputDatas)
            {
                if (nodeHeads == NULL)
                {
                    nodeHeads = new TreeNode(myItem);
                    treeLevelHeads = new TreeNode(myItem);
                    continue;
                }

                if (myItem == NULL && switchLevel)
                {

                }


                if (myItem == NULL)
                {
                    continue;
                }
                else
                {
                    TreeNode* newItem = new TreeNode(myItem);
                }
            }
            return nodeHeads;
        };
#pragma endregion TestData
    };
}
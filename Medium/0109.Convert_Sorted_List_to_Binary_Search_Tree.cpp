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
    
    int main()
    {
        Solution109::Convert_Sorted_List_to_Binary_Search_Tree useClass;
        Solution109::Convert_Sorted_List_to_Binary_Search_Tree::Convert_Sorted_List_to_Binary_Search_Tree_Model getTestModel = useClass.GetTestData001();
        Convert_Sorted_List_to_Binary_Search_Tree::TreeNode* result = useClass.sortedListToBST(getTestModel.head);
    
    }
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
        ///         思路 :同108題，但題目的輸入參數變為鏈結串鍊，所以要利用雙指標的方式，找出二分搜尋法的中間值
        ///      Runtime :   23 ms Beats 90.28 %
        /// Memory Usage : 28.4 MB Beats 69.49 %

        TreeNode* sortedListToBST(ListNode* head) {
            //1-1. 檢核當前節點是否為nullptr
            if (head == nullptr)
                return nullptr;
            //1-2. 檢核當前節點下一點是否為nullptr，為null此節點的值需要直接回傳
            if (head->next == nullptr)
                return new TreeNode(head->val);
            //2-1. 進行二分搜尋法 
            ListNode* midPointer = head;//每次走1步
            ListNode* endPointer = head;//每次走2步，當走到底時，此時midPointer為中間值
            ListNode* lastPointer = midPointer;//當endPointer走到底時，此時lastPointer會為midPointer前一值
            while (endPointer->next && endPointer->next->next)
            {
                lastPointer = midPointer;
                midPointer = midPointer->next;
                endPointer = endPointer->next->next;
            }
            //2-2. endPointer為了當右樹的起點
            endPointer = midPointer->next;
            //2-3. lastPointer必須設為null，讓左子樹走到midPointer前一步(作為左子樹終點)
            lastPointer->next = NULL;
            //3-1. 中間樹 + 左樹 + 右樹 建立
            TreeNode* cur = new TreeNode(midPointer->val);
            if (head != midPointer)
                cur->left = sortedListToBST(head);
            cur->right = sortedListToBST(endPointer);
            return cur;
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
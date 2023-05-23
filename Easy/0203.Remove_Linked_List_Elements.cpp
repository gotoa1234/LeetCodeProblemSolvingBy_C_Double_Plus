#include <iostream>
#include <vector>
using namespace std;

namespace Solution203
{
#pragma region Paste to execute 
    /*
    #include "0203.Remove_Linked_List_Elements.cpp"
    using namespace Solution203;
    using namespace std;

    Solution203::Remove_Linked_List_Elements useClass;
    Solution203::Remove_Linked_List_Elements::Remove_Linked_List_Elements_Model getTestModel = useClass.GetTestData001();
    auto result = useClass.invertTree(getTestModel.root);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 移除鏈結串列元素
    /// </summary>
    class Remove_Linked_List_Elements
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
    public:
        class Remove_Linked_List_Elements_Model
        {
        public:
            ListNode* head;
            int val;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：遍歷鏈結串鍊，當遇到符合的節點就跳過，最後重組出來的就是捨去val的串鍊
        ///      Runtime :   23 ms Beats 75.46 %
        /// Memory Usage : 14.8 MB Beats 95.33 %
        ListNode* removeElements(ListNode* head, int val) {
            ListNode* dummy= new ListNode();
            ListNode* moveNode = head;
            ListNode* lastNode = dummy;
            dummy->next = head;
            while (moveNode != nullptr)
            {
                if (moveNode->val == val)
                {
                    lastNode->next = moveNode->next;
                }
                else
                {
                    lastNode = moveNode;
                }
                moveNode = moveNode->next;
            }
            return dummy->next;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Remove_Linked_List_Elements_Model GetTestData001(void)
        {
            Remove_Linked_List_Elements_Model result;
            vector<int> l1Vectors = { 1,2,6,3,4,5,6 };
            result.head = ConstructNodes(l1Vectors);
            result.val = 6;
            return result;//[1,2,3,4,5]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Remove_Linked_List_Elements_Model GetTestData002(void)
        {
            Remove_Linked_List_Elements_Model result;
            vector<int> l1Vectors = {};
            result.head = ConstructNodes(l1Vectors);
            result.val = 1;
            return result;//[]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Remove_Linked_List_Elements_Model GetTestData003(void)
        {
            Remove_Linked_List_Elements_Model result;
            vector<int> l1Vectors = { 7,7,7,7 };
            result.head = ConstructNodes(l1Vectors);
            result.val = 7;
            return result;//[]
        };

    private:
        ListNode* ConstructNodes(vector<int>& inputDatas)
        {
            ListNode* nodeHeads = NULL;
            ListNode* moveNode = NULL;
            for (auto& myItem : inputDatas)
            {
                ListNode* newItem = new ListNode(myItem);
                if (nodeHeads == NULL)
                {
                    nodeHeads = newItem;
                    moveNode = nodeHeads;
                    continue;
                }
                moveNode->next = newItem;
                moveNode = newItem;
            }
            return nodeHeads;
        };
#pragma endregion TestData
    };
}
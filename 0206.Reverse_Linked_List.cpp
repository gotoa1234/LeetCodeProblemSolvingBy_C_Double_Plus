#include <iostream>
#include <vector>
using namespace std;

namespace Solution206
{
#pragma region Paste to execute 
    /*
    #include "0206.Reverse_Linked_List.cpp"
    using namespace Solution206;
    using namespace std;

    Solution206::Reverse_Linked_List useClass;
    Solution206::Reverse_Linked_List::Reverse_Linked_List_Model getTestModel = useClass.GetTestData001();
    Solution206::Reverse_Linked_List::ListNode* result = useClass.addTwoNumbers(getTestModel.l1, getTestModel.l2);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 逆轉鏈結串鍊數字
    /// </summary>
    class Reverse_Linked_List
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
        class Reverse_Linked_List_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ： 在遍歷過程中，用指標將方向逆轉
        ///      Runtime :   5 ms, faster than 87.75% of C++ online submissions for Reverse Linked List.
        /// Memory Usage : 8.3 MB,   less than 79.67% of C++ online submissions for Reverse Linked List.
        
        ListNode* reverseList(ListNode* head) {
            
            ListNode* leftNode = NULL;
            ListNode* currentNode = head;
            ListNode* rightNode;

            while (currentNode != NULL)
            {
                rightNode = currentNode->next;
                currentNode->next = leftNode;
                leftNode = currentNode;
                currentNode = rightNode;
            }
            return leftNode;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Reverse_Linked_List_Model GetTestData001(void)
        {
            Reverse_Linked_List_Model result;
            vector<int> l1Vectors = { 1, 2, 3, 4, 5 };
            result.head = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Reverse_Linked_List_Model GetTestData002(void)
        {
            Reverse_Linked_List_Model result;
            vector<int> l1Vectors = { 1, 2};
            result.head = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Reverse_Linked_List_Model GetTestData003(void)
        {
            Reverse_Linked_List_Model result;
            vector<int> l1Vectors{};
            result.head = ConstructNodes(l1Vectors);
            return result;
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
#include <iostream>
#include <vector>
using namespace std;

namespace Solution141
{
#pragma region Paste to execute 
    /*
    #include "Easy\0141.Linked_List_Cycle.cpp"
    using namespace Solution141;
    using namespace std;

    Solution141::Linked_List_Cycle useClass;
    Solution141::Linked_List_Cycle::Linked_List_Cycle_Model getTestModel = useClass.GetTestData001();
    bool result = useClass.hasCycle(getTestModel.head);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 鏈結串列中是否存在循環
    /// </summary>
    class Linked_List_Cycle
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
        class Linked_List_Cycle_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：2個節點，一個走1步 ，另一個走2步，走2步的兩個節點若記憶體相等時必為循環，有遇到Null必為非循環
        ///      Runtime : 8 ms, faster than 94.27% of C++ online submissions for Linked List Cycle.
        /// Memory Usage : 8 MB,   less than 81.43% of C++ online submissions for Linked List Cycle.

        bool hasCycle(ListNode* head) {
            if (head == NULL)
                return false;
            
            ListNode* oneStepNode = head;
            ListNode* twoStepNode = head;

			while (twoStepNode != NULL && twoStepNode->next != NULL)
            {
                oneStepNode = oneStepNode->next;
                if (twoStepNode->next)
                    twoStepNode = twoStepNode->next->next;
                else 
                    break;
                if (oneStepNode == twoStepNode)
                    return true;
            }
            return false;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Linked_List_Cycle_Model GetTestData001(void)
        {
            Linked_List_Cycle_Model result;
            vector<int> l1Vectors = { 3, 2, 0, -4 };
            result.head = ConstructNodes(l1Vectors);
            //題目第[3] -> [1] 個節點作為循環
            result.head->next->next->next->next = result.head->next;
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Linked_List_Cycle_Model GetTestData002(void)
        {
            Linked_List_Cycle_Model result;
            vector<int> l1Vectors = { 1, 2 };
            result.head = ConstructNodes(l1Vectors);
            //題目第[1] -> [0] 個節點作為循環
            result.head->next->next = result.head;
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Linked_List_Cycle_Model GetTestData003(void)
        {
            Linked_List_Cycle_Model result;
            vector<int> l1Vectors{ 1 };
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
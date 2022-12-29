#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution142
{
#pragma region Paste to execute 
    /*
    #include "0142.Linked_List_Cycle_II.cpp"
    using namespace Solution142;
    using namespace std;

    Solution142::Linked_List_Cycle_II useClass;
    Solution142::Linked_List_Cycle_II::Linked_List_Cycle_II_Model getTestModel = useClass.GetTestData001();
    Solution142::Linked_List_Cycle_II::ListNode* result = useClass.detectCycle(getTestModel.head);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 循環節點，找出循環開始的節點
    /// </summary>
    class Linked_List_Cycle_II
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
        class Linked_List_Cycle_II_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ： 利用141. 題的方法找出是否回圈，然後利用走1步的節點 與 head 節點一起往前，彼此碰到的必定為起始點
        ///      Runtime :   6 ms, faster than 94.92% of C++ online submissions for Linked List Cycle II.
        /// Memory Usage : 7.4 MB,   less than 99.09% of C++ online submissions for Linked List Cycle II.

        ListNode* detectCycle(ListNode* head) {
            
            ListNode* oneStepNode = head;
            ListNode* twoStepNode = head;
            ListNode* entry = head;
            
            while (twoStepNode != NULL && twoStepNode->next != NULL)
            {
                oneStepNode = oneStepNode->next;
                if (twoStepNode->next == NULL)
                    break;
                else
                    twoStepNode = twoStepNode->next->next;

                if (oneStepNode == twoStepNode)
                {
                    //利用1步節點 + 頭節點 彼此往前直到交會，就是起點
                    while (oneStepNode != entry) 
                    {
                        oneStepNode = oneStepNode->next; 
                        entry = entry->next;
                    }
                    return entry;
                }       
            }
            return NULL;
        }

#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Linked_List_Cycle_II_Model GetTestData001(void)
        {
            Linked_List_Cycle_II_Model result;
            vector<int> l1Vectors = {3, 2, 0, -4};
            result.head = ConstructNodes(l1Vectors);
            //題目第[3] -> [1] 個節點作為循環
            result.head->next->next->next->next = result.head->next;
            return result;
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Linked_List_Cycle_II_Model GetTestData002(void)
        {
            Linked_List_Cycle_II_Model result;
            vector<int> l1Vectors = { 1, 2 };
            result.head = ConstructNodes(l1Vectors);
            //題目第[1] -> [0] 個節點作為循環
            result.head->next->next = result.head;
            return result;
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Linked_List_Cycle_II_Model GetTestData003(void)
        {
            Linked_List_Cycle_II_Model result;
            vector<int> l1Vectors{1};
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
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution92
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0092.Reverse_Linked_List_II.cpp"
    using namespace Solution92;

    int main()
    {
         Solution92::Reverse_Linked_List_II useClass;
         Solution92::Reverse_Linked_List_II::Reverse_Linked_List_II_Model getTestModel = useClass.GetTestData001();
         auto result1 = useClass.reverseBetween(getTestModel.head, getTestModel.left, getTestModel.right);
         
         getTestModel = useClass.GetTestData002();
         auto result2 = useClass.reverseBetween(getTestModel.head, getTestModel.left, getTestModel.right);
         
         return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 反向鍊錶二
    /// </summary>
    class Reverse_Linked_List_II
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
        class Reverse_Linked_List_II_Model
        {
        public:
            ListNode* head;
            int left;
            int right;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：先跑到left的位置，然後再進行(right -left)次數的節點反轉
        ///      Runtime :  0 ms Beats   100 %
        /// Memory Usage :7.5 MB Beats 20.33 %
        /// </summary>
        /// <returns></returns>
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* leftLastNode = dummy;

            for (int index = 0; index < left - 1; index++)
            {
                leftLastNode = leftLastNode->next;
            }
            ListNode* moveNode = leftLastNode->next;
            ListNode* nextNode = new ListNode(-1);
            for (int index = 0; index < right - left; index++)
            {
				nextNode = moveNode->next;
				moveNode->next = nextNode->next;
                nextNode->next = leftLastNode->next;
                leftLastNode->next = nextNode;
            }
            return dummy->next;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Reverse_Linked_List_II_Model GetTestData001(void)
        {
            Reverse_Linked_List_II_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 1,2,3,4,5 };
            result.head = ConstructNodes(l1Vectors);
            result.left= 2;
            result.right= 4;
            return result;//expect:  [1,4,3,2,5]
        };

         /// <summary>
        /// test2 
        /// </summary>        
        Reverse_Linked_List_II_Model GetTestData002(void)
        {
            Reverse_Linked_List_II_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 5 };
            result.head = ConstructNodes(l1Vectors);
            result.left= 1;
            result.right= 1;
            return result;//expect:  [5]
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
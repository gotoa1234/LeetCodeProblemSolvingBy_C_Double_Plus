#include <iostream>
#include <vector>
using namespace std;

namespace Solution160
{
#pragma region Paste to execute 
    /*
    #include "Easy\0160.Intersection_of_Two_Linked_Lists.cpp"
    using namespace Solution160;
    using namespace std;

    Solution160::Intersection_of_Two_Linked_Lists useClass;
    Solution160::Intersection_of_Two_Linked_Lists::Intersection_of_Two_Linked_Lists_Model getTestModel = useClass.GetTestData001();
    auto result = useClass.getIntersectionNode(getTestModel.headA, getTestModel.headB);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 
    /// </summary>
    class Intersection_of_Two_Linked_Lists
    {
#pragma region Model
        public:
        //Definition for singly-linked list.
        struct ListNode
        {
            int val;
            ListNode* next;
            ListNode(int x) : val(x), next(NULL) { }
        };
        public:
        class Intersection_of_Two_Linked_Lists_Model
        {
            public:
            ListNode* headA;
            ListNode* headB;
        };
#pragma endregion Model

#pragma region Main
        public:
        /// <summary>
        ///         思路 ：問題有個隱藏的係數，必須要跳過headA 與 headB前面節點
        ///      Runtime :   45 ms Beats 87.60%
        /// Memory Usage : 14.6 MB Beats 65.34%
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
        {
            int hALength = FindLength(headA);
            //1. 找出兩個串鍊長度
            int hBLength = FindLength(headB);
            //2. 找出距離
            int distance = abs(hALength - hBLength);
            //3. 跳過距離差
            if (hALength > hBLength)
            {
                for (int index = 0; index < distance; index++)                
                    headA = headA->next;                
            }
            else
            {
                for (int index = 0; index < distance; index++)                
                    headB = headB->next;                
            }

            //4-1. 找出兩個節點交集
            while (headB != NULL && headA != NULL)
            {
                if (headB == headA)
                {
                    return headB;
                }
                headB = headB->next;
                headA = headA->next;
            }

            //4-2. 如果沒有交集則回傳Null
            return nullptr;
        }

        /// <summary>
        /// 找出串鍊長度
        /// </summary>        
        int FindLength(ListNode* head)
        {
            int maxLength = 0;
            while (head != NULL)
            {
                maxLength++;
                head = head->next;
            }
            return maxLength;
        }
#pragma endregion Main

#pragma region TestData
        public:
        /// <summary>
        /// test 1
        /// </summary>        
        Intersection_of_Two_Linked_Lists_Model GetTestData001(void)
        {
            Intersection_of_Two_Linked_Lists_Model result;
            vector<int> l1Vectors1 = { 4, 1, 8, 4, 5 };
            result.headA = ConstructNodes(l1Vectors1);
            vector<int> l1Vectors2 = { 5, 6, 1, 8 ,4 ,5 };
            result.headB = ConstructNodes(l1Vectors2);
            return result;//Expect : 8
           
        };

        private:
        ListNode* ConstructNodes(vector<int>& inputDatas)
        {
            ListNode* nodeHeads = NULL;
            ListNode* moveNode = NULL;
            for (auto & myItem : inputDatas)
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
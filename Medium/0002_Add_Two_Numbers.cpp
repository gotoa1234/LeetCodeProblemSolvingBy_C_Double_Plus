#include <iostream>
#include <vector>
using namespace std;

namespace Solution2
{
#pragma region Paste to execute 
    /*
    #include "Medium/0002_Add_Two_Numbers.cpp"
    using namespace Solution2;
    using namespace std;
    
    int main()
    {
    
        Solution2::Add_Two_Numbers useClass;
        Solution2::Add_Two_Numbers::Add_Two_Numbers_Model getTestModel = useClass.GetTestData001();
        Solution2::Add_Two_Numbers::ListNode* result = useClass.addTwoNumbers(getTestModel.l1, getTestModel.l2);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 兩個陣列相加: 強制使用指定兩個鏈結串列，並且使其兩串列相加得出一個加總合的結果
    /// 思路：鏈結串鍊基本練習
    /// </summary>
    class Add_Two_Numbers
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
        class Add_Two_Numbers_Model
        {
        public:
            ListNode* l1;
            ListNode* l2;
        };
#pragma endregion Model

#pragma region Main
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* head = new ListNode(0);
            ListNode* moveNode = head;
            int summary = 0, carry = 0, digit = 0, l1Val = 0, l2Val = 0;
            while (l1 != nullptr ||
                   l2 != nullptr ||
                          carry > 0)
            {
                l1Val = l1 == nullptr ? 0 : l1->val;
                l2Val = l2 == nullptr ? 0 : l2->val;
                summary = l1Val + l2Val + carry;
                digit = summary % 10;
                carry = summary / 10;
                moveNode->next = new ListNode(digit);
                moveNode = moveNode->next;

                l1 = l1 == nullptr ? NULL : l1->next;
                l2 = l2 == nullptr ? NULL : l2->next;
            }
            return head->next;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Add_Two_Numbers_Model GetTestData001(void)
        {
            Add_Two_Numbers_Model result;
            vector<int> l1Vectors = { 2, 4, 3 };
            vector<int> l2Vectors = { 5, 6, 4 };
            result.l1 = ConstructNodes(l1Vectors);
            result.l2 = ConstructNodes(l2Vectors);
            return result;//expect:[7,0,8]
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Add_Two_Numbers_Model GetTestData002(void)
        {
            Add_Two_Numbers_Model result;
            result.l1 = new ListNode(0);
            result.l2 = new ListNode(0);
            return result;//expect:[0]
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Add_Two_Numbers_Model GetTestData003(void)
        {
            Add_Two_Numbers_Model result;
            vector<int> l1Vectors = { 9,9,9,9,9,9,9 };
            vector<int> l2Vectors = { 9,9,9,9 };
            result.l1 = ConstructNodes(l1Vectors);
            result.l2 = ConstructNodes(l2Vectors);
            return result;//expect :[8,9,9,9,0,0,0,1]
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
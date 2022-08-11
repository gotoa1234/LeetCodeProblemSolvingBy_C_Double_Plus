#include <iostream>
#include <vector>
using namespace std;

namespace Solution2
{
#pragma region Paste to execute 
    /*
    #include "0002_Add_Two_Numbers.cpp"
    using namespace Solution2;
    using namespace std;

    Solution2::Add_Two_Numbers useClass;
    Solution2::Add_Two_Numbers::Add_Two_Numbers_Model getTestModel = useClass.GetTestData001();
    Solution2::Add_Two_Numbers::ListNode* result = useClass.addTwoNumbers(getTestModel.l1, getTestModel.l2);

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

            ListNode* resultHead = new ListNode(0);
            ListNode* moveNode = resultHead;
            int summary = 0;
            int digits = 0;
            int carry = 0;
            while (l1 && l2)
            {
                summary = (l1->val + l2->val + carry);
                digits = summary % 10;
                carry = summary / 10;
                ListNode* newItem = new ListNode(digits);
                l1 = l1->next;
                l2 = l2->next;
                moveNode->next = newItem;
                moveNode = moveNode->next;
            }

            while (l1)
            {
                summary = (l1->val + carry);
                digits = summary % 10;
                carry = summary / 10;
                ListNode* newItem = new ListNode(digits);
                l1 = l1->next;
                moveNode->next = newItem;
                moveNode = moveNode->next;
            }

            while (l2)
            {
                summary = (l2->val + carry);
                digits = summary % 10;
                carry = summary / 10;
                ListNode* newItem = new ListNode(digits);
                l2 = l2->next;
                moveNode->next = newItem;
                moveNode = moveNode->next;
            }

            if (carry > 0)
            {
                ListNode* newItem = new ListNode(carry);
                moveNode->next = newItem;
                moveNode = moveNode->next;

            }
            return resultHead->next;
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
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Add_Two_Numbers_Model GetTestData002(void)
        {
            Add_Two_Numbers_Model result;
            result.l1 = new ListNode(0);
            result.l2 = new ListNode(0);
            return result;
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
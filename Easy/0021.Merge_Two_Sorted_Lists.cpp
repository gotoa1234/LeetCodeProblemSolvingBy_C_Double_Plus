#include <iostream>
#include <vector>
using namespace std;

namespace Solution21
{
#pragma region Paste to execute 
    /*
#include "Easy\0021.Merge_Two_Sorted_Lists.cpp"
using namespace Solution21;
using namespace std;

int main()
{
    Solution21::Merge_Two_Sorted_Lists useClass;
    Solution21::Merge_Two_Sorted_Lists::Merge_Two_Sorted_Lists_Model getTestModel = useClass.GetTestData001();
    Solution21::Merge_Two_Sorted_Lists::ListNode* result = useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);

    getTestModel = useClass.GetTestData002();
    auto result2 = useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);

    getTestModel = useClass.GetTestData003();
    auto result3= useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);

    getTestModel = useClass.GetTestData004();
    auto result4 = useClass.mergeTwoLists(getTestModel.list1, getTestModel.list2);
    return 0;
}


    */
#pragma endregion Paste to execute

    /// <summary>
    /// 合併兩個已排序的鏈結串鍊，由小到大
    /// </summary>
    class Merge_Two_Sorted_Lists
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
        class Merge_Two_Sorted_Lists_Model
        {
        public:
            ListNode* list1;
            ListNode* list2;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ： 預處理(可省略) => 將2個NodeList組成1個
        ///      Runtime :    8 ms, faster than 80.99% of C++ online submissions for Merge Two Sorted Lists.
        /// Memory Usage : 14.7 MB,   less than 97.86% of C++ online submissions for Merge Two Sorted Lists.

        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr)
                return list2;
            if (list2 == nullptr)
                return list1;
            ListNode* head = nullptr;
            ListNode* moveNode = new ListNode();
            head = moveNode;
            while (list1 && list2)
            {
                if (list1->val < list2->val)
                {
                    moveNode->next = list1;
                    moveNode = moveNode->next;
                    list1 = list1->next;
                }
                else
                {
                    moveNode->next = list2;
                    moveNode = moveNode->next;
                    list2 = list2->next;
                }
            }
            if (list1 == nullptr)
                moveNode->next = list2;
            else if(list2 == nullptr)
                moveNode->next = list1;
            return head->next;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Merge_Two_Sorted_Lists_Model GetTestData001(void)
        {
            Merge_Two_Sorted_Lists_Model result;
            vector<int> l1Vectors = { 1, 2, 4 };
            vector<int> l2Vectors = { 1, 3, 4 };
            result.list1 = ConstructNodes(l1Vectors);
            result.list2 = ConstructNodes(l2Vectors);
            return result;//expect :[1,1,2,3,4,4]
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Merge_Two_Sorted_Lists_Model GetTestData002(void)
        {
            Merge_Two_Sorted_Lists_Model result;
            vector<int> l1Vectors{};
            vector<int> l2Vectors = { 0 };
            result.list1 = ConstructNodes(l1Vectors);
            result.list2 = ConstructNodes(l2Vectors);
            return result;//Expect : [0]
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Merge_Two_Sorted_Lists_Model GetTestData003(void)
        {
            Merge_Two_Sorted_Lists_Model result;
            vector<int> l1Vectors{ };
            vector<int> l2Vectors{ };
            result.list1 = ConstructNodes(l1Vectors);
            result.list2 = ConstructNodes(l2Vectors);
            return result;//Expect : []
        };

        /// <summary>
        /// 測試資料4
        /// </summary>   
        Merge_Two_Sorted_Lists_Model GetTestData004(void)
        {
            Merge_Two_Sorted_Lists_Model result;
            vector<int> l1Vectors{ 5 };
            vector<int> l2Vectors{ 1, 2, 4};
            result.list1 = ConstructNodes(l1Vectors);
            result.list2 = ConstructNodes(l2Vectors);
            return result;//Expect : [1, 2, 4, 5]
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
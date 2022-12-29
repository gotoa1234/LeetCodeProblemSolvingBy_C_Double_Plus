#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution82
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0082.Remove_Duplicates_from_Sorted_List_II.cpp"
    using namespace Solution82;

    int main()
    {
        Solution82::Remove_Duplicates_from_Sorted_List_II useClass;
        Solution82::Remove_Duplicates_from_Sorted_List_II::Remove_Duplicates_from_Sorted_List_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.deleteDuplicates(getTestModel.head, getTestModel.target);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.deleteDuplicates(getTestModel.head, getTestModel.target);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 從排序列表中刪除重複項 II
    /// </summary>
    class Remove_Duplicates_from_Sorted_List_II
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
        class Remove_Duplicates_from_Sorted_List_II_Model
        {
        public:
            ListNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// </summary>
        /// <returns></returns>
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            return {};
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Remove_Duplicates_from_Sorted_List_II_Model GetTestData001(void)
        {
            Remove_Duplicates_from_Sorted_List_II_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 1,2,3,3,4,4,5 };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect: [1,2,5]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Remove_Duplicates_from_Sorted_List_II_Model GetTestData002(void)
        {
            Remove_Duplicates_from_Sorted_List_II_Model result;
            vector<int> l1Vectors{};
            l1Vectors = { 1,1,1,2,3 };
            result.head = ConstructNodes(l1Vectors);
            return result;//expect:[2,3]
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
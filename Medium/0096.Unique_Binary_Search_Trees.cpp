#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution96
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0096.Unique_Binary_Search_Trees.cpp"
    using namespace Solution96;

    int main()
    {
        Solution96::Unique_Binary_Search_Trees useClass;
        Solution96::Unique_Binary_Search_Trees::Unique_Binary_Search_Trees_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.numTrees(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.numTrees(getTestModel.n);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 獨特的二叉搜索樹
    /// </summary>
    class Unique_Binary_Search_Trees
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
        class Unique_Binary_Search_Trees_Model
        {
        public:
            int n;
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
        int numTrees(int n) {
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Unique_Binary_Search_Trees_Model GetTestData001(void)
        {
            Unique_Binary_Search_Trees_Model result;
            result.n = 3;
            return result;//expect:  5
        };

         /// <summary>
        /// test2 
        /// </summary>        
        Unique_Binary_Search_Trees_Model GetTestData002(void)
        {
            Unique_Binary_Search_Trees_Model result;
            result.n = 1;
            return result;//expect: 1
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
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution95
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0095.Unique_Binary_Search_Trees_II.cpp"
    using namespace Solution95;

    int main()
    {
        Solution95::Unique_Binary_Search_Trees_II useClass;
        Solution95::Unique_Binary_Search_Trees_II::Unique_Binary_Search_Trees_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.generateTrees(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.generateTrees(getTestModel.n);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 獨特的二叉搜索樹 II
    /// </summary>
    class Unique_Binary_Search_Trees_II
    {
#pragma region Model
    public:
        //Definition for singly-linked list.
        struct TreeNode {
            int val;
            TreeNode* next;
            TreeNode() : val(0), next(nullptr) {}
            TreeNode(int x) : val(x), next(nullptr) {}
            TreeNode(int x, TreeNode* next) : val(x), next(next) {}
        };
    public:
        class Unique_Binary_Search_Trees_II_Model
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
        vector<TreeNode*> generateTrees(int n) {
        return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Unique_Binary_Search_Trees_II_Model GetTestData001(void)
        {
            Unique_Binary_Search_Trees_II_Model result;
            result.n = 3;
            return result;//expect:  [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
        };

         /// <summary>
        /// test2 
        /// </summary>        
        Unique_Binary_Search_Trees_II_Model GetTestData002(void)
        {
            Unique_Binary_Search_Trees_II_Model result;
            result.n = 1;
            return result;//expect: [[1]]
        };
    private:
        TreeNode* ConstructNodes(vector<int>& inputDatas)
        {
            TreeNode* nodeHeads = NULL;
            TreeNode* moveNode = NULL;
            for (auto& myItem : inputDatas)
            {
                TreeNode* newItem = new TreeNode(myItem);
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
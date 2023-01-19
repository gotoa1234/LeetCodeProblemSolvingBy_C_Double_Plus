#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
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
            TreeNode* left;
            TreeNode* right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
        ///         思路 ：利用動態規劃(DP)，將起1 訖n 之間的節點結構用遞迴遍歷，找出結果
        ///      Runtime :   8 ms Beats 99.65 %
        /// Memory Usage :12.3 MB Beats 96.52 %
        /// </summary>
        /// <returns></returns>
    public:
        vector<vector<vector<TreeNode*>>> _dp;
        vector<TreeNode*> generateTrees(int n) 
        {
            fill_n(std::back_inserter(_dp), n, vector<vector<TreeNode*>>(n));
            return FindCompose(1, n);
        }

        vector<TreeNode*> FindCompose(int start, int end) {

            //1-1. 左節點檢定: start在每次遞迴中表示上一節點的值，End表示當前的值，若start > end 必為nullptr
            if (start > end) 
                return { nullptr };
            //1-2. dp表判斷，若已經存在可沿著用，不用重新遞迴
            if (!_dp[start - 1][end - 1].empty()) 
                return _dp[start - 1][end - 1];

            //2-1. 進行節點的產生
            vector<TreeNode*> compose;
            for (int index = start; index <= end; index++) 
            {
                //2-2. 左節點與右節點找出
                auto left = FindCompose(start, index - 1);
                auto right = FindCompose(index + 1, end);
                for (auto leftNode : left) 
                {
                    for (auto rightNode : right) 
                    {
                        //3. 建立此層節點構造
                        TreeNode* node = new TreeNode(index);
                        node->left = leftNode;
                        node->right = rightNode;
                        compose.push_back(node);
                    }
                }
            }
            //4. 返回本次 start -> end 之間的節點結構
            _dp[start - 1][end - 1] = compose;
            return compose;
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
#pragma endregion TestData
    };
}
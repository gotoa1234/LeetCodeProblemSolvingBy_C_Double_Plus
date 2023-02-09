#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace Solution107
{
#pragma region Paste to execute 
    /*
    #include "Medium\0107.Binary_Tree_Level_Order_Traversal_II.cpp"
    using namespace Solution107;
    using namespace std;

    Solution107::Binary_Tree_Level_Order_Traversal_II useClass;
    Solution107::Binary_Tree_Level_Order_Traversal_II::Binary_Tree_Level_Order_Traversal_II_Model getTestModel = useClass.GetTestData001();
    vector<vector<int>> result = useClass.levelOrderBottom(getTestModel.root);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 二元樹級順序遍歷2
    /// </summary>
    class Binary_Tree_Level_Order_Traversal_II
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
        class Binary_Tree_Level_Order_Traversal_II_Model
        {
        public:
            TreeNode* root;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路  :參考102，利用queue 組成每層結果，然後反轉結果順序
        ///      Runtime :    3 ms Beats 86.11 %
        /// Memory Usage : 12.5 MB Beats 87.36 %
        vector<vector<int>> levelOrderBottom(TreeNode* root) 
        {
            //1. 排除為空的可能
            if (root == nullptr)
                return {};
            vector<vector<int>> result{};
            queue<TreeNode*> queueTemp{};
            //2. 將根結點開始遍歷
            queueTemp.push(root);
            //3. 直到所有的點都走完，必為空
            while (!queueTemp.empty())
            {
                //4-1. 取出當前queue中所有值，若有值就是該層要組成
                int size = queueTemp.size();
                vector<int> child{};               
                while (size--)
                {
                    //4-2. 將queue最前端的項目取出，為同一層的資料(用child紀錄群內數值)
                    TreeNode* get = queueTemp.front();
                    queueTemp.pop();
                    child.push_back(get->val);
                    //4-3. 每個節點走到，若有子節點則把值放進下個queue中，繼續重複3.的步驟
                    if (get->left != nullptr)
                        queueTemp.push(get->left);
                    if (get->right != nullptr)
                        queueTemp.push(get->right);
                }
                result.push_back(child);
            }
            //5. 與102.最大差異就是用Reverse反轉陣列內項目順序
            reverse(result.begin(), result.end());
            return result;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Binary_Tree_Level_Order_Traversal_II_Model GetTestData001(void)
        {
            Binary_Tree_Level_Order_Traversal_II_Model result;
            vector<int> l1Vectors = { 3,9,20,NULL,NULL,15,7 };
            //result.root = ConstructNodes(l1Vectors);
            result.root = new TreeNode(3);
            result.root->left = new TreeNode(9);
            result.root->right = new TreeNode(20);
            result.root->right->left = new TreeNode(15);
            result.root->right->right = new TreeNode(7);

            return result;//[[15,7],[9,20],[3]]
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Binary_Tree_Level_Order_Traversal_II_Model GetTestData002(void)
        {
            Binary_Tree_Level_Order_Traversal_II_Model result;
            vector<int> l1Vectors = { 1};
            result.root = ConstructNodes(l1Vectors);
            return result;// [[1]]
        };

        /// <summary>
        /// 測試資料3
        /// </summary>   
        Binary_Tree_Level_Order_Traversal_II_Model GetTestData003(void)
        {
            Binary_Tree_Level_Order_Traversal_II_Model result;
            vector<int> l1Vectors{ };
            result.root = ConstructNodes(l1Vectors);
            return result;// []
        };
    private:
        TreeNode* ConstructNodes(vector<int>& inputDatas)
        {
            /*   *int val;
               *TreeNode* left;
               *TreeNode* right;
               *TreeNode() : val(0), left(nullptr), right(nullptr) {}
               *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
               *TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}*/
            TreeNode* nodeHeads = NULL;
            TreeNode* treeLevelHeads = NULL;
            bool switchLevel = true;
            for (auto& myItem : inputDatas)
            {
                if (nodeHeads == NULL)
                {
                    nodeHeads = new TreeNode(myItem);
                    treeLevelHeads = new TreeNode(myItem);
                    continue;
                }

                if (myItem == NULL && switchLevel)
                {

                }


                if (myItem == NULL)
                {
                    continue;
                }
                else
                {
                    TreeNode* newItem = new TreeNode(myItem);
                }
            }
            return nodeHeads;
        };
#pragma endregion TestData
    };
}
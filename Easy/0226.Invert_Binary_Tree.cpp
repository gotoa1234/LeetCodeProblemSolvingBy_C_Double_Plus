#include <iostream>
#include <vector>
using namespace std;

namespace Solution226
{
#pragma region Paste to execute 
    /*
    #include "0226.Reverse_Linked_List.cpp"
    using namespace Solution226;
    using namespace std;

    Solution226::Reverse_Linked_List useClass;
    Solution226::Reverse_Linked_List::Reverse_Linked_List_Model getTestModel = useClass.GetTestData001();
    auto result = useClass.invertTree(getTestModel.root);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 反轉二叉樹
    /// </summary>
    class Reverse_Linked_List
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
        class Reverse_Linked_List_Model
        {
        public:
            TreeNode* head;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：每次將當前的節點底下的兩個左右節點互換，直到走到底，即完成反轉二元樹      
        ///               STEP 1:  一開始由4開始，將底下的兩個左右節點交換
        ///                    [4]        
        ///                 2       7
        ///               1   3   6   9
        /// 
        ///               STEP 2: 但沒有走到底，所以將7 底下的兩個左右節點交換
        ///                     4        
        ///                 2      [7]
        ///               1   3   6   9
        /// 
        ///               STEP 3: 這時9底下為null 所以與節點6做交換
        ///                      4        
        ///                 2         7
        ///               1   3   [6]   [9]
        /// 
        ///               STEP 4: 回到7，因為底下已交換完畢，由自己跟2交換
        ///                      4        
        ///                [2]        [7]
        ///               1   3     9     6
        /// 
        ///               STEP 5: 7與2交換完畢，開始從節點2 往下跑
        ///                       4        
        ///                  7        [2]
        ///                9   6    1     3
        ///  
        ///              STEP 6: 3與1兌換，回到2時發現已做完，所以再回到4 ，此時4是根節點所以結束
        ///                       4        
        ///                  7          2
        ///                9   6     3     1
        ///      Runtime : 0 ms Beats 100 %
        /// Memory Usage : 9.8 MB Beats 5.14 %
        TreeNode* invertTree(TreeNode* root) 
        {
            if (root == nullptr)
                return nullptr;
            auto tempNode = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(tempNode);
            return root
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        Reverse_Linked_List_Model GetTestData001(void)
        {
            Reverse_Linked_List_Model result;
			vector<int> l1Vectors = { 2,1,3 };
            result.head = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        Reverse_Linked_List_Model GetTestData002(void)
        {
            Reverse_Linked_List_Model result;
            vector<int> l1Vectors = {};
            result.head = ConstructNodes(l1Vectors);
            return result;
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
#include <iostream>
#include <vector>
using namespace std;

namespace Solution589
{
#pragma region Paste to execute 
    /*
    #include "0589.N_aryTree_Preorder_Traversal.cpp"
    using namespace Solution589;
    using namespace std;

    Solution589::N_aryTree_Preorder_Traversal useClass;
    Solution589::N_aryTree_Preorder_Traversal::N_aryTree_Preorder_Traversal_Model getTestModel = useClass.GetTestData001();
    bool result = useClass.hasCycle(getTestModel.head);

    */
#pragma endregion Paste to execute

    /// <summary>
    /// 
    /// </summary>
    class N_aryTree_Preorder_Traversal
    {
#pragma region Model
    public:
        //Definition for singly-linked list.
        struct Node {
            int val;
            vector<Node*> children;
            Node() {}
            Node(int _val) {
                val = _val;
            }
            Node(int _val, vector<Node*> _children) {
                val = _val;
                children = _children;
            }
        };
    public:
        class N_aryTree_Preorder_Traversal_Model
        {
        public:
            Node* root;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：
        ///      Runtime :
        /// Memory Usage :

        vector<int> preorder(Node* root) {

        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// 測試資料1
        /// </summary>        
        N_aryTree_Preorder_Traversal_Model GetTestData001(void)
        {
            N_aryTree_Preorder_Traversal_Model result;
            vector<int> l1Vectors = { 1,NULL,3,2,4,NULL,5,6 };
            result.root = ConstructNodes(l1Vectors);
            return result;
        };

        /// <summary>
        /// 測試資料2
        /// </summary>   
        N_aryTree_Preorder_Traversal_Model GetTestData002(void)
        {
            N_aryTree_Preorder_Traversal_Model result;
            vector<int> l1Vectors = { 
                1,                    NULL,
                2,3       ,4    ,5   ,NULL,
                NULL,6,7   ,NULL,8, NULL ,9,10,NULL,
                  NULL,11,NULL,  12,NULL,13, NULL,NULL,
                    14
            };
            result.root = ConstructNodes(l1Vectors);
            return result;
        };
    private:
        Node* ConstructNodes(vector<int>& inputDatas)
        {
            vector<vector<int>> inputTrans;
            int index = 0;
            vector<int> thisLevel;
            for (index = 0 ; index < inputDatas.size(); index++)
            {
                if (inputTrans.size() >= 2)
                    break;

                thisLevel.push_back(inputDatas[index]);
                if (inputDatas[index] == NULL)
                {
                    inputTrans.push_back(thisLevel);
                    thisLevel = {};
                    continue;
                }
            }

            for (int myLevel = 2; index < inputDatas.size();)
            {
                //觀察上一層的有效數
                int availCount = 0;
                thisLevel = {};
                for (int i=0, availCount = 0; i < inputTrans[myLevel - 1].size();i++)
                {
                    if (inputTrans[myLevel - 1][i] != NULL)
                    {
                        availCount++;
                    }
                }
                
                for (int ind = 0; ind < availCount;ind)
                {
                    thisLevel.push_back(inputDatas[index]);
                    if (inputDatas[index] == NULL)
                    {
                        ind++;                        
                    }
                    index++;
                }
                myLevel++;
            }

            Node* nodeHeads = NULL;
         /*   Node* moveHeads = NULL;
            bool headFlag = true;
            bool secondLevel = false;
            for (auto& myItem : inputDatas)
            {
                if (headFlag && myItem == NULL)
                {
                    headFlag = false;
                    secondLevel = true;
                    continue;
                }

                if (nodeHeads == NULL)
                {
                    nodeHeads = new Node(myItem);
                    moveHeads = nodeHeads;
                    continue;
                }

                if (secondLevel)
                {

                }
             

                if (nodeHeads == NULL)
                {
                    nodeHeads = new Node(myItem);
                    treeLevelHeads = new Node(myItem);
                    continue;
                }

                if (myItem == NULL)
                {
                    continue;
                }
                else
                {
                    Node* newItem = new Node(myItem);
                }
            }
            
            Node* nodeHeads = NULL;
            Node* treeLevelHeads = NULL;
            bool switchLevel = true;
            for (auto& myItem : inputDatas)
            {
                if (nodeHeads == NULL)
                {
                    nodeHeads = new Node(myItem);
                    treeLevelHeads = new Node(myItem);
                    continue;
                }

                if (myItem == NULL)
                {
                    continue;
                }
                else
                {
                    Node* newItem = new Node(myItem);
                }
            }*/
            return nodeHeads;
        };
#pragma endregion TestData
    };
}
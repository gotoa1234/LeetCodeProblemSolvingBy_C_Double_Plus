#include <iostream>
#include <vector>
#include <stack>
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
    /// N元樹的前序遍歷
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
        ///         思路 ：利用堆疊的特性，將每個節點從進行遍歷並取出，直到所有的節點都訪問
        ///      Runtime :   27 ms, faster than 77.50% of C++ online submissions for N-ary Tree Preorder Traversal.
        /// Memory Usage : 11.5 MB,   less than 21.53% of C++ online submissions for N-ary Tree Preorder Traversal.

        vector<int> preorder(Node* root) {
            vector<int> result;
            if (root == nullptr)
                return result;

            stack<Node*> stack;
            stack.push(root);
            while (!stack.empty())
            {
                //每次取出最後一個塞入的節點
                Node* currentNode = stack.top();
                stack.pop();
                result.push_back(currentNode->val);
                vector<Node*> child = currentNode->children;
                int length = child.size();
                //由尾巴(最右側)先塞入，取出時必定由頭(最左邊)取出
                while (length--)
                {
                    stack.push(child[length]);
                }
            }
            return result;
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
            //result.root = ConstructNodes(l1Vectors);
            result.root = new Node(1);

            result.root->children.push_back(new Node(3));
            result.root->children.push_back(new Node(2));
            result.root->children.push_back(new Node(4));

            result.root->children[0]->children.push_back(new Node(5));
            result.root->children[0]->children.push_back(new Node(6));
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
            //result.root = ConstructNodes(l1Vectors);
            result.root = new Node(1);
            vector<Node*> temp1;
            temp1.push_back(new Node(2));
            temp1.push_back(new Node(3));
            temp1.push_back(new Node(4));
            temp1.push_back(new Node(5));
			result.root->children = temp1;

            result.root->children[1]->children.push_back(new Node(6));
            result.root->children[1]->children.push_back(new Node(7));

            result.root->children[2]->children.push_back(new Node(8));

            result.root->children[3]->children.push_back(new Node(9));
            result.root->children[3]->children.push_back(new Node(10));
            
            result.root->children[1]->children[1]->children.push_back(new Node(11));

            result.root->children[2]->children[0]->children.push_back(new Node(12));

            result.root->children[3]->children[0]->children.push_back(new Node(13));

            result.root->children[1]->children[1]->children[0]->children.push_back(new Node(14));
            return result;
        };
    private:
        //TODO : 未完成
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
                thisLevel = {};
                int availCount = 0;
                vector<int> currentArray = inputTrans[myLevel - 1];
				for (int innerIndex = 0; innerIndex < currentArray.size(); innerIndex++)
				{
					if (currentArray[innerIndex] != NULL)
					{
						availCount = availCount + 1;
					}
				}

                for (int innerIndex = 0; 
                    innerIndex < availCount && index < inputDatas.size();)
                {
                    thisLevel.push_back(inputDatas[index]);
                    if (inputDatas[index] == NULL)
                    {
                        innerIndex++;
                    }
                    index++;
                }
                inputTrans.push_back(thisLevel);
                myLevel++;
            }

            Node* nodeHeads = NULL;
            Node* topNode = NULL;
            if (inputTrans.size() == 0)
            {
                return nodeHeads;
            }

            //1 
            vector<int> currentLevel = inputTrans[0];
            nodeHeads = new Node(currentLevel[0]);
            //2
            if (inputTrans.size() == 1)
                return nodeHeads;

            currentLevel = inputTrans[1];
            vector<Node*> _childrens;
			for (int i = 0; i < currentLevel.size() - 1; i++)
            {
                _childrens.push_back(new Node(currentLevel[i]));
            }
            nodeHeads->children = _childrens;
            return nodeHeads;
        };
#pragma endregion TestData
    };
}
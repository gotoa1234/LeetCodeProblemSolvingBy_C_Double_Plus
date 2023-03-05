#include <iostream>
#include <vector>
using namespace std;

namespace Solution117
{
#pragma region Paste to execute 
    /*
    #include "Medium\0117.Populating_Next_Right_Pointers_in_Each_Node_II.cpp"
    using namespace Solution117;
    using namespace std;
    
    int main()
    {
        Solution117::Populating_Next_Right_Pointers_in_Each_Node_II useClass;
        Solution117::Populating_Next_Right_Pointers_in_Each_Node_II::Populating_Next_Right_Pointers_in_Each_Node_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.connect(getTestModel.root);
    
        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.connect(getTestModel.root);
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 在每個節點 II 中填充下一個右指針
    /// </summary>
    class Populating_Next_Right_Pointers_in_Each_Node_II
    {
#pragma region Model
    public:
        //Definition for singly-linked list.
        struct Node {
            int val;
            Node* left;
            Node* right;
            Node* next;

            Node() : val(0), left(NULL), right(NULL), next(NULL) {}

            Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

            Node(int _val, Node* _left, Node* _right, Node* _next)
                : val(_val), left(_left), right(_right), next(_next) {}
        };
    public:
        class Populating_Next_Right_Pointers_in_Each_Node_II_Model
        {
        public:
            Node* root;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：BFS 廣度優先，遞迴版本是只做根節點然後每個的左節點為起始點，不斷往下
        ///               當前節點會處理下一層每個左節點的next指向右邊的節點，直到走到底後，將當前節點的左節點在持續重複直到走到底
        ///           ※備註，題目要求常數空間(You may only use constant extra space.)
        ///      Runtime :   12 ms Beats 82.20 %
        /// Memory Usage : 17.4 MB Beats 72.64 %
        Node* connect(Node* root) {
            //1. 跳出條件，處理完成
            if (nullptr == root)   
                return nullptr;

            //2. 設定一個暫存當前節點的左節點用的Node
            Node dummy(0);
            //3-1. 每次將自己的節點指向右邊(next)，做平移
            for (Node* currentNode = root, *lastNode = &dummy; currentNode; currentNode = currentNode->next)
            {
                //3-2. 將當前左節點給上一個右節點->next指向
                if (currentNode->left)
                {
                    lastNode->next = currentNode->left;
                    lastNode = lastNode->next;
                }//3-3. 將當前右節點給上一個左節點->next指向 
                if (currentNode->right)
                {
                    lastNode->next = currentNode->right;
                    lastNode = lastNode->next;
                }
            }
            //4. 該層都已完成，進入下一層
            connect(dummy.next);

            return root;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Populating_Next_Right_Pointers_in_Each_Node_II_Model GetTestData001(void)
        {
            Populating_Next_Right_Pointers_in_Each_Node_II_Model result;
            vector<int> l1Vectors = { 1, 2, 4 };
            result.root = new Node(1);

            result.root->left = new Node(2);
            result.root->right = new Node(3);

            result.root->left->left = new Node(4);
            result.root->left->right = new Node(5);
            result.root->right->left = nullptr;
            result.root->right->right = new Node(7);

            return result;//Expect:  [1,#,2,3,#,4,5,7,#]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Populating_Next_Right_Pointers_in_Each_Node_II_Model GetTestData002(void)
        {
            Populating_Next_Right_Pointers_in_Each_Node_II_Model result;
            result.root = nullptr;
            return result;//Expect : []
        };

#pragma endregion TestData
    };
}
#include <iostream>
#include <vector>
using namespace std;

namespace Solution116
{
#pragma region Paste to execute 
    /*
    #include "Medium\0116.Populating_Next_Right_Pointers_in_Each_Node.cpp"
    using namespace Solution116;
    using namespace std;
    int main()
    {
        Solution113::Path_Sum useClass;
        Solution113::Path_Sum::Populating_Next_Right_Pointers_in_Each_Node_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.connect(getTestModel.root);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.connect(getTestModel.root);
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 在每個節點中填充下一個右指針
    /// </summary>
    class Populating_Next_Right_Pointers_in_Each_Node
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
        class Populating_Next_Right_Pointers_in_Each_Node_Model
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

        Node* connect(Node* root) {
            return {};
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Populating_Next_Right_Pointers_in_Each_Node_Model GetTestData001(void)
        {
            Populating_Next_Right_Pointers_in_Each_Node_Model result;
            vector<int> l1Vectors = { 1, 2, 4 };
            result.root = new Node(1);
            
            result.root->left = new Node(2);
            result.root->right = new Node(3);

            result.root->left->left = new Node(4);
            result.root->left->right = new Node(5);
            result.root->right->left = new Node(6);
            result.root->right->right = new Node(7);

            return result;//Expect: [1, #, 2, 3, #, 4, 5, 6, 7, #]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Populating_Next_Right_Pointers_in_Each_Node_Model GetTestData002(void)
        {
			Populating_Next_Right_Pointers_in_Each_Node_Model result;
			result.root = nullptr;
			return result;//Expect : []
        };

#pragma endregion TestData
    };
}
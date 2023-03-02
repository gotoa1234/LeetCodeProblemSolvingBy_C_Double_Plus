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
    /// �b�C�Ӹ`�I����R�U�@�ӥk���w
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
        ///         ��� �G�D�جO�@�������G����A�ҥH�@�w�|�������`�I�A�~�|���������k�`�I
        ///                �]���i�H�P�_�`�I�����`�I���ŮɡA���ΦA���U�i��F
        ///                �Q�λ��j�A�N��e�`�I�����`�I���V�k�`�I�A�k�`�I�A���V�W�Ÿ`�I��Next�U�����`�I
        ///      Runtime :  19 ms Beats 81.15 %
        /// Memory Usage :16.9 MB Beats 74.66 %
        Node* connect(Node* root) {
            //1. ���X����
            if (root == nullptr || root->left == nullptr)
                return root;
            //2. �����k�A�k���ڸ`�I��next�����`�I
            root->left->next = root->right;
            root->right->next = root->next == nullptr ? nullptr : root->next->left;
            //3. ���k�`�I�~�򩹤U����
            connect(root->left);
            connect(root->right);
            return root;
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
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
    /// �b�C�Ӹ`�I II ����R�U�@�ӥk���w
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
        ///         ��� �GBFS �s���u���A���j�����O�u���ڸ`�I�M��C�Ӫ����`�I���_�l�I�A���_���U
        ///               ��e�`�I�|�B�z�U�@�h�C�ӥ��`�I��next���V�k�䪺�`�I�A���쨫�쩳��A�N��e�`�I�����`�I�b���򭫽ƪ��쨫�쩳
        ///           ���Ƶ��A�D�حn�D�`�ƪŶ�(You may only use constant extra space.)
        ///      Runtime :   12 ms Beats 82.20 %
        /// Memory Usage : 17.4 MB Beats 72.64 %
        Node* connect(Node* root) {
            //1. ���X����A�B�z����
            if (nullptr == root)   
                return nullptr;

            //2. �]�w�@�ӼȦs��e�`�I�����`�I�Ϊ�Node
            Node dummy(0);
            //3-1. �C���N�ۤv���`�I���V�k��(next)�A������
            for (Node* currentNode = root, *lastNode = &dummy; currentNode; currentNode = currentNode->next)
            {
                //3-2. �N��e���`�I���W�@�ӥk�`�I->next���V
                if (currentNode->left)
                {
                    lastNode->next = currentNode->left;
                    lastNode = lastNode->next;
                }//3-3. �N��e�k�`�I���W�@�ӥ��`�I->next���V 
                if (currentNode->right)
                {
                    lastNode->next = currentNode->right;
                    lastNode = lastNode->next;
                }
            }
            //4. �Ӽh���w�����A�i�J�U�@�h
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
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution129
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0129.Sum_Root_to_Leaf_Numbers.cpp"
    using namespace Solution129;

    int main()
    {
        Solution129::Sum_Root_to_Leaf_Numbers useClass;
        Solution129::Sum_Root_to_Leaf_Numbers::Sum_Root_to_Leaf_Numbers_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.sumNumbers(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.sumNumbers(getTestModel.n);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.sumNumbers(getTestModel.n);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �N�ڻP���Ƭۥ[
    /// </summary>
    class Sum_Root_to_Leaf_Numbers
    {
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
#pragma region Model
    public:
        class Sum_Root_to_Leaf_Numbers_Model
        {
        public:
            TreeNode* root;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q�λ��j�N�C�����ȳ����H10�֥[�A�̫����
        ///      Runtime :   0 ms Beats 100 %
        /// Memory Usage : 9.2 MB Beats 87.77 %
        /// </summary>
        /// <returns></returns>
        int sumNumbers(TreeNode* root) 
        {            
            return FindRoot(root, 0);
        }

        int FindRoot(TreeNode* root, int price)
        {                                   
            //1. �C���i�ӳ����{������ * 10 �֥[
            price = root->val + price * 10;
            if (root->left && root->right)//2-1. ��Ӹ`�I�����p  
                return FindRoot(root->left, price) + FindRoot(root->right, price);
            else if(root->left && root->right == nullptr)//2-2. ���`�I�����p      
                return FindRoot(root->left, price);            
            else if(root->left == nullptr && root->right)//2-3. �k�`�I�����p
                return FindRoot(root->right, price);            
            return price;//2-4. ���쩳�F�A�����^��
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Sum_Root_to_Leaf_Numbers_Model GetTestData001(void)
        {
            Sum_Root_to_Leaf_Numbers_Model result;
            result.root = new TreeNode(1);
            result.root->left = new TreeNode(2); 
            result.root->right = new TreeNode(3);
            return result;//expect: 25
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Sum_Root_to_Leaf_Numbers_Model GetTestData002(void)
        {
            Sum_Root_to_Leaf_Numbers_Model result;
            result.root = new TreeNode(4);
            result.root->left = new TreeNode(9);
            result.root->right = new TreeNode(0);

            result.root->left->left = new TreeNode(5);
            result.root->left->right = new TreeNode(1);
            return result;//expect: 1026
        };

#pragma endregion TestData
    };
}
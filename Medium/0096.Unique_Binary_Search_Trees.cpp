#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution96
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0096.Unique_Binary_Search_Trees.cpp"
    using namespace Solution96;

    int main()
    {
        Solution96::Unique_Binary_Search_Trees useClass;
        Solution96::Unique_Binary_Search_Trees::Unique_Binary_Search_Trees_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.numTrees(getTestModel.n);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.numTrees(getTestModel.n);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �W�S���G�e�j����
    /// </summary>
    class Unique_Binary_Search_Trees
    {
#pragma region Model
    public:
        //Definition for singly-linked list.
        struct ListNode {
            int val;
            ListNode* next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode* next) : val(x), next(next) {}
        };
    public:
        class Unique_Binary_Search_Trees_Model
        {
        public:
            int n;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�o�D�̨ήį�O�μƾǪ�������
        ///               ���qn ���W�߬ݡA��n=1�ɬ�1�A���n �i��Y�ӭp��i�H�o��1�A�o��ȩwn=0 �]��1
        ///              n    |  ���G       n    |  ���G
        ///              ------------       ------------
        ///              1        1         0        1    
        ///              2        2         1        1     
        ///              3        5     =>  2        2    
        ///              4        14        3        5
        ///              5        42        4        14
        ///              6        132       5        42
        ///                                 6        132
        /// 
        ///              �ƹ�W�����p�U�G
        ///              n = 2 �ɡA�[�`�H�U
        ///              n  | �N�H�U�p��ۥ[�A�i�H�o��2 (1+1)
        ///              ---------
        ///              0  | n=0�����G * n=1�����G => 1 * 1 = 1
        ///              1  | n=1�����G * n=0�����G => 1 * 1 = 1
        /// 
        ///              n = 5 �ɡA�[�`�H�U
        ///              n  | �N�H�U�p��ۥ[�A�i�H�o��42 (14 + 5 + 4 + 5 + 14)
        ///              ---------
        ///              0  | n=0�����G * n=4�����G =>  1 * 14= 14
        ///              1  | n=1�����G * n=3�����G =>  1 * 5 = 5
        ///              2  | n=2�����G * n=2�����G =>  2 * 2 = 4
        ///              3  | n=3�����G * n=1�����G =>  5 * 1 = 5
        ///              4  | n=4�����G * n=0�����G => 14 * 1 = 14
        ///
        ///      Runtime :  0 ms Beats 100 %
        /// Memory Usage :5.9 MB Beats 77.88 %
        /// </summary>
        /// <returns></returns>
    public:
        int numTrees(int n) 
        {
            //�Q�Τ����W�߸� + �ʺA�W���Q�Ϋe���D�X�����G
            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int index = 1; index <= n; index++)
            {
                for (int innerIndex = 0; innerIndex < index; ++innerIndex) 
                {
                    dp[index] += dp[innerIndex] * dp[index - innerIndex - 1];
                }
            }
            return dp[n];
        }


    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Unique_Binary_Search_Trees_Model GetTestData001(void)
        {
            Unique_Binary_Search_Trees_Model result;
            result.n = 3;
            return result;//expect:  5
        };

         /// <summary>
        /// test2 
        /// </summary>        
        Unique_Binary_Search_Trees_Model GetTestData002(void)
        {
            Unique_Binary_Search_Trees_Model result;
            result.n = 1;
            return result;//expect: 1
        };
    private:
        ListNode* ConstructNodes(vector<int>& inputDatas)
        {
            ListNode* nodeHeads = NULL;
            ListNode* moveNode = NULL;
            for (auto& myItem : inputDatas)
            {
                ListNode* newItem = new ListNode(myItem);
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
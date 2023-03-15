#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution131
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0131.Palindrome_Partitioning.cpp"
    using namespace Solution131;

    int main()
    {
        Solution131::Palindrome_Partitioning useClass;
        Solution131::Palindrome_Partitioning::Palindrome_Partitioning_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.solve(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.solve(getTestModel.s);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �^�幺��
    /// </summary>
    class Palindrome_Partitioning
    {
#pragma region Model
    public:
        class Palindrome_Partitioning_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q��DFS���_���j�A�qs[0]�}�l�����A�Ns[Index] ���^��r�������X��i���G��
        ///      Runtime :   86 ms Beats 98.89 %
        /// Memory Usage : 49.2 MB Beats 86.2 %
        /// </summary>
        /// <returns></returns>        
        vector<vector<string>> _result;
        vector<vector<string>> partition(string s) {
            _result = vector<vector<string>>();
            vector<string> compose;
            //1. �qs[0]�}�l����
            FindCompseByDFS(0, s, compose);
            return _result;
        }

        void FindCompseByDFS(int index, string& s, vector<string>& compose) 
        {            
            //4. ���X����O��e��������I�F�A����compose�զ����r�����
            if (index == s.size()) {
                _result.push_back(compose);
                return;
            }

            //2. ���_�M���r��ѬY��char �����k�X�W�A�Y�ŦX�^�媺�h�O��
            for (int innerIndex = index; innerIndex < s.length(); innerIndex++)
            {
                //3-1. �ˬd�e�B����ެO�_�^��
                if (IsPalindrome(s, index, innerIndex))
                {
                    //3-2. �^��h�����A�åB���U�~��i��DFS����
                    compose.push_back(s.substr(index, innerIndex - index + 1));
                    FindCompseByDFS(innerIndex + 1, s, compose);
                    //3-3. �Y���쩳 or ���򱴯����D�^��A�h�|�N��e�@��@��compose�����A�A�~�򱴯��t�@��innerIndex(�����)
                    compose.pop_back();
                }
            }
        }

        //�ˬd�^��
        bool IsPalindrome(string& s, int start, int end) {
            while (start <= end)
            {
                if (s[start] != s[end])
                    return 0;
                start++;
                end--;
            }
            return 1;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Palindrome_Partitioning_Model GetTestData001(void)
        {
            Palindrome_Partitioning_Model result;
            result.s = "redivider";
            return result;//expect: [["a","a","b"],["aa","b"]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Palindrome_Partitioning_Model GetTestData002(void)
        {
            Palindrome_Partitioning_Model result;
            result.s = "a";
            return result;//expect: [["a"]]
        };

#pragma endregion TestData
    };
}
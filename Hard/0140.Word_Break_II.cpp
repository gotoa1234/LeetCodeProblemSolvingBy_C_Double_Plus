#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution140
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0140.Word_Break_II.cpp"
    using namespace Solution140;

    int main()
    {
        Solution140::Word_Break_II useClass;
        Solution140::Word_Break_II::Word_Break_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.wordBreak(getTestModel.s, getTestModel.wordDict);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ����2
    /// </summary>
    class Word_Break_II
    {
#pragma region Model
    public:
        class Word_Break_II_Model
        {
        public:
            string s;
            vector<string> wordDict;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� : �ݭn�Q�λ��j�A��X�Ҧ��i�઺�զX�A�x���I�O���j���W�h
        ///                �C���n��X�ŦX�����(�bwordDict)���A�M��N�ѤU���r���J���j���A����M������
        ///                �åB�ݭn�Τ@��HashTable�����w��쪺�r��A�קK���ƹB��
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 8.2 MB Beats 14.19 %
        /// </summary>
        /// <returns></returns>  
        unordered_map<string, vector<string>> _hash{};
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            return Find(s, wordDict);
        }

        vector<string> Find(string s, vector<string>& wordDict) {
            //1. �C�������[��hashTable�O�_�w����ơA�����ܤ����Ƭd��
            if (_hash.find(s) != _hash.end())
                return _hash[s];
            //2. �p�G�r��w�M���쩳�A��@�ӵ���""�r�šA�]���D�ػݨD�C�Ӧr���� ' '���j�A���̫�@�Ӥ���
            if (s.empty())
				return { "" };

            vector<string> result{};
            //3. �q�r���}�l��X�C�ӳ���ŦX���զ�
            for (auto& word : wordDict)
            {
                //4-1. ���ŦX���U�@��word
                if (s.substr(0, word.size()) != word)
                    continue;
                //4-2. s���쩳��Atemp�~�|���o���
                vector<string> temp = Find(s.substr(word.size()), wordDict);
                for (auto& item : temp)
                {
					result.push_back(word + (item.empty() ? "" : " ") + item);
                }
            }
            //5. �N���G�O���b _hash ��
            _hash[s] = result;
            return _hash[s];
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Word_Break_II_Model GetTestData001(void)
        {
            Word_Break_II_Model result;
            result.s = "catsanddog";
            result.wordDict = {"cat", "cats", "and", "sand", "dog"};
            return result;//expect:  ["cats and dog","cat sand dog"]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Word_Break_II_Model GetTestData002(void)
        {
            Word_Break_II_Model result;
            result.s = "pineapplepenapple";
            result.wordDict = { "apple","pen","applepen","pine","pineapple" };
            return result;//expect: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Word_Break_II_Model GetTestData003(void)
        {
            Word_Break_II_Model result;
            result.s = "catsandog";
            result.wordDict = { "cats","dog","sand","and","cat" };
            return result;//expect: []
        };

#pragma endregion TestData
    };
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

namespace Solution692
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0692.Top_K_Frequent_Words.cpp"
    using namespace Solution692;

    int main()
    {
        Solution692::Top_K_Frequent_Words useClass;
        Solution692::Top_K_Frequent_Words::Top_K_Frequent_Words_Model getTestModel = useClass.GetTestData001();
         vector<string> result = useClass.topKFrequent(getTestModel.words, getTestModel.k);

        getTestModel = useClass.GetTestData002();
        result = useClass.topKFrequent(getTestModel.words, getTestModel.k);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �ƦW�̰�(TOP) K �`�ε�
    /// </summary>
    class Top_K_Frequent_Words
    {
#pragma region Model
    public:
        class Top_K_Frequent_Words_Model
        {
        public:
            vector<string> words;
            int k;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            ����G�إߵL��hashMap�s��Ҧ�word���ƶq�A�M��b�ƧǥѦh�ܤ֪�words�A�̫�b���Xk �ƶq��words�X��
        ///        Runtime :    7 ms, faster than 99.11% of C++ online submissions for Top K Frequent Words.
        ///   Memory Usage : 12.4 MB,   less than 86.62% of C++ online submissions for Top K Frequent Words.
        ///Time complexity :
        /// <returns></returns>
        vector<string> topKFrequent(vector<string>& words, int k)
        {
            //1. �إߵL�Ǫ�hashMap�����C�Ӽƶq
            unordered_map<string, int> hashMap;
            for (const auto& word : words)
                hashMap[word]++;

            //2. �e��vector �s�񦳧Ǫ����
            vector<pair<string, int>> priority(hashMap.begin(), hashMap.end());

            auto compare = [](const pair<string, int>& lhs, const pair<string, int>& rhs) 
            {
                return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
            };

            nth_element(priority.begin(), priority.begin() + k, priority.end(), compare);
            sort(priority.begin(), priority.begin() + k, compare);

            vector<string> result(k);
            for (int i = 0; i < k; ++i) 
            {
                result[i] = move(priority[i].first);
            }

            return result;
        }
        
        /// <summary>
        /// �򥻫���A�e���z�Ѧ��Ŷ��į�t
        /// </summary>
        vector<string> topKFrequent2(vector<string>& words, int k)
        {
            unordered_map<string, int> hashMap;
            for (int index = 0; index < words.size(); index++)
            {
                hashMap[words[index]]++;
            }
            //map<typ1 , type2, ���>
            map<int, set<string>, greater<int>> sortVector;
            for (auto& item : hashMap)
            {
                sortVector[item.second].insert(item.first);
            }

            vector<string> result;
            for (auto& item : sortVector)
            {
                for (auto& innerItem : item.second)
                {
                    result.emplace_back(innerItem);
                    k--;
                    if (k == 0)
                        return result;
                }
            }

            return result;
        }     
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��2
        /// </summary>        
        Top_K_Frequent_Words_Model GetTestData001(void)
        {
            Top_K_Frequent_Words_Model result;
            vector<string> input = { "i","love","leetcode","i","love","coding" };
            result.words = input;
            result.k = 2;
            return result;//expect "i","love"
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Top_K_Frequent_Words_Model GetTestData002(void)
        {
            Top_K_Frequent_Words_Model result;
            vector<string> input = { "the","day","is","sunny","the","the","the","sunny","is","is" };
            result.words = input;
            result.k = 4;
            return result;//expect "the","is","sunny","day"

        };

#pragma endregion TestData
    };
}
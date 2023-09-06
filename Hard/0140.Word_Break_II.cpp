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
    /// 分詞2
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
        ///         思路 : 需要利用遞迴，找出所有可能的組合，困難點是遞迴的規則
        ///                每次要找出符合的單詞(在wordDict)中，然後將剩下的字串放入遞迴中，直到遍歷完畢
        ///                並且需要用一個HashTable紀錄已找到的字串，避免重複運算
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 8.2 MB Beats 14.19 %
        /// </summary>
        /// <returns></returns>  
        unordered_map<string, vector<string>> _hash{};
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            return Find(s, wordDict);
        }

        vector<string> Find(string s, vector<string>& wordDict) {
            //1. 每次都先觀察hashTable是否已有資料，有的話不重複查詢
            if (_hash.find(s) != _hash.end())
                return _hash[s];
            //2. 如果字串已遍歷到底，放一個結束""字符，因為題目需求每個字詞用 ' '分隔，但最後一個不用
            if (s.empty())
				return { "" };

            vector<string> result{};
            //3. 從字典表開始找出每個單詞符合的組成
            for (auto& word : wordDict)
            {
                //4-1. 不符合跳下一個word
                if (s.substr(0, word.size()) != word)
                    continue;
                //4-2. s走到底後，temp才會取得到值
                vector<string> temp = Find(s.substr(word.size()), wordDict);
                for (auto& item : temp)
                {
					result.push_back(word + (item.empty() ? "" : " ") + item);
                }
            }
            //5. 將結果記錄在 _hash 中
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
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
    /// 回文劃分
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
        ///         思路 ：利用DFS不斷遞迴，從s[0]開始探索，將s[Index] 的回文字串全部找出放進結果中
        ///      Runtime :   86 ms Beats 98.89 %
        /// Memory Usage : 49.2 MB Beats 86.2 %
        /// </summary>
        /// <returns></returns>        
        vector<vector<string>> _result;
        vector<vector<string>> partition(string s) {
            _result = vector<vector<string>>();
            vector<string> compose;
            //1. 從s[0]開始探索
            FindCompseByDFS(0, s, compose);
            return _result;
        }

        void FindCompseByDFS(int index, string& s, vector<string>& compose) 
        {            
            //4. 跳出條件是當前探索到終點了，此時compose組成的字串紀錄
            if (index == s.size()) {
                _result.push_back(compose);
                return;
            }

            //2. 不斷遍歷字串由某個char 往左右擴增，若符合回文的則記錄
            for (int innerIndex = index; innerIndex < s.length(); innerIndex++)
            {
                //3-1. 檢查前、後索引是否回文
                if (IsPalindrome(s, index, innerIndex))
                {
                    //3-2. 回文則紀錄，並且往下繼續進行DFS探索
                    compose.push_back(s.substr(index, innerIndex - index + 1));
                    FindCompseByDFS(innerIndex + 1, s, compose);
                    //3-3. 若走到底 or 後續探索為非回文，則會將當前作後一個compose移除，再繼續探索另一個innerIndex(後索引)
                    compose.pop_back();
                }
            }
        }

        //檢查回文
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
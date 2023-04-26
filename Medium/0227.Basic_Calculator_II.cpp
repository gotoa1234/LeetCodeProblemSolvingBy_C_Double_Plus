#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

namespace Solution227
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0227.Basic_Calculator_II.cpp"
    using namespace Solution227;

    int main()
    {
        Solution227::Basic_Calculator_II useClass;
        Solution227::Basic_Calculator_II::Basic_Calculator_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.calculate(getTestModel.s);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.calculate(getTestModel.s);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.calculate(getTestModel.s);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 基本計算機
    /// </summary>
    class Basic_Calculator_II
    {
#pragma region Model
    public:
        class Basic_Calculator_II_Model
        {
        public:
            string s;            
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：重點有2個 
        ///                1. 運算規則先* / 後 + - 最後要注意是否走到最後一個字元
        ///                2. 有可能出現連線的數值，要進行*10的累進計算
        ///      Runtime :  10 ms Beats 97.59 %
        /// Memory Usage : 9.5 MB Beats 96.29 %
        /// </summary>
        /// <returns></returns>        
        int calculate(string s) {
            long result=0;
            long currentResult = 0;
            long tempValue = 0;
            long strLength = s.size();
            char lastOpeatorChar = '+';
            //1. 遍歷字串的字元
            for (int index = 0; index < strLength; index++) 
            {
                char currenChar = s[index];
                //2-1. 數值要做累計，如果有連續數EX:42 => tempValue 前一次數值會是4 本次就會是tempvalue = 4 * 10 + 2
                if (currenChar >= '0' && currenChar <= '9') 
                    tempValue = tempValue * 10 + currenChar - '0';   
                //2-2. 字元為運算子，或走到底 
                if (currenChar == '+' || currenChar == '-' || currenChar == '*' || currenChar == '/' || index == strLength - 1) 
                {
                    //3-1. 遇到預算原將自己的值做計算
                    if(lastOpeatorChar == '+')
                        currentResult += tempValue;
                    else if (lastOpeatorChar == '-')
                        currentResult -= tempValue;
                    else if (lastOpeatorChar == '*')
                        currentResult *= tempValue;
                    else if (lastOpeatorChar == '/')
                        currentResult /= tempValue;

                    //3-2. 若為+ - 時或走到底將當前的運算結果累進至真實的結果Result中
                    //     ※若為* / 則可以發現會把currentResult保留，完成先* / 後加減的規則
                    if (currenChar == '+' || 
                        currenChar == '-' || 
                        index == strLength - 1) 
                    {
                        result += currentResult;
                        currentResult = 0;
                    }
                    //3-3. 當前為運算元必紀錄最後一次的運算元
                    lastOpeatorChar = currenChar;
                    tempValue = 0;
                }
            }            
            return result;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Basic_Calculator_II_Model GetTestData001(void)
        {
            Basic_Calculator_II_Model result;
            result.s = "3+2*2";
            return result;//expect: 7
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Basic_Calculator_II_Model GetTestData002(void)
        {
            Basic_Calculator_II_Model result;
            result.s = "3/2 ";
            return result;//expect: 1
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Basic_Calculator_II_Model GetTestData003(void)
        {
            Basic_Calculator_II_Model result;
            result.s = " 3+5 / 2 ";
            return result;//expect: 5
        };

#pragma endregion TestData
    };
}
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution202
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Easy/0202.Happy_Number.cpp"
    using namespace Solution202;

    int main()
    {
        Solution202::Happy_Number useClass;
        Solution202::Happy_Number::Happy_Number_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.isHappy(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isHappy(getTestModel.nums);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 快樂的號碼
    /// </summary>
    class Happy_Number
    {
#pragma region Model
    public:
        class Happy_Number_Model
        {
        public:
            int n;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：依照題目意思，當進入無窮迴圈時跳出，利用一個HashTable紀錄查過的值，如果後續發現已經查過，表示可以跳出
        ///                否則一值計算到算出1為止
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 6.1 MB Beats 55.13 %
        /// </summary>
        /// <returns></returns>        
        bool isHappy(int n) {
            //1. 回查是否重複用
            unordered_map<int, bool> _hashMap{};
            int caculation = -1;
            while (true)
            {
                //2. 依照公式計算快樂的號碼
                caculation = 0;
                while (n > 0)
                {
                    caculation += (n % 10) * (n % 10);
                    n /= 10;
                }
                n = caculation;
                //3. 跳出條件只有兩個，其他情況都是拿計算出的數值重複運算
                if (caculation == 1)
                    return true;
                if (_hashMap.count(caculation))
                    return false;
                _hashMap[n] = true;
            }
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Happy_Number_Model GetTestData001(void)
        {
            Happy_Number_Model result;
            result.n = 19;
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Happy_Number_Model GetTestData002(void)
        {
            Happy_Number_Model result;
            result.n = 2;
            return result;//expect:  false
        };
#pragma endregion TestData
    };
}
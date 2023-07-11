#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution204
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0204.Count_Primes.cpp"
    using namespace Solution204;

    int main()
    {
        Solution204::Count_Primes useClass;
        Solution204::Count_Primes::Count_Primes_Model getTestModel = useClass.GetTestData2();
        auto result = useClass.countPrimes(getTestModel.grid);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.countPrimes(getTestModel.grid);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.countPrimes(getTestModel.grid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 計算(質數)素數
    /// </summary>
    class Count_Primes
    {
#pragma region Model
    public:
        class Count_Primes_Model
        {
        public:
            int n;            
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 由小而大到指定的數N遍歷，並且跳過偶數，並將當前質數的乘積~N標記為非質數，
        ///                每次往下一個質數判斷時可以快速知道當前是否為質數，為質數時Count數量+1
        ///      Runtime:   165 ms Beats 98.15 %
        /// Memory Usage : 10.2 MB Beats 92.60 %
        int countPrimes(int n) {
            if (n <= 2)
                return 0;
            int resultCount = 1;
            //1. 配置n的空間，先設為false
            vector<bool> primesArray(n, false);
            
            //2-1. 由3開始，遍歷到n，其中偶數(2,4,6,8)必定非質數，可以省略
            for (int currentNum = 3; currentNum < n; currentNum += 2) 
            {
                //2-2. 如果已經被標記表示非質數，可跳過
                if (primesArray[currentNum])
                    continue;
                //3. 此數先標記為質數，並且 此數~N 之間的乘積都標記上非質數(true)
                resultCount++;
				for (int innerIndex = 3; innerIndex * currentNum < n; innerIndex += 2)
                {
                    primesArray[currentNum * innerIndex] = true;
                }
            }
            return resultCount;
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Count_Primes_Model GetTestData001(void)
        {
            Count_Primes_Model result;
            result.n = 10;
            return result;
            //Expect: 4
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Count_Primes_Model GetTestData002(void)
        {
            Count_Primes_Model result;
            result.n = 0;
            return result;
            //Expect:0
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Count_Primes_Model GetTestData003(void)
        {
            Count_Primes_Model result;
            result.n = 1;
            return result;
            //Expect:0
        };
#pragma endregion TestData
    };
}
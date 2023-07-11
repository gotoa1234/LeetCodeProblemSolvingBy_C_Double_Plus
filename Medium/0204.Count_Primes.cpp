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
    /// �p��(���)����
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
        ///         ��� : �Ѥp�Ӥj����w����N�M���A�åB���L���ơA�ñN��e��ƪ����n~N�аO���D��ơA
        ///                �C�����U�@�ӽ�ƧP�_�ɥi�H�ֳt���D��e�O�_����ơA����Ʈ�Count�ƶq+1
        ///      Runtime:   165 ms Beats 98.15 %
        /// Memory Usage : 10.2 MB Beats 92.60 %
        int countPrimes(int n) {
            if (n <= 2)
                return 0;
            int resultCount = 1;
            //1. �t�mn���Ŷ��A���]��false
            vector<bool> primesArray(n, false);
            
            //2-1. ��3�}�l�A�M����n�A�䤤����(2,4,6,8)���w�D��ơA�i�H�ٲ�
            for (int currentNum = 3; currentNum < n; currentNum += 2) 
            {
                //2-2. �p�G�w�g�Q�аO��ܫD��ơA�i���L
                if (primesArray[currentNum])
                    continue;
                //3. ���ƥ��аO����ơA�åB ����~N ���������n���аO�W�D���(true)
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
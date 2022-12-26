#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution77
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0077.Combinations.cpp"
    using namespace Solution77;

    int main()
    {
        Solution77::Combinations useClass;
        Solution77::Combinations::Combinations_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.combine(getTestModel.n, getTestModel.k);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.combine(getTestModel.n, getTestModel.k);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �զX
    /// </summary>
    class Combinations
    {
#pragma region Model
    public:
        class Combinations_Model
        {
        public:
            int n;
            int k;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G
        ///      Runtime :   3 ms Beats 100 %
        /// Memory Usage : 9.9 MB Beats 54.70 %
        /// </summary>
        /// <returns></returns>  
        vector<vector<int>> _result;
        vector<vector<int>> combine(int n, int k) {
			//1. �إߤ@�Ӳզ����G���e��
			vector<int> combination;
            //2. ���j
			solve(combination, 1, n, k, 0);
			return _result;
        }

        void solve(vector<int>& combination, int currentValue, const int& n, const int& k, int count) {
            
            //3-1. �C���i�J���P�_�O�_�֭p���զ���k ��ܹF�춵�ؼ�
            if (count == k) 
            {
                //4. �[�J�쵲�G�� 
                _result.push_back(combination);
                return;
            }
            //3-2. �_�h�C�����i�滼�j
            for (int index = currentValue; index <= n - k + count + 1; index++) 
            {
                combination.push_back(index);
                solve(combination, index + 1, n, k, count + 1);
                combination.pop_back();
            }
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Combinations_Model GetTestData001(void)
        {
            Combinations_Model result;
            result.n = 4;
            result.k = 2;
            return result;//expect:  [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Combinations_Model GetTestData002(void)
        {
            Combinations_Model result;
            result.n = 1;
            result.k = 1;
            return result;//expect:[[1]]
        };

#pragma endregion TestData
    };
}
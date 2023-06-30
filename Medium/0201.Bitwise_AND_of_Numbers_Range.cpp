#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution201
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0201.Bitwise_AND_of_Numbers_Range.cpp"
    using namespace Solution201;
    
    int main()
    {
        Solution201::Bitwise_AND_of_Numbers_Range useClass;
        Solution201::Bitwise_AND_of_Numbers_Range::Bitwise_AND_of_Numbers_Range_Model getTestModel = useClass.GetTestData2();
        int result = useClass.numIslands(getTestModel.grid);
    
        getTestModel = useClass.GetTestData002();
        result = useClass.numIslands(getTestModel.grid);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// ���줸�AAND�޿�h�Ʀr�d��
    /// </summary>
    class Bitwise_AND_of_Numbers_Range
    {
#pragma region Model
    public:
        class Bitwise_AND_of_Numbers_Range_Model
        {
        public:
            int left;
            int right;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         ��� : �Nleft �Pright ��X�V�k�첾������(���P�h�V�k)�A������X��A�̷Ӧ��ư�2bit �i��첾
        ///         �D�N : ���wleft �P right �M���X�����Ҧ���2�i�AND �̫᪺�Ȭ��h��
        ///          EX  : [5, 7]  101
        ///                        110
        ///                        111
        ///                  ���G��100 �N�O4
        ///      Runtime: 
        /// Memory Usage :
        int rangeBitwiseAnd(int left, int right) {
            int count = 0;
            while (left != right) {
                left = left >> 1;
                right = right >> 1;
                count++;
            }
            return (left << count);
        }
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Bitwise_AND_of_Numbers_Range_Model GetTestData001(void)
        {
            Bitwise_AND_of_Numbers_Range_Model result;
            result.left = 5;
            result.right = 7;            
            return result;
            //Expect: 4
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Bitwise_AND_of_Numbers_Range_Model GetTestData002(void)
		{
			Bitwise_AND_of_Numbers_Range_Model result;
            result.left = 0;
            result.right = 0;
			return result;
            //Expect:0
		};
#pragma endregion TestData
    };
}
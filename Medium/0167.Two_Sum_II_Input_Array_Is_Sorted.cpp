#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution167
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0167.Two_Sum_II_Input_Array_Is_Sorted.cpp"
    using namespace Solution167;

    int main()
    {
        Solution167::Two_Sum_II_Input_Array_Is_Sorted useClass;
        Solution167::Two_Sum_II_Input_Array_Is_Sorted::Two_Sum_II_Input_Array_Is_Sorted_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.twoSum(getTestModel.numbers, getTestModel.target);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.twoSum(getTestModel.numbers, getTestModel.target);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.twoSum(getTestModel.numbers, getTestModel.target);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ��өM II - ��J�Ʋդw�Ƨ�
    /// </summary>
    class Two_Sum_II_Input_Array_Is_Sorted
    {
#pragma region Model
    public:
        class Two_Sum_II_Input_Array_Is_Sorted_Model
        {
        public:
            vector<int> numbers;
            int target;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ����G�D�ئ��S�O�n�D�Ŷ������סA�]�������HashTable�A²�檺TimeSpace(N) �N�O�q�̥����ޥ[�W�̥k���ޡA
        ///               �[�_�Ӥp��target �����ީ��k�A�Ϥ��h�k���ީ���        
        ///         �n�D�G Space(1) 
        ///      Runtime�G  15 ms Beats 62.32 %
        /// Memory Usage�G15.5 MB Beats 74.35 %
        /// </summary>
        /// <returns></returns>
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int leftIndex = 0;
            int rightIndex = numbers.size() - 1;
            int caculation = 0;
            while (leftIndex < rightIndex)
            {
                caculation = numbers[leftIndex] + numbers[rightIndex];
                if (caculation == target)
                    return { leftIndex + 1, rightIndex + 1 };
                else if (caculation < target)
                    leftIndex++;
                else
                    rightIndex--;
            }
            return {};
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Two_Sum_II_Input_Array_Is_Sorted_Model GetTestData001(void)
        {
            Two_Sum_II_Input_Array_Is_Sorted_Model result;
            result.numbers.push_back(2);
            result.numbers.push_back(7);
            result.numbers.push_back(11);
            result.numbers.push_back(15);

            result.target = 9;
            return result;//expect: 1, 2
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Two_Sum_II_Input_Array_Is_Sorted_Model GetTestData002(void)
        {
            Two_Sum_II_Input_Array_Is_Sorted_Model result;
            result.numbers.push_back(2);
            result.numbers.push_back(3);
            result.numbers.push_back(4);            

            result.target = 6;
            return result;//expect: 1, 3
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Two_Sum_II_Input_Array_Is_Sorted_Model GetTestData003(void)
        {
            Two_Sum_II_Input_Array_Is_Sorted_Model result;
            result.numbers.push_back(-1);
            result.numbers.push_back(0);
            result.target = -1;
            return result;//expect: 1, 2
        };

#pragma endregion TestData
    };
}
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution75
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0075.Sort_Colors.cpp"
    using namespace Solution75;

    int main()
    {
        Solution75::Sort_Colors useClass;
        Solution75::Sort_Colors::Sort_Colors_Model getTestModel = useClass.GetTestData001();
        useClass.sortColors(getTestModel.nums);

        getTestModel = useClass.GetTestData002();
        useClass.sortColors(getTestModel.nums);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �Ƨ��C��
    /// </summary>
    class Sort_Colors
    {
#pragma region Model
    public:
        class Sort_Colors_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q�Υu���T�ӭȪ��S�ʡA0��b�}�C�̥���A2��b�̥k��A1���n��
        ///                ����_�l����0 �A�C���@�ӭȮɻ��W����
        ///                �k��_�l����nums.size()-1 �A�C���@�ӭȮɻ����
        ///                ��M���ɹJ��k����ު�ܨ���I�F(�k����ެO2�A��ܥk�䱵�U�ӳ��O2�i�H���L)
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 8.2 MB Beats 91.39 %
        /// </summary>
        /// <returns></returns>
        void sortColors(vector<int>& nums) 
        {
            int left = 0, right = (int)nums.size() - 1;
            //1.�M��
            for (int index = 0; index <= right; index++) 
            {
                //2-1. �B�z0�����p
                if (nums[index] == 0) 
                {
                    swap(nums[index], nums[left]);
                    left++;//����ϥ�+1
                }
                else if (nums[index] == 2) //2-2. �B�z2�����p
                {
                    swap(nums[index], nums[right]);
                    right--;//�k��ϥ�-1
                    index--;//�o��index-- => �]���P�̥k��洫�ȡA�Ӧ�m�����٭n�A�ˬd�@��
                }
            }
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Sort_Colors_Model GetTestData001(void)
        {
            Sort_Colors_Model result;
            result.nums = { 2, 0, 2, 1, 1, 0 };
            return result;//expect: [0, 0, 1, 1, 2, 2]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Sort_Colors_Model GetTestData002(void)
        {
            Sort_Colors_Model result;
            result.nums = {1, 2, 0 };
            return result;//expect: [0, 1, 2]
        };
#pragma endregion TestData
    };
}
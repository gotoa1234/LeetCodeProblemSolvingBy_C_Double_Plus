#include <iostream>
#include <vector>
using namespace std;

namespace Solution4
{
#pragma region Paste to execute 
    /*
    #include "0004_Median_of_Two_Sorted_Arrays.cpp"
    using namespace Solution4;

    Solution4::Median_of_two_sorted_arrays useClass;
    Solution4::Median_of_two_sorted_arrays::Median_of_two_sorted_arrays_Model getTestModel = useClass.GetTestData001();
    double result = useClass.findMedianSortedArrays(getTestModel.nums1, getTestModel.nums2);
    */
#pragma endregion Paste to execute

    /// <summary>
    /// ��Ӱ}�C������� -�n�D�į� O(log (m+n))
    /// <para>����G�]���}�C�Ҥw�g�Ƨǧ����A�H�䤤�@��Array����ǡA�q�Ӱ}�C�����ȻP�t�@�}�C�����Ȱ�����A�z�L�첾���ޭȨD�o�����</para>
    /// </summary>
    class Median_of_two_sorted_arrays
    {
#pragma region Model
    public:
        class Median_of_two_sorted_arrays_Model
        {
        public:
            vector<int> nums1;
            vector<int> nums2;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        /// ������ƽd��
        /// </summary>
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

            if ((nums1.size() + nums2.size()) % 2 == 1)
            {
                return FindArrayMiddleNumberValue(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
            }
            return (FindArrayMiddleNumberValue(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1) +
                FindArrayMiddleNumberValue(nums1, nums2, (nums1.size() + nums2.size()) / 2)
                ) / 2.0;
        }
    private:
        double FindArrayMiddleNumberValue(vector<int>& array1, vector<int>& array2, int searchMiddleIndex)
        {
            //�Ϊ����εu�}�C���䤤�@�Ӭ��߰��I
            int array1Count = array1.size();
            int array2Count = array2.size();

            if (array1Count > array2Count)
            {
                return FindArrayMiddleNumberValue(array2, array1, searchMiddleIndex);
            }

            int searchMiddleCount = searchMiddleIndex - 1;
            int left = 0, right = array1Count;
            while (left < right)
            {
                int mid = left + (right - left) / 2;

                if (0 <= searchMiddleCount - mid &&
                    searchMiddleCount - mid < array2Count &&
                    array1[mid] >= array2[searchMiddleIndex - 1 - mid])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            int array1Value = left - 1 >= 0 ? array1[left - 1]
                : numeric_limits<int>::min();
            int array2Value = searchMiddleCount - left >= 0 ? array2[searchMiddleCount - left]
                : numeric_limits<int>::min();

            return max(array1Value, array2Value);
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Median_of_two_sorted_arrays_Model GetTestData001(void)
        {
            Median_of_two_sorted_arrays_Model result;
            result.nums1.push_back(1);
            result.nums1.push_back(3);

            result.nums2.push_back(2);
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Median_of_two_sorted_arrays_Model GetTestData002(void)
        {
            Median_of_two_sorted_arrays_Model result;
            result.nums1.push_back(1);
            result.nums1.push_back(2);

            result.nums2.push_back(3);
            result.nums2.push_back(4);
            return result;
        };
#pragma endregion TestData
    };
}
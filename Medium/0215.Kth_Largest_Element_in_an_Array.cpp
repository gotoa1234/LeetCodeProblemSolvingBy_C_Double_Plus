#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

namespace Solution215
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "Medium\0215.Kth_Largest_Element_in_an_Array.cpp"
    using namespace Solution215;

    int main()
    {
        Solution215::Kth_Largest_Element_in_an_Array useClass;
        Solution215::Kth_Largest_Element_in_an_Array::Kth_Largest_Element_in_an_Array_Model getTestModel = useClass.GetTestData2();
        auto result1 = useClass.findKthLargest(getTestModel.nums, getTestModel.k);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.findKthLargest(getTestModel.nums, getTestModel.k);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 數組中的第 K 大元素
    /// </summary>
    class Kth_Largest_Element_in_an_Array
    {
#pragma region Model
    public:
        class Kth_Largest_Element_in_an_Array_Model
        {
        public:
            vector<int> nums;
            int k;
        };
#pragma endregion Model

#pragma region Main
    public:
        ///         思路 : 
        ///         題目 : 要求不排序解決此問題
        ///      Runtime :   43 ms Beats 99.99 %
        /// Memory Usage : 45.3 MB Beats 98.65 %
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();

            if (n == 0)
                return INT_MIN;

            int start = 0, end = n - 1, res;

            srand(time(NULL));

            while (start <= end) {

                int randomIndex = start + rand() % (end - start + 1);
                swap(nums[start], nums[randomIndex]);

                int pivot = partition(nums, start, end);
                int countGreaterOrEqual = n - pivot;

                if (countGreaterOrEqual >= k) {
                    res = nums[pivot];
                    start = pivot + 1;
                }
                else
                    end = pivot - 1;
            }

            return res;
        }

        //分割部分
        int partition(vector<int>& nums, int start, int end) {

            int pivotElement = nums[start], countSmaller = 0, left = start + 1, right = end;

            while (left <= right) {
                if (nums[left] <= pivotElement) {
                    left++;
                    countSmaller++;
                }
                else if (nums[right] > pivotElement) {
                    right--;
                }
                else {
                    swap(nums[left], nums[right]);
                }
            }

            int pivot = start + countSmaller;
            swap(nums[start], nums[pivot]);

            return pivot;
        }

        /// <summary>
        /// 排序的解法        
        ///      Runtime : 83 ms Beats 97.53 %
        /// Memory Usage : 45.4 MB Beats 85.7 %
        /// </summary>
        int findKthLargest_Sotr(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            return nums[k];            
        }

    private:
#pragma endregion Main

#pragma region TestData
        /// <summary>
        /// test 1
        /// </summary>        
        Kth_Largest_Element_in_an_Array_Model GetTestData001(void)
        {
            Kth_Largest_Element_in_an_Array_Model result;
            result.nums = { 3,2,1,5,6,4 };
            result.k = 2;
            return result;//Expect: 5
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Kth_Largest_Element_in_an_Array_Model GetTestData002(void)
        {
            Kth_Largest_Element_in_an_Array_Model result;
            result.nums = { 3,2,3,1,2,4,5,5,6 };
            result.k = 4;
            return result;
            //Expect:4
        };
#pragma endregion TestData
    };
}
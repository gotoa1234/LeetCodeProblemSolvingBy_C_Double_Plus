#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <deque>
#include <map>
using namespace std;

namespace Solution436
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0436.Find_Right_Interval.cpp"
    using namespace Solution436;

    int main()
    {
        Solution436::Find_Right_Interval useClass;
        Solution436::Find_Right_Interval::Find_Right_Interval_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.findRightInterval(getTestModel.intervals);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.findRightInterval(getTestModel.intervals);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.findRightInterval(getTestModel.intervals);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 加數
    /// </summary>
    class Find_Right_Interval
    {
#pragma region Model
    public:
        class Find_Right_Interval_Model
        {
        public:
            vector<vector<int>> intervals;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///        think :需要用有序的map (Hash)來達成，並且使用lower_bound找出map中等於(找不到才接近大於)的數值
        ///      Runtime :  62 ms Beats 76.44 %
        /// Memory Usage :28.5 MB Beats 31.90 %
        /// </summary>
        /// <returns></returns>        
        vector<int> findRightInterval(vector<vector<int>>& intervals) {
            vector<int> result{};
            map<int, int> _startIndexHash{};
            //1. 有序HashTable紀錄每個起點的對應索引
            for (int index = 0; index < intervals.size(); index++)
            {
                _startIndexHash[intervals[index][0]] = index;
            }
            //2. 判斷end是否有在某個Hash中的Key
            for (int index = 0; index < intervals.size(); index++)
            {
                //2-1. 會找出等於(沒有會找大於接近)的Key
                auto findIt = _startIndexHash.lower_bound(intervals[index][1]);
                //3-1. 沒找到大於等於的Key設為-1 (表示小於不符合規則)
                if (findIt == _startIndexHash.end())
                {
                    result.push_back(-1);
                }
                else//3-2. 找到大於等於則將對應的索引位置填入
                {
                    result.push_back(findIt->second);
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
        Find_Right_Interval_Model GetTestData001(void)
        {
            Find_Right_Interval_Model result;
			result.intervals = { {1, 2} };
            return result;//expect: {-1}
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Find_Right_Interval_Model GetTestData002(void)
        {
            Find_Right_Interval_Model result;
            result.intervals = { {3, 4}, {2,3},{1,2}};
            return result;//expect: [-1, 0, 1]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Find_Right_Interval_Model GetTestData003(void)
        {
            Find_Right_Interval_Model result;
            result.intervals = { {1, 4}, {2,3},{3, 4} };
            return result;//expect: [-1, 2, -1]
        };

        /// <summary>
        /// test 4
        /// </summary>   
        Find_Right_Interval_Model GetTestData004(void)
        {
            Find_Right_Interval_Model result;
            result.intervals = { {4, 5}, {2,3},{1, 2} };
            return result;//expect: [-1,0,1]
        };
#pragma endregion TestData
    };
}

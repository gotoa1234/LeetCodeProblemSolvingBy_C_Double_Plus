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
    /// �[��
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
        ///        think :�ݭn�Φ��Ǫ�map (Hash)�ӹF���A�åB�ϥ�lower_bound��Xmap������(�䤣��~����j��)���ƭ�
        ///      Runtime :  62 ms Beats 76.44 %
        /// Memory Usage :28.5 MB Beats 31.90 %
        /// </summary>
        /// <returns></returns>        
        vector<int> findRightInterval(vector<vector<int>>& intervals) {
            vector<int> result{};
            map<int, int> _startIndexHash{};
            //1. ����HashTable�����C�Ӱ_�I����������
            for (int index = 0; index < intervals.size(); index++)
            {
                _startIndexHash[intervals[index][0]] = index;
            }
            //2. �P�_end�O�_���b�Y��Hash����Key
            for (int index = 0; index < intervals.size(); index++)
            {
                //2-1. �|��X����(�S���|��j�󱵪�)��Key
                auto findIt = _startIndexHash.lower_bound(intervals[index][1]);
                //3-1. �S���j�󵥩�Key�]��-1 (��ܤp�󤣲ŦX�W�h)
                if (findIt == _startIndexHash.end())
                {
                    result.push_back(-1);
                }
                else//3-2. ���j�󵥩�h�N���������ަ�m��J
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

#include <vector>
#include <algorithm>
using namespace std;

namespace Solution1046
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include <algorithm>
    #include "1046.Last_Stone_Weight.cpp"
    using namespace Solution1046;

    int main()
    {
          Solution1046::Last_Stone_Weight useClass;
          Solution1046::Last_Stone_Weight::Last_Stone_Weight_Model getTestModel = useClass.GetTestData001();
          int result = useClass.lastStoneWeight(getTestModel.stones);
         
          getTestModel = useClass.GetTestData002();
          result = useClass.lastStoneWeight(getTestModel.stones);
          return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �̫᪺���Y���q
    /// </summary>
    class Last_Stone_Weight
    {
#pragma region Model
    public:
        class Last_Stone_Weight_Model
        {
        public:
            vector<int> stones;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            ����G���i��Ƨ�(�Q��QuickSort O(n * log n))�A�C���N�̤j���������Y���X�ۮ��A�Y���l�۩�^�}�C���A�A���Ƨ�
        ///                  �̫ᥲ�w�ѤU�@���ΨS�����Y�C
        ///        Runtime :   0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
        ///   Memory Usage : 7.5 MB,   less than 97.82 % of C++ online submissions for Last Stone Weight.
        ///Time complexity :
        /// <returns></returns>
        int lastStoneWeight(vector<int>& stones) 
        {
            int stone1{}, stone2{};
            sort(stones.begin(), stones.end());
            while (stones.size() >= 2)
            {
                stone1 = stones[stones.size() - 1];
                stone2 = stones[stones.size() - 2];
                if (stone1 == stone2)
                {
                    stones.pop_back();
                    stones.pop_back();
                }
                else
                {
                    stones.pop_back();
                    stones.pop_back();
                    stones.push_back(stone1 - stone2);
                    sort(stones.begin(), stones.end());
                }
            }
            return stones.size() > 0 ? stones[0] : 0;
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��2
        /// </summary>        
        Last_Stone_Weight_Model GetTestData001(void)
        {
            Last_Stone_Weight_Model result;
            vector<int> input = { 2, 7, 4, 1, 8, 1 };
            result.stones = input;
            return result; 
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Last_Stone_Weight_Model GetTestData002(void)
        {
            Last_Stone_Weight_Model result;
            vector<int> input = { 1 };
            result.stones = input;
            return result;

        };

#pragma endregion TestData
    };
}
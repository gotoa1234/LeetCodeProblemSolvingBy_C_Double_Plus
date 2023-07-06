#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution149
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0149.Max_Points_on_a_Line.cpp"
    using namespace Solution149;

    int main()
    {
        Solution149::Max_Points_on_a_Line useClass;
        Solution149::Max_Points_on_a_Line::Max_Points_on_a_Line_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.maxPoints(getTestModel.points);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.maxPoints(getTestModel.points);
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �̤j���I���@�u
    /// </summary>
    class Max_Points_on_a_Line
    {
#pragma region Model
    public:
        class Max_Points_on_a_Line_Model
        {
        public:
            vector<vector<int>> points;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Q�αײv�p��A�åB�Ҽ{�쪽�B��C
        ///      Runtime :   24 ms Beats 96.90 %
        /// Memory Usage : 10.2 MB Beats 82.22 %
        /// </summary>
        /// <returns></returns>        
        int maxPoints(vector<vector<int>>& points) {
            if (points.size() <= 2)
                return points.size();
            //1. �򥻴N�O2�I���� 
            int basePoints = 2;
            int maxCount = points.size();

            //2. �إ�Hash Map �����Y�ӱײv��X���ȬO�_�ۦP�A�ۦP�n�i��֥[
            unordered_map<float, int> hashMap = {};

            //3-1. �C���q�@�Ӯy���I���L�y���I�p��ײv�O�_�@�P
            for (int index = 0; index < maxCount; index++) 
            {
                hashMap.clear();
                //3-2. �ײv�����A�n�Ҽ{���u�P���u�����p
                for (int innerIndex = 0; innerIndex < index; innerIndex++) 
                {
                    if (index == innerIndex) 
                        continue;
                    float key = (float)(points[innerIndex][1] - points[index][1]) / (points[innerIndex][0] - points[index][0]);
                    if (isnan(key))//�ˬd�O�_�D�ƭ� (�B�z��u �X)
                        key = NAN;
                    if (isinf(key))//�ˬd�O�_�L���j (�B�z���u | )
                        key = INFINITY;
                    basePoints = max(basePoints, hashMap[key] + 2);
                    hashMap[key]++;
                }
            }
            //4. �N�Ҧ����ײv��諸���G��^(�̤j��)
            return basePoints;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Max_Points_on_a_Line_Model GetTestData001(void)
        {
            Max_Points_on_a_Line_Model result;
			result.points = { {1,1}, {2,2}, {3,3} };
            return result;//expect:3
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Max_Points_on_a_Line_Model GetTestData002(void)
        {
            Max_Points_on_a_Line_Model result;
			result.points = { {1,1}, {3,2}, {5,3},{4,1},{2,3},{1,4} };
            return result;//expect:4
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Max_Points_on_a_Line_Model GetTestData003(void)
        {
            Max_Points_on_a_Line_Model result;
			result.points = { {4, 5 },{4, -1 },{4, 0} };
            return result;//expect:3 ���p�G���ˬd�L���j �� �D�ƭ� �|�o����~������2
        };
#pragma endregion TestData
    };
}
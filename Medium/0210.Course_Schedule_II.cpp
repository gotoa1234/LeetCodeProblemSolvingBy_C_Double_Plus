#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

namespace Solution210
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0210.Course_Schedule_II.cpp"
    using namespace Solution210;

    int main()
    {
        Solution210::Course_Schedule_II useClass;
        Solution210::Course_Schedule_II::Course_Schedule_II_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.findOrder(getTestModel.numCourses, getTestModel.prerequisites);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.findOrder(getTestModel.numCourses, getTestModel.prerequisites);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �ƽ� II
    /// </summary>
    class Course_Schedule_II
    {
#pragma region Model
    public:
        class Course_Schedule_II_Model
        {
        public:
            int numCourses;
            vector<vector<int>> prerequisites;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         �D�ءG   numCourses �X�󥲭׽� �p�G��2 ��ܤ��Ѧ� 0,1 (2�ؽ�)
        ///               prerequisites ���M���� {1,0} ��ܭn��1 ���������� 0
        ///               �H�d�� test 01�ӻ��A�N�|�O [0 , 1] 
        ///               �����u����0 �M��b��1�A�̫�F�� 0,1 �ҵ{���ק�
        ///         ����G
        ///      Runtime�G
        /// Memory Usage�G
        /// </summary>
        /// <returns></returns>
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> result;
            queue<int> queueTemp;
            //1-1. �ؼХ��ת��ҵ{��
            vector<int> mainCourse(numCourses, 0);
            //1-2. �إ߬Y�ӽҵ{���X���Q��� <�ҵ{ , �Q����> 
            vector<vector<int>> graph(numCourses);
            for (int index = 0; index < prerequisites.size(); index++) {
                graph[prerequisites[index][1]].push_back(prerequisites[index][0]);
                mainCourse[prerequisites[index][0]]++;
            }
            //1-3. ��X�ثe�i�H���N��ת��� mainCourse[X]���Ȫ�ܳQ�e�m�n��XXX�Ҥ~��W�A�ҥH�S���Ȫ�ܥi�H�����W��
            for (int index = 0; index < numCourses; index++) 
            {
                if (mainCourse[index] == 0)
                    queueTemp.push(index);
            }
            while (!queueTemp.empty()) {
                int node = queueTemp.front();
                queueTemp.pop();
                result.push_back(node);
                for (auto child : graph[node]) 
                {
                    if (mainCourse[child]) 
                    {
                        mainCourse[child]--;
                        if (mainCourse[child] == 0) 
                        {
                            queueTemp.push(child);
                        }
                    }
                }
            }
            if (result.size() == numCourses) {
                return result;
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
        Course_Schedule_II_Model GetTestData001(void)
        {
            Course_Schedule_II_Model result;
            result.numCourses = 2;
            result.prerequisites = { {1,0} };
            return result;//expect: [0,1]
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Course_Schedule_II_Model GetTestData002(void)
        {
            Course_Schedule_II_Model result;
            result.numCourses = 4;
            result.prerequisites = { {1,0},{2,0},{3,1},{3,2} };        
            return result;//expect: [0,2,1,3]
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Course_Schedule_II_Model GetTestData003(void)
        {
            Course_Schedule_II_Model result;
            result.numCourses = 1;
            result.prerequisites = { };
            return result;//expect: [0]
        };
#pragma endregion TestData
    };
}
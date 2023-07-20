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
    /// 排課 II
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
        ///         題目：   numCourses 幾堂必修課 如果為2 表示今天有 0,1 (2種課)
        ///               prerequisites 先決條件 {1,0} 表示要修1 但必須先修 0
        ///               以範例 test 01來說，就會是 [0 , 1] 
        ///               ※我優先修0 然後在修1，最後達成 0,1 課程都修完
        ///         思路：
        ///      Runtime：
        /// Memory Usage：
        /// </summary>
        /// <returns></returns>
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> result;
            queue<int> queueTemp;
            //1-1. 目標必修的課程數
            vector<int> mainCourse(numCourses, 0);
            //1-2. 建立某個課程有幾次被選到 <課程 , 被選到數> 
            vector<vector<int>> graph(numCourses);
            for (int index = 0; index < prerequisites.size(); index++) {
                graph[prerequisites[index][1]].push_back(prerequisites[index][0]);
                mainCourse[prerequisites[index][0]]++;
            }
            //1-3. 找出目前可以任意選修的課 mainCourse[X]有值表示被前置要修XXX課才能上，所以沒有值表示可以直接上課
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
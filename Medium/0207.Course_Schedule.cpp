#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

namespace Solution207
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0207.Course_Schedule.cpp"
    using namespace Solution207;

    int main()
    {
        Solution207::Course_Schedule useClass;
        Solution207::Course_Schedule::Course_Schedule_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.canFinish(getTestModel.numCourses, getTestModel.prerequisites);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.canFinish(getTestModel.numCourses, getTestModel.prerequisites);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 排課
    /// </summary>
    class Course_Schedule
    {
#pragma region Model
    public:
        class Course_Schedule_Model
        {
        public:
            int numCourses;
            vector<vector<int>> prerequisites;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         題目：題目意思給定numCourses 一個正整數，表示今天給的課會再 0 ~ (numCourses-1) EX: 7 表示會有 0, 1,2,3,4,5,6 種課程。
        ///               是否給了prerequisites，可以把裡面的課程修完 prerequisites的每個值會是像{ 2,5 } 表示我要修2的課程前要先修完5
        ///               課程如一個有向圖沒有產生Circle表示可以修完回傳 true
        ///         思路： 建立一個主課被必修課依賴數的表，然後用queue將每個可利用課程消化主課，最後主客依賴的表都為0時，表示可完成修課(true)
        ///      Runtime： 17 ms Beats 92.44 %
        /// Memory Usage： 14 MB Beats 46.38 %
        /// </summary>
        /// <returns></returns>
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
        {
            //1. 建立變數有向圖graph 與 主修的課程mainCourese[] 預期每個課程最終都為0，才表示都修完課
            vector<vector<int>> graph(numCourses, vector<int>());
            vector<int> mainCourese(numCourses);
            //2. 將每個課程放進有向圖中，表示彼此課程間的關係
            for (auto item : prerequisites) 
            {
                //2-1. 課程間的關係，需先有item[1] 才可有item[0]
                graph[item[1]].push_back(item[0]);
                //2-2. 必修的主課累計，當此值增加時，表示有前置必修
                mainCourese[item[0]]++;
            }

            //3. 找出所有沒有前置的必修主課
            queue<int> queueBox;
            for (int index = 0; index < numCourses; index++) 
            {                
                if (mainCourese[index] == 0) 
                    queueBox.push(index);
            }

            //4. 開始將所有關係課程找出，在queueBox中的課程都是沒有前置的課程
            while (false == queueBox.empty()) 
            {
                //4-1. 逐一取出可利用課程
                int currentValue = queueBox.front(); queueBox.pop();
                //4-2. 每個可利用課程找出，使主課的必修課程減少
                for (auto item : graph[currentValue]) 
                {
                    mainCourese[item]--;
                    //4-3. 表示該主修課程沒有其他需要先修的課，變成可利用課程
                    if (mainCourese[item] == 0) 
                        queueBox.push(item);
                }
            }
            
            //5. 4.步驟將所有關係排除後，如果還有主修課程大於0，表示課程消化不了
            for (int index = 0; index < numCourses; index++) 
            {
                if (mainCourese[index] != 0) 
                    return false;
            }
            return true;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Course_Schedule_Model GetTestData001(void)
        {
            Course_Schedule_Model result;
            result.numCourses = 2;
			result.prerequisites = { {1,0} };
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Course_Schedule_Model GetTestData002(void)
        {
            Course_Schedule_Model result;
            result.numCourses = 2;
			result.prerequisites = { {1,0}, {0,1} };
            return result;//expect: false
        };
#pragma endregion TestData
    };
}
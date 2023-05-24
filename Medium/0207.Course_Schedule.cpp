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
    /// �ƽ�
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
        ///         �D�ءG�D�طN�䵹�wnumCourses �@�ӥ���ơA��ܤ��ѵ����ҷ|�A 0 ~ (numCourses-1) EX: 7 ��ܷ|�� 0, 1,2,3,4,5,6 �ؽҵ{�C
        ///               �O�_���Fprerequisites�A�i�H��̭����ҵ{�ק� prerequisites���C�ӭȷ|�O��{ 2,5 } ��ܧڭn��2���ҵ{�e�n���ק�5
        ///               �ҵ{�p�@�Ӧ��V�ϨS������Circle��ܥi�H�ק��^�� true
        ///         ����G �إߤ@�ӥD�ҳQ���׽Ҩ̿�ƪ���A�M���queue�N�C�ӥi�Q�νҵ{���ƥD�ҡA�̫�D�Ȩ̿઺����0�ɡA��ܥi�����׽�(true)
        ///      Runtime�G 17 ms Beats 92.44 %
        /// Memory Usage�G 14 MB Beats 46.38 %
        /// </summary>
        /// <returns></returns>
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
        {
            //1. �إ��ܼƦ��V��graph �P �D�ת��ҵ{mainCourese[] �w���C�ӽҵ{�̲׳���0�A�~��ܳ��ק���
            vector<vector<int>> graph(numCourses, vector<int>());
            vector<int> mainCourese(numCourses);
            //2. �N�C�ӽҵ{��i���V�Ϥ��A��ܩ����ҵ{�������Y
            for (auto item : prerequisites) 
            {
                //2-1. �ҵ{�������Y�A�ݥ���item[1] �~�i��item[0]
                graph[item[1]].push_back(item[0]);
                //2-2. ���ת��D�Ҳ֭p�A���ȼW�[�ɡA��ܦ��e�m����
                mainCourese[item[0]]++;
            }

            //3. ��X�Ҧ��S���e�m�����ץD��
            queue<int> queueBox;
            for (int index = 0; index < numCourses; index++) 
            {                
                if (mainCourese[index] == 0) 
                    queueBox.push(index);
            }

            //4. �}�l�N�Ҧ����Y�ҵ{��X�A�bqueueBox�����ҵ{���O�S���e�m���ҵ{
            while (false == queueBox.empty()) 
            {
                //4-1. �v�@���X�i�Q�νҵ{
                int currentValue = queueBox.front(); queueBox.pop();
                //4-2. �C�ӥi�Q�νҵ{��X�A�ϥD�Ҫ����׽ҵ{���
                for (auto item : graph[currentValue]) 
                {
                    mainCourese[item]--;
                    //4-3. ��ܸӥD�׽ҵ{�S����L�ݭn���ת��ҡA�ܦ��i�Q�νҵ{
                    if (mainCourese[item] == 0) 
                        queueBox.push(item);
                }
            }
            
            //5. 4.�B�J�N�Ҧ����Y�ư���A�p�G�٦��D�׽ҵ{�j��0�A��ܽҵ{���Ƥ��F
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
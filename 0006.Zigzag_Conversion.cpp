#include <iostream>
#include <vector>
using namespace std;

namespace Solution6
{
#pragma region Paste to execute 
    /*
    #include "0006.Zigzag_Conversion.cpp"
    #include <vector>
    using namespace Solution6;
    using namespace std;

    Solution6::convert useClass;
    Solution6::convert::Zigzag_Conversion_Model getTestModel = useClass.GetTestData001();
    string result = useClass.convert(getTestModel.s, getTestModel.numRows);
    */
#pragma endregion Paste to execute

    /// <summary>
    /// Z�r���ഫ - �����@�Ӧr�� + ��� �C �r�ꤤ�r���ƦC���ѤW�ܤU����w��ơA�M��A����V�W���1��A�̫�ѲĤ@�� ��̫�@�� �զ��s�r��
    /// </summary>
    class Zigzag_Conversion
    {
#pragma region Model
    public:
        class Zigzag_Conversion_Model
        {
        public:
            string s;
            int numRows;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        /// ����G��X�ƦC�W�h�A�u�ݹM���@���r��A�Y�i�F��O(n) ���į�
        ///      Runtime :  14 ms, faster than 68.09 % of C++ online submissions for Zigzag Conversion.
        /// Memory Usage : 8.2 MB,   less than 81.10 % of C++ online submissions for Zigzag Conversion.
        /// </summary>
        string convert(string s, int numRows) 
        {
            if (numRows <= 1)
            {
                return s;
            }

            string result;
            // ��X�g����
            int period = 2 * numRows - 2;

            // �C�檺�r��
            for (int index = 0; index < numRows; index++) 
            {               
                //���ʯ���
                int moveIndex = index;
                //���ʶ����
                int movePeriod = period - 2 * index;
                while (moveIndex < s.size()) 
                {
                    result.push_back(s[moveIndex]);
                    moveIndex += (index > 0 && index < numRows - 1) ? movePeriod : period;
                    movePeriod = period - movePeriod;
                }
            }

            return result;
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Zigzag_Conversion_Model GetTestData001(void)
        {
            Zigzag_Conversion_Model result;
            result.s = "PAYPALISHIRING";
            result.numRows = 3;

            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Zigzag_Conversion_Model GetTestData002(void)
        {
            Zigzag_Conversion_Model result;
            result.s = "PAYPALISHIRING";
            result.numRows = 4;

            return result;
        };
#pragma endregion TestData
    };
}
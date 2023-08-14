#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

namespace Solution306
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0306.Additive_Number.cpp"
    using namespace Solution306;

    int main()
    {
        Solution306::Additive_Number useClass;
        Solution306::Additive_Number::Additive_Number_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.isAdditiveNumber(getTestModel.num);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isAdditiveNumber(getTestModel.num);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �[��
    /// </summary>
    class Additive_Number
    {
#pragma region Model
    public:
        class Additive_Number_Model
        {
        public:
            string num;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///        think :�g���t��k�A��r��C������2�ӳ����A�åB�ۥ[�A����P�D�جۦP���u
        ///      Runtime : 0 ms Beats 100.0 %
        /// Memory Usage : 6 MB Beats 80.58 %
        /// </summary>
        /// <returns></returns>        
        bool isAdditiveNumber(string num) {
            //1. �M���Ҧ��Ʀr
            for (int index = 1; index < num.size(); index++)
            {
                //2-1. �����X�Ĥ@�Ӽƭ�
                string s1 = num.substr(0, index);
                if (s1.size() > 1 && s1[0] == '0') 
                    break;

                for (int innerIndex = index + 1; innerIndex < num.size(); innerIndex++)
                {
                    //2-2. �A���X�ĤG�Ӽƭ�
                    string s2 = num.substr(index, innerIndex - index);
                    if ((s2.size() > 1 && s2[0] == '0'))
                        break;
                    //2-3. �p��X�ĤT�Ӽƭ�
                    long d1 = stol(s1);
                    long d2 = stol(s2);
                    long next = d1 + d2;
                    string nextStr = to_string(next);
                    if (nextStr != num.substr(innerIndex, nextStr.length())) 
                        continue;
                    string allStr = s1 + s2 + nextStr;
                    //3. ���ƹB��Ĥ@+�ĤG����ĤT�Ӽƭ�
                    while (allStr.size() < num.size()) 
                    {
                        d1 = d2;
                        d2 = next;
                        next = d1 + d2;
                        nextStr = to_string(next);
                        allStr += nextStr;
                    }
                    //4. �p�G���Ҧ��r�굥���D�خɡA��ܬO�@��"�[��"
                    if (allStr == num) 
                        return true;
                }
            }
            return false;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Additive_Number_Model GetTestData001(void)
        {
            Additive_Number_Model result;
			result.num = "112358";
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Additive_Number_Model GetTestData002(void)
        {
            Additive_Number_Model result;
            result.num = "199100199";
            return result;//expect: true
        };

#pragma endregion TestData
    };
}

/*
Input: "112358"
Output: true
Explanation:
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation:
The additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199

*/
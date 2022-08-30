#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace Solution299
{
#pragma region Paste to execute 
    /*
    #include <vector>
    #include "0299.Bulls_and_Cows.cpp"
    using namespace Solution299;

    int main()
    {
        Solution299::Bulls_and_Cows useClass;
        Solution299::Bulls_and_Cows::Bulls_and_Cows_Model getTestModel = useClass.GetTestData001();
        string result = useClass.getHint(getTestModel.secret, getTestModel.guess);

        getTestModel = useClass.GetTestData002();
        result = useClass.getHint(getTestModel.secret, getTestModel.guess);
        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// �d��r�Ŧꤤ���Ҧ��r��
    /// </summary>
    class Bulls_and_Cows
    {
#pragma region Model
    public:
        class Bulls_and_Cows_Model
        {
        public:
            string secret;
            string guess;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///            ����G�Ψ�Ӱ}�C�A�M��guess �P secret �Y�ۦP�����޻P�Ʀr���A +1
        ///                  �_�h�����Ʀr�W�[1�A�̫�A�N��ӼƦr�}�C (0-9) �֪����ص���B
        ///         Runtime:   0 ms, faster than 100.00% of C++ online submissions for Bullsand Cows.
        ///   Memory Usage : 6.5 MB,   less than 94.86 % of C++ online submissions for Bullsand Cows.
        ///Time complexity :
        /// <returns></returns>
        string getHint(string secret, string guess) 
        {
            vector<int> secretCount(10, 0), guessCount(10, 0);
            int aCount = 0;
            int bCount = 0;
            for (int index = 0; index < guess.size(); index++)
            {
                if (guess[index] == secret[index])
                {
                    aCount++;
                }
                else
                {
					secretCount[secret[index] - '0']  ++;
                    guessCount[guess[index] - '0']++;
                }
            }
            for (int index = 0; index < 10; index++)
                bCount += min(guessCount[index], secretCount[index]);

            return to_string(aCount) + "A" + to_string(bCount) + "B";
        }
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��2
        /// </summary>        
        Bulls_and_Cows_Model GetTestData001(void)
        {
            Bulls_and_Cows_Model result;
            result.secret = "1807";
            result.guess = "7810";
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Bulls_and_Cows_Model GetTestData002(void)
        {
            Bulls_and_Cows_Model result;
            result.secret = "1123";
            result.guess = "0111";
            return result;

        };

#pragma endregion TestData
    };
}
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution135
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0135.Candy.cpp"
    using namespace Solution135;

    int main()
    {
        Solution135::Candy useClass;
        Solution135::Candy::Candy_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.candy(getTestModel.ratings);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.candy(getTestModel.ratings);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �}�G
    /// </summary>
    class Candy
    {
#pragma region Model
    public:
        class Candy_Model
        {
        public:
            vector<int> ratings;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         �D�ءG���w�@�Ӱ}�C���ơA�H�U�W�h
        ///               1. ��e���ޤ��Ƥj����A�h��e���ަh��1���}�G�A�_�h����
        ///               2. ��e���ޤ��Ƥj��k��A�h��e���ަA�h��1���}�G�A�_�h����
        ///               3. �C�ӤH���ܤ֦�1���}�G
        ///               4. ��Ĳ�o1.�B2. ����ɡA���F�h��1���}�G�~�A�٤�ݤ�����H�h1���}�G
        ///         ����G�����Ҧ�1���}�G�A�M�����O(2N) �ѥ��ܥk����A�M��A�ѥk��������A        
        ///      Runtime�G   18 ms Beats 91.33 %
        /// Memory Usage�G 17.7 MB Beats 60.87 %
        /// </summary>
        /// <returns></returns>        
        int candy(vector<int>& ratings) {
            int ratingLength = ratings.size();
            //1. �ư����έp�⪺���p
            if (ratingLength == 1)
                return 1;

            vector<int> candies(ratingLength, 1);
            //2-1. �B�z��e���޻P�e�ӯ��ު��p��
            for (int index = 1; index < ratingLength; index++) 
            {
                //2-2. �ŦX�����e��m���}�G�ƶq�n��e�ӯ��ަh1��
                if (ratings[index] > ratings[index - 1] && 
                    candies[index] <= candies[index - 1])
                    candies[index] = candies[index - 1] + 1;
            }

            //3-1.  �B�z��e���޻P�U�ӯ��ު��p��
            for (int index = ratingLength - 2; index >= 0; index--) 
            {
                //3-2. �ŦX�����e��m���}�G�ƶq�n��U�ӯ��ަh1��
                if (ratings[index] > ratings[index + 1] && 
                    candies[index] <= candies[index + 1])
                    candies[index] = candies[index + 1] + 1;
            }

            //4. �`�p�Ҧ��}�G���ƶq
            int totalCandies = 0;
            for (int index = 0; index < ratingLength; index++) {
                totalCandies += candies[index];
            }
            return totalCandies;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Candy_Model GetTestData001(void)
        {
            Candy_Model result;
            result.ratings = { 1, 0, 2 };
            return result;//expect: 5
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Candy_Model GetTestData002(void)
        {
            Candy_Model result;
            result.ratings = { 1, 2, 2 };
            return result;//expect: 4
        };

        
#pragma endregion TestData
    };
}
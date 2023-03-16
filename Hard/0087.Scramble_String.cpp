#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution87
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Hard/0087.Scramble_String.cpp"
    using namespace Solution87;

    int main()
    {
        Solution87::Scramble_String useClass;
        Solution87::Scramble_String::Scramble_String_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.isScramble(getTestModel.s1, getTestModel.s2);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isScramble(getTestModel.s1, getTestModel.s2);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.isScramble(getTestModel.s1, getTestModel.s2);
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// ���ܦr��
    /// </summary>
    class Scramble_String
    {
#pragma region Model
    public:
        class Scramble_String_Model
        {
        public:
            string s1;
            string s2;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ����G�Q�λ��j�A�C�����Ψ�զr��A�ä��� 1. ���Ϊ���զr���� 2. �U�@�����Ϊ���զr����
        ///               �åB�Τ@��HashTable ������զr��O�_�����ܳW�h�A�L�׬O�_�A���O���A�קK���ƹB��
        ///               �Y�̫ᦳ�o�{�䤤�@�Ӭ�true����D�ص���s1�Ps2���@�ӦX�k�����ܡC
        ///     �D�طN��G���w��Ӧr��: s1 ="great"; s2= "rgeat"; ��Ӫ��ץ��w�ۦP�A�B�r�ꥲ�w�p�g�r���A�B�u���@�Ӯt��
        ///                great         rgeat 
        ///                �� ��         �� ��
        ///              gre   at      rge   at
        ///             �� �� ����    �� �� ����
        ///            gr   e a  t   rg   e a  t 
        ///           ����          ����
        ///          g   r         r   g
        ///      ����s1��r�Pg �������� = rgeat  ���� s2��rgeat 
        ///      s1�u��"1"�����l��P�k�l��N�i�H�F�쵥��s2 �ҥH��^True�A�o�O�@�Ӫ��ܦr��
        ///      Runtime�G   8 ms Beats 95.8 %
        /// Memory Usage�G15.3 MB Beats 79.72 %
        /// </summary>
        /// <returns></returns>
        unordered_map<string, bool> hashMap;
        bool isScramble(string s1, string s2) 
        {
            //1-1. �p�G���Ϋ᪺s1 �P s2 ���ۦP�r���i�H�����s�b
            if (s1 == s2) {
                return true;
            }
            //1-2. �p�Ghash��w�g�s�b�A��ܨ�L�𦳭��|���r��զ��A�i�H���ٰO�����G�A���έ��ƻ��j
            else if (hashMap.count(s1 + s2))
                return hashMap[s1 + s2];
            //2. �إ�3�Ӥp�g�r����(26�ӭ^��r��)
            vector<int> s1AlphabetTable(26, 0);
            vector<int> s2AlphabetTable(26, 0);
            vector<int> diffAlphabetTable(26, 0);
            int splitIndex{};
            //3-1. �M��s1�r��
            for (int index = 1; index <= s1.size() - 1; index++)
            {
                //3-2. �����r���X�{���ơA�䤤diffAlphabetTable�����Φ�m���r��
                splitIndex = s1.size() - index;
                s1AlphabetTable[s1[index - 1] - 'a']++;
                s2AlphabetTable[s2[index - 1] - 'a']++;
                diffAlphabetTable[s2[splitIndex] - 'a']++;

                //3-3. �r��s1�Ps2���i��A�åB�P�_�O�_������
                if (s1AlphabetTable == s2AlphabetTable && 
                    isScramble(s1.substr(0, index), s2.substr(0, index)) && 
                    isScramble(s1.substr(index), s2.substr(index))) 
                {
                    hashMap[s1 + s2] = true;
                    return true;
                }
                //3-4. �r��s1�Ps2���Φr���m���i��A�åB�P�_�O�_������
                if (s1AlphabetTable == diffAlphabetTable && 
                    isScramble(s1.substr(0, index), s2.substr(splitIndex)) && 
                    isScramble(s1.substr(index), s2.substr(0, splitIndex))) 
                {
                    hashMap[s1 + s2] = true;
                    return true;
                }
            }
            //4. �p�G���S����쪧�ܡA�h�o��s1 + s2 ���O�@�Ӫ��ܦr���զ�
            hashMap[s1 + s2] = false;
            return false;
        }

    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Scramble_String_Model GetTestData001(void)
        {
            Scramble_String_Model result;
            result.s1 = "great";
            result.s2 = "rgeat";
            return result;//expect: true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Scramble_String_Model GetTestData002(void)
        {
            Scramble_String_Model result;
            result.s1 = "abcde";
            result.s2 = "caebd";
            return result;//expect: false
        };

        /// <summary>
        /// test 2
        /// </summary>
        Scramble_String_Model GetTestData003(void)
        {
            Scramble_String_Model result;
            result.s1 = "a";
            result.s2 = "a";
            return result;//expect: true
        };
#pragma endregion TestData
    };
}
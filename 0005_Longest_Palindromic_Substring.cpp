#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace Solution5
{
#pragma region Paste to execute 
    /*

    */
#pragma endregion Paste to execute

    /// <summary>
    /// �̪��^��l�r��A���w�@�Ӧr��A��X�^��
    /// �^��G�q�Y��� �P �����Y �r�곣�O�ۦP���A�N�O�^�� EX: aa�Babcba�Ba
    /// </summary>
    class Longest_Palindromic_Substring
    {
#pragma region Model
    public:
        class Longest_Palindromic_Substring_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
	public:
        /// <summary>
        /// ����G�^��Ѫk���u��: Manachers algorithm https://zh.wikipedia.org/zh-tw/%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2
        /// ����G²�u:��R�B��g�B��L���إ�Dynimic Programing����
        /// �į�G O(n)
        ///      Runtime :   4 ms, faster than 99.05 % of C++ online submissions for Longest Palindromic Substring.
        /// Memory Usage : 8.5 MB,   less than 64.33 % of C++ online submissions for Longest Palindromic Substring.
        /// <returns></returns>
        string longestPalindrome(string s) {
            int stringMaxLength = s.length();
            if (stringMaxLength <= 1)
            {
                return s;
            }

            //Step 1 : ��R�r��# - �ѨM�_���B�z
            string s2 = "#";
            for (int i = 0; i < stringMaxLength; i++)
            {
                s2.push_back(s[i]);
                s2.push_back('#');
            }

            //Step 2�G�v�B��X�d��
            int currentMaxIndex = 0;//��e�̤j�Ȫ����ަ�m
            int currentMax = 0;//��e�̤j�^���
            const int s2StringMaxLength = s2.size();
            vector<int> dynamicPrograming(s2StringMaxLength, 0);

            //s2[0] �O# �r���A�G�qindex = 1 �}�l
            for (int index = 1; index < s2StringMaxLength; index++)
            {
                int moveableIndex = 0;//�[��k��r�����ޡA���e�ݪ��ƶq
                if (index >= currentMax)
                {
                    moveableIndex = index + 1;
                }
                else//�i�J�����q currentMax �j�� index  ��ܤW�@�Ӧr�����[�\�j�d�򪺦^��
                {
                    //��g�����쪺����� 
                    int leftIndex = 2 * currentMaxIndex - index;
                    //��e���˯��r���^����ץi�H����g�X�� DP ���
                    dynamicPrograming[index] = min(currentMax - index, dynamicPrograming[leftIndex]);
                    //�p�G�k���DP�� �P �k���DP�� �ۦP or �k��ɶW�X�A�h�~��첾�[��O�_���s��
                    if (leftIndex - dynamicPrograming[leftIndex] <= currentMaxIndex - dynamicPrograming[currentMaxIndex])
                    {
                        moveableIndex = currentMax + 1;
                    }
                }

                //��X�^��A�åH���޳v�B�����k�X�j
                for (int leftIndex = 2 * index - moveableIndex, rightIndex = moveableIndex;
                    moveableIndex && moveableIndex < s2StringMaxLength && leftIndex >= 0;
                    leftIndex = 2 * index - moveableIndex, rightIndex = moveableIndex)
                {
                    if (s2[leftIndex] == s2[rightIndex])
                    {
                        dynamicPrograming[index]++;
                        moveableIndex++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                //��s�̤j�^��
                if (index + dynamicPrograming[index] > currentMax)
                {
                    currentMax = index + dynamicPrograming[index];
                    currentMaxIndex = index;
                }
            }
            
            //Step 3�G�˯��XDP�̭��̪����^�� �P �Ӧr���_�l���ަ�m
            int targeId = 0;
			for (int index = 1, maxlength = 0; index < s2StringMaxLength; index++)
			{
				if (dynamicPrograming[index] > maxlength)
				{
					maxlength = dynamicPrograming[index];
					targeId = index;
				}
			}

            //Step 4�G���L # �r���A�զ��^�쥻���^��l�r��
			string result;
            for (int Index = targeId - dynamicPrograming[targeId] + 1; 
                Index <= targeId + dynamicPrograming[targeId]; 
                Index += 2
                )
            {
                result.push_back(s2[Index]);
            }
            return result;
		};

    /// <summary>
    /// ����G�^��Ѫk�@��H�q��: �C�Ӧr���M���A�C���M���ɱN�r�� �ۤv + �U�@�ӡA��i�禡���A�Ӧr���������k���_�]������̪��^��
    /// �į�G O(n^2)
    ///      Runtime :  13 ms, faster than 94.30 % of C++ online submissions for Longest Palindromic Substring.
    /// Memory Usage : 6.9 MB,   less than 97.46 % of C++ online submissions for Longest Palindromic Substring.
    /// </summary>
    public:
        string longestPalindrome_Solution2(string s) {
            int maxSize = s.length();
            int resultIndex{};
            int resultCount{};

            for (int index{}; index < maxSize; index++) 
            {
                //����1: �����k�˯� => �_(�ۤv�������I) ; ��(�ۤv+�U�@�Ӧ�m)
                GetPalindromeString_Solution2(s, resultIndex, resultCount, index, index);
                GetPalindromeString_Solution2(s, resultIndex, resultCount, index, index + 1);

                //����2: �˯��L�{�����ܪ�����ơA�i�H�N���ް���I���̫᪺���ޫe�@�Ӧ�m�A�]�����q�w�g�b���׽d��
                //       �קK�L�ת��˯����O
                if ((resultIndex - 1) > index)
                {
                    //����I�i����
                    index = resultIndex - 1;
                }
            }
            return s.substr(resultIndex, resultCount);
        }
    private:
        void GetPalindromeString_Solution2(string& sourceString,
            int& resultIndex,
            int& resultCount,
            int startIndex, 
            int lastIndex)
        {
			for (; 0 <= startIndex && lastIndex < sourceString.size(); startIndex--, lastIndex++)
            {
                if (sourceString[startIndex] != sourceString[lastIndex])
                {
                    break;
                }
                if ((lastIndex - startIndex + 1) > resultCount)
                {
                    resultIndex = startIndex;
                    resultCount = (lastIndex - startIndex + 1);
                }
            }
        };
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// ���ո��1
        /// </summary>        
        Longest_Palindromic_Substring_Model GetTestData001(void)
        {
            Longest_Palindromic_Substring_Model result;
            result.s = "sadxaabacxcabaaxcabaax";// "babad";
            return result;
        };

        /// <summary>
        /// ���ո��2
        /// </summary>   
        Longest_Palindromic_Substring_Model GetTestData002(void)
        {
            Longest_Palindromic_Substring_Model result;
            result.s = "cbbd";
            return result;
        };
#pragma endregion TestData
    };
}
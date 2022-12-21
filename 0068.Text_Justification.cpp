#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution68
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0068.Text_Justification.cpp"
    using namespace Solution68;

    int main()
    {
        Solution68::Text_Justification useClass;
        Solution68::Text_Justification::Text_Justification_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.fullJustify(getTestModel.words, getTestModel.maxWidth);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.fullJustify(getTestModel.words, getTestModel.maxWidth);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.fullJustify(getTestModel.words, getTestModel.maxWidth);

        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// �奻���
    /// </summary>
    class Text_Justification
    {
#pragma region Model
    public:
        class Text_Justification_Model
        {
        public:
            vector<string> words; 
            int maxWidth;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         ��� �G�Ҧr���k�ǡA�D�n��2�ر���
        ///                a. 1�ӳ�� �P �̫�@�ճ�� �n�m�� - �C�ӳ�����u��1�Ӫťզr��
        ///                b. �h�ӳ���H�W�A�B�D�̫�@�ճ�� - �C�ӳ�����������ťզr���A�h���̧ǥѥ���2�ӳ����������
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 7.4 MB Beats 55.26 %
        /// <returns></returns>
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            
            vector<string> result{};
            int currentSpaceLength = 0;
            int peddingLength = 0;
            string lineMsg = "";
            int calculator = 0;
            //1. ���_���X�C�Ӧr�갵�զX�A������B�z
            while (words.size() > 0)
            {
                //2-1. ��e�i�Ϊ���
                currentSpaceLength = maxWidth;
                vector<string> temp{};
                peddingLength = 0;
                lineMsg = "";
                calculator = words[0].size();
                //2-2. �C����֥i�Ϊ��סA�p��O�_�٦��Ŷ��i�H���r(�r��)
                while (!words.empty() &&
                    (currentSpaceLength - (calculator + peddingLength)) >= 0)
                {
                    temp.push_back(words[0]);
                    currentSpaceLength -= (calculator + peddingLength);
                    words.erase(words.begin());
                    //���p�G�O�Ĥ@�������ɭԡA���ΰt�m1�Ӫťզr���A�H�u���@�ӳ��"hello"����10���� 
                    //EX: "hello     " ���w��b�̥���
                    //�����p���G�ӳ��"hello"�B"be"����10���� 
                    //EX: "hello be  " hello��be�������w�ܤ�1�Ӫťզr��
                    peddingLength = 1;
                    calculator = words.empty() ? 0 : words[0].size();
                }
                
                int redermine = currentSpaceLength;//�Ѿl���ťզr����
                int everyExtraSpace = 0;//�����զ��r�ꪺ��������B�~���ťզr����
                //3. �p��ťզr�����t�m
                if (temp.size() == 1 || words.empty())
                {
                    //3-1. �u��1�ӳ���Ψ��쩳(�t�m�̥���)�A�ѤU���ťզr���i�H���t�m�b�k��
                    redermine = currentSpaceLength + (temp.size() - 1);
                }
                else
                {
                    //3-2. 2�ӳ���H�W�����ءA�n�t�m����P��������ťզr��
                    everyExtraSpace = redermine / (temp.size() - 1);
                    everyExtraSpace += 1;
                    redermine = redermine % (temp.size() - 1);
                }

                //4. �զ���� + �ťզr��
                auto useSpace = 0;
                for (int index = 0; index < temp.size() - 1; index++)
                {
                    useSpace = everyExtraSpace;
                    if (redermine > 0)
                    {
                        useSpace++;
                        redermine--;
                    }                    
                    lineMsg += temp[index] + string(useSpace, ' ');
                }
                lineMsg += temp[temp.size() - 1] + string(redermine, ' ');
                //5. �������զ���J
                result.push_back(lineMsg);
            }
            return result;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Text_Justification_Model GetTestData001(void)
        {
            Text_Justification_Model result;
            result.words = { "This", "is", "an", "example", "of", "text", "justification." };
            result.maxWidth = 16;
            return result;/*expected = 
            [
              "This    is    an",
              "example  of text",
              "justification.  "
            ]
             */
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Text_Justification_Model GetTestData002(void)
        {
            Text_Justification_Model result;
            result.words = { "What","must","be","acknowledgment","shall","be" };
            result.maxWidth = 16;
            return result;/*expected =
            [
               "What   must   be",
               "acknowledgment  ",
               "shall be        "
            ]         
            
            */
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Text_Justification_Model GetTestData003(void)
        {
            Text_Justification_Model result;
            result.words = { "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
            result.maxWidth = 20;
            return result;/*expected =
            [
                "Science  is  what we",
                "understand      well",
                "enough to explain to",
                "a  computer.  Art is",
                "everything  else  we",
                "do                  "
            ]
            */
        };
#pragma endregion TestData
    };
}
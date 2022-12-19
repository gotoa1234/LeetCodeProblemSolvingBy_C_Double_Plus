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
    /// 文本對齊
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
        ///         思路 ：
        ///      Runtime : 
        /// Memory Usage : 
        /// <returns></returns>
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            
            vector<string> result{};
            vector<string> temp{};
            int currentSpace = 0;
            int peddingLength = 0;
            while (words.size() > 0)
            {
                currentSpace = maxWidth;
                vector<string> temp{};
                peddingLength = 0;
                while (currentSpace - (words[0].size() + peddingLength) >= 0)
                {
                    temp.push_back(words[0]);
                    currentSpace= - words[0].size();
                    words.erase(words.begin());
                    peddingLength = 1;
                }

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
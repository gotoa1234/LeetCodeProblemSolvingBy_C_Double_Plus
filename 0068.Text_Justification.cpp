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
        ///         思路 ：考字串歸納，主要有2種情境
        ///                a. 1個單詞 與 最後一組單詞 要置左 - 每個單詞間只有1個空白字元
        ///                b. 多個單詞以上，且非最後一組單詞 - 每個單詞間平均分空白字元，多的依序由左邊2個單詞間先取用
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 7.4 MB Beats 55.26 %
        /// <returns></returns>
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            
            vector<string> result{};
            int currentSpaceLength = 0;
            int peddingLength = 0;
            string lineMsg = "";
            int calculator = 0;
            //1. 不斷取出每個字串做組合，直到全處理
            while (words.size() > 0)
            {
                //2-1. 當前可用長度
                currentSpaceLength = maxWidth;
                vector<string> temp{};
                peddingLength = 0;
                lineMsg = "";
                calculator = words[0].size();
                //2-2. 每次減少可用長度，計算是否還有空間可以放單字(字串)
                while (!words.empty() &&
                    (currentSpaceLength - (calculator + peddingLength)) >= 0)
                {
                    temp.push_back(words[0]);
                    currentSpaceLength -= (calculator + peddingLength);
                    words.erase(words.begin());
                    //※如果是第一次取的時候，不用配置1個空白字元，以只有一個單詞"hello"長度10為例 
                    //EX: "hello     " 必定放在最左邊
                    //※假如有二個單詞"hello"、"be"長度10為例 
                    //EX: "hello be  " hello跟be中間必定至少1個空白字元
                    peddingLength = 1;
                    calculator = words.empty() ? 0 : words[0].size();
                }
                
                int redermine = currentSpaceLength;//剩餘的空白字元數
                int everyExtraSpace = 0;//本次組成字串的單詞中間額外的空白字元數
                //3. 計算空白字元的配置
                if (temp.size() == 1 || words.empty())
                {
                    //3-1. 只有1個單詞或走到底(配置最左邊)，剩下的空白字元可以全配置在右邊
                    redermine = currentSpaceLength + (temp.size() - 1);
                }
                else
                {
                    //3-2. 2個單詞以上的情框，要配置單詞與單詞間的空白字元
                    everyExtraSpace = redermine / (temp.size() - 1);
                    everyExtraSpace += 1;
                    redermine = redermine % (temp.size() - 1);
                }

                //4. 組成單詞 + 空白字元
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
                //5. 完成的組成放入
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
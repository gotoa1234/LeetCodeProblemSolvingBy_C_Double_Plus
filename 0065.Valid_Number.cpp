#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution65
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "0065.Valid_Number.cpp"
    using namespace Solution65;

    int main()
    {
        Solution65::Valid_Number useClass;
        Solution65::Valid_Number::Valid_Number_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.isNumber(getTestModel.s);

        // true
        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isNumber(getTestModel.s);

        // false
        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.isNumber(getTestModel.s);

        //false
        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.isNumber(getTestModel.s);

        //under true
        getTestModel = useClass.GetTestData004();
        auto result4 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData005();
        auto result5 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData006();
        auto result6 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData007();
        auto result7 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData008();
        auto result8 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData009();
        auto result9 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData010();
        auto result10 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData011();
        auto result11 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData012();
        auto result12 = useClass.isNumber(getTestModel.s);

        //under false
        getTestModel = useClass.GetTestData013();
        auto result13 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData014();
        auto result14 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData015();
        auto result15 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData016();
        auto result16 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData017();
        auto result17 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData018();
        auto result18 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData019();
        auto result19 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData020();
        auto result20 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData021();
        auto result21 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData022();
        auto result22 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData023();
        auto result23 = useClass.isNumber(getTestModel.s);

        getTestModel = useClass.GetTestData024();
        auto result24 = useClass.isNumber(getTestModel.s);

        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 喷靡计
    /// “  12345678901 陪ボ 1.23E+10  硂琌猭厩计
    /// </summary>
    class Valid_Number
    {
#pragma region Model
    public:
        class Valid_Number_Model
        {
        public:
            string s;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         隔 肈ヘ盢﹃计だΘ4贺摸
        ///                1:计 2:厩计-计(E or e) 3:タ璽腹 4.计翴
        ///                璶猔種讽じ :
        ///                2:厩计-计(E or e) -> 计ぃΘミ璶钡タ璽腹ぃ钡计翴
        ///                3:タ璽腹  -> 玡ぃΤ计计翴タ璽腹 
        ///                4:计翴  -> 玡ぃΤ计翴计
        ///                璝常才碞Θミ程计篨夹ご琌 true 痷タ计
        ///      Runtime : 0 ms Beats   100 %
        /// Memory Usage : 6 MB Beats 39.24 %
        /// <returns></returns>
        bool isNumber(string s) {
            bool number = false;
            bool exponent = false;
            bool sign = false;
            bool dot = false;

            for (auto sChar : s)
            {
                if (sChar >= '0' && sChar <= '9')
                    number = true;
                else if (sChar == 'E' || sChar == 'e')
                    if (exponent)
                        return false;
                    else if (false == number)
                        return false;
                    else
                        exponent = true, sign = number = dot = false;
                else if (sChar == '+' or sChar == '-')
                    if (dot || sign || number)
                        return false;
                    else
                        sign = true;
                else if (sChar == '.')
                    if (dot || exponent)
                        return false;
                    else
                        dot = true;
                else
                    return false;
            }
            return number;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Valid_Number_Model GetTestData001(void)
        {
            Valid_Number_Model result;
            result.s = "0";
            return result;//expected = true
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Valid_Number_Model GetTestData002(void)
        {
            Valid_Number_Model result;
            result.s = "e";
            return result;//expected = false
        };

        /// <summary>
        /// test 3
        /// </summary>   
        Valid_Number_Model GetTestData003(void)
        {
            Valid_Number_Model result;
            result.s = ".";
            return result;//expected = false
        };


        Valid_Number_Model GetTestData004(void)
        {
            Valid_Number_Model result;
            result.s = "3.e1";
            return result;//expected = true
        };

        Valid_Number_Model GetTestData005(void)
        {
            Valid_Number_Model result;
            result.s = "+1.e+5";
            return result;//expected = true
        };

        Valid_Number_Model GetTestData006(void)
        {
            Valid_Number_Model result;
            result.s = "-54.53061";
            return result;//expected = true
        };

        Valid_Number_Model GetTestData007(void)
        {
            Valid_Number_Model result;
            result.s = "0";
            return result;//expected = True
        };

        Valid_Number_Model GetTestData008(void)
        {
            Valid_Number_Model result;
            result.s = "0.1";
            return result;//expected = true
        };
        Valid_Number_Model GetTestData009(void)
        {
            Valid_Number_Model result;
            result.s = "2e10";
            return result;//expected = true
        };

        Valid_Number_Model GetTestData010(void)
        {
            Valid_Number_Model result;
            result.s = "2e-9";
            return result;//expected = True
        };

        Valid_Number_Model GetTestData011(void)
        {
            Valid_Number_Model result;
            result.s = "+.8";
            return result;//expected = true
        };

        Valid_Number_Model GetTestData012(void)
        {
            Valid_Number_Model result;
            result.s = "005047e+6";
            return result;//expected = true
        };

        Valid_Number_Model GetTestData013(void)
        {
            Valid_Number_Model result;
            result.s = "abc";
            return result;//expected = false
        };

        Valid_Number_Model GetTestData014(void)
        {
            Valid_Number_Model result;
            result.s = "1 a";
            return result;//expected = false
        };

        Valid_Number_Model GetTestData015(void)
        {
            Valid_Number_Model result;
            result.s = "-e10";
            return result;//expected = false
        };

       
        Valid_Number_Model GetTestData016(void)
        {
            Valid_Number_Model result;
            result.s = "+e1";
            return result;//expected = false
        };

        Valid_Number_Model GetTestData017(void)
        {
            Valid_Number_Model result;
            result.s = "1+e";
            return result;//expected = false
        };

        Valid_Number_Model GetTestData018(void)
        {
            Valid_Number_Model result;
            result.s = "";
            return result;//expected = false
        };
        Valid_Number_Model GetTestData019(void)
        {
            Valid_Number_Model result;
            result.s = ".";
            return result;//expected = false
        };

        Valid_Number_Model GetTestData020(void)
        {
            Valid_Number_Model result;
            result.s = "e9";
            return result;//expected = false
        };

        Valid_Number_Model GetTestData021(void)
        {
            Valid_Number_Model result;
            result.s = "4e+";
            return result;//expected = false
        };

        Valid_Number_Model GetTestData022(void)
        {
            Valid_Number_Model result;
            result.s = " -.";
            return result;//expected = false
        };


        Valid_Number_Model GetTestData023(void)
        {
            Valid_Number_Model result;
            result.s = "3.e";
            return result;//expected = False
        };

        Valid_Number_Model GetTestData024(void)
        {
            Valid_Number_Model result;
            result.s = ". 1";
            return result;//expected = False
        };

#pragma endregion TestData
    };
}

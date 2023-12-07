#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution67
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Easy\0067.Add_Binary.cpp"
    using namespace Solution67;

    int main()
    {
        Solution67::Add_Binary useClass;
        Solution67::Add_Binary::Add_Binary_Model getTestModel = useClass.GetTestData001();
        auto result1 = useClass.addBinary(getTestModel.a, getTestModel.b);

        getTestModel = useClass.GetTestData002();
        auto result2 = useClass.addBinary(getTestModel.a, getTestModel.b);

        getTestModel = useClass.GetTestData003();
        auto result3 = useClass.addBinary(getTestModel.a, getTestModel.b);

        return 0;
    }
    */
#pragma endregion Paste to execute

    /// <summary>
    /// 增加二進位
    /// </summary>
    class Add_Binary
    {
#pragma region Model
    public:
        class Add_Binary_Model
        {
        public:
            string a;
            string b;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路 ：兩個字串從尾部相加，每次加總的結果 %2 為當前值 /2 為進位值
        ///      Runtime :   0 ms Beats   100 %
        /// Memory Usage : 6.4 MB Beats 56.41 %
        /// <returns></returns>
        string addBinary(string a, string b) {
            //1. 將長的字串放前面
            if (b.size() > a.size())
                return addBinary(b, a);

            int aMoveIndex = a.size() - 1;
            int bMoveIndex = b.size() - 1;            
            int carry = 0;
            string result = {};
            //2. aMoveIndex 永遠最長，直到該值為負跳出
            while (aMoveIndex >= 0)
            {
                auto aChar = aMoveIndex >= 0 ? a[aMoveIndex] - '0' : 0;
                auto bChar = bMoveIndex >= 0 ? b[bMoveIndex] - '0' : 0;
                result.insert(result.begin(), ((aChar + bChar + carry) % 2) + '0');
                carry = (aChar + bChar + carry) / 2;
                aMoveIndex--;
                bMoveIndex--;
            }
            //3. 最後若有進位則將該值插入
            if (carry == 1)
                result.insert(result.begin(), '1');
            return result;
        }
    public:
#pragma endregion Main

#pragma region TestData
    public:
        /// <summary>
        /// test 1
        /// </summary>        
        Add_Binary_Model GetTestData001(void)
        {
            Add_Binary_Model result;
            result.a = "11";
            result.b = "1";
            return result;//expected = "100"
        };

        /// <summary>
        /// test 2
        /// </summary>   
        Add_Binary_Model GetTestData002(void)
        {
            Add_Binary_Model result;
            result.a = "1010";
            result.b = "1011";
            return result;//expected = "10101"
        };
#pragma endregion TestData
    };
}
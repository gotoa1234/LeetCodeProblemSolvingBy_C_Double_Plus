#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

namespace Solution155
{
#pragma region Paste to execute 
    /*
    #include <unordered_map>
    #include "Medium/0155.Min_Stack.cpp"
    using namespace Solution155;

    int main()
    {
        Solution155::Min_Stack useClass;        
        Solution155::Min_Stack::MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin(); // return -3
        minStack.pop();
        minStack.top();    // return 0
        minStack.getMin(); // return -2
        return 0;
    }
    */
#pragma endregion Paste to executes

    /// <summary>
    /// 最小堆疊
    /// </summary>
    class Min_Stack
    {
#pragma region Model
    public:
        class Min_Stack_Model
        {
        public:
            vector<int> nums;
        };
#pragma endregion Model

#pragma region Main
    public:
        /// <summary>
        ///         思路： 設定兩個Stack 一個是紀錄原本的，另一個紀錄最小的，當有更小的時候才記錄到最小的Stack中        
        ///      Runtime：   21 ms Beats 82.41 %
        /// Memory Usage： 16.4 MB Beats 40.41 %
        /// </summary>
        /// <returns></returns>
    public:
        class MinStack {
        private:
            stack<int> _BaseStack;
            stack<int> _MinStack;
        public:
            MinStack() {

            }

            void push(int val) {
                _BaseStack.push(val);
                if (_MinStack.empty() || val <= _MinStack.top())
                {
                    _MinStack.push(val);
                }
            }

            void pop() {
                if (_BaseStack.top() == _MinStack.top())
                {
                    _MinStack.pop();
                }
                _BaseStack.pop();
            }

            int top() {
                return _BaseStack.top();
            }

            int getMin() {
                return _MinStack.top();
            }
        };
    public:
#pragma endregion Main

    };
}

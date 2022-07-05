class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        div = abs(dividend)
        dis = abs(divisor)
        result = 0
        while div>=dis:
            tmp = dis
            mul = 1
            while div>=tmp:
                div -= tmp
                result += mul
                mul += mul
                tmp += tmp
                
        if(dividend >= 0 and divisor < 0 or dividend < 0 and divisor >= 0):
            result = -result
        return min(2147483647, max(-2147483648, result))












// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         int result = 0;
//         int div = abs(dividend);
//         int dis = abs(divisor);
//         while(div >= dis) {
//             int tem = dis;
//             int mult = 1;
//             while(div >= tem) {
//                 div -= tem;
//                 result += mult;  
//                 mult += mult;
//                 tem += tem;              
//             }
//         }
//         if(dividend >= 0 && divisor < 0 || dividend < 0 && divisor >= 0) 
//             result = -1*result;
//         int tem = (-2147483648 < result)?result:-2147483648;
//         return min(2147483647,tem);
//     }
// };
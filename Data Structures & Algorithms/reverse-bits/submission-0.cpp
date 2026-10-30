class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result=0;
        for(int i=1;i<=32;i++)
        {
            result<<=1;
            result=result|(n&1);
            n>>=1;
        }
        return result;
    }
};

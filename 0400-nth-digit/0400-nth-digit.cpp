using ll = long long;
class Solution {
public:
    int findNthDigit(int n) {
        ll x = n;
        ll val = 9;
        int idx = 1;
        for(int i = 0; i < 9; i++){
            if(x - val*(ll)(idx) > 0 && x > 9){
                x -= val*(ll)(idx);
                val*= 10;
                idx++;
            }else{
                break;
            }
        }
        ll st = 1;
        for(int i =0; i<idx-1; i++){
            st *= 10;
        }

        ll final_val = st + (x-1)/idx;

        int j = (x-1)%idx;
        string ans = to_string(final_val);
        return ans[j] - '0';
    }
};
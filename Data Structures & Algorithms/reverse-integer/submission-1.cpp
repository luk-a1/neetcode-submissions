class Solution {
public:
    int reverse(int x) {
    int maxn = pow(2, 31) - 1;
    int minn = -pow(2, 31);
    int output = 0;
    int multi = 10;
    bool negative = x < 0;
    x = abs(x);
    //if(output > maxn) return 0;
    //if(output < minn) return 0;
    cout<<minn<<" "<<maxn<<" ";
    while( x > 0 ){
        
        int curr = x%10;
        if(output > maxn/10 || (output == (maxn / 10) && (curr > maxn%10))) {cout<<"entered maxn\n"; return 0;}
        if(output < minn/10 || (output == -1*(minn / 10) && (curr > 2))) {cout<<curr<<" "<<output<<" entered minn\n"; return 0;}

        output = output*multi + curr;
        x/=10;
        
    }

    return negative ? -1*output : output;
    }
};

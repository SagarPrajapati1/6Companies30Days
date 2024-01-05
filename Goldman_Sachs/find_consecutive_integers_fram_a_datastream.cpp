class DataStream {
public:
    int value;
    int k;
    
    int cnt = 0;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {

        if(num == value) cnt++; 
        else cnt = 0;
        return cnt >= k;
    }
};

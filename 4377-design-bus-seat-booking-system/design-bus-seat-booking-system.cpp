class BusBooking {
public:
    vector<vector<int>> vec;
    int totalTime = 0;
    int minTime = 0;

    BusBooking(int n) {
        vec.resize(n, vector<int>(4, -1));
    }

    void toggle(string seat) {
        string row = seat.substr(1);
        int r = stoi(row) - 1;
        int c = seat[0] - 'A';

        if(vec[r][c] != -1)
        {
            totalTime -= vec[r][c];
            vec[r][c] = -1;
            minTime--;
            return; 
        }
        else
        {
            if(c == 0)
            {
                if(vec[r][c+1] != -1)
                {
                    totalTime += 3;
                    minTime++;
                    vec[r][c] = 3;
                }
                else 
                {
                    totalTime += 1;
                    minTime++;
                    vec[r][c] = 1;
                }
                return;
            }

            if(c == 3)
            {
                if(vec[r][c-1] != -1)
                {
                    totalTime += 3;
                    minTime++;
                    vec[r][c] = 3;
                }
                else 
                {
                    totalTime += 1;
                    minTime++;
                    vec[r][c] = 1;
                }
                return;
            }
        }

        vec[r][c] = 1;
        minTime++;
        totalTime++;
    }

    int getTotalTime() {
        return totalTime;
    }

    int getMinTime() {
        return minTime;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
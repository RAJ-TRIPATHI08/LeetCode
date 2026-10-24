class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string M = arriveAlice.substr(0, 2);
        string D = arriveAlice.substr(3);

        int AliceArrM = stoi(M);
        int AliceArrD = stoi(D);

        M = leaveAlice.substr(0, 2);
        D = leaveAlice.substr(3);

        int AliceLeaM = stoi(M);
        int AliceLeaD = stoi(D);

        M = arriveBob.substr(0, 2);
        D = arriveBob.substr(3);

        int BobArrM = stoi(M);
        int BobArrD = stoi(D);

        M = leaveBob.substr(0, 2);
        D = leaveBob.substr(3);

        int BobLeaM = stoi(M);
        int BobLeaD = stoi(D);

        int AliceArr = AliceArrD, AliceLea = AliceLeaD;
        int BobArr = BobArrD, BobLea = BobLeaD;

        for(int i = 0; i < AliceArrM - 1; i++)
            AliceArr += days[i];

        for(int i = 0; i < AliceLeaM - 1; i++)
            AliceLea += days[i];

        for(int i = 0; i < BobArrM - 1; i++)
            BobArr += days[i];

        for(int i = 0; i < BobLeaM - 1; i++)
            BobLea += days[i];

        int start = max(AliceArr, BobArr);
        int end = min(AliceLea, BobLea);

        return max(0, end - start + 1);
    }
};
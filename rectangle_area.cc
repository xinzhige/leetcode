class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap = 0;
        if(C < E || G < A || D < F || H < B){
            overlap = 0;
        } else {
            vector<int> x = {A, C, E, G};
            vector<int> y = {B, D, F, H};
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            overlap = (x[2] - x[1]) * (y[2] - y[1]);
        }
        int combined = (C - A) * (D - B) + (G - E) * (H - F);
        return combined - overlap;
    }
};

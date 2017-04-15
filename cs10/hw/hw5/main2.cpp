#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;

int genRandInt(int min, int max)
{
    return min + rand() %(max - min +1);
}

int singleTurn(int hold)
{
    srand();
    int score = 0;
    while(score < hold)
    {
        int r = genRandInt(1,6);
        if(r == 1)
            return 0;
        else
            score += r;
    }
    return score;
}

int main()
{
    int maxround = 0;
    int turn_score = 0;
    int hold = 0;
    int count_0 = 0;
    int count_hold = 0;
    int count_1 = 0;
    int count_2 = 0; 
    int count_3 = 0;
    int count_4 = 0;
    int count_5 = 0;
    
    cout << "What value should we hold at? ";
    cin  >> hold;
    cout << "Hold-at-N turn simulations? ";
    cin >> maxround;
    cout << endl;
    for(int i = 1; i <= maxround; ++i)
    {
        turn_score = singleTurn(hold);
        if(turn_score == 0)
            count_0++;
        if(turn_score == hold)
            count_hold++;
        if(turn_score == (hold + 1))
            count_1++;
        if(turn_score == (hold + 2))
            count_2++;
        if(turn_score == (hold + 3))
            count_3++;
        if(turn_score == (hold + 4))
            count_4++;
        if(turn_score == (hold + 5))
            count_5++;
    }

    cout << fixed << setprecision(6) << endl;
    cout << "Score\tEstimated Probability" << endl;
    cout << "0\t" << static_cast<double>(count_0)/maxround << endl;
    cout << hold << "\t" << static_cast<double>(count_hold)/maxround << endl;
    cout << hold + 1 << "\t" << static_cast<double>(count_1)/maxround << endl;
    cout << hold + 2 << "\t" << static_cast<double>(count_2)/maxround << endl;
    cout << hold + 3 << "\t" << static_cast<double>(count_3)/maxround << endl;
    cout << hold + 4 << "\t" << static_cast<double>(count_4)/maxround << endl;
    cout << hold + 5 << "\t" << static_cast<double>(count_5)/maxround << endl;

    return 0;
}


#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

long long sumOfDivision(long long &number)
{
    long long sum = 1;
    for (long long i = 2; i < (number / i); i++)
    {
        if ((number % i) == 0)
        {
            sum += i + (number / i);
        }
    }
    return sum;
}

namespace Bud
{
    string buddy(long long start, long long limit)
    {
        long long m;
        stringstream result;
        for (long long n = start; n <= limit; n++)
        {
            m = sumOfDivision(n) - 1;
            if (m > n)
                if (sumOfDivision(m) == n + 1)
                {
                    result << "(" << n << " " << m << ")";
                    cout << result.str() << endl;
                    return result.str();
                }
        }
        return "Nothing";
    }
} // namespace Bud

using namespace Bud;

int main(int argc, char const *argv[])
{
    auto start = chrono::steady_clock::now();
    assert(buddy(47, 50) == "(48 75)");
    assert(buddy(1071625, 1103735) == "(1081184 1331967)");
    assert(buddy(2382, 3679) == "Nothing");
    assert(buddy(8983, 13355) == "(9504 20735)");
    cout << "Done" << endl;
    auto stop = chrono::steady_clock::now();
    cout << "Elapsed time in sec: " << chrono::duration_cast<chrono::seconds>(stop - start).count() << endl;
    return 0;
}

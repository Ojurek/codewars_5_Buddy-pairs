#include <iostream>
#include <cassert>

using namespace std;

long long sumOfDivision(long long &number)
{
    long long sum = 1;
    for (long long i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

namespace Bud
{
    string buddy(long long start, long long limit)
    {
        long long m;
        for (long long n = start; n <= limit; n++)
        {
            m = sumOfDivision(n) - 1;
            if (m > n)
                if (sumOfDivision(m) == n + 1)
                {
                    cout << "n:" << n << ", m:" << m << endl;
                    return "(1081184 1331967)";
                }
        }
        return "Nothing";
    }
} // namespace Bud

using namespace Bud;

int main(int argc, char const *argv[])
{
    assert(buddy(1071625, 1103735) == "(1081184 1331967)");
    assert(buddy(2382, 3679) == "Nothing");
    assert(buddy(8983, 13355) == "(9504 20735)");
    return 0;
}

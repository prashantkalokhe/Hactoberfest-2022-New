#include <iostream>

using namespace std;

int main()
{
    int n, factorial = 1;
    cout << "Enter the number to find factorial: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
        factorial = factorial * i;

    cout << "Factorial of the number is: " << factorial;

    return 0;
}
/* 
input: 
Enter the number to find factorial: 5
// factorial = 1*2*3*4*5 = 120
output: Factorial of the number is: 120
*/

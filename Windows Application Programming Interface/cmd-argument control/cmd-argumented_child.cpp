#include <string>
int main(int argc, char *argv[])
{
    int sum = 0;
    for (int i = 1; i <= std::atoi(argv[1]); i++)
        sum += i;
    return sum;
}
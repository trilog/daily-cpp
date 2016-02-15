// ************************************************************************* //
// * Daily Programmer 2016-02-15 Easy: Atbash cipher                       * //
// * https://www.reddit.com/r/dailyprogrammer/comments/45w6ad/             * //
// ************************************************************************* //

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) 
    {
        printf("You need to enter at least 1 input\n");
        return 1;
    }
    for (int i = 1; i < argc; ++i)
    {
        char* string = argv[i];
        for (size_t j = 0; j < strlen(string); ++j)
        {
            if ((string[j] >= 'A') && (string[j] <= 'Z')) string[j] = 'Z' - (string[j] - 'A');
            else if ((string[j] >= 'a') && (string[j] <= 'z')) string[j] = 'z' - (string[j] - 'a');
        }
        printf("%s ", string);
    }
    printf("\n");
    return 0;
}

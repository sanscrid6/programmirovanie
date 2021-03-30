#include "funcs.h"
#include "assert.h"
#include <stdio.h>

int test()
{
    assert(isPalindrome("qwewq")==1);
    assert(isPalindrome("asdasda")==0);
}

int main()
{
    test();
    printf("Tests passed");
    return 0;
}
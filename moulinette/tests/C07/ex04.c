#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

void test(char *nbr, char *base_from, char *base_to)
{
    char *res;
    res = ft_convert_base(nbr, base_from, base_to);
    if (res == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%s\n", res);
}

int main(void)
{
    test("4242", "0123456789", "");
    test("4242", "0123456789", "0");
    test("4242", "0123456789", "01");
    test("4242", "0123456789", "0+");
    test("4242", "0123456789", "0-");
    test("4242", "0123456789", "0 ");
    test("4242", "0123456789", "0\t");
    test("4242", "0123456789", "0\n");
    test("4242", "0123456789", "0\v");
    test("4242", "0123456789", "0\f");
    printf("---\n");
    test("1000010010010", "", "0123456789");
    test("1000010010010", "0", "0123456789");
    test("1000010010010", "01", "0123456789");
    test("1000010010010", "0+", "0123456789");
    test("1000010010010", "0-", "0123456789");
    test("1000010010010", "0 ", "0123456789");
    test("1000010010010", "0\t", "0123456789");
    test("1000010010010", "0\n", "0123456789");
    test("1000010010010", "0\v", "0123456789");
    test("1000010010010", "0\f", "0123456789");
    printf("---\n");
    test("4242", "abcdefghij", "abcdefghij");
    printf("---\n");
    test(" \t\n\v\f+1234", "0123456789", "0123456789");
    test(" \t\n\v\f+-1234", "0123456789", "0123456789");
    test(" \t\n\v\f+--1234", "0123456789", "0123456789");
    test(" \t\n\v\f-+-1234", "0123456789", "0123456789");
    test(" \t\n\v\f-+--1234", "0123456789", "0123456789");
    test(" \t\n\v\f-+-1234a", "0123456789", "0123456789");
    test(" \t\n\v\f-+-123a4", "0123456789", "0123456789");
    test(" \t\n\v\f-+-12a34", "0123456789", "0123456789");
    test(" \t\n\v\f-+-1a234", "0123456789", "0123456789");
    test(" \t\n\v\f-1234-", "0123456789", "0123456789");
    test(" \t\n\v\f+1234-", "0123456789", "0123456789");
    printf("---\n");
    test(" \t\n\v\f-+-IOI", "OI", "0123456789");
    test(" \t\n\v\f-+-!@!", "@!", "0123456789");
    test(" \t\n\v\f-+-^%^", "%^", "0123456789");
    printf("---\n");
    test(" \t\n\v\f+1234", "0123456789", "0123456788");
    test(" \t\n\v\f+1234", "0123456784", "0123456789");
    return 0;
}

/*
** EPITECH PROJECT, 2018
** uni-test
** File description:
** uni-test for printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_word, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, test_percent_word, .init = redirect_all_std)
{
    my_printf("hello % world");
    cr_assert_stdout_eq_str("hello % world");
}

Test(my_printf, test_backslash_n, .init = redirect_all_std)
{
    my_printf("hello world\n");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(my_printf, test_s, .init = redirect_all_std)
{
    my_printf("%s", "helloworld");
    cr_assert_stdout_eq_str("helloworld");
}

Test(my_printf, test_c, .init = redirect_all_std)
{
    my_printf("%c", 'B');
    cr_assert_stdout_eq_str("B");
}

Test(my_printf, test_d, .init = redirect_all_std)
{
    my_printf("%d", 1525);
    cr_assert_stdout_eq_str("1525");
}

Test(my_printf, test_i, .init = redirect_all_std)
{
    my_printf("%i", 1525);
    cr_assert_stdout_eq_str("1525");
}

Test(my_printf, test_u, .init = redirect_all_std)
{
    my_printf("%u", 1525);
    cr_assert_stdout_eq_str("1525");
}

Test(my_printf, test_o7, .init = redirect_all_std)
{
    my_printf("%o", 7);
    cr_assert_stdout_eq_str("7");
}

Test(my_printf, test_o8, .init = redirect_all_std)
{
    my_printf("%o", 8);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf, test_o12, .init = redirect_all_std)
{
    my_printf("%o", 12);
    cr_assert_stdout_eq_str("14");
}

Test(my_printf, test_o20, .init = redirect_all_std)
{
    my_printf("%o", 20);
    cr_assert_stdout_eq_str("24");
}

Test(my_printf, test_x12, .init = redirect_all_std)
{
    my_printf("%x", 12);
    cr_assert_stdout_eq_str("c");
}

Test(my_printf, test_x524757, .init = redirect_all_std)
{
    my_printf("%x", 524757);
    cr_assert_stdout_eq_str("801d5");
}

Test(my_printf, test_x755236, .init = redirect_all_std)
{
    my_printf("%x", 755236);
    cr_assert_stdout_eq_str("b8624");
}

Test(my_printf, test_X12, .init = redirect_all_std)
{
    my_printf("%X", 12);
    cr_assert_stdout_eq_str("C");
}

Test(my_printf, test_X524757, .init = redirect_all_std)
{
    my_printf("%X", 524757);
    cr_assert_stdout_eq_str("801D5");
}

Test(my_printf, test_X755236, .init = redirect_all_std)
{
    my_printf("%X", 755236);
    cr_assert_stdout_eq_str("B8624");
}

Test(my_printf, test_perpercent, .init = redirect_all_std)
{
    my_printf("%%%%s%s","anticonstitutionnellement");
    cr_assert_stdout_eq_str("%%santiconstitutionnellement");
}

Test(my_printf, test_mult_flags, .init = redirect_all_std)
{
    my_printf("Bonjour, %s, t as %d ans et %d glaces.", "Gabriel", 18, 2);
    cr_assert_stdout_eq_str("Bonjour, Gabriel, t as 18 ans et 2 glaces.");
}

Test(my_printf, test_x16, .init = redirect_all_std)
{
    my_printf("%x", 16);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf, test_xnico, .init = redirect_all_std)
{
    my_printf("I am %x", 15);
    cr_assert_stdout_eq_str("I am f");
}

Test(my_printf, test_p, .init = redirect_all_std)
{
    my_printf("My adress is %p", 16457982);
    cr_assert_stdout_eq_str("My adress is 0xfb20fe");
}

Test(my_printf, test_S127, .init = redirect_all_std)
{
    char str[5];

    my_strcpy(str, "toto");
    str[1] = 127;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t\\177to\n");
}

Test(my_printf, test_S31, .init = redirect_all_std)
{
    char str[5];

    my_strcpy(str, "toto");
    str[1] = 31;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t\\037to\n");
}

Test(my_printf, test_S48, .init = redirect_all_std)
{
    char str[5];

    my_strcpy(str, "toto");
    str[1] = 48;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t0to\n");
}

Test(my_printf, test_S126, .init = redirect_all_std)
{
    char str[5];

    my_strcpy(str, "toto");
    str[1] = 126;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t~to\n");
}

Test(my_printf, test_S6, .init = redirect_all_std)
{
    char str[5];

    my_strcpy(str, "toto");
    str[1] = 6;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t\\006to\n");
}

Test(my_printf, test_S8, .init = redirect_all_std)
{
    char str[5];

    my_strcpy(str, "toto");
    str[1] = 8;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t\\010to\n");
}

Test(my_printf, test_S7, .init = redirect_all_std)
{
    char str[5];

    my_strcpy(str, "toto");
    str[1] = 7;
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("t\\007to\n");
}

Test(my_printf, test_ldint, .init = redirect_all_std)
{
    int nb = 12548;

    my_printf("%ld\n", nb);
    cr_assert_stdout_eq_str("12548\n");
}

Test(my_printf, test_ldlong, .init = redirect_all_std)
{
    int nb = 481545245;

    my_printf("%ld\n", nb);
    cr_assert_stdout_eq_str("481545245\n");
}

Test(my_printf, test_ll, .init = redirect_all_std)
{
    long long nb = 147865214855854;

    my_printf("%lld\n", nb);
    cr_assert_stdout_eq_str("147865214855854\n");
}

Test(my_printf, test_htgo12, .init = redirect_all_std)
{
    my_printf("%#o", 12);
    cr_assert_stdout_eq_str("014");
}

Test(my_printf, test_htgo524757, .init = redirect_all_std)
{
    my_printf("%#o", 524757);
    cr_assert_stdout_eq_str("02000725");
}

Test(my_printf, test_htgo755236, .init = redirect_all_std)
{
    my_printf("%#o", 755236);
    cr_assert_stdout_eq_str("02703044");
}

Test(my_printf, test_htgx12, .init = redirect_all_std)
{
    my_printf("%#x", 12);
    cr_assert_stdout_eq_str("0xc");
}

Test(my_printf, test_htgx524757, .init = redirect_all_std)
{
    my_printf("%#x", 524757);
    cr_assert_stdout_eq_str("0x801d5");
}

Test(my_printf, test_htgx755236, .init = redirect_all_std)
{
    my_printf("%#x", 755236);
    cr_assert_stdout_eq_str("0xb8624");
}

Test(my_printf, test_htgX12, .init = redirect_all_std)
{
    my_printf("%#X", 12);
    cr_assert_stdout_eq_str("0XC");
}

Test(my_printf, test_htgX524757, .init = redirect_all_std)
{
    my_printf("%#X", 524757);
    cr_assert_stdout_eq_str("0X801D5");
}

Test(my_printf, test_htgX755236, .init = redirect_all_std)
{
    my_printf("%#X", 755236);
    cr_assert_stdout_eq_str("0XB8624");
}

Test(my_printf, test_crash_base, .init = redirect_all_std)
{
    my_printf("%s%%s%%%s%%%%s%d%%d%%%d", "la", "la", 5, 5);
    cr_assert_stdout_eq_str("la%s%la%%s5%d%5%\n");
}

Test(my_printf, test_spe_crash_base, .init = redirect_all_std)
{
    my_printf("%s%%d%%%%d%d", "Astek", 15);
    cr_assert_stdout_eq_str("Astek%d%%d15");
}

Test(my_printf, test_spercent, .init = redirect_all_std)
{
    my_printf("%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, test_dpercent, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, test_tpercent, .init = redirect_all_std)
{
    my_printf("%%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, test_qpercent, .init = redirect_all_std)
{
    my_printf("%%%%");
    cr_assert_stdout_eq_str("%%");
}

Test(my_printf, test_lengthhhc, .init = redirect_all_std)
{
    my_printf("%hhc", 125);
    cr_assert_stdout_eq_str("}");
}

Test(my_printf, test_lengthhc, .init = redirect_all_std)
{
    my_printf("%hc", 125);
    cr_assert_stdout_eq_str("}");
}

Test(my_printf, test_lengthhd180, .init = redirect_all_std)
{
    my_printf("%hhd", 180);
    cr_assert_stdout_eq_str("-76");
}

Test(my_printf, test_lengthhd127, .init = redirect_all_std)
{
    my_printf("%hhd", 127);
    cr_assert_stdout_eq_str("127");
}

Test(my_printf, test_125p, .init = redirect_all_std)
{
    my_printf("%p", 125);
    cr_assert_stdout_eq_str("0x7d");
}

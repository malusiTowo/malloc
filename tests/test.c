/*
** EPITECH PROJECT, 2018
** TEST
** File description:
** TEST
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Test1, test3)
{
    cr_expect(1 == 1, "should be true");
}

Test(Test2, test4)
{
    cr_expect(0 == 1, "should be false");
}
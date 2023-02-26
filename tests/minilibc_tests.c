/*
** EPITECH PROJECT, 2023
** minilibc_tests
** File description:
** minilibc_tests
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "../include/tests.h"

static void init_lib(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (handle == NULL) {
        write(2, "Library not found\n", 18);
        return;
    }
    my_strlen = dlsym(handle, "strlen");
    my_strchr = dlsym(handle, "strchr");
    my_strrchr = dlsym(handle, "strrchr");
    my_memset = dlsym(handle, "memset");
    my_memcpy = dlsym(handle, "memcpy");
    my_strcmp = dlsym(handle, "strcmp");
    my_memmove = dlsym(handle, "memmove");
    my_strncmp = dlsym(handle, "strncmp");
    my_strpbrk = dlsym(handle, "strpbrk");
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_strstr = dlsym(handle, "strstr");
    my_strcspn = dlsym(handle, "strcspn");
    my_index = dlsym(handle, "index");
    my_rindex = dlsym(handle, "rindex");
    my_memfrob = dlsym(handle, "memfrob");
}

Test(strlen, test_strlen, .init = init_lib)
{
    cr_assert_eq(strlen("test"), my_strlen("test"));
}

Test(strchr, test_strchr, .init = init_lib)
{
    cr_assert_eq(strchr("test", 'e'), my_strchr("test", 'e'));
}

Test(strchr, test_strchr2, .init = init_lib)
{
    cr_assert_eq(strchr("e", 'e'), my_strchr("e", 'e'));
}

Test(strchr, test_strchr_null, .init = init_lib)
{
    cr_assert_eq(strchr("test", 'o'), my_strchr("test", 'o'));
}

Test(strchr, test_strchr_null2, .init = init_lib)
{
    cr_assert_eq(strchr("test", '\0'), my_strchr("test", '\0'));
}

Test(strchr, test_strchr_empty, .init = init_lib)
{
    cr_assert_eq(strchr("", 'o'), my_strchr("", 'o'));
}

Test(strrchr, test_strrchr, .init = init_lib)
{
    cr_assert_eq(strrchr("test", 't'), my_strrchr("test", 't'));
}

Test(strrchr, test_strrchr2, .init = init_lib)
{
    cr_assert_eq(strrchr("t", 't'), my_strrchr("t", 't'));
}

Test(strrchr, test_strrchr_null, .init = init_lib)
{
    cr_assert_eq(strrchr("test", 'a'), my_strrchr("test", 'a'));
}

Test(strrchr, test_strrchr_null2, .init = init_lib)
{
    cr_assert_eq(strrchr("test", '\0'), my_strrchr("test", '\0'));
}

Test(strrchr, test_strrchr_empty, .init = init_lib)
{
cr_assert_eq(strrchr("", 'o'), my_strrchr("", 'o'));
}

Test(memset, test_memset_pointer, .init = init_lib)
{
    char *str = malloc(10);

    cr_assert_eq(memset(str, 'z', 15), my_memset(str, 'z', 15));
    free(str);
}

Test(memset, test_memset_value, .init = init_lib)
{
    char *str = malloc(10);
    char *str1 = memset(str, 'z', 10);
    char *str2 = my_memset(str, 'z', 10);

    cr_assert_eq(str1, str2);
    free(str);
}

Test(memcpy, test_memcpy_pointer, .init = init_lib)
{
    char *str1 = strdup("Salut World");
    char *str2 = strdup("Hello");

    cr_assert_eq(memcpy(str1, str1, 5), my_memcpy(str1, str1, 5));
    free(str1);
    free(str2);
}

Test(memcpy, test_memcpy_value, .init = init_lib)
{
    char *str1 = strdup("Salut World");
    char *str2 = strdup("Hello");

    cr_assert_eq(str1, my_memcpy(str1, str2, 5));
    free(str1);
    free(str2);
}

Test(strcmp, test_strcmp_equal, .init = init_lib)
{
    cr_assert_eq(strcmp("test", "test"), my_strcmp("test", "test"));
}

Test(strcmp, test_strcmp_greater, .init = init_lib)
{
    cr_assert_eq(strcmp("test", "testz"), my_strcmp("test", "testz"));
}

Test(strcmp, test_strcmp_lower, .init = init_lib)
{
    cr_assert_eq(strcmp("testz", "test"), my_strcmp("testz", "test"));
}

Test(strcmp, test_strcmp_greater2, .init = init_lib)
{
    cr_assert_eq(strcmp("testa", "testz"), my_strcmp("testa", "testz"));
}

Test(strcmp, test_strcmp_lower2, .init = init_lib)
{
    cr_assert_eq(strcmp("testz", "testa"), my_strcmp("testz", "testa"));
}

Test(strncmp, test_strncmp_equal, .init = init_lib)
{
    cr_assert_eq(strncmp("test", "test", 4), my_strncmp("test", "test", 4));
}

Test(strncmp, test_strncmp_equal_greater_n, .init = init_lib)
{
    cr_assert_eq(strncmp("test", "test", 7), my_strncmp("test", "test", 7));
}

Test(strncmp, test_strncmp_equal_greater_src, .init = init_lib)
{
    cr_assert_eq(strncmp("test", "testdd", 4), my_strncmp("test", "testdd", 4));
}

Test(strncmp, test_strncmp_equal_greater_dest, .init = init_lib)
{
    cr_assert_eq(strncmp("testdd", "test", 4), my_strncmp("testdd", "test", 4));
}

Test(strncmp, test_strncmp_lower_dest, .init = init_lib)
{
    cr_assert_eq(strncmp("testa", "testz", 5), my_strncmp("testa", "testz", 5));
}

Test(strncmp, test_strncmp_greater_dest, .init = init_lib)
{
    cr_assert_eq(strncmp("testz", "testa", 5), my_strncmp("testz", "testa", 5));
}

Test(strpbrk, test_strpbrk_pointer_null, .init = init_lib)
{
    char *str1 = strdup("Hello World");

    cr_assert_eq(strpbrk(str1, "z"), my_strpbrk(str1, "z"));
}

Test(strpbrk, test_strpbrk_pointer, .init = init_lib)
{
    char *str1 = strdup("Hello World");

    cr_assert_eq(strpbrk(str1, "W"), my_strpbrk(str1, "W"));
}

Test(strpbrk, test_strpbrk_pointer_multiple, .init = init_lib)
{
    char *str1 = strdup("Hello World");

    cr_assert_eq(strpbrk(str1, "We"), my_strpbrk(str1, "We"));
}

Test(strpbrk, test_strpbrk_str, .init = init_lib)
{
    char *str1 = strdup("Hello World");
    char *str2 = strdup("Hello World");

    str1 = strpbrk(str1, "W");
    str2 = my_strpbrk(str2, "W");
    cr_assert_str_eq(str1, str2);
}

Test(strpbrk, test_strpbrk_str_multiple, .init = init_lib)
{
    char *str1 = strdup("Hello World");
    char *str2 = strdup("Hello World");

    str1 = strpbrk(str1, "We");
    str2 = my_strpbrk(str2, "We");
    cr_assert_str_eq(str1, str2);
}

Test(strcasecmp, test_strcasecmp_equal, .init = init_lib)
{
    cr_assert_eq(strcasecmp("test", "test"), my_strcasecmp("test", "test"));
}

Test(strcasecmp, test_strcasecmp_equal_maj, .init = init_lib)
{
    cr_assert_eq(strcasecmp("tesTT", "tesTT"), my_strcasecmp("tesTT", "tesTT"));
}

Test(strcasecmp, test_strcasecmp_greater, .init = init_lib)
{
    cr_assert_eq(strcasecmp("testt", "test"), my_strcasecmp("testt", "test"));
}

Test(strcasecmp, test_strcasecmp_greater_maj, .init = init_lib)
{
    cr_assert_eq(strcasecmp("tEstT", "tEst"), my_strcasecmp("tEstT", "tEst"));
}

Test(strcasecmp, test_strcasecmp_lower, .init = init_lib)
{
    cr_assert_eq(strcasecmp("test", "testt"), my_strcasecmp("test", "testt"));
}

Test(strcasecmp, test_strcasecmp_lower_maj, .init = init_lib)
{
    cr_assert_eq(strcasecmp("TeSt", "tEstT"), my_strcasecmp("TeSt", "tEstT"));
}

Test(strstr, test_strstr_classic, .init = init_lib)
{
    char *str = strdup("Hello World");

    cr_assert_eq(strstr(str, "W"), my_strstr(str, "W"));
    free(str);
}

Test(strstr, test_strstr_not_found, .init = init_lib)
{
    char *str = strdup("Hello World");

    cr_assert_eq(strstr(str, "a"), my_strstr(str, "a"));
    free(str);
}

Test(strstr, test_strstr_not_first, .init = init_lib)
{
    char *str = strdup("Hello World");

    cr_assert_eq(strstr(str, "or"), my_strstr(str, "or"));
    free(str);
}

Test(strstr, test_strstr_end, .init = init_lib)
{
    char *str = strdup("Hello World");

    cr_assert_eq(strstr(str, "orld"), my_strstr(str, "orld"));
    free(str);
}

Test(strcspn, test_strcspn_classic, .init = init_lib)
{
    char *str = strdup("Hello World");

    cr_assert_eq(strcspn(str, "W"), my_strcspn(str, "W"));
    free(str);
}

Test(strcspn, test_strcspn_classic2, .init = init_lib)
{
    char *str = strdup("Hello World");

    cr_assert_eq(strcspn(str, "Wo"), my_strcspn(str, "Wo"));
    free(str);
}

Test(strcspn, test_strcspn_not_found, .init = init_lib)
{
    char *str = strdup("Hello World");

    cr_assert_eq(strcspn(str, "a"), my_strcspn(str, "a"));
    free(str);
}

Test(strcspn, test_strcspn_empty1, .init = init_lib)
{
    char *str = strdup("");

    cr_assert_eq(strcspn(str, "W"), my_strcspn(str, "W"));
    free(str);
}

Test(strcspn, test_strcspn_empty2, .init = init_lib)
{
    char *str = strdup("Hello World");

    cr_assert_eq(strcspn(str, ""), my_strcspn(str, ""));
    free(str);
}

Test(index, test_index_classic, .init = init_lib)
{
    cr_assert_eq(index("Hello World", 'W'), my_index("Hello World", 'W'));
}

Test(index, test_index_classic2, .init = init_lib)
{
    cr_assert_eq(index("W", 'W'), my_index("W", 'W'));
}

Test(index, test_index_empty, .init = init_lib)
{
    cr_assert_eq(index("", 'W'), my_index("", 'W'));
}

Test(index, test_index_null, .init = init_lib)
{
    cr_assert_eq(index("Hello", 'w'), my_index("Hello", 'W'));
}

Test(rindex, test_rindex_classic, .init = init_lib)
{
    cr_assert_eq(rindex("Hello World", 'W'), my_rindex("Hello World", 'W'));
}

Test(rindex, test_rindex_classic2, .init = init_lib)
{
    cr_assert_eq(rindex("W", 'W'), my_rindex("W", 'W'));
}

Test(rindex, test_rindex_empty, .init = init_lib)
{
    cr_assert_eq(rindex("", 'W'), my_rindex("", 'W'));
}

Test(rindex, test_rindex_null, .init = init_lib)
{
    cr_assert_eq(rindex("Hello", 'w'), my_rindex("Hello", 'W'));
}

Test(memfrob, test_memfrob_full, .init = init_lib)
{
    char *str1 = strdup("Hello");
    char *str2 = strdup("Hello");

    str1 = memfrob(str1, 5);
    str2 = my_memfrob(str2, 5);
    cr_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}

Test(memfrob, test_memfrob_not_full, .init = init_lib)
{
    char *str1 = strdup("Hello World");
    char *str2 = strdup("Hello World");

    str1 = memfrob(str1, 5);
    str2 = my_memfrob(str2, 5);
    cr_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}

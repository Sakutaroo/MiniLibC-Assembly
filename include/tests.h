/*
** EPITECH PROJECT, 2023
** tests
** File description:
** tests
*/

#ifndef TESTS_H_
    #define TESTS_H_
    #include <unistd.h>
    #include <string.h>
    #include <strings.h>

size_t (*my_strlen)(const char *);
char *(*my_strchr)(const char *, int);
char *(*my_strrchr)(const char *, int);
void *(*my_memset)(void *, int, size_t);
void *(*my_memcpy)(void *, const void *, size_t);
int (*my_strcmp)(const char *, const char *);
void *(*my_memmove)(void *, const void *, size_t);
int (*my_strncmp)(const char *, const char *, size_t);
char *(*my_strpbrk)(const char *, const char *);
int (*my_strcasecmp)(const char *, const char *);
char *(*my_strstr)(const char *, const char *);
size_t (*my_strcspn)(const char *, const char *);
char *(*my_index)(const char *, int);
char *(*my_rindex)(const char *, int);
void *(*my_memfrob)(void *, size_t);

#endif /* !TESTS_H_ */

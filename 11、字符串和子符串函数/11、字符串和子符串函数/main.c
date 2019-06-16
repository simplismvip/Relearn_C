//
//  main.c
//  11、字符串和子符串函数
//
//  Created by 赵俊明 on 2019/5/18.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void put1(const char *string);
int put2(const char *string);
void testFunc(void);
void getlen(const char *string,unsigned int size);
void change(char *string);
void mod_str(void);
void toUpper(char *str);
int PunctCount(char *str);
void sort_str(void);
int main(int argc, const char * argv[])
{
    const char *str = "Enough about me - what's your name?";
//    while (*str) {
//        *str = toupper(*str);
//        str++;
//    }
//    printf("%s",str);
//    put1(str);
//    put2(str);
//    change(str);
//    mod_str();
    sort_str();
    return 0;
}
void testFunc(void)
{
    const char *m3[] = {"\nEnough about me - what's your name?\n"};
    char m2[] = "\nEnough about me - what's your name?";
    printf("%s--%s",m2,*m3);
}

// 这里不改变传入字符串，形参使用const限定符。
// 这里字符串值不可更改，但是指针可以递增。移动指针获取字符串不同的值。
// ++优先级高于*，因此*string=*(string++)；
void put1(const char *string)
{
    while (*string !='\0') {
        putchar(*string++);
    }
}

int put2(const char *string)
{
    int count = 0;
    while (*string) {
        putchar(*string++);
        count++;
    }
    putchar('\n');
    return count;
}

// 字符串函数
// srelen(),strcat(),strcmp(),strncmp(),strcpy(),strncpy()
void getlen(const char *string,unsigned int size)
{
    
}

void fit(char *string,unsigned int size)
{
    if (strlen(string)> size) {
        string[size] = '\0';
    }
}

void change(char *string)
{
    while (*string) {
        *string = '1';
    }
    printf("%s\n",string);
}

#define LIMIT 81
void mod_str(void)
{
    char line[LIMIT];
    char *find;
    puts("Please enter a line");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n');
    if (find) {
        *find = '\0';
    }
    toUpper(line);
    puts(line);
    printf("That lin has %d punctuation characters.\n",PunctCount(line));
}

void toUpper(char *str)
{
    while (*str) {
        // 小写变大写
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(char *str)
{
    int ct = 0;
    while (*str) {
        // 判断是否是变电符号
        if (ispunct(*str)) {
            ct++;
        }
        str++;
    }
    return ct;
}

// 字符串排序
#define SIZE 81
#define LIM 20
#define HALT ""
void sort_str(void)
{
    char input[LIM][SIZE] = {"hellow","no hao","zheshi yige","tianyahaijiao","bucuow","you a my des"};
    char *ptstr[LIM];
    // 指针赋值给ptstr
    for (int i = 0; i < 6; i ++) {
        ptstr[i] = input[i];
    }
    
}
void sort1(char *strings[])
{
    // 排序
    for (int i = 0; i < 6; i ++) {
        for (int j = i+1; j < 6; j ++) {
            if (strcmp((strings[i]), strings[j])>0) {
                char *temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

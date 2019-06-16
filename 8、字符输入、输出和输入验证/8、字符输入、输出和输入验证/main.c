//
//  main.c
//  8、字符输入、输出和输入验证
//
//  Created by 赵俊明 on 2019/5/10.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
void echoChar(void);
void echo_eof(void);
void echo_file(void);
void guess(void);
void guess_a(void);
void display(char ch,int lines,int width);
void showchar(void);
char get_choice(void);
void count(void);
void get_choice_start(void);
int main(int argc, const char * argv[]) {
    
//    echoChar();
//    echo_eof();
//    echo_file();
//    guess();
//    guess_a();
//    showchar();
    return 0;
}

void echoChar(void)
{
    char ch;
    while ((ch = getchar()) != '#') {
        putchar(ch);
    }
}

void echo_eof(void)
{
    int ch;
    while ((ch=getchar()) != EOF) {
        putchar(ch);
    }
}

void echo_file(void)
{
    int ch;
    FILE *fp;
    char fname[50];
    printf("输入文件名字：\n");
    scanf("%s",fname);
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("文件读取失败");
//        exit(1);
        return;
    }
    while ((ch=getc(fp))!=EOF) {
        putchar(ch);
    }
    fclose(fp);
}

// 输出结果来看这个程序有一个问题
// 首先输入n的时候while循环读取结果后作出判断，然后读取换行字符进行第二次判断
// 所以这导致进行了两次判断
void guess(void)
{
    int guess = 1;
    printf("挑选一个数，我将猜出这个数。如果正确输入y如果错误输入n\n");
    printf("我猜这个数是1！\n");
    char ch;
    while ((ch=getchar())!='y') {
        printf("这个数是%d吗?\n",++guess);
        // 读取的字符不是y，可能是换行符，遇到这个需要跳过
        // 这里判断是不是‘\n’,如果不是继续。如果是等待
        if (getchar()!='\n') {
            continue;
        }
//        while (getchar()!='\n') {
//            continue;
//        }
    }
    printf("哈，被我猜出来了!\n");
}
/*
 输出结果：
 挑选一个数，我将猜出这个数。如果正确输入y如果错误输入n
 我猜这个数是1！
 n
 这个数是2吗?
 这个数是3吗?
 n
 这个数是4吗?
 这个数是5吗?
 */

// 这是修正过的程序，试图修复读取'\n'当作输入的问题
void guess_a(void)
{
    int guess = 1;
    printf("挑选一个数，我将猜出这个数。如果正确输入y如果错误输入n\n");
    printf("我猜这个数是1！\n");
    char ch;
    while ((ch=getchar())!='y' && ch !='\n') {
        printf("这个数是%d吗?\n",++guess);
        // 读取的字符不是y，可能是换行符，遇到这个需要跳过
        while (getchar()!='\n') {
            continue;
        }
    }
    printf("哈，被我猜出来了!\n");
}

void showchar(void)
{
    int ch;
    int row,cols;
    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n') {
        if (scanf("%d %d",&row,&cols) != 2) {
            break;
        }
        display(ch, row, cols);
        while (getchar() != '\n') {
            continue;
        }
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to qquit.\n");
    }
    printf("Buy!\n");
}

void display(char ch,int lines,int width)
{
    int row,col;
    for (row = 1; row<= lines; row++) {
        for (col = 1; col<=width; col++) {
            putchar(ch);
        }
        putchar('\n');
    }
}

void get_choice_start(void)
{
    int choice;
    while ((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Buy low, sell high.\n");
                break;
            case 'b':
                putchar('\a');
                break;
            case 'c':
                count();
                break;
            default:printf("Program error!\n");
                break;
        }
    }
}

char get_choice(void)
{
    int ch;
    printf("Enter thr letter of your choice.\n");
    printf("a.  advice                b. bell\n");
    printf("c.  count                 q. quit\n");
    ch = getchar();
    while ((ch < 'a' || ch > 'c') && ch != 'a') {
        printf("Please respond with a,b,c,or q\n");
        ch = getchar();
    }
    return ch;
}

void count(void)
{
    
}

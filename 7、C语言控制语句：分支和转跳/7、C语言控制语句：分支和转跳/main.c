//
//  main.c
//  7、C语言控制语句：分支和转跳
//
//  Created by 赵俊明 on 2019/5/10.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void colddats(void);
void cypher(void);
void cypherNew(void);
void findPrime(void);
void chcount(void);
void wordcount(void);
int main(int argc, const char * argv[]) {
//        colddats();
//        cypher();
//        cypherNew();
//        findPrime();
//    chcount();
    wordcount();
    return 0;
}

void colddats(void)
{
    const int FREEZING = 0;
    float temperature;
    int cold_days = 0;
    int all_days = 0;
    printf("输入当日最低温度。\n");
    printf("输入q退出\n");
    while (scanf("%f",&temperature)==1) {
        all_days ++;
        if (temperature < FREEZING) {
            cold_days++;
        }
    }
    if (all_days !=0) {
        printf("%d 天数总共：%.1f%%在零点以下\n",all_days,100.0*(float)cold_days/all_days);
    }
    if (all_days==0) {
        printf("NO data entered!\n");
    }
}

#define SPACE ' '
void cypher(void)
{
    char ch;
    // !=运算符优先级高于=
    while ((ch = getchar()) != '\n') {
        if (ch==SPACE) {
            putchar(ch);
        }else{
            putchar(ch+1);
        }
        ch = getchar();
    }
    putchar(ch);
}

// Look!It's a programmer!
void cypherNew(void)
{
    char ch;
    // !=运算符优先级高于=
    while ((ch = getchar()) != '\n') {
        // 判断是否是字母,这里不改变标点符号
        if (isalpha(ch)) {
            putchar(ch+1);
        }else{
            putchar(ch);
        }
    }
    // 这里打印换行
    putchar(ch);
}

// 寻找素数
// 素数n指除了1和本身外不能背其他任何数整除。
// 所以可以设计一个循环从2到n，如果取余能被整出，不是素数，否则是。
void findPrime(void)
{
    unsigned long num;
    unsigned long div;
    bool isPrime = false;
    printf("输入一个数：\n");
    while (scanf("%lu",&num) == 1) {
        for (div = 2,isPrime = true; (div*div) < num; div++) {
            if (num % div ==0) {
                if ((div*div)!=num) {
                    printf("%lu is divisible by %lu and %lu.\n",num,div,num/div);
                }else{
                    printf("%lu is divisible by %lu.\n",num,div);
                }
                isPrime = false;
            }
        }
        
        printf("%lu %s.\n",num,isPrime?"is a Prime":"is not a Prime");
        printf("Please enter another number for analysis;\n");
        printf("Enter q to quit.\n");
    }
    printf("Bye.\n");
}

// 找出一句话里面的非单引号双引号的数量
#define PERIOD '.'
void chcount(void)
{
    char ch;
    int charcount = 0;
    while ((ch = getchar())!= PERIOD) {
        if (ch !='"' && ch != '\'') {
            charcount++;
        }
    }
    printf("There are %d non-quote characters.\n",charcount);
}

#define STOP '|'
void wordcount(void)
{
    char c;//读入字符
    char prev;//读入的前一个字符
    long n_chars = 0L;//字符数
    int n_lines = 0;//行数
    int n_words = 0;//单词数
    int p_lines = 0;//不完整的行数
    bool inword = false;//如果c在单词中，inword等于true
    printf("Enter text to be analysed(| to terminare):\n");
    prev = '\n';
    while ((c=getchar()) != STOP) {
        n_chars++;
        if (c=='\n') {
            n_lines++;
            if (!isspace(c)&&!inword) {
                inword = true;
                n_words++;
            }
            if (isspace(c)&&inword) {
                inword = false;
                prev = c;
            }
            if (prev !='\n') {
                p_lines = 1;
            }
            
            printf("characters=%ld,words=%d,lines=%d,",n_chars,n_words,n_lines);
            printf("partial line = %d\n",p_lines);
        }
    }
}

void animals(void)
{
    char ch;
    printf("Give me aletter of the alphabet,and I will give");
    printf("an animal name \n beginning with that letter.\n");
    printf("Please type in a letter;type # to end my act.\n");
    while ((ch=getchar())!='#') {
        if ('\n' == ch) {
            continue;
        }
        if (islower(ch)) {
            switch (ch) {
                case 'a':
                    printf("argali,a wild sheep of asia\n");
                    break;
                case 'b':
                    printf("babirusa,awild pig of malay\n");
                    break;
                case 'c':
                    printf("coati,racoonlike mammal\n");
                    break;
                case 'd':
                    printf("desman, aquatic,molelike critter\n");
                    break;
                case 'e':
                    printf("echidna,the spiny anteater\n");
                    break;
                case 'f':
                    printf("fisher, brownish marter\n");
                    break;
                default:
                    break;
                    
            }
            printf("That's a stumper!\n");
        }else{
            printf("I recognize only lowercase letters.\n");
            while (getchar() !='\n') {
                continue;
            }
            printf("Please type another letter or a #.\n");
        }
    }
    printf("Bye!\n");
}

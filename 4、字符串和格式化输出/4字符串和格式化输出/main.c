//
//  main.c
//  4字符串和格式化输出
//
//  Created by 赵俊明 on 2019/5/6.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define DENSITY 62.4
#define PRAISE "You are an extraordinary being."

void testFunc1(void);
void plains(void);
void strlength(void);
void printout(void);
void testPrint1(void);
void testPrint2(void);
void testPrint3(void);
void testPrint4(void);
void testPrint5(void);
void testPrint6(void);
void testPrint7(void);
void testPrint8(void);
void testPrint9(void);
void testPrint10(void);
void testPrint11(void);
void testPrint12(void);
int main(int argc, const char * argv[]) {
//    testFunc1();
//    plains();
//    strlength();
//    printout();
//    testPrint1();
//    testPrint2();
//    testPrint3();
//    testPrint4();
//    testPrint5();
//    testPrint6();
//    testPrint7();
//    testPrint8();
//    testPrint9();
//    testPrint10();
//    testPrint11();
    testPrint12();
   
    return 0;
}

void testFunc1(void)
{
    float weight,volume;
    int size;
    size_t letters;
    char name[40];
    printf("Hi! What's you frist name?\n");
    scanf("%s",name);
    printf("%s,what's you weighr in pounds?\n",name);
    scanf("%f",&weight);
    size = sizeof(name);
    letters = strlen(name);
    volume = weight/DENSITY;
    printf("Well,%s,your volume is %2.2f cubic feet.\n",name,volume);
    printf("Also, your frist name has %zu letters,\n",letters);
    printf("and we have %d byte to store it.\n",size);
}
void plains(void)
{
    char name[40];
    printf("what's you name?\n");
    scanf("%s",name);
    printf("Hello,%s,%s\n",name,PRAISE);
}
void strlength(void)
{
    char name[40] = "Hi!";
    printf("strlen %zd-sizeof %zd\n",strlen(name),sizeof(name));
    printf("strlen %zd-sizeof %zd\n",strlen(PRAISE),sizeof(PRAISE));
}

#define PI 3.141593
void printout(void)
{
    int number = 7;
    float pies = 12.75;
    int cost = 7800;
    printf("The %d contestants ate %f berry pies.\n",number,pies);
    printf("The values of pi is %f.\n",PI);
    printf("Farewell!thou art too dear for my possessing,\n");
    printf("%c%d\n",'$',2*cost);
}

#define PAGES 336
void testPrint1(void)
{
    printf("*%d*\n",PAGES);
    printf("*%2d*\n",PAGES);
    printf("*%10d*\n",PAGES);
    printf("*%-10d*\n",PAGES);
}

void testPrint2(void)
{
    const double RENT = 3852.99;
    printf("*%f*\n",RENT);
    printf("*%e*\n",RENT);
    printf("*%4.2f*\n",RENT);
    printf("*%3.1f*\n",RENT);
    printf("*%10.3f*\n",RENT);
    printf("*%10.3E*\n",RENT);
    printf("*%+4.2f*\n",RENT);
    printf("*%010.2f*\n",RENT);
}

void testPrint3(void)
{
    printf("%x*%X*%#x\n",31,31,31);
    printf("**%d**% d**% d**\n",31,31,-31);
    printf("**%5d**%5.3d**%05d**%05.3d**\n",6,6,6,6);
}

#define BLURB "Authentic imitation!"
void testPrint4(void)
{
    printf("[%2s]\n",BLURB);
    printf("[%24s]\n",BLURB);
    printf("[%24.5s]\n",BLURB);
    printf("[%-24.5s]\n",BLURB);
}

// 转换不匹配问题
#define WORDS 65618
void testPrint5(void)
{
    short num = PAGES;
    short mnum = -PAGES;
    printf("num as short and unsigned short:%hd*%hu\n",num,num);
    printf("-num as int and unsigned short:%d*%hu\n",mnum,mnum);
    printf("num as int and char:%d*%c\n",num,num);
    printf("WORDS as int short and char:%d*%hd*%c\n",WORDS,WORDS,WORDS);
}

void testPrint6(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;
    printf("%.1e %.1e %.1e %.1e\n",n1,n2,n3,n4);
    printf("%ld %ld\n",n3,n4);
    printf("%ld %ld %ld %ld\n",n1,n2,n3,n4);
}

void testPrint7(void)
{
    int age;
    float assets;
    char pet[30];
    printf("Enter you age,assets,and favorite pet\n");
    scanf("%d %f",&age,&assets);
    scanf("%s",pet);
    printf("%d $%.2f %s\n",age,assets,pet);
}

void testPrint8(void)
{
    int input;
    char str[30];
    printf("please input numbers:\n");
    scanf("%d",&input);
    scanf("%s",str);
    printf("output is %d,str is %s\n",input,str);
}

void testPrint9(void)
{
    float input;
    int number;
    printf("please input numbers:\n");
    scanf("%2f",&input);
    scanf("%2d",&number);
    printf("input is %f\n",input);
    printf("number is %d\n",number);
}

void testPrint10(void)
{
    int number1;
    int number2;
    printf("please input numbers:\n");
    scanf("%d,-=%d",&number1,&number2);
    printf("number is %d--%d\n",number1,number2);
}

void testPrint11(void)
{
    unsigned width,precision;
    int number = 256;
    double weight = 242.5;
    printf("Please enter width!\n");
    scanf("%d",&width);
    printf("The number is:%*d\n",width,number);
    printf("Now enter a width and aprecision:\n");
    scanf("%d %d",&width,&precision);
    printf("Weight=%*.*f\n",width,precision,weight);
}

void testPrint12(void)
{
    int n;
    printf("Please enter three intger\n");
    scanf("%*d %*d %d",&n);
    printf("last number is %d\n",n);
}

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

int main(int argc, const char * argv[]) {
//    testFunc1();
//    plains();
    strlength();
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

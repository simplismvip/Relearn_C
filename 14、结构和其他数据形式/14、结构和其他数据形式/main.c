//
//  main.c
//  14、结构和其他数据形式
//
//  Created by 赵俊明 on 2019/5/29.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "structFunc.h"
#include "names1.h"
#include "names2.h"
#include "names3.h"
#define MAXTITLE 41
#define MAXAUTL 31
#define LEN 20
struct book {
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};

struct names {
    char frist[LEN];
    char last[LEN];
};
struct guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

const char *magsp[5] = {
    "Thank you for the wonderful evening",
    "You certainly prove that a",
    "is a special king of guy.we must get together",
    "over a delicious",
    "and have a few laughs",
};
char *str_gets(char *st,int n);
int main(int argc, const char * argv[]) {
//    struct book library;
//    printf("Please enter the book title.\n");
//    str_gets(library.title, MAXTITLE);
//    printf("Now enter thr author.\n");
//    str_gets(library.author, MAXAUTL);
//    printf("Now enter thr value.\n");
//    scanf("%f",&library.value);
//    printf("%s by %s:$%.2f\n",library.title,library.author,library.value);
//    printf("Done!\n");
    start();
//    start2();
//    start3();
    return 0;
}

void friends(void)
{
    struct guy fellow = {
        {"Ewen","Villard"},
        "grilled salmon",
        "persionality caoch",
        6812.00
    };
    printf("Dear%s,\n\n",fellow.handle.frist);
    printf("%s%s.\n",magsp[0],fellow.handle.frist);
    printf("%s%s\n",magsp[1],fellow.job);
    printf("%s\n",magsp[2]);
    printf("%s%s%s\n",magsp[3],fellow.favfood,magsp[4]);
    if (fellow.income > 15000.0) {
        puts("!!");
    }else{
        puts(".");
    }
    printf("\n%40s%s\n","","See you soon");
    printf("\n%40s%s\n","","Shalala");
}

#define MAXBKS 100
void manybooks(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    printf("Press enter at the start of a line to stop.\n");
    while (count<MAXBKS && str_gets(library[count].title, MAXTITLE) != NULL && library[count].title[0]!='\0') {
        printf("Now enter the author.\n");
        str_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f",&library[count++].value);
        while (getchar()!='\n') {
            continue;
        }
        if (count<MAXBKS) {
            printf("Enter the next title\n");
        }
    }
    if (count>0) {
        printf("Here is the list of your books:\n");
        for (index = 0; index< count; index++) {
            printf("%sby %s:$%.2f\n",library[index].title,library[index].author,library[index].value);
        }
    }else{
        printf("No books?Too bad.\n");
    }
}

char *str_gets(char *st,int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        // 查找‘\n’在st字符串中c首次出现的位置，找到返回st中相同字符的指针
        // 找不到返回NULL
        find = strchr(st, '\n');
        if (find) {
            // 找到讲换行符替换为结束符
            *find = '\0';
        }
    }else{
        while (getchar() != '\n') {
            continue;
        }
    }
    return ret_val;
}


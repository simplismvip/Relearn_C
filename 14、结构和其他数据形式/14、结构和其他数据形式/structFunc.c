//
//  structFunc.c
//  14、结构和其他数据形式
//
//  Created by 赵俊明 on 2019/5/30.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "structFunc.h"
#define FUNDLEN 50
struct funds{
    char bank[FUNDLEN];
    double banfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(double n1,double n2);
double sum1(const struct funds *fund);
double sum2(struct funds fund);
// 传递结构成员
void structFunc1(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        12.34,
        "Lucky's Savings and Loan",
        98.99
    };
    printf("Stan has a total of $%.2f.\n",sum(stan.banfund, stan.savefund));
}
// 传递结构指针
void structFunc2(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        12.34,
        "Lucky's Savings and Loan",
        98.99
    };
    printf("Stan has a total of $%.2f.\n",sum1(&stan));
}
// 传递结构
void structFunc3(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        12.34,
        "Lucky's Savings and Loan",
        98.99
    };
    printf("Stan has a total of $%.2f.\n",sum2(stan));
}

double sum2(struct funds fund)
{
    return (fund.banfund+fund.savefund);
}

double sum1(const struct funds *fund)
{
    return (fund->banfund+fund->savefund);
}
double sum(double n1,double n2)
{
    return (n1+n2);
}

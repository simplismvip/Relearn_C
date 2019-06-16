//
//  structArr.c
//  14、结构和其他数据形式
//
//  Created by 赵俊明 on 2019/5/30.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "structArr.h"
#define FUNDLEN 50
#define N 2
struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum3(const struct funds money[],int n);
void start5(void);

void start5(void)
{
    struct funds jones[N] = {
        {
            "Garlic-Melon Banlk",
            30299.37,
            "Lucky's SSavings and Loan",
            8543.94
        },
        {
            "Honest-Melon Banlk",
            3629.09,
            "Party Time Savings",
            2803.91
        },
    };
    printf("The Jonese have of $%.2f\n",sum3(jones,2));
    
}

double sum3(const struct funds money[],int n)
{
    double total = 0.0;
    for (int i = 0; i < n ; i ++) {
        struct funds jone = *(money+i);
        total = jone.bankfund+jone.savefund;
    }
    return total;
}

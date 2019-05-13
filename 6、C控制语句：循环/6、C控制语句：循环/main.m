//
//  main.m
//  6、C控制语句：循环
//
//  Created by 赵俊明 on 2019/5/10.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#import <Foundation/Foundation.h>
void sorese_in(void);
double power(double n,int num);
void testfunc1(void);
int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        sorese_in();
//        power(2.5, 10);
        testfunc1();
    }
    return 0;
}

#define SIZE 10
#define PAR 72
void sorese_in(void)
{
    int index,score[SIZE];
    int sum=0;
    float average;
    printf("Enter %d golf scores:\n",SIZE);
    for (index = 0; index< SIZE; index++) {
        scanf("%d",&score[index]);
        printf("%5d",score[index]);
        sum+=score[index];
    }
    printf("\n");
    average = (float)sum/SIZE;
    printf("Sum of score=%d,average =%.3f\n",sum,average);
    printf("That's a handicap of %.0f.\n",average-PAR);
}

double power(double n,int num)
{
    double sum=1;
    for (int i = 0; i < num; i ++) {
        sum*=n;
    }
    printf("sum is %f\n",sum);
    return sum;
}

void testfunc1(void)
{
    double x;
    int exp;
    printf("请输入要计算的数和幂数：\n");
    // scanf()函数返回成功读取参数数
    while (scanf("%lf%d",&x,&exp) == 2) {
        double n = power(x, exp);
        printf("%.2f的%d次幂为%.3f\n",x,exp,n);
        printf("输入q退出，继续输入：\n");
    }
}


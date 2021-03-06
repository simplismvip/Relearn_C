//
//  main.c
//  数据和C
//
//  Created by 赵俊明 on 2019/5/5.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
void testFunc(void);

int main(int argc, const char * argv[]) {
    float weight;// 你的体重
    float value;// 相等重量白金价格
    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds:");
//    scanf("%f",&weight);
    weight = 60;
    value=1700.0*weight*14.5833;
    printf("Your weight in platinum is worth $%.2f.\n",value);
    printf("You are easily worth that! If platinum price drop,\n");
    printf("eat more to maintain your value.\n");
    printf("%lu-%lu-%lu-%lu-%lu-%lu-%lu字节\n",sizeof(char),sizeof(int),sizeof(short int),sizeof(long int),sizeof(long long int),sizeof(float),sizeof(double));
    
    testFunc();
    return 0;
}

// 测试整数溢出情况
void testFunc(void)
{
    // int 4位32字节最大表示数位-2^32~2^31-1 (-2147483648~2147483647)
    int i = 2147483647;
    // unsign int 表示最大为0～2^32 (0~4294967296)
    unsigned int j = 4294967295;
    printf("%d %d %d\n",i,i+1,i+2);
    printf("%u %u %u\n",j,j+1,j+2);
}           

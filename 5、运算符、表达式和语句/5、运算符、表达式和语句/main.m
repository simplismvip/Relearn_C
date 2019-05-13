//
//  main.m
//  5、运算符、表达式和语句
//
//  Created by 赵俊明 on 2019/5/8.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#import <Foundation/Foundation.h>
void testfunc1(void);
void sorese_in(void);

int main(int argc, const char * argv[]) {
//    testfunc1();
    sorese_in();
    return 0;
}

#define SEC_PRE_MIN 60
void testfunc1(void)
{
    int seconds,min,sec;
    printf("please input seconds:\n");
    scanf("%d",&seconds);
    while (seconds > 0) {
        min = seconds/SEC_PRE_MIN;
        sec = seconds%SEC_PRE_MIN;
        printf("%d seconds is %d min,%d sec.\n",seconds,min,sec);
        printf("please input next seconds:\n");
        scanf("%d",&seconds);
    }
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

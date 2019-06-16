//
//  main.c
//  树
//
//  Created by 赵俊明 on 2019/5/30.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
// 回掉函数指针
void (*callback)(const char *);
void feedback(const char *desc);
void Max(int a,int b, void (*callback)(const char *));

int main(int argc, const char * argv[]) {
    Max(10, 20, feedback);
    return 0;
}

void Max(int a,int b, void (*callback)(const char *))
{
    int temp = a>b?a:b;
    (*callback)("测试成功，回掉开始");
}

void feedback(const char *desc)
{
    printf("%s\n",desc);
}



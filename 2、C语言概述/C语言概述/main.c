//
//  main.c
//  C语言概述
//
//  Created by 赵俊明 on 2019/5/5.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>

void testFunc(void);
int main(int argc, const char * argv[]) {
    int num = 1;
    printf("I am a simple.\n");
    printf("Compture.\n");
    printf("My favorate number is %d because it is frist.\n",num);
    testFunc();
    return 0;
}

void testFunc(void)
{
    int feet,fathoms;
    fathoms = 2;
    feet = 6*fathoms;
    printf("There are %d feet in %d fathoms!\n",feet,fathoms);
    printf("Yes, I said %d feet!\n",6*fathoms);
}

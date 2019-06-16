//
//  main.c
//  10、数组和指针
//
//  Created by 赵俊明 on 2019/5/16.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
void zippo(void);
void testfunc(void);
void testfunc2(int (*arr)[5],int count);
int main(int argc, const char * argv[]) {
//    zippo();
//    testfunc();
//    int junk[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,12,13,14},{15,16,17,18,19},{21,22,23,24,25}};
//    testfunc2(junk,5);
    return 0;
}

void testfunc2(int (*arr)[5],int count)
{
    int in = 0;
    for (int i = 0; i < count; i ++) {
        int *subArr = *(arr+i);
        for (int j = 0; j < count; j ++) {
            in += *(subArr+j);
        }
    }
    printf("in=%d\n",in);
}

void testfunc1(void)
{
    const int **p2;
    int *p1;
    const int n = 12;
    //这一步也是x允许的，但是很危险
    p2 = &p1;
    
    // 这一步修改了p2的值，使const失效
    *p2 = &n;
    *p1 = 10;
}

void testfunc(void)
{
    int x = 1;
    int y = 2;
    
    int *p = &x;
    const int *q = &y;
    printf("%d\n",*q);
    
    // 这个修改了const修饰的变量，不安全
    p = q;
    *p = 10;
    printf("%d\n",*q);
    
    // 非const指针赋值给const指针，是允许的
    q = p;
    
    // int const *p等价 const int *p
    // 数据类型对于const而言是透明的
    // 可以记忆为const （*p）,p指向地址的内容不可改变，但是p指向的地址是可以改变的这就是sort函数可以进行排序的原因
    
    // int *const p
    // 可以记忆为*（const p），const修饰的地址，p指向的地址不可改变，但是p指向地址的内容可以改变
    int z = 10;
    int *const m = &z;
    int const* mm = &z;
}

void zippo(void)
{
    // 指针指向数组的首个元素，指针相加相当于加上首歌元素大小的倍数
    // int类型对指针地址加n，其值会增加 sizeof(int)*n
    // 多维数组内元素m个元素，则会增加sizeof(int)*m
    int zippo[4][2]={{2,4},{6,8},{1,3},{5,7}};
    // 声明二维数组
    int (*pz)[2];
    pz = zippo;
    printf("pz=%p,pz+1=%p\n",pz,pz+1);
    printf("pz[0]=%p,pz[0]+1=%p\n",pz[0],pz[0]+1);
    printf("*pz=%p,*pz+1=%p\n",*pz,*pz+1);
    printf("pz[0][0]=%d\n",pz[0][0]);
    printf("*pz[0]=%d\n",*pz[0]);
    printf("**pz=%d\n",**pz);
    printf("pz[2][1]=%d\n",pz[2][1]);
    // 这个结果是8，pz指向的对象占用了两个int大小，*pz指向的对象占用了一个int大小
    printf("*(*pz[2]+1)=%d\n",*((*pz+2)+1));
    // 这个结果是3
    printf("*(*pz[2]+1)=%d\n",*(*(pz+2)+1));
    printf("*(*pz[2]+1)=%d\n",*(*pz+2));
}


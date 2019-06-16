//
//  main.c
//  算法练习
//
//  Created by 赵俊明 on 2019/5/21.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
int * findTarget(int nums[],int target,int count);
void reverseStr1(char *str,size_t len);
void reverseStr(char *str);
void xuanzeSort(int *num,int len);
void maopaoSort(int *num,int len);
void logArray(int *arr,int len);
void insertionSort(int *num,int len);
int main(int argc, const char * argv[]) {
//    char str[] = "1234567890";
//    reverseStr(str);
//
//    char str1[] = "1234567890";
//    reverseStr1(str1,10);
//    int sort1[] = {2,3,1,5,19,4,98,32,45,9,5};
//    maopaoSort(sort1, 11);
//    int sort2[] = {10,3,18,5,9,24,8,21,45,9,25};
//    xuanzeSort(sort2, 11);
    int nums[4] = {2, 7, 11, 15};
    int *nu = findTarget(nums,9,4);
    for (int i = 0; i < 2; i ++) {
        printf("%d\n",*(nu+i));
    }
    return 0;
}

//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//示例:
//给定 nums = [2, 7, 11, 15, 3, 6], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
int * findTarget(int nums[],int target,int count)
{
    static int tempArr[2];
    _Bool flag = 0;
    for (int i = 0; i < count; i ++) {
        if (flag) {break;}
        int n1 = *(nums+i);
        for (int j = 0; j < count; j ++) {
            int n2 = *(nums+j);
            if (n1+n2==target) {
                *tempArr = i;
                *(tempArr+1) = j;
                flag = 1;
                break;
            }
        }
    }
    return tempArr;
}

// 字符串翻转算法
void reverseStr(char *str)
{
    char *p = str;
    char *q = str;
    while (*q !='\0') {
        q++;
    }
    q--;
    while (p < q) {
        char temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
    printf("%s\n",str);
}

// 字符串翻转算法
void reverseStr1(char *str,size_t len)
{
    char *start = str;
    char *end = str+len-1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    printf("%s\n",str);
}

// 冒泡排序算法
void maopaoSort(int *num,int len)
{
    // 外层循环为比较趟数，每一堂都找到一个最大元素，放到最后
    for (int i = 0; i < len; i ++) {
        // 内层循环为交换次数，因为每一次完整比较都会找到最大元素
        // 所以每次内层循环就可以减少交换次数（即i是几就已经有几个元素完成排序了）
        for (int j = 0; j < len-i-1; j ++) {
            if (*(num+j)>*(num+j+1)) {
                int temp = *(num+j);
                *(num+j) = *(num+j+1);
                *(num+j+1) = temp;
            }
        }
    }
    logArray(num,len);
}

// 选择排序
// 先找到最小的放在起始位置，再从剩下的找到最小值放到排好的后面
void xuanzeSort(int *num,int len)
{
    int indexMin;
    for (int i = 0; i < len; i ++) {
        indexMin = i;
        for (int j = i+1; j < len; j ++) {
            // 这里找到最小值更新索引，然后继续找，找到了接着更新
            if (*(num+j) < *(num+indexMin)) {
                // 这里更新最小索引值
                indexMin = j;
            }
        }
        // 当前值
        int temp = *(num+i);
        *(num+i) = *(num+indexMin);
        *(num+indexMin) = temp;
    }
    logArray(num,len);
}

// 插入排序
void insertionSort(int *num,int len)
{
    
}

void logArray(int *arr,int len)
{
    for (int i = 0; i < len; i ++) {
        printf("%d,",*(arr+i));
    }
    printf("\n");
}

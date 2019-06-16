//
//  fseek_test.c
//  13、文件输入、输出
//
//  Created by 俊明 on 2019/6/4.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "fseek_test.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 5
typedef struct student{
    long sno;
    char name[10];
    float score[3];
}STU;

// size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
// 函数向制定文件中写入若干数据块，如果执行成功则返回实际写入的数据块数目。该函数以二进制行事对文件进行操作
// buffer：指针类型，要获取数据的地址
// size：要写入内容的单字节数
// count：要写入size字节的数据项的个数
// stream：目标文件指针
void fun_insert(const char *fileName,STU n)
{
    FILE *fp;
    if ((fp = fopen(fileName, "rb+")) != NULL) {
        fseek(fp, -1L*sizeof(STU), SEEK_END);
        fwrite(&n, sizeof(STU), 1, fp);
        fclose(fp);
    }
}

void logSTU(const STU ss[])
{
    int i,j;
    for (j=0; j<N; j++) {
        printf("\nNo:%ld Name:%-8sScores:",ss[j].sno,ss[j].name);
        for (i = 0; i< 3; i++) {
            printf("%6.2f",ss[j].score[i]);
        }
    }
    printf("\n");
}

// size_t fread ( void *buffer, size_t size, size_t count, FILE *stream) ;
// buffer：用于接收数据到内存地址
// size：要读到每个数据项的字节数
// count：要读的数据项个数，每个数据项size字节
// stream：输入流
// "/Users/jl/Desktop/Code/Relearn_C/source/student.dat"
void start(const char *path)
{
    STU t[N] = {
        {10001,"MaChao",91,92,77},
        {10002,"CaoKai",75,60,88},
        {10003,"LiSi",85,70,78},
        {10004,"FangFang",90,82,87},
        {10005,"ZhangSan",95,80,88}
    };
    // 1、写入数据到文件
    FILE *fp;
    if ((fp=fopen(path, "wb")) == NULL) {
        printf("打开文件失败");
        exit(EXIT_FAILURE);
    }
    fwrite(t, sizeof(STU), N, fp);
    fclose(fp);
    
    // 2、读取文件内容
    STU ss[N];
    if ((fp=fopen(path, "rb")) == NULL) {
        printf("打开文件失败");
        exit(EXIT_FAILURE);
    }
    fread(ss, sizeof(STU), N, fp);
    fclose(fp);
    printf("\nThe original data:\n");
    logSTU(ss);
    
    // 添加新元素到文件
    STU n = {10006,"ZhaoYun",51,70,97};
    fun_insert(path, n);
    // 3、再次读取更新后的文件
    if ((fp=fopen(path, "rb")) == NULL) {
        printf("打开文件失败");
        exit(EXIT_FAILURE);
    }
    fread(ss, sizeof(STU), N, fp);
    fclose(fp);
    printf("\nThe modifing after data:\n");
    logSTU(ss);
}

#define BUFFER_SIXE 1024*1024 //1M
void read_image(const char *path)
{
    FILE *fp;
    if ((fp=fopen(path, "rb")) == NULL) {
        printf("打开照片流失败\n");
        exit(EXIT_FAILURE);
    }
    unsigned char *buf = (unsigned char *)malloc(BUFFER_SIXE);
    fread(buf, 1, BUFFER_SIXE, fp);
    for (int i = 0; i < BUFFER_SIXE; i ++) {
        printf("%c\n",buf[i]);
    }
    fclose(fp);
}

void read_imageSize(const char *path)
{
    FILE *fp;
    if ((fp=fopen(path, "rb")) == NULL) {
        printf("打开照片流失败\n");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    size_t size = ftell(fp);
    fclose(fp);
    printf("size:%lu\n",size/1024);
}

void ungetc_test(void)
{
    int ch;
    int result = 0;
    printf("Enter an integer:");
    // getchar读取缓冲区中的字符，调用getchar函数时，程序就等待用户按键，用户输入的字符被存储到键盘缓冲区，知道用户按回车为止，按下回车getchar才
    // 开始从stdio流中取入一个字符，返回值是读取的字符或者EOF。
    while ((ch = getchar()) != EOF && isdigit(ch)) {
        // ch-'0'：为了把ch转换为数字，实际上是两个ASCII码值相减
        // result*10保证几位数字乘几次10，保证最高位正确
        result = result*10+ch-'0';
        printf("char:%c,ch-'0':%d\n",ch,result);
    }
    // 最后一次读取到的是字符，把字符放入到输入流中
    if (ch != EOF) {
        // 标准输入流
        ungetc(ch, stdin);
    }
    printf("Number=%d\nNext character in stream=%c\n",result,ch);
}

void setvbuf_test(void)
{
    FILE *input,*outout;
    char bufr[512];
    input = fopen("file.in", "r+b");
    outout = fopen("file.out", "w");
    if (setvbuf(input, bufr, _IOFBF, 512) != 0) {
        printf("fail tp set buf for input file\n");
    }else{
        printf("buf set for input file\n");
    }
    if (setvbuf(outout, NULL, _IOLBF, 132) != 0) {
        printf("fail tp set buf for output file\n");
    }else{
        printf("buf set for output file\n");
    }
    fclose(input);
    fclose(outout);
}

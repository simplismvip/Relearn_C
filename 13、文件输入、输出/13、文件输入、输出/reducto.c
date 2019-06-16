//
//  reducto.c
//  13、文件输入、输出
//
//  Created by 俊明 on 2019/6/3.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "reducto.h"
#include <stdlib.h>
#include <string.h>
#define LEN_S 40
struct RGB {
    unsigned int r;
    unsigned int g;
    unsigned int b;
};

void readRGB(const char *path)
{
    FILE *data;
    if (strlen(path)<1) {
        return;
    }
    if ((data = fopen(path, "rb")) ==NULL) {
        return;
    }
}

long file_size(const char *path)
{
    FILE *data;
    if (strlen(path)<1) {
        return -1;
    }
    if ((data = fopen(path, "rb")) ==NULL) {
        return -1;
    }
    fseek(data, 0, SEEK_END);
    long size = ftell(data);
    fclose(data);
    return size;
    
}

void fput_test(const char *path)
{
    char msg[100];
    printf("输入要写入文件的字符串：\n");
    fgets(msg, 100, stdin);
    
    FILE *fp;
    if ((fp=fopen(path, "a"))==NULL) {
        fprintf(stdout, "打开文件错误");
        exit(EXIT_FAILURE);
    }
    fputs(msg, fp);
    // 返回0表示关闭失败
    if (fclose(fp) != 0) {
        printf("关闭文件失败");
    }
}

void fget_test(const char *path)
{
    FILE *fp;
    char msg[100];
    if ((fp = fopen(path, "r"))==NULL) {
        fprintf(stdout, "打开文件错误");
        exit(EXIT_FAILURE);
    }
    fgets(msg, sizeof(char)*100-1, fp);
    printf("字符串：%s\n",msg);
    // 返回0表示关闭失败
    if (fclose(fp) != 0) {
        printf("关闭文件失败");
    }
}

void fget_test1(const char *path)
{
    FILE *fp;
    char *string = "Thisisatest";
    char msg[20];
    if ((fp=fopen(path, "w+")) != NULL) {
        // 把字符串写入文件
        fwrite(string, sizeof(string), 1, fp);
        fseek(fp, 1, SEEK_SET);
        
        // 从流中读取数据
        fgets(msg, 19, fp);
        printf("%s\n",msg);
        fclose(fp);
    }else{
        printf("打开文件错误\n");
    }
}

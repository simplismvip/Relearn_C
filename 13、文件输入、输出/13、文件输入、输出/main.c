//
//  main.c
//  13、文件输入、输出
//
//  Created by 赵俊明 on 2019/5/25.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reducto.h"
#include "fseek_test.h"

#define LEN 40
#define MAX 41
void testFunc(int argc, const char *argv[]);
void testFunc1(int argc, const char *argv[]);
void logContent(const char *path);
void addaworld(const char *path);
int main(int argc, const char * argv[]) {
//    const char *parmas[3]={"main.c","./Eddy.red.rtf","./eddy.txt"};
//    testFunc1(3,parmas);
//    printf("%d--%s",argc,argv[0]);
//    logContent("/Users/jl/Desktop/Code/Relearn_C/source/eddy.txt");
//    addaworld("/Users/jl/Desktop/Code/Relearn_C/source/eddy.txt");
//    fget_test("/Users/jl/Desktop/Code/Relearn_C/source/fgettest.txt");
//    fput_test("/Users/jl/Desktop/Code/Relearn_C/source/fputtest.txt");
//    start("/Users/jl/Desktop/Code/Relearn_C/source/student.dat");
//    read_image("/Users/jl/Desktop/Code/Relearn_C/source/10.PNG");
//    read_imageSize("/Users/jl/Desktop/Code/Relearn_C/source/10.PNG");
//    long size = file_size("/Users/jl/Desktop/Code/Relearn_C/source/10.PNG");
//    printf("Size:%ld\n",size);
    ungetc_test();
    return 0;
}

#define CNTL_Z '\032'// DOS文本结束标志
#define SLEN 81
void reverse(const char *path)
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count,last;
    puts("Enter the name of the file to be processed\n");
    scanf("%80s",file);
    if ((fp = fopen(path, "rb"))==NULL) {
        printf("reverse can't open %s\n",file);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    for (count = 1L; count<=last; count++) {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch!=CNTL_Z && ch != 'r') {
            putchar(ch);
        }
    }
    putchar('\n');
    fclose(fp);
}

void addaworld(const char *path)
{
    FILE *fp;
    char words[MAX];
    if ((fp=fopen(path, "a+")) == NULL) {
        fprintf(stdout, "Can't open file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter world to add to the file;press the #");
    puts("key at the beginning of a line to terminate.");
    // 读取输入流中的数据存储到word中
    while ((fscanf(stdin, "%40s",words)==1) && (words[0] != '#')) {
        // 输出word到文件中
        fprintf(fp, "%s\n",words);
    }
    puts("File contents");
    rewind(fp);
    // 读取fp中的数据到word中
    while (fscanf(fp, "%s",words) ==1) {
        // 输入内容
        puts(words);
    }
    puts("Done!");
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
    }
}

void logContent(const char *path)
{
    if (strlen(path)<1) {
        exit(EXIT_FAILURE);
    }
    FILE *fp,*out;
    char ch;
    fp = fopen(path, "r");
    out = fopen("/Users/jl/Desktop/Code/Relearn_C/source/new_eddy.txt", "a");
    while ((ch = getc(fp)) != EOF) {
        printf("%c",ch);
        putc(ch, out);
    }
    printf("\n");
    fclose(fp);
}

void testFunc1(int argc, const char *argv[])
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;
    if (argc < 2) {
        fprintf(stderr, "Usage:%s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Usage:%s filename\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    strncpy(name, argv[1], LEN-5);
    name[LEN-5]='\0';
    // extern char *strcat(char *dest, const char *src);
    // 将src内容拼接到dest，返回指向dest的指针
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Usage:%s filename\n",argv[1]);
        exit(3);
    }
    
    while ((ch=getc(in) != EOF)) {
        if (count++ %3 == 0) {
            putc(ch, out);
        }
        if (fclose(in) != 0 || fclose(out) != 0) {
            fprintf(stderr, "Error in closeing files\n");
        }
    }
}

void testFunc(int argc, const char *argv[])
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    if (argc !=2 ) {
        printf("usage:%s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r"))==NULL) {
        printf("Can't open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp))!=EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu character\n",argv[1],count);
}

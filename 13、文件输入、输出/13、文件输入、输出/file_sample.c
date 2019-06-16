//
//  file_sample.c
//  13、文件输入、输出
//
//  Created by 俊明 on 2019/6/11.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "file_sample.h"
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81

void sfile_start(void)
{
    FILE *fa,*fs;// fa指向目标文件，fs指向源文件
    int files = 0; // 附加文件的数量
    char file_app[SLEN];// 目标文件名
    char file_src[SLEN];//源文件名
    int ch;
    puts("Enter name of destination file:");
    sfile_get(file_app, SLEN);
    if ((fa=fopen(file_app, "a+")) == NULL) {
        fprintf(stderr, "Can't open %s\n",file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZ) != 0) {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file(empty line to quit)\n");
    while (sfile_get(file_src, SLEN) && file_src[0] != '\0') {
        if (strcmp(file_src, file_app) == 0) {
            fputs("Can't append file to itself\n", stderr);
        }else if((fs = fopen(file_src, "r")) == NULL){
            fprintf(stderr, "Can't open %s\n",file_src);
        }else{
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZ) != 0) {
                fputs("Cant's create input buffer\n", stderr);
                continue;
            }
            sfile_append(fs,fa);
            if (ferror(fs) != 0) {
                fprintf(stderr, "Erroe in reading file%s.\n",file_src);
            }
            if (ferror(fa) != 0) {
                fprintf(stderr, "Erroe in writing file%s.\n",file_app);
            }
            fclose(fs);
            files++;
            printf("File %s appended.\n",file_src);
            puts("Next file(emputy line to quit)");
        }
    }
    
    printf("Done appending.%d files appended.\n",files);
    rewind(fa);
    printf("%s contents:\n",file_app);
    while ((ch = getc(fa)) != EOF) {
        putchar(ch);
    }
    puts("Done displaying.");
    fclose(fa);
}

char *sfile_get(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) {
            *find='\0';
        }else{
            while (getchar()!='\n') {
                continue;
            }
        }
    }
    return ret_val;
}

void sfile_append(FILE *source,FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZ];
    while ((bytes = fread(temp, sizeof(char), BUFSIZ, source)) > 0) {
        fwrite(temp, sizeof(char), bytes, dest);
    }
}

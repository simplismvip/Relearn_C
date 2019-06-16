//
//  names3.c
//  14、结构和其他数据形式
//
//  Created by 赵俊明 on 2019/5/30.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "names3.h"
#include <stdlib.h>
#include <string.h>
#define SLEN 81
struct namect3 {
    char *fname;
    char *lname;
    int letters;
};

char *s_gets3(char *st,int n);
void getinfo3(struct namect3 *);
void makeinfo3(struct namect3 *);
void showinfo3(const struct namect3*);
void clearnup(struct namect3 *name);

void start3(void)
{
    // 创建结构变量
    struct namect3 name;
    printf("%lu\n",sizeof(name));
    getinfo3(&name);
    makeinfo3(&name);
    showinfo3(&name);
    clearnup(&name);
    printf("%lu\n",sizeof(name));
}

void getinfo3(struct namect3 *pst)
{
    char temp[SLEN];
    printf("Please enter yur first name.\n");
    s_gets3(temp, SLEN);
    pst->fname = malloc(strlen(temp)+1);
    // 拷贝数组到已分配到内存
    // char *strcpy(char* dest, const char *src);
    // 函数从scr地址开始到包含结束符的字符串复制到dest地址开始空间。dest必须有足够空间容纳src字符串。
    strcpy(pst->fname, temp);
    
    printf("Please enter yur last name.\n");
    s_gets3(temp, SLEN);
    pst->lname = malloc(strlen(temp)+1);
    strcpy(pst->lname, temp);
    // 这样的指向字符串的指针因为地址是确定的，就不用担心指针未初始化的问题。但是记得要注意释放空间
}

void makeinfo3(struct namect3 *pst)
{
    pst->letters = (int)(strlen(pst->fname)+strlen(pst->lname));
}

void showinfo3(const struct namect3*pst)
{
    printf("%s%s,your name contains %d letters.\n",pst->fname,pst->lname,pst->letters);
}

void clearnup(struct namect3 *pst)
{
    if (pst->lname) {
        free(pst->fname);
        free(pst->lname);
    }
}

char *s_gets3(char *st,int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        }
    }else{
        while (getchar() != '\n') {
            continue;
        }
    }
    return ret_val;
}

//
//  names1.c
//  14、结构和其他数据形式
//
//  Created by 赵俊明 on 2019/5/30.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "names1.h"
#define NLEN 30
struct namect {
    char fname[NLEN];
    char lName[NLEN];
    int letters;
};
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect*);
char *s_gets(char *st,int n);

void start(void)
{
    // 创建结构变量
    struct namect person;
    printf("%lu\n",sizeof(person));
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    printf("%lu\n",sizeof(person));
}

void getinfo(struct namect *name)
{
    printf("Please enter yur first name.\n");
    s_gets(name->fname, NLEN);
    perror("Please enter yur last name.\n");
    s_gets(name->lName, NLEN);
}
void makeinfo(struct namect *name)
{
    name->letters = (int)(strlen(name->fname)+strlen(name->lName));
}
void showinfo(const struct namect*name)
{
    printf("%s%s,your name contains %d letters.\n",name->fname,name->lName,name->letters);
}
char *s_gets(char *st,int n)
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

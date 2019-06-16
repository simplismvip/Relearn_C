//
//  names2.c
//  14、结构和其他数据形式
//
//  Created by 赵俊明 on 2019/5/30.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "names2.h"
#define NLENS 30
struct namect2 {
    char fname[NLENS];
    char lName[NLENS];
    int letters;
};
struct namect2 getinfos(void);
struct namect2 makeinfos(struct namect2);
void showinfos(const struct namect2);
char *s_getsS(char *st,int n);

void start2(void)
{
    struct namect2 person;
    person = getinfos();
    person = makeinfos(person);
    showinfos(person);
}

struct namect2 getinfos()
{
    struct namect2 temp;
    printf("Please enter yur first name.\n");
    s_getsS(temp.fname, NLENS);
    perror("Please enter yur last name.\n");
    s_getsS(temp.lName, NLENS);
    return temp;
}
struct namect2 makeinfos(struct namect2 name)
{
    name.letters = (int)(strlen(name.fname)+strlen(name.lName));
    return name;
}
void showinfos(const struct namect2 name)
{
    printf("%s%s,your name contains %d letters.\n",name.fname,name.lName,name.letters);
}
char *s_getsS(char *st,int n)
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

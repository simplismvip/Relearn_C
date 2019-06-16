//
//  main.c
//  链表
//
//  Created by 赵俊明 on 2019/5/28.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "sll_insert.h"

int main(int argc, const char * argv[]) {
    // 返回头部链表
    struct NODE *root = create(10);
    sll_insert(root, 5);
    bianli(root);
    del_node(root, 5);
    bianli(root);
    return 0;
}







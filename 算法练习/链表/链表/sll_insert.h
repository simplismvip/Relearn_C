//
//  sll_insert.h
//  链表
//
//  Created by 赵俊明 on 2019/5/28.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#ifndef sll_insert_h
#define sll_insert_h
#include "node.h"
#include <stdio.h>
// 插入节点
_Bool sll_insert(Node *root, int value);
// 删除节点
void del_node(Node *root,int value);
// 初始化链表
Node *create(int n);
// 遍历链表元素
void bianli(Node*root);
// 获取链表元素个数
int ssl_count(Node *root);
#endif /* sll_insert_h */

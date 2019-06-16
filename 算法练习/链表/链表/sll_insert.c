//
//  sll_insert.c
//  链表
//
//  Created by 赵俊明 on 2019/5/28.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#include "sll_insert.h"
#include <stdlib.h>

// current：根链表
_Bool sll_insert(Node *root, int value)
{
    // 找到大于插入值的节点的上一个节点
    Node *preview = NULL;
    while (root->value < value) {
        preview = root;
        printf("%d--%d\n",value,root->value);
        root = root->link;
    }
    Node *new = (Node *)malloc(sizeof(Node));;
    if (preview) {
        preview->link = new;
        // 新节点指向下一个节点
        new->link = root;
        new->value = value;
        return 1;
    }else{
        return 0;
    }
}

// 遍历一个链表
void bianli(Node*root)
{
    while (root) {
        printf("%p--%d\n",root->link,root->value);
        root=root->link;
    }
}

// 删除一个链表
void del_node(Node *root,int value)
{
    Node *preview = NULL;
    while (root->value < value) {
        // 找到要删除的node
        preview = root;
        root = root->link;
    }
    // 删除node
    preview->link = root->link;
    free(root);
}

// 初始化一个链表
Node *create(int n)
{
    Node *head,*node,*end;
    head = (Node*)malloc(sizeof(Node));
    end = head;
    for (int i = 0; i < n; i ++) {
        // 新节点
        node = (Node *)malloc(sizeof(Node));
        // 最后节点指向新节点
        end->link=node;
        end->value = i;
        // 更新最后节点
        end = node;
    }
    end->link = NULL;
    return head;
}

int ssl_count(Node *root)
{
    int count = 0;
    while (root) {
        root=root->link;
        count++;
    }
    return count;
}

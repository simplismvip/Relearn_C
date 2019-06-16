//
//  tree.h
//  树
//
//  Created by 赵俊明 on 2019/5/30.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#ifndef _TREE_H_
#define _TREE_H_
#define SLEN 20
#define MAXITEMS 10

#include <stdbool.h>
#include <stdio.h>
// 二叉树，包含一个值和两个指向其他节点的指针
typedef struct item{
    char petname[SLEN];
    char petkind[SLEN];
} Item;

typedef struct trnode{
    Item item;
    struct trnode *left;
    struct trnode *right;
} Trnode;

typedef struct tree {
    Trnode *root;// 指向根节点的指针
    int size;// 树的项数
} Tree;
/** 函数原型
 *  初始化空树
 *  ptree指向一个空树
 */
void InitializeTree(Tree *ptree);
/** 判断树是否为空
 *  如果空树，返回true，否则false
 *  ptree指向一个已经初始化的树
 */
bool TreeEmpty(const Tree *ptree);
/** 确定树是否已满
 *  如果满，返回true，否则false
 *  ptree指向一个已经初始化的树
 */
bool TreeIsFull(const Tree *ptree);
/** 确定树的项数
 *  返回树的项数
 *  ptree指向一个已经初始化的树
 */
int TreeItemCount(const Tree *ptree);
/** 在树中添加一个项
 *  pi是待添加的项
 *  ptree指向一个已经初始化的树
 *  如果可以添加，返回true，否则false
 */
bool AddItem(const Item *pi, Tree *ptree);
/** 在树中查找一个项
 *  pi是待添加的项
 *  ptree指向一个已经初始化的树
 *  如果在树中，返回true，否则false
 */
bool InTree(const Item*pi,const Tree *ptree);
/** 删除一个项
 *  pi是待添加的项
 *  ptree指向一个已经初始化的树
 *  如果在树中删除一个项，返回true，否则false
 */
bool DeleteItem(const Item *pi,Tree *ptree);
/** 把函数应用于树中的每一项
 *  pfun指向一个函数
 *  ptree指向一个已经初始化的树
 *  函数接受一个Item类型，并无返回值
 */
void Traverse(const Tree *ptree,void(*pfun)(Item item));
/** 清空树
 *  ptree指向一个已经初始化的树
 */
void DeleteAll(Tree *ptree);
#endif /* tree_h */

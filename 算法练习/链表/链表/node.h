//
//  node.h
//  链表
//
//  Created by 赵俊明 on 2019/5/28.
//  Copyright © 2019 赵俊明. All rights reserved.
//

// 定义一个结构
typedef struct NODE{
    // 结构指针指向结构开始位置
    struct NODE *link;
    int value;
} Node;


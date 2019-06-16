//
//  reducto.h
//  13、文件输入、输出
//
//  Created by 俊明 on 2019/6/3.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#ifndef reducto_h
#define reducto_h

#include <stdio.h>

//long size = file_size("/Users/jl/Desktop/Code/Relearn_C/source/10.png");
//printf("image size:%ld\n",size);
void fget_test(const char *path);
void fget_test1(const char *path);
void fput_test(const char *path);
long file_size(const char *path);
void readRGB(const char *path);
#endif /* reducto_h */

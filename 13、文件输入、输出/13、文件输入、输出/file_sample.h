//
//  file_sample.h
//  13、文件输入、输出
//
//  Created by 俊明 on 2019/6/11.
//  Copyright © 2019 赵俊明. All rights reserved.
//

#ifndef file_sample_h
#define file_sample_h
#include <stdio.h>
void sfile_start(void);
char *sfile_get(char *st, int n);
void sfile_append(FILE *source,FILE *dest);
#endif /* file_sample_h */

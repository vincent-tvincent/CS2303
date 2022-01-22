//#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(int argc,char* argv[])
{
     printf("%d", argc);
    printf("%s\n",*argv);
    return 0;
    // int i = 0;
    // printf("%d\n", argc);//输出argc
    // for (i = 0; i < argc; i++)
    // {
    //     printf("%s\n", *(argv + i));//输出命令行参数
    // }
    // return 0;
}
/*————————————————
版权声明：本文为CSDN博主「无聊星期三」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Boring_Wednesday/article/details/78954104*/
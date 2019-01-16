//
//1. 结构体的定义
//2. 函数声明，变量声明，宏定义，常数定义等
//3. 当源代码不便公布时使用头文件提供接口
//4. 在大项目中需要多文件联合编译
// Created by liyaxi on 2019/1/15.
//

#ifndef CTEST_TEST_H   //“ifndef”意思是“如果在导入头文件的文件中之前没有导入该头文件就编译下面的代码”，该句的作用是防止重复导入
#define CTEST_TEST_H  //宏定义的意思，表示以下代码是头文件主体部分
typedef struct NEO{
    char name[20];
    int age;
} neo;
#endif //CTEST_TEST_H

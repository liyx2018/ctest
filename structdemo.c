//结构体
// Created by Administrator on 2019/1/8.
//
#include <stdio.h>
#include <mhash.h>

//#define 只是简单的字符串替换,而 typedef 则是为一个类型引入一个新的别名
// typedef 语句的一般形式是: typedef 已定义的类型 新的类型;
//typedef的最常用的作用就是给结构体变量重命名
typedef struct AGE {
    int year;
    int month;
    int day;
} age;

struct STUDENT {
    char name[20];
    int age;
    float score;
    age birthday;
};

struct TEACHER {
    char name[10];
    int age;
    char sex;
    char score[20];
};


int sum(int a, int b) {
    return a + b;
}

void getMaxValue(struct TEACHER info[5]);//声明函数

int main() {
//-----------------------------结构体------------------------------------------------------------------
    //结构体初始化
    struct STUDENT stu1 = {
            "liming",
            15,
            95,
            {1995, 2, 15}
    };
    printf("name=%s;\nage=%d;\nscore=%.1f;\n", stu1.name, stu1.age, stu1.score);
    printf("birthday : %d-%d-%d\n", stu1.birthday.year, stu1.birthday.month, stu1.birthday.day);
    printf("%d\n", sum(5, 9));

//    struct STUDENT student2;
//    printf("请输入姓名：");
//    scanf("%s", &student2.name);
//    printf("请输入年龄：");
//    scanf("%d", &student2.age);
//    printf("请输入生日：");
//    scanf("%d", &student2.birthday.year);
//    scanf("%d", &student2.birthday.month);
//    scanf("%d", &student2.birthday.day);
//    printf("请输入成绩：");
//    scanf("%f", &student2.score);
//    printf("name2=%s;\nage2=%d;\nscore2=%.1f;\n", student2.name, student2.age, student2.score);
//    printf("birthday2 : %d-%d-%d\n", student2.birthday.year, student2.birthday.month, student2.birthday.day);

    //字节对齐  以结构体成员中占内存最多的数据类型所占的字节数为标准，所有的成员在分配内存时都要与这个长度对齐。
    //如果一行中剩下的空间不足以填充某成员变量，即剩下的空间小于某成员变量的数据类型所占的字节数，则该成员变量在分配内存时另起一行分配
    struct HELL {
        char name[10];//本质是 10 个 char 变量,还是以最长类型还是int  此处占用10个字节，每行四个，需要分配3行12个字节，占用10个，剩下的空那儿
        int age; //分配并占用4个字节
        char sex;//分配4个字节，占用只有1个
    };
    struct HELL hello;
    printf("占字节数:%d\n", sizeof(hello));

    //结构数组 获取分数最高的
    struct TEACHER info[5] = {{"liming",   15, 95, "15"},
                              {"wuyi",     18, 90, "33"},
                              {"zhnagsan", 11, 85, "6"},
                              {"liushu",   8,  77, "22"},
                              {"xiaohong", 5,  85, "95"}};
    getMaxValue(info);

    //指向结构体变量的指针  (*指针变量名).成员名  或者 指针变量名->成员名 或者 结构体变量.成员名
    struct SCHOOL {
        char name[15];
        int num;
    } school;
    struct SCHOOL *p = NULL;
    p = &school;
    strcpy(p->name, "zhangsan");
    p->num = 1000;
    printf("name=%s,num=%d\n", (*p).name, p->num);
//-----------------------------位域结构------------------------------------------------------------------
    //定义位域结构  int占用4个字节 一字节等于8位
    //struct
    //{
    //  type [member_name] : width ;
    //};
    //type 整数类型，决定了如何解释位域的值。类型可以是整型、有符号整型、无符号整型。 member_name 位域的名称。width 位域中位的数量。宽度必须小于或等于指定类型的位宽度。
    struct {
        unsigned int a:5;
        unsigned int b:3;
    } data1;

    //结构体
    struct {
        int a;
        int b;
    } data2;

    printf("Memory size occupied by data1 : %d\n", sizeof(data1));//4
    printf("Memory size occupied by data2 : %d\n", sizeof(data2));//8

    data1.b = 6; //二进制表示为110 有3位不超过4
    printf("获取位域结构成员的值：%d\n", data1.b); //6
    data1.b = 8;//二进制表示为1000 有4位超过b的位域中位的数量3
    printf("获取位域结构成员的值：%d\n", data1.b);//0
//---------------------------内存管理-------------------------------------------------------------------
//  void *calloc(int num, int size);     在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。
//   所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是0。
//  void *malloc(int num);          在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
//  void *realloc(void *address, int newsize);     该函数重新分配内存，把内存扩展到 newsize。
//  void free(void *address);    该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。

    char name[100];
    char *description;

    strcpy(name, "Zara Ali");

    /* 动态分配内存 */
    description = (char *) malloc(30 * sizeof(char));
    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcpy(description, "Zara ali a DPS student.");
    }
    /* 假设您想要存储更大的描述信息 */
    description = realloc(description, 100 * sizeof(char));
    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcat(description, "She is in class 10th");
    }

    printf("Name = %s\n", name);
    printf("Description: %s\n", description);

    /* 使用 free() 函数释放内存 */
    free(description);
//---------------------------头文件-------------------------------------------------------------------



    return 0;
}

void getMaxValue(struct TEACHER info[5]) {

    struct TEACHER stumax = info[0];
    for (int j = 1; j < 5; ++j) {
        if (strcmp(stumax.score, info[j].score) < 0) {
            stumax = info[j];
        }
    }
    printf("姓名：%s 年龄：%d 性别：%c 分数：%s\n", stumax.name, stumax.age, stumax.sex, stumax.score);
}
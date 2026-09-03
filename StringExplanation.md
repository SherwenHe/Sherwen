课程设计-C语言字符串解释说明

一、什么是字符串（String）

在 C语言 中，字符串（string） 是由一系列字符（例如字母、数字、符号）组成的字符数组，并且以特殊的结束符 '\0'（空字符）结尾。

可以理解为：

字符串 = 若干个字符 + 结尾的 \0
char s[] = "Hello";

这个字符串在内存中其实是：
| 字符 | H | e | l | l | 0 | \n |
|----|---|---|---|---|---|----|
| 地址 | 0 | 1 | 2 | 3 | 4 | 5  |


虽然你看不到 \0，但它是字符串结束的标志。

这让函数（如 printf、strlen 等）知道字符串在哪里结束。

二、字符串与字符的区别


|类型|	        示例|	    本质	|     占用空间	 |是否有\0结尾|
|----|---|---|---|---|
|字符（char）|	'A'|	单个字符   |       	1字节|	   ❌|
|字符串（string）|	"A"|	含一个字符和\0的数组|	2字节|	   ✅|

📘 注意：

char c = 'A';   // 字符常量

char s[] = "A"; // 字符串常量（含 'A' 和 '\0'）

三、字符串的本质是“字符数组”

在C语言中，没有真正的“字符串类型”。

字符串实际上是一个 char类型数组，例如：

char str[10] = "CSU";

等价于：

char str[10] = {'C', 'S', 'U', '\0'};

四、字符串在内存中的存储

例如：

char name[] = "cat";

内存中为：

|地址|	内容|ASCII码|
|----|---|---|
| 0 | c |99|
|1|	a|	97|
|2|	t|	116|
|3|	\0|	0|

\0 不是数字0字符，而是 ASCII值为0的结束标志。

五、C语言中字符串的输入

C语言提供了多种方法来输入字符串，不同场景下应选择不同函数。

1. scanf("%s", str);
   
特点：\
读入 一个单词（以空格、回车或制表符结束）；\
自动在末尾加 \0；\
会自动跳过所有空白字符（包括空格 ' '、制表符 \t、换行符 \n），然后从第一个非空白字符开始读取字符串。\
不能读入空格。

char name[20];\
scanf("%s", name);\
printf("Name: %s\n", name);

输入：\
Zhang San\
输出：\
Name: Zhang

⚠️ 只读入第一个单词 "Zhang"，后面的 "San" 被留在输入缓冲区。

2. gets(str);（❌ 已废弃）

读入一行字符串（包含空格，直到\n）；\
不检查长度，容易溢出；\
已在C11标准中废弃，不推荐使用。

4. fgets(str, n, stdin);
   
特点：\
最多读取 n-1 个字符；\
会保留行尾的 \n；\
自动添加 \0。

fgets() 不会自动跳过换行符。如果前面有残留的 \n，它会直接读到一个空行：\
char s[100];\
fgets(s, 100, stdin);\
printf("You entered: %s", s);\
输入：\
I love C language\
输出：\
You entered:\
I love C language\
\0 不是数字0字符，而是 ASCII值为0的结束标志。

六、OJ平台中字符串输入示例

OJ平台中可能有以下几种字符串输入方式

1. 先给出行数，再逐行读入\
如： 字符串成对 这道题\
a.使用 scanf();\
    scanf("%d",&K);\
    while (K--){\
     >   char str[1005];\
     >   scanf("%s",str);\
     >   int len=strlen(str); 
    }
适合于所输入的字符串中不包含空格的情况。

请注意：由于需要在末尾添加 \0及其他操作，所以题目输入说明长度不超过n（如：1000）个字符时，缓冲区再开大一点，起码+2（如1002），多加点更稳妥（如1005）。

b.使用 fgets();\
    scanf("%d\n",&K); 注意后面的“\n”\
    while (K--){\
        char str[1005];\
        int top=-1;\
        fgets(str,sizeof(str), stdin); \
        int len=strlen(str);\
        for (int i=0;i<len;i++){\
            if(str[i] == '\n' || str[i] == '\r') break;\            
        }\
    }\
    
请注意：\
fgets()不会跳过前面的'\n'等空白字符，所以scanf("%d\n",&K);的“%d”后面有一个“\n”，用于消化掉换行符。当然scanf("%d",&K)，后面加一个getchar()也可以。\
fgets()会读入后面的回车换行符到字符串中并计入字符串长度，但是回车换行不能算作我们字符串中的字符。所以，增加了一行：if(str[i] == '\n' || str[i] == '\r') break; 用于将结尾的回车换行符直接扔掉。\
scanf("%d\n",&K)中的'\n'在 scanf 的格式字符串中不是“读掉换行符”，而是表示：“忽略任意数量的空白符（空格、Tab、换行）直到遇到非空白字符”。

另外：\
  scanf("%d\n", &n);\
  getchar();\
和\
    scanf("%d", &n);\
    getchar();\
的区别：

scanf("%d\n", &n);中的'\n'会吃掉连续多个空白符，而getchar()只会吃掉一个。因此，用scanf("%d\n", &n);会更加稳妥。

2.不给定行数，直接读入

如： 回文判定 这道题\
    char huiwen[10086];\
    while(scanf("%s",&huiwen)!=EOF)\
    { \
      int k=strlen(huiwen);\      
    }\
逐行读入直到碰到EOF

如果用fgets()\
    char huiwen[10006];\
    while(fgets(huiwen,sizeof(huiwen),stdin))\
    { \
      int k=strlen(huiwen);\
      if(huiwen[k-1]=='\n') k=k-1;\
      if(huiwen[k-1]=='\r') k=k-1;\      
    }\
注意：\
fgets()如果读到文件末尾直接返回NULL（数值0），而不是EOF（数值-1），所以循环条件里可以直接嵌入。\
fgets()要记得处理末尾的回车换行符

3.分析
大家可以读入后，逐个输出其ASCII码值来进行查看\
#include <stdio.h>\
#include <string.h>\
int main(){\
    int K;\
    scanf("%d\n",&K);\
    while (K--){\
        char str[1005];\
        fgets(str,sizeof(str), stdin); \
        int len=strlen(str);\
        for (int i=0;i<len;i++){\
            printf("%d ",str[i]);\
        }\
        printf("\n");\
    }\
    return 0;\
}\
这样写，对于输入

3
abc\
defg\
hijkl\
缓冲区内容为：\
'3' '\n' 'a' 'b' 'c' '\n' 'd' 'e' 'f' 'g' '\n' 'h' 'i' 'j' 'k' 'l'\
其输出为\
97 98 99 10 \
100 101 102 103 10 \
104 105 106 107 108  \
fgets()读入了3个字符串，最后一个字符均为换行符'\n'（其ASCII码的值为10）。

最后一行没有，因为最后一个字符串后面确实没有换行符。其他程序中到底有没有，不确定。\
注意：我们做测试，所以输出用的"%d"，不是"%c"，输出的字符对应的ASCII数值。

如果去掉  scanf("%d\n",&K);   中的'\n'，\
#include <stdio.h>\
#include <string.h>\
int main(){\
    int K;\
    scanf("%d",&K);   //去掉了'\n'\
    while (K--){\
        char str[1005];\
        fgets(str,sizeof(str), stdin); \
        int len=strlen(str);\
        for (int i=0;i<len;i++){\
            printf("%d ",str[i]);\
        }\
        printf("\n");\
    }\
    return 0;\
}\
其输出为：
10 \
97 98 99 10 \
100 101 102 103 10 \
因为fgets()会将输入中‘3’后面的换行符'\n'作为一行进行读入。所以除了"\n"这一行外，只读入了另外2行（总共3行）

那么，如果用的scanf()

#include <stdio.h>\
#include <string.h>\
int main(){\
    int K;\
    scanf("%d",&K);\
    while (K--){\
        char str[1005];\
        scanf("%s",str);\
        int len=strlen(str);\
        for (int i=0;i<len;i++){\
            printf("%d ",str[i]);\
        }\
        printf("\n");\
    }\
    return 0;\
}\
对于输入\
3\
abc\
defg\
hijkl\
其输出为\
97 98 99 \
100 101 102 103 \
104 105 106 107 108 \
scanf()读入了3个字符串（即使scanf("%d",&K);中没有'\n'），换行符'\n'也没有读入进来。


接下来做个测试\
如果将for循环次数加一（字符串长度+1），多读一个。\
#include <stdio.h>\
#include <string.h>\
int main(){\
    int K;\
    scanf("%d",&K);    //这里没有'\n'\
    while (K--){\
        char str[1005];\
        scanf("%s",str);\
        int len=strlen(str);\
        for (int i=0;i<len+1;i++){ //这里多加了1\
            printf("%d ",str[i]);\
        }\
        printf("\n");\
    }\
    return 0;\
}\
其输出为：\
97 98 99 0 \
100 101 102 103 0 \
104 105 106 107 108 0 \
可以看出每个字符串最后都以0结尾（整数0，不是字符'0'），但是这个0不计入字符串长度。

另外注意，如果我们多输出几个，会有什么情况

#include <stdio.h>\
#include <string.h>\
int main(){\
    int K;\
    scanf("%d",&K);\
    while (K--){\
        char str[1005];\
        scanf("%s",str);\
        int len=strlen(str);\
        for (int i=0;i<len+4;i++){    //这里多加了4\
            printf("%d ",str[i]);\
        }\
        printf("\n");\
    }\
    return 0;\
}\
对于输入：\
3\
aaaaaaaa\
bbb\
ccccccccccc\
输出为：\
97 97 97 97 97 97 97 97 0 0 0 0 \
98 98 98 0 97 97 97 \
99 99 99 99 99 99 99 99 99 99 99 0 0 0 0 \
注意第二行在0后面出现了97（字符'a‘），说明输入时只是覆盖当前输入的字符长度+1的区域，不会覆盖后面的字符。

如果用getchar()??

#include <stdio.h>\
int main(){\
    char c;\
    while (1){\
        c=getchar();\
        printf("%d ",c);\
        if(c==EOF) break;\
    }\
    return 0;\
}\
对于输入：\
2 \
abc\
123\
输出：\
50 32 10 97 98 99 10 49 50 51 -1  \
另外，如果fgets的缓冲区（第二个参数）开小了，会怎样？\
在下面例子中，字符串的长度定义为3。

#include <stdio.h>\
#include <string.h>\
int main(){\
    int K;\
    char c;\
    scanf("%d\n",&K);\
    while(K--){\
        char str[3];\
        fgets(str,sizeof(str), stdin);\
        int len=strlen(str);\
        printf("len:%d\n",len);\
        for(int i=0;i<len;i++){\
            printf("%d ",str[i]);\
        }\
        printf("\n");\
    }\
    printf("others:");\
    while (1){\
        c=getchar();\
        printf("%d ",c);\
        if(c==EOF) break;\
    }\
    return 0;\
}\
对于输入：\
4\
ab\
efg\
hi\
xyzz\
输出：\
len:2\
97 98 \
len:1\
10 \
len:2\
101 102 \
len:2\
103 10 \
others:104 105 10 120 121 122 122 -1  \

分析：\
对于fgets()来说，其第二个参数也就是缓冲区大小是 3 (sizeof(str))，由于最后要放上0作为字符串结尾，所以其每次最多只能读入2个字符。\
一共执行了4次fgets():\
第1次：读入了2个字符：'a','b'\
第2次：读入了1个字符，为'a','b'后面的 '\n' ，由于读到了 '\n' 表示该字符串读入结束，其也将 '\n' 放入字符串中\
第3次：读入了2个字符：'e','f'\
第4次：读入了2个字符：'g'，以及'g'后面的 '\n'\
后面的字符都还在缓冲区中，并由getchar()，读入并输出1\

七、到底用scanf()还是fgets()？

如果读入的字符串里没有空格，用scanf()吧！\
有空格或者不确定有没有，那只能fgets()了\
如何判断是否有空格，看输入描述或者提示了。如字符串成对 这道题，“提示”中写了“字符串只有英文字母”，这就代表没有空格\


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md\
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)\
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目\
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目\
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)\
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)

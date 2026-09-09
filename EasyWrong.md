C语言典型的段错误（Segmentation Fault）实例及代码示例，按常见场景分类说明：

1. ‌引用空指针‌

#include <stdio.h>
int main() 
{
&emsp;&emsp;int *p = NULL;

&emsp;&emsp;printf("%d\n", *p); // 解引用空指针

&emsp;&emsp;return 0;
}

‌原因‌：p 未指向有效内存地址。

2. ‌访问受保护的内存地址‌

int *p = (int*)1;  // 强制将指针指向地址 0x1
*p = 100;          // 访问系统保护的内存区域

‌原因‌：尝试操作内核或系统保留的内存区域。

3. ‌修改字符串常量‌

char *str = "hello";  // 字符串常量存储在只读区
str[0] = 'H';         // 尝试修改常量区数据

‌原因‌：字符串字面量存储在只读内存段，不可被修改6。

4. ‌栈溢出‌

void infinite_loop() 
{
&emsp;&emsp;infinite_loop();  // 无限递归导致栈空间耗尽
}

int main()
{
&emsp;&emsp;infinite_loop();
}

‌原因‌：无限递归导致栈内存溢出6。

5. ‌数组越界访问‌

int arr[5];
arr[5] = 10;  // 合法索引为 0~4，越界访问无效内存
‌原因‌：访问超出数组定义大小的内存区域。

#include <stdio.h>
int main() 
{
&emsp;&emsp;int arr[5] = {0, 1, 2, 3, 4};
&emsp;&emsp;printf("%d\n", arr[10]); // 访问不存在的元素
&emsp;&emsp;return 0;
}

执行结果：未定义行为，可能会导致程序崩溃或打印出垃圾值。

数组越界是一些新手最容易出错的地方，经常因为数组下标控制不好，导致访问越界，而这种情况可能99%几率不是立刻报段错误，也可能程序运行几年都不报错， 但是它一旦报了错，就会特别隐蔽，非常难查。

刚工作的时候在zte，曾经有2位大佬追一个德国运营商现场报的bug，花了一个月时间，最后发现是数组越界导致。

6. ‌使用未初始化的指针‌

int *p;        // 未初始化指针
*p = 42;       // 野指针指向无效地址

‌原因‌：指针未指向有效内存空间。

7. ‌访问已释放的内存‌

int *p = malloc(sizeof(int));
free(p);
*p = 10;       // 内存释放后继续使用

‌原因‌：操作已被释放的动态内存区域。

8. ‌缓冲区溢出‌

char buffer[5];
strcpy(buffer, "HelloWorld");  // 超出 buffer 容量

‌原因‌：字符串操作超过目标缓冲区大小。

9. ‌双重释放内存‌

int *p = malloc(sizeof(int));
free(p);
free(p);  // 重复释放同一块内存

‌原因‌：多次释放同一内存导致堆管理器异常。

10. ‌强制类型转换错误‌

int num = 42;
char *p = (char*)num;  // 将整数值强制转换为地址
*p = 'A';              // 访问非法地址

‌原因‌：将非指针类型强制转换为指针并解引用。

11.格式化字符串与参数类型不匹配示例

int data = 0;
sprintf(buf,"%s",data);

12、忘记字符串结尾的空字符示例：

#include <stdio.h>
int main() 
{
&emsp;&emsp;char str[5] = {'H', 'e', 'l', 'l', 'o'}; // 缺少 '\0'
&emsp;&emsp;printf("%s\n", str);
&emsp;&emsp;return 0;
}

执行结果：未定义行为，可能会打印出乱码直到遇到一个’\0’。

13、缓冲区溢出示例：

#include <stdio.h>
#include <string.h>
int main() 
{
&emsp;&emsp;char dest[5];
&emsp;&emsp;strcpy(dest, "Hello, World!"); // 目标缓冲区太小
&emsp;&emsp;printf("%s\n", dest);
&emsp;&emsp;return 0;
}

执行结果：未定义行为，可能会崩溃或覆盖内存。

14、未检查类型大小示例：

#include <stdio.h>
int main() 
{
&emsp;&emsp;char *p = (char *)malloc(10 * sizeof(int));
&emsp;&emsp;int *q = (int *)p; // 错误的假设char和int大小相同
&emsp;&emsp;for (int i = 0; i < 10; ++i) 
&emsp;&emsp;{
&emsp;&emsp;&emsp;q[i] = i; // 可能导致内存越界
&emsp;&emsp;}
&emsp;&emsp;free(p);
&emsp;&emsp;return 0;
}

执行结果：未定义行为，可能会导致内存越界。

15、变量未正确初始化示例：

#include <stdio.h>
int main() 
{
&emsp;&emsp;int num = 123;
&emsp;&emsp;printf("%s\n", num); // 错误的格式化字符串，应为%d
&emsp;&emsp;return 0;
}

执行结果：未定义行为，可能会打印出任意值。

16、忽视错误返回值示例：

#include <stdio.h>
#include <stdlib.h>
int main() 
{
&emsp;&emsp;FILE *file = fopen("nonexistent.txt", "r");
&emsp;&emsp;if (!file) 
&emsp;&emsp;{// 忽视错误，没有处理
&emsp;&emsp;}
&emsp;&emsp;// 使用file...
&emsp;&emsp;fclose(file);
&emsp;&emsp;return 0;
}

执行结果：如果文件不存在，程序会尝试使用未初始化的指针，可能导致崩溃。

总结

段错误本质是访问了非法内存地址，可通过以下方式避免：

初始化指针并检查有效性；

避免越界操作数组或缓冲区；

谨慎处理动态内存的分配与释放；

区分常量区与变量区的数据修改权限

对一些库函数返回值一定要判断
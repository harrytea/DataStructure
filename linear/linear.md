## 线性表

##### 定义：

n（n>=0）个数据元素的有限序列，记作（a1,……ai-1，ai，ai+1,……，an），其中ai是表中数据元素，n是表长度

##### 特点：

1. 同一线性表中元素具有相同特性
2. 相邻元素之间存在序偶关系
3. 除第一个元素外，其他每一个元素有且仅有一个直接前驱
4. 除最后一个元素外，其他每一个元素有且仅有一个直接后继

##### 举例：

* La=（34，89，765，12，90，-34，22）数据元素类型为int
* Ls=（“hello”，“world”，“china”，“welcome”）数据元素类型为string

##### 线性表的基本操作

1. 初始化线性表
2. 销毁线性表
3. 清空线性表
4. 求线性表的长度
5. 判断线性表是否为空
6. 获取线性表中的某个数据元素内容
7. 检索值为e的数据元素
8. 返回线性表中e的直接前驱元素
9. 返回线性表中e的直接后继元素
10. 在线性表中插入一个数据元素
11. 删除线性表中的第i个数据元素

## 顺序表

##### 定义：将线性表中的元素相继存放在一个连续的存储空间中

##### 存储结构：数组

##### 特点：线性表的顺序存储方式

##### 存取方式：顺序存取

|  0   |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  45  |  89  |  67  |  40  |  90  |  78  |

[^ ]:顺序存储结构示意图

##### 存储地址 内存单元

Loc（ai+1）=Loc（ai）+l

Loc（ai）=Loc（a1）+（i-1)*l

| 1    | 2    | ……   | i    | ……   | n    |
| ---- | ---- | ---- | ---- | ---- | ---- |
| a1   | a2   | ……   | ai   | ……   | an   |

##### 练习1：

设计一个高效算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O（1）

##### 练习2：

设将n个整数存放到一维数组R中。试设计一个时间和空间两方面尽可能高效的算法，将R中整数序列循环左移p个位置，即将R中的序列（X0,X1,…, Xn-1)变换为(Xp,Xp+1,…,
Xn-1
,X0
,X1,…,Xp-1)。

##### 练习3：

寻找主元素

## 线性表的链式存储结构

利用数据元素的存储顺序表示相应的逻辑顺序，线性表顺序存储结构的特点，是一种简单、方便的存储方式，他要求线性表的数据元素依次存放在连续的存储单元中，从而这种存储方式属于静态存储

静态存储方式暴露的问题：

1. 在做插入或删除元素的操作时，会产生大量的数据元素移动
2. 对于长度变化较大的线性表，要一次性地分配足够的存储空间，但这些空间常常又得不到充分的利用
3. 线性表的容量难以扩充

### 链表

链表是线性表的链接存储表示

#### 单链表

##### 定义：用一组地址任意的存储单元存放线性表中的数据元素

[^说明]:头指针为31

| 存储地址 | 数据域 | 指针域 |
| -------- | ------ | ------ |
| 1        | ZHANG  | 13     |
| 7        | WANG   | 1      |
| 13       | LI     | NULL   |
| 19       | ZHAO   | 37     |
| 25       | WU     | 7      |
| 31       | ZHOU   | 19     |
| 37       | SUN    | 25     |

##### 单链表结构：

每个元素由结点（node）构成，它包括两个域：数据域Data和指针域next

| data | next |
| ---- | ---- |
|      |      |

##### 存储结构：链式存储结构

##### 特点：存储单元可以不连续

##### 存取方式：非随机存取

##### 常见指针操作：

1. q=p
2. q=p->next
3. p=p->next
4. q-next=p
5. q->next=p->next

##### 单链表的基本运算

###### 插入：

1. 在第一个结点前插入
2. 在链表中间插入
3. 在链表末尾插入

#### 带表头结点的单链表

表头结点位于表的最前端，本身不带数据，仅标志表头

##### 设置表头节点的目的：简化链表操作的实现

##### 练习1：

设计一个算法，在带头结点的单链表L中删除所有值为x的结点并释放空间，假设这样的节点不是唯一

##### 练习2：

设计一个算法，在带头节点的单链表L中删除一个最小值结点，假设其唯一

##### 练习3：

设C={a1,b1,a2,b2,…,an,bn}为一线性表，采用带头结点的hc单链表存放，设计一个就地算法，将其拆分为两个单链表ha和hb

##### 练习4：

在一个长度为n的带头结点的单链表h上，另设尾指针r，执行 （b） 操作与链表的长度有关。

（a）删除单链表中的首结点

（b）删除单链表中的尾结点

（c）在单链表首结点前插入一个新结点

（d）在单链表尾结点后插入一个新结点

#### 静态链表

| node          | data  | next |
| :------------ | ----- | ---- |
| 0(L.nodes[0]) |       | 1    |
| 1             | ZHANG | 2    |
| 2             | WANG  | 6    |
| 3             | LI    | 5    |
| 4(L.newptr)   | ZHAO  | ?    |
| 5             | WU    | -1   |
| 6             | CHEN  | 3    |
| 7             |       |      |

#### 循环链表

##### 特点：

最后一个结点的next指针不为NULL，而是指向头结点，只要已知表中某一个结点的地址，就可搜寻所有结点的地址

##### 存储结构：链式存储结构

##### 约瑟夫问题：用循环链表求解约瑟夫问题

n个人围成一个圆圈，首先第1个人从1开始一个人一个人顺时针报数，报到第m个人，令其出列。然后再从下一个人开始，从1顺时针报数，报到第m个人，在令其出列，如此下去，直到圆圈中只剩下一个人为止，此人即为优胜者

##### 练习1：

有两个循环单链表，头指针分为head1和head2，编写函数将链表head2链接到head1之后，链接后的链表仍保持是循环链表的形式

##### 练习2：

有一个单链表L（至少有一个结点），其表头结点指针为head，编写一个函数将L逆置，即最后一个结点变成第1个结点，原来倒数第二个结点变成第2个结点……

#### 双向循环链表

在循环链表中，访问后继节点，只需要向后走一步，而访问前驱结点，就需要转一圈，循环链表并不适用于经常访问前驱结点的情况

在需要频繁地同时访问前驱和后继节点的时候，使用双向链表：每个结点有两个指针域：一个指向后继节点，另一个指向前驱结点

***

### 顺序表与链表的比较

##### 基于时间的比较

###### 存储方式：

1. 顺序表可以随机存取，也可以顺序存取
2. 链表是顺序存取的

###### 插入/删除时移动元素个数：

1. 顺序表平均需要移动近一半元素
2. 链表不需要移动元素，只需要修改指针


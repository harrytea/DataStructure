## 第六章 树和二叉树

### 树的定义和基本术语

##### 树的定义：

树是由n（n>=0）个结点的有限集合。如果n=0，称为空树；如果n>0，则有且只有一个特定的称之为根（Root）的结点，当n>1，除根以外的其他结点划分为m（m>0）个互不相交的有限集T1，T2，……Tm，其中每个集合本身又是一棵树，并且称为根的**子树**（SubTree）

![1556352112425](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556352112425.png)

其中，A是根；其余结点分成三个互不相交的子集，**T1={B,E,F,K,L}；T2={C,G}；T3={D,H,I,J,M}**,T1,T2,T3都是根A的子树，且本身也是一棵树

##### 树的基本术语

![1556352295243](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556352295243.png)

###### 结点（node）：数据元素及其分支

###### 结点的度（degree）：结点拥有的子树个数

###### 树的度（degree）：树中结点的度的最大值

###### 分支（branch）结点：度不为0的结点

###### 叶子（leaf）结点：度为0的结点

###### 子（child）结点：结点子树的根

###### 双亲（parent）结点：子结点的直接前驱节点

###### 兄弟（sibling）结点：同一双亲的子结点互称兄弟结点

###### 结点的层次（level）：根为第一层；子结点的层次比双亲结点的层次+1

###### 树的深度（depth）：树中结点的最大层次

###### 有序树：子树从左到右有序

###### 无序树：子树无序

###### 森林（forest）：m棵互不相交的树的集合

### 二叉树

##### 定义：

一棵二叉树是结点的一个有限集合，该集合或者为空，或者是由一个根结点加上两棵分别称为左子树和右子树的、互不相交的二叉树组成

##### 特点：

每个结点至多只有两棵子树（二叉树中不存在度大于2的结点）

##### 五种形态：

![1556352860784](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556352860784.png)

#### 性质：

1. 在二叉树的第i 层上至多有2^(i-1)个结点。（i>=1） [证明用归纳法]
2. 深度为k的二叉树至多有2^k-1个结点（k>=1)
3. 对任何一棵二叉树T，如果其叶节点数为N0，度为2的结点数为N2，则N0=N2+1

#### 两种特殊形态的二叉树：

##### 定义1：满二叉树

一棵深度为K且有2^k-1个结点的二叉树称为满二叉树

##### 定义2：完全二叉树

若设二叉树的高度为h，则共有h层。除第h层外，其他各层（1~h-1）的结点数都达到最大个数，第h层从右向左连续缺若干结点，这就是完全二叉树

![1556353236712](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556353236712.png)

4. 具有n（n>=0）个结点的完全二叉树的深度为[log2(n)]+1
5. 对于有n个结点的完全二叉树中的所有结点按从上到下，从左到右的顺序进行编号，则对任意一个结点i（1<=i<=n）都有：

* 如果i=1，则结点i是这棵完全二叉树的根，没有双亲；否则其双亲结点的编号为[i/2]
* 如果2i>n，则结点i没有左孩子；否则其左孩子结点的编号为2i
* 如果2i+1>n，则结点i没有右孩子；否则其右孩子结点的编号为2i+1

![1556353531863](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556353531863.png)

### 二叉树的存储结构

#### 顺序表示

![1556353576661](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556353576661.png)

#### 链表表示

![1556353625690](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556353625690.png)

### 二叉树链表表示示例

![1556353680109](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556353680109.png)

### 三叉链表的静态结构

![1556353743724](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556353743724.png)

#### 练习：

1. 对一棵具有n个结点的树，其中所有度之和是多少？

* n-1

2. 一棵度为4的树T中，若有20个度为4的结点，10个度为3的结点，1个度为2的结点，10个度为1的结点，则树T的叶子结点个数是多少？

* 82

3. 一棵完全二叉树上有768个结点，则该二叉树中叶子结点的个数是多少？

* 384

4. 已知一棵完全二叉树的第6层有8个叶子节点，则该完全二叉树的结点个数最多是多少？

* 111

### 二叉树遍历

树的遍历就是按某种次序访问树中的结点，要求每个结点访问一次且仅访问一次

前序：VLR 

中序：LVR

后序：LRV

![1556354077059](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556354077059.png)

#### 线性表的遍历

##### 顺序表的遍历：for（i=1;i<=v.last;i++） visit(v.elem[i]);

##### 链表的遍历：for(p=L->next;p!=NULL;p=p->next)  visit(p->data);

####  二叉树的遍历

非线性关系，需确定先后次序

##### 按对根节点的处理次序分为：先序、中序、后序

![1556354340131](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556354340131.png)

#### 练习：

1. 已知结点的前序序列和中序序列分别为：

前序序列：ABCDEFG

中序序列：CBEDAFG

![1556354410986](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556354410986.png)

2. 若一棵二叉树的先序遍历和后序遍历分别为1234，4321，则该二叉树的中序遍历序列不会是：

     (a)1234	(b)2341	(c)3241	(4)4321

   * c

### 中序遍历（Inorder Traversal）

#### 中序遍历二叉树算法的定义：

若二叉树为空，则为空操作；否则

* 中序遍历左子树（L）
* 访问根节点（V）
* 中序遍历右子树（R）

![1556354664789](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556354664789.png)

遍历结果：a+b*c-d-e/f

#### 中序遍历二叉树（非递归算法）用栈实现

![1556354742082](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556354742082.png)

### 前序遍历（Preorder Traversal）

#### 前序遍历二叉树算法的定义：

若二叉树为空，则空操作，否则：

* 访问根节点
* 前序遍历左子树
* 前序遍历右子树

![1556354847760](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556354847760.png)

遍历结果：-+a*b-cd/ef

#### 前序遍历二叉树（非递归算法）用栈实现

![1556354909874](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556354909874.png)

### 后序遍历（Postorder Traversal）

#### 后序遍历二叉树算法的定义：

若二叉树为空，则空操作，否则：

* 后序遍历左子树
* 后序遍历右子树
* 访问根节点

![1556354993073](C:/Users/DELL/AppData/Roaming/Typora/typora-user-images/1556354993073.png)

遍历结果：abcd-*+ef/-






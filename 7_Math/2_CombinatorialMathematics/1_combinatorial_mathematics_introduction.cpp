//组合数学介绍
//combinatorial_mathematics_introduction.cpp

//组合数学是一门与计算机算法联系紧密的数学学科
//本文介绍一些算法中常见的组合数学概念与定理

//1)鸽巢原理，也称抽屉原理，鞋盒原理
//简单形式：n+1个物体放进n个盒子，则至少有一个盒子包含两个物体
//加强形式：令q1, q2, ..., qn为n个正整数，若将q1+q2+...+qn-n+1个物体放入n个盒子中
//那么，或者第1个盒子至少含q1个物体，或者第2个盒子至少含q2个物体，...
//或者第n个盒子至少含qn个物体
//加强形式2：当加强形式中的n个数字q1到qn都等于r时，即将n*(r-1)+1个物体放入n个盒子
//那么至少有一个盒子含有r个或更多的物体
//平均原理1：当加强形式中的n个数字q1到qn的平均值大于r-1(大于等于r)
//那么其中至少有一个数字大于等于r
//平均原理2：当加强形式中的n个数字q1到qn的平均值小于r+1(小于等于r)
//那么其中至少有一个数字小于r+1
//Ramsey定理：在6个人中，或者有3个人其中任意两人相互认识
//或者有3个人其中任意两人相互不认识，抽象的记作K6->K3,K3
//设含有6个节点的无向完全图，用红色的边指代两节点认识，蓝色的边指代两节点不认识
//那么该定理也可以说成是，无论怎么涂色，总有全红色边或全蓝色边的3个节点的子图
//但是在5个节点的无向完全图中却有不存在这样的全红K3和全蓝K3
//更一般的Ramsey定理：对于整数m>=2和n>=2，存在一个正整数p使得Kp->Km,Kn
//即在p个节点的无向完全图中，无论如何涂色总有红色Km或蓝色Kn
//而最小的正整数p就是Ramsey数r(m, n)
//
//2)排列组合
//第一原理：集合S的一个划分是S的子集集合S1,S2,...,Sm
//其中任意两子集不相交，且S1到Sm的并集是原集合S，每一个子集都称为集合S的一个部分
//加法原理：集合S的元素数量是S的各部分的元素数量之和，即|S|=|S1|+|S2|+...|Sm|
//乘法原理：若集合S是序偶(a,b)的集合，其中第一个元素a来自数量为p的集合
//而对于a的每个选择，b都有q种选择，则集合S的大小为p*q，即|S|=p*q
//减法原理：设集合U包含集合S，集合S在U中的补集是S'，则|S|=|U|-|S'|
//除法原理：集合S被划分为k个部分且每个部分的元素数量相等，则k=|S|/每个部分的元素数量
//线性排列：有n个元素的集合S的r-排列是n个元素中r个元素的有序摆放，排列数量记作P(n,r)
//当r > n时P(n,r) = 0，当r <= n时P(n,r) = n*(n-1)*...*(n-r+1)
//特别的当r = n时P(n,r) = n*(n-1)*...*1 = n!即n的阶乘
//循环排列：将集合S中的元素首尾相接，形成一个环，称为循环r-排列
//循环排列的数量P(n,r) = r*(n!)/(r*((n-r)!))，特别的当r = n时P(n,r) = (n-1)!
//
//排列公式P被特殊的记作P(k,n) = (n!)/(n-k)!，即将上面的P(n,r)中的n和r颠倒了
//组合公式C被特殊的记作C(k,n) = P(k,n)/k!
//
//3)容斥原理
//容斥原理相比于排列组合具有更一般性，不要求集合S具有互不相交的多个部分
//公式1：集合S有一子集A，则A在S中的补集A'的大小|A'|=|S|-|A|
//公式2：集合S有子集A1和A2，A1具有性质P1，A2具有性质P2，A1'和A2'分别是A1和A2的补集
//则有|A1'交A2'|=|S|-(|A1|+|A2|)+|A1交A2|
//公式3：集合S有子集A1,A2,A3，分别具有性质P1,P2,P3和补集A1',A2',A3'
//则有|A1'交A2'交A3'|=|S|-(|A1|+|A2|+|A3|)+(|A1交A2|+|A1交A3|+|A2交A3|)-|A1交A2交A3|
//
//一般性定理：集合S有子集A1,A2,...Am，分别具有性质P1,...Pm和补集A1',...,Am'
//则有|A1'交...交Am'|=|S|-sum(|Ai|)+sum(|Ai交Aj|)-sum(|Ai交Aj交Ak|)+...
//+(-1)^m|A1交A2交...交Am|
//其中sum(Ai)是A1到Am的1-组合，sum(Ai交Aj)是A1到Am的2-组合
//sum(Ai交Aj交Ak)是A1到Am的3-组合，以此类推直到A1到Am的m-组合，即A1交A2交...交Am
//推论：在上述集合中有|A1并A2并...并Am|=sum(|Ai|)-sum(|Ai交Aj|)+sum(|Ai交Aj交Ak|)-...
//+(-1)^(m+1)|A1交A2交...交Am|
//
//4)Catalan序列
//设有一个这样的序列C0，C1，C2，...，Cn，...
//其中Cn = 1/(n+1)*C(n,2n)，其中C(n,2n)是组合公式，即C(n,2n) = P(n,2n)/n!
//
//5)置换群与对称群
//设集合X有n个元素1，2，...，n，而X的置换i1，i2，...，in
//是一个X到自身的一对一的函数f:X->X，其中f(1)=i1，f(2)=i2，...，f(n)=in
//用一个2*n的阵列来描述函数f
//比如集合X={1,2,3}，X的6个置换为：
//|1 2 3| |1 2 3| |1 2 3| |1 2 3| |1 2 3| |1 2 3|
//|1 2 3| |1 3 2| |2 1 3| |2 3 1| |3 1 2| |3 2 1|
//显然有n个元素的集合X有n!个置换
//设有n个元素的集合X的所有置换组成的集合是Sn
//若Sn的非空子集G是一个群，则定义它是X的一个置换群
//若Sn是一个置换群，则称Sn是n阶对称群
//
//6)生成函数
//生成函数就是使用利用指数的运算特性构造多项式，利用多项式系数和指数对应的不同模型意义
//广泛应用与计数中，常见的
/**我们假设要求的数是N（N>=1,且为正整数）
 *
 *那么比N小的数都是有可能组成大数N的
 *共有1,2,3,4,5,6,7,8,9,10,....N-1,N
 *
 *设每个比N小的数为I，且I为无限个，那么出现相同的I也不会超过N个
 *对于每个I，能组成的数有
 *个数 0 	1 	2	3	4	5 	6 	7 	 ....	N-1		N
 *数字 0 	I 	2*I	3*I	4*I	5*I	6*I 7*I	 ....	I*(N-1) I*N
 *考虑到I也是从1-N变化的，不同之间的I也是可以组合的
 *
 *比如
 *个数 0 	1 	2	3	4	5 	6 	7 	 ....	N-1		N
 *数字 0 	J 	2*J	3*J	4*J	5*I	6*J 7*J	 ....	J*(N-1) J*N
 *由K个I和S个J组成的数字必然和为I+J,且有K*S种组法
 *这就迫使我们构造母函数
 *F(X,I)=X^(I*0)+X^(I*1)+X^(I*2)+X^(I*3)+X^(I*4)+....+X^(I*N)
 *其中1<=I<=N
 *我们将F(X,1)*F(X,2)*F(X,3)*F(X,4)*****F(X,N-1)*F(X,N)
 *得到的系数就是对应指数的方案数了
*/
//7)Polya计数公式(略)
//
//由于篇幅限制本文简略的介绍了组合数学中常见的概念与定理
//更多内容可以参考本文所引用的教材“组合数学”，作者“Richard A.Brualdi”

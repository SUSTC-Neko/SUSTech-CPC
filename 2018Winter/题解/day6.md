# Day 6
* * *
##  Course -- `math`

<br/>

* * *
## Problem--`SUSTechCPC 寒假集训day6`

<br/>

[<center> A. Tunnel Warfare </center>](https://cn.vjudge.net/problem/17493/origin)
---

**思路：**
> 题意：每个人都没有抽到自己的名字的概率是多少
> 做法：错排公式。函数f(n)表示把n个编号元素放在n个编号位置,元素编号与位置编号各不对应的方法数。则f(n-1)表示(n-1)个编号元素放在n-1个编号位置,元素编号与位置编号各不对应的方法数，以此类推。
> 具体方法：
> 第一步：把第n个元素放在一个位置(除了第n位之外),比如位置k,一共有n-1种方法;
> 第二步：移动编号为K的元素，这时有两种方法：
> 1、 把它放到位置n,那么,对于剩下的n-2个元素,就有f(n-2)种方法错排
> 2、 不把它放到位置n，那么对于剩下的n-1个元素有f(n-1)种方法错排。
> 第三步：对于每一个位置上的元素都有上面的过程。
> 所以：：综上可知错排公式为： f(n)=(n-1)*[f(n-1)+f(n-2)]。

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day6/A.cpp)

<br/>

[<center> B. Merge Equals </center>](https://cn.vjudge.net/problem/19394/origin)
---

**思路：**
> 题意：求直线与抛物线围成的面积
> 做法：1.积分硬算 2.自适应汤普森公式

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day6/B.cpp)

<br/>

[<center> C. Tunnel Warfare </center>](https://cn.vjudge.net/problem/20419/origin)
---

**思路：**
> 题意：一个立方体，n种颜色，问能涂成多少不同立方体
> 做法：Ploya
> 1.不变置换(1)(2)(3)(4)(5)(6), 共1个;
> 2.沿对面中心轴旋转 90度, 270度 (1)(2345)(6), (1)(5432)(6) 同类共 6个;
> 3.沿对面中心轴旋转 180度 (1)(24)(35)(6), 同类共 3个;
> 4.沿对角线轴旋转 120度, 240度 (152)(346), (251)(643) 同类共 8个;
> 5.沿对边中点轴旋转 180度 (16)(25)(43) 同类共 6个;
> (最开始做的时候，类比了学化竞中的晶胞的N重旋转轴)

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day6/C.cpp)

<br/>

[<center> D. Tunnel Warfare </center>](https://cn.vjudge.net/problem/45943/origin)
---

**思路：**
> 题意：整数分拆
> 做法：五边形数定理（其实只是套了叶老师的板子）

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day6/D.cpp)

<br/>

[<center> E. Tunnel Warfare </center>](https://cn.vjudge.net/problem/218742/origin)
---

**思路：**
> 题意：砖上放木人桩，有多少种放法
> 做法：DP题，把一个木头人当占三格来看，考虑一下两边的情况。a[i][j] = a[i - 1][j] + a[i - 1][j - 1]，最后ans += a[n - (i - 1) * 2][i]即可。
> 做法2：假设用f[n]表示有n个地板时所有的可能情况，那么可以分为两种情况。
> 一种是如果在第n个地板上不放置木桩的情况，一种是如果在第n个地板上放置木桩的情况。 对于第一种情况，可能的方案就为f[n-1]，因为不在这个地板上放置木桩，所以等同于有n-1个地板可以放置的方案数。
> 而对于第二种情况，我们知道，如果在第n个木板上放置木桩，那么上一个放置木桩的地方最近可以为n-3的地方，也就是说等同于在n-3个木板上放置木桩的最大方案数，但是因为在n-3个地板上放置的方案数不包括一个木桩都不放的情况，而如果仅在第n个木桩放置木桩，那么则需要加一。
> 由此可以得到递推关系:f[n] = f[n-1] + f[n-3] + 1;


[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day6/E.cpp)

<br/>

[<center> F. Tunnel Warfare </center>](https://cn.vjudge.net/problem/22019/origin)
---

**思路：**
> 题意：给你k张不同的卡放到n本书里有多少种放法？（n是无限大）
> 做法：第二类斯特灵数（给你k张牌放到n个无标号的盘子里（盘子不能为空）问你有多少种方法），Stirling[i][j] = Stirling[i-1][j-1] + j * Stirling[i-1][j]，然后求和即可。

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day6/F.cpp)

<br/>

[<center> J. Tunnel Warfare </center>](https://cn.vjudge.net/problem/30525/origin)
---

**思路：**
> 题意：从A到D与从B到C的路径中不相交的有多少条。
> 做法：从反面考虑，找相交的条数，用总条数减去相交的即为不相交的。所以找ac，bd相交的情况有多少种。

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day6/J.cpp)

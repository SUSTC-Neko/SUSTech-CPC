# Day 4
* * *
##  Course -- `segtree`

<br/>

* * *
## Problem--`SUSTechCPC 寒假集训day4`

<br/>

[<center> A. 敌兵布阵  </center>](http://acm.hdu.edu.cn/showproblem.php?pid=1166)
---

**思路：**
> 题意：给定N个营地的人数，给出每次人数的变化，查询从X-Y的营地人数总和。
> 做法：标准的线段树插入查询操作。我用的板子是区间加减的线段树，但本题只需要给一位加减操作就好了，也不需要想下传递。

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day4-segtree/A.cpp)

<br/>

[<center> B. Tunnel Warfare </center>](http://acm.hdu.edu.cn/showproblem.php?pid=1540)
---

**思路：**
> 题意：D代表破坏村庄，R代表修复最后被破坏的那个村庄，Q代表询问包括x在内的最大连续区间是多少
> 做法：三个变量记录左边连续区间，右边连续区间和最大连续区间，类似一个01序列连续个1的长度的问题

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day4-segtree/B.cpp)

<br/>

[<center> E. Merge Equals </center>](https://codeforces.com/problemset/problem/962/D)
---

**思路：**
> 题意：给你n个数，然后如果同一个数出现过两次或者多次的话，就把两个数求和，并放在两个数的右边。然后问你最终的那个数列的顺序。
> 做法：因为需要考虑最小的那个数字，所以我们可以采用优先队列的做法，取出顶堆的两个数（数值，位置），如果相同，把第二个数的数值乘2放回去；反之，把第一个数拿出来，第二个数放回去。

[[C++实现代码传送门]](https://github.com/SUSTech-Neko/SUSTech-CPC/blob/master/2018Winter/day4-segtree/E.cpp)

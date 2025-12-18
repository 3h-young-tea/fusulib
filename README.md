fusulib api 详解

[https://github.com/3h-young-tea/fusulib/edit/main/README.md](https://github.com/3h-young-tea/fusulib/edit/main/README.md)

更加现代的算法竞赛题目数据生成器, 使用 c++20 编写.

基于 [一扶苏一女士](https://codeforces.com/profile/_Fusu) 的 [代码](https://www.luogu.com.cn/paste/softmqwh) 重写而成, 原代码没有许可证, 所以我们使用 gplv3.

原码来自 [一扶苏一女士](https://codeforces.com/profile/_Fusu), [原网志](https://www.luogu.com.cn/article/exdkjvcu), [原代码](https://www.luogu.com.cn/paste/softmqwh).

由 [young_tea](https://codeforces.com/profile/young_tea) 重写代码并介绍 api.

注意和原代码的 api 不太一样.

#	用法

很简单, 只有一行.

```cpp
#include"fusulib.h"
```

#	命名空间

所有函数都在 `namespace fusu`, 辛苦朋友们在调用的时候使用 `fusu::next_x(0,999)`.

#	设置种子

`fusu::set_seed(ull x)` 函数用于设置种子, 不传入参数则会设为 $998~244~353$.

#	有效性检查

`fusu::is_valid(bool x)` 函数会检查传入的条件是否有效, 如果无效则会调用 `std::exit(777)`.

>	趣味小常识: `std::exit` 函数让程序崩溃后, 可以使用 `echo $?` 看到返回值.

#	基本随机数

##	$0$-base 随机数

`fusu::next_0(t x)` 返回的随机数在 $[0,x)$ 范围内.

##	$1$-base 随机数

`fusu::next_1(t x)` 返回的随机数在 $[1,x]$ 范围内.

##	范围随机数

`fusu::next_x(t l,t h)` 返回的随机数在 $[l,h]$ 范围内.

#	关联随机数

`fusu::next_range(t l,t h)` 会返回一个 `std::tuple<t,t>` 对象, 你可以使用一个 `auto [x,y]=fusu::next_range(1l,n)` 来承载. $x$ 和 $y$ 都在 $[l,h]$ 区间内, 且 $x\le y$.

>	注意: `n` 的类型是 `using ll=std::ptrdiff_t` 所以需要相同类型的 `1l`, 其中常数后缀 `l` 表示 `long` (即 `std::ptrdiff_t`).

##	用法 $1$

如果要生成一个有向边可以使用如下代码:

```cpp
auto [x,y]=fusu::next_range(1l,n);
if(fusu::next_x(0,1))	// 生成一个 bool 值
	std::swap(x,y);	// 如果生成的 bool 值有效则翻转边
std::cout<<x<<" "s<<y<<"\n"s;
```

##	用法 $2$

生成一个区间, 也是这个函数原本的作用:

```cpp
auto [f,g]=fusu::next_range(1l,n);
std::cout<<f<<" "s<<g<<"\n"s;
```

#	随机数组

##	$0$-base 数组

`fusu::next_arr_0(ll n,t l,t h)` 会返回一个数组, 下标 $[0..n)$ 是 $[l,h]$ 内的随机值.

这个数组是 `new` 出来的, 请手动 `delete[]`.

##	$1$-base 数组

`fusu::next_arr_1(ll n,t l,t h)` 会返回一个数组, 下标 $[1..n]$ 是 $[l,h]$ 内的随机值, 下标 $0$ 是 $0$.

这个数组是 `new` 出来的, 请手动 `delete[]`.

##	$0$-base 向量

`fusu::next_vec_0(ll n,t l,t h)` 会返回一个 `std::vector<t>` 对象, 下标 $[0..n)$ 是 $[l,h]$ 内的随机值.

##	$1$-base 向量

`fusu::next_vec_1(ll n,t l,t h)` 会返回一个 `std::vector<t>` 对象, 下标 $[1..n]$ 是 $[l,h]$ 内的随机值, 下标 $0$ 是 $0$.

#	随机选数字

##	$0$-base 随机选元素

`fusu::choice_0(t a,ll n)` 可以在 `a` 的 $[0,n)$ 下标内随机选元素并返回. 支持数组 `std::array` `std::vector` 等多种对象.

##	$1$-base 随机选元素

`fusu::choice_1(t a,ll n)` 可以在 `a` 的 $[1,n]$ 下标内随机选元素并返回. 支持数组 `std::array` `std::vector` 等多种对象.

#	生成弦

##	随机小写字母

`fusu::next_letter()` 会返回一个随机的小写字母.

##	随机大写字母

`fusu::next_Letter()` 会返回一个随机的大写字母.

##	随机弦

`fusu::next_str(ll n,bool op)` 在 $op==0$ 时会生成一个由小写字母组成的的弦, 下标在 $[0,n-1)$; 在 $op==1$ 时会生成一个由大写字母组成的的弦, 下标在 $[0,n-1)$.

#	文件操作

##	创建文件夹

`fusu::mkdir(std::string x)` 会创建文件夹 $x$.

在 $x$ 存在或 $x$ 不是文件夹 (比如是文件) 时不会做任何事.

##	生成 `.in` 文件

`fusu::gen_in(std::string file,FUNC func)` 会设置 `fusu::fout` 对象输出到 `file`, 然后调用 `func()`, 之后刷新 `fusu::fout` 并关闭 `file` 文件.

>	`func` 函数内请使用 `fusu::fout` 进行输出, 用法和 `std::cout` 相同.

`std::string file` 需要 `./recall/recall7.in` 的格式.

第二个参数建议使用 lambda, 当然也可以直接传入函数名, 但 lambda 可以捕获参数, 传入函数只能无参.

##	生成 `.ans` 文件

`fusu::gen_ans(std::string task,std::string stdx)` 会调用可执行文件 `stdx` 来制造 `.ans` 文件.

`task` 不需要 `.in` 或 `.out`, 只需要 `./recall/recall7` 的格式即可.

`stdx` 请不要使用 `std::freopen`, 我们会使用 `%s < %s.in > %s.ans`.

#	以及 `gen.cpp` 里的例子

在这个例子里我们制造了 [联合省选 2025 day 1 prob b recall](https://vjudge.net/problem/QOJ-10148) 的数据, 希望这个例子不要出锅.

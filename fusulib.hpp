#pragma once

#include <bits/stdc++.h>

using std::complex_literals::operator""i;
using std::string_literals::operator""s;

#ifdef	_WIN32
#error	"they are not like us"
#endif

/*
original by:	一扶苏一女士 https://codeforces.com/profile/_Fusu
original blog:	https://www.luogu.com.cn/article/exdkjvcu
original code:	https://www.luogu.com.cn/paste/softmqwh
recode by:	lil_tea https://codeforces.com/profile/fire_at_will
coding style:	lil_tea c++ style guide https://www.cnblogs.com/young-tea/p/19740914
*/

namespace fs {
std::mt19937_64 hack(998244353);

void	set_seed(unsigned long x = 998244353) {
	hack.seed(x);
}

long	nxt_0(long x) {
	return hack() % x;
}

long	nxt_1(long x) {
	return hack() % x + 1;
}

long	nxt_x(long low, long hgh) {
	return low + hack() % (hgh - low + 1);
}

std::tuple<long, long> nxt_tied(long low, long hgh) {
	long x = nxt_x(low, hgh), y = nxt_x(low, hgh);

	if (y < x)
		std::swap(x, y);

	return std::make_tuple(x, y);
}

std::vector<long> nxt_vec_0(std::size_t len, long low, long hgh) {
	std::vector<long> a(len);
	std::generate(a.begin(), a.end(), [&](void) {
		return nxt_x(low, hgh);
	});
	return a;
}

std::vector<long> nxt_vec_1(std::size_t len, long low, long hgh) {
	std::vector<long> a(len + 1);
	std::generate(a.begin() + 1, a.end(), [&](void) {
		return nxt_x(low, hgh);
	});
	return a;
}

std::vector<long> nxt_perm_0(std::size_t len) {
	std::vector<long> a(len);
	for (std::size_t x : std::views::iota(0uz, len))
		a[x] = x + 1;
	std::shuffle(a.begin(), a.end(), hack);
	return a;
}

std::vector<long> nxt_perm_1(std::size_t len) {
	std::vector<long> a(len + 1);
	for (std::size_t x : std::views::iota(1uz, len + 1))
		a[x] = x;
	std::shuffle(a.begin() + 1, a.end(), hack);
	return a;
}

long	choice_0(const std::vector<long> &a) {
	return a[nxt_0(a.size())];
}

long	choice_1(const std::vector<long> &a) {
	return a[nxt_1(a.size() - 1)];
}

char	nxt_letter(void) {
	return 'a' + nxt_0('z' - 'a' + 1);
}

char	nxt_Letter(void) {
	return 'A' + nxt_0('Z' - 'A' + 1);
}

std::string nxt_str(std::size_t len) {
	std::string s;
	for (std::size_t x : std::views::iota(0uz, len))
		s += nxt_letter();
	return s;
}

std::string nxt_Str(std::size_t len) {
	std::string s;
	for (std::size_t x : std::views::iota(0uz, len))
		s += nxt_Letter();
	return s;
}

void	mkdir(const std::string &x) {
	namespace ns_fs = std::filesystem;
	if (ns_fs::exists(x))
		if (ns_fs::is_directory(x))
			std::println(std::cerr, "has created the dir {}", x);
		else
			std::println(std::cerr, "lil_tea luvs _fusu"),
			std::abort();
	else
		ns_fs::create_directory(x),
		std::println(std::cerr, "created dir: {}", x);
}

std::ofstream fout;

void	gen_in(const std::string &prob, long task, auto &&func) {
	std::string file = prob + std::to_string(task);
	fout.open(file + ".in"s);
	func(task);
	fout.close();
	std::println(std::cerr, "gened in: {}.in", file);
}

void	gen_ans(const std::string &prob, long task, const std::string &stdx) {
	std::string file = prob + std::to_string(task);
	std::string cmd = "./"s + stdx + " < "s + file + ".in > "s + file + ".ans"s;
	std::system(cmd.c_str());
	std::println(std::cerr, "gened ans: {}.ans", file);
}
}

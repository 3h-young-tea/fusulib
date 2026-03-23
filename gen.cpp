#include <bits/stdc++.h>
#include "fusulib.hpp"

using std::complex_literals::operator""i;
using std::string_literals::operator""s;

constexpr long k_inf = 0x3f3f3f3f3f3f3f3fl;
constexpr long k_mod = 0x3b800001l;

auto	nxt(void) {
	long x;
	std::cin >> x;
	return x;
}

/*
prob link:	https://vjudge.net/problem/QOJ-10148
start think:	
term think:	
start code:	
term code:	
*/

void	make_data(long task) {
	long vtxes = 1e5, edges = 2e5, queries = 1e5;
	
	std::println(fs::fout, "{} 1", task);
	std::println(fs::fout, "{} {} {}", vtxes, edges, queries);

	while (edges--) {
		auto [x, y] = fs::nxt_tied(1, vtxes);

		while (x == y)
			std::tie(x, y) = fs::nxt_tied(1, vtxes);

		std::println(fs::fout, "{} {}", x, y);
	}

	std::vector<long> a(vtxes);

	for (long x : std::views::iota(0, vtxes))
		a[x] = x + 1;

	std::shuffle(a.begin(), a.end(), fs::hack);

	for (long x : std::views::iota(0, vtxes))
		std::print(fs::fout, "{}{}", a[x], " \n"s[x == vtxes - 1]);

	std::shuffle(a.begin(), a.end(), fs::hack);

	for (long x : std::views::iota(0, vtxes))
		std::print(fs::fout, "{}{}", a[x], " \n"s[x == vtxes - 1]);

	while (queries--) {
		long op = fs::nxt_x(1, 3);

		if (op == 1 || op == 2) {
			auto [x, y] = fs::nxt_tied(1, vtxes);

			while (x == y)
				std::tie(x, y) = fs::nxt_tied(1, vtxes);

			std::println(fs::fout, "{} {} {}", op, x, y);
		} else if (op == 3) {
			long x = fs::nxt_x(1, vtxes);
			auto [f, g] = fs::nxt_tied(1, vtxes);
			std::println(fs::fout, "{} {} {} {}", op, x, f, g);
		} else {
			std::println(std::cerr, "i`ve aked wf!");
		}
	}
}

void	solve(void) {
	std::string prob = "recall"s;
	long cases_tot = 25;
	std::string path = "./"s + prob + "/"s;

	fs::set_seed(std::chrono::system_clock::now().time_since_epoch().count());
	fs::mkdir(path);

	for (long t : std::views::iota(1, cases_tot + 1)) {
		fs::gen_in(path + prob, t, make_data);
		fs::gen_ans(path + prob, t, "std.x"s);
	}
}

signed	main(void) {
//	std::freopen(".in", "r", stdin);
//	std::freopen(".out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long _ = 1;

//	_ = nxt();

	while (_--)
		solve();

	std::cout.flush();
	return EXIT_SUCCESS;
}

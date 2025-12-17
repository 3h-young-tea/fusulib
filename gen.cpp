#include<bits/stdc++.h>
#include"fusulib.h"
using namespace std::string_literals;
using lf=double;
using ll=std::ptrdiff_t;
using ull=std::size_t;
using us=unsigned;
auto	nxt_lf(void)->lf{lf x;std::cin>>x;return x;}
auto	nxt_ll(void)->ll{ll x;std::cin>>x;return x;}
auto	nxt_ull(void)->ull{ull x;std::cin>>x;return x;}
auto	nxt_us(void)->us{us x;std::cin>>x;return x;}
constexpr ll inf=0x3f3f3f3f3f3f3f3fl;
constexpr ll mod=0x3b800001l;
/*
prob link:	https://vjudge.net/problem/QOJ-10148
start think:	
term think:	
start code:	
term code:	
*/
void	make_data(ll t){
	fusu::fout<<t<<" 1\n"s;
	ll n=100000,m=200000,q=100000;
	fusu::fout<<n<<" "s<<m<<" "s<<q<<"\n"s;
	while(m--){
		auto [x,y]=fusu::next_range(1l,n);
		while(x==y)
			std::tie(x,y)=fusu::next_range(1l,n);
		fusu::fout<<x<<" "s<<y<<"\n"s;
	}	ll *a=new ll[n+1]();
	for(ll x=1;x<=n;x++)
		a[x]=x;
	std::shuffle(a+1,a+1+n,fusu::hack);
	for(ll x=1;x<=n;x++)
		fusu::fout<<a[x]<<" \n"s[x==n];
	std::shuffle(a+1,a+1+n,fusu::hack);
	for(ll x=1;x<=n;x++)
		fusu::fout<<a[x]<<" \n"s[x==n];
	delete[] a;
	while(q--){
		ll op=fusu::next_x(1,3);
		fusu::fout<<op<<" "s;
		if(op<=2){
			auto [x,y]=fusu::next_range(1l,n);
			fusu::fout<<x<<" "s<<y<<"\n"s;
		}else{	ll x=fusu::next_x(1l,n);
			auto [f,g]=fusu::next_range(1l,n);
			fusu::fout<<x<<" "s<<f<<" "s<<g<<"\n"s;
		}
	}
}
void	solve(void){
	std::string prob="recall"s;
	ll tot_case=25;
	std::string stdx="std"s;
	std::string folder="recall"s;
	std::string path="./"s+folder+"/"s;
	fusu::mkdir(path);
	fusu::set_seed(std::chrono::system_clock::now().time_since_epoch().count());
	for(ll t=1;t<=tot_case;t++){
		std::string task=prob+std::to_string(t);
		fusu::gen_in(path+task+".in"s,[t]{make_data(t);});
		fusu::gen_ans(path+task,stdx);
	}
}
auto	main(void)->signed{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	ll _=1;
//	_=nxt_ll();
	while(_--)
		solve();
	return 0;
}

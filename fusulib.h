#ifndef _FUSULIB_H_
#define _FUSULIB_H_
#include<bits/stdc++.h>
using namespace std::string_literals;
using lf=double;
using ll=std::ptrdiff_t;
using ull=std::size_t;
using us=unsigned;
/*
original by 一扶苏一女士 https://codeforces.com/profile/_Fusu
original blog: https://www.luogu.com.cn/article/exdkjvcu
original code: https://www.luogu.com.cn/paste/softmqwh
recode by young_tea https://codeforces.com/profile/young_tea
*/
namespace fusu{
std::mt19937_64 hack(0x20000430l);
void	set_seed(ull x=0x20000430l){
	hack.seed(x);
}
void	is_valid(bool x){
	if(x==0)
		exit(777);
}
template<class t>
auto	next_0(t x)->t{
	is_valid(0<x);
	return hack()%x;
}
template<class t>
auto	next_1(t x)->t{
	is_valid(0<x);
	return hack()%x+1;
}
template<class t>
auto	next_x(t l,t h)->t{
	is_valid(l<=h);
	return l+hack()%(h-l+1);
}
template<class t>
auto	next_range(t l,t h)->std::tuple<t,t>{
	ll f=next_x(l,h),g=next_x(l,h);
	if(g<f)
		std::swap(f,g);
	return std::make_tuple(f,g);
}
template<class t>
auto	next_arr_0(ll n,t l,t h)->t*{
	is_valid(0<n);
	t *a=new t[n]();
	std::generate(a,a+n,[&](void){return next_x(l,h);});
	return a;
}
template<class t>
auto	next_arr_1(ll n,t l,t h)->t*{
	is_valid(0<n);
	t *a=new t[n+1]();
	std::generate(a+1,a+1+n,[&](void){return next_x(l,h);});
	return a;
}
template<class t>
auto	next_vec_0(ll n,t l,t h)->std::vector<t>{
	is_valid(0<n);
	std::vector<t>a(n,t());
	std::generate(a.begin(),a.end(),[&](void){return next_x(l,h);});
	return a;
}
template<class t>
auto	next_vec_1(ll n,t l,t h)->std::vector<t>{
	is_valid(0<n);
	std::vector<t>a(n+1,t());
	std::generate(a.begin()+1,a.end(),[&](void){return next_x(l,h);});
	return a;
}
template<typename t>
auto	choice_0(t &a,ll n){
	return a[next_0(n)];
}
template<typename t>
auto	choice_1(t &a,ll n){
	return a[next_1(n)];
}
auto	next_letter(void)->char{
	return 'a'+next_0(26);
}
auto	next_Letter(void)->char{
	return 'A'+next_0(26);
}
auto	next_str(ll n,bool op)->std::string{
	is_valid(0<n);
	std::string ct;
	for(ll x=0;x<n;x++)
		if(op==0)
			ct+=next_letter();
		else	ct+=next_Letter();
	return ct;
}
void	mkdir(std::string &x){
	is_valid(0<x.length());
	namespace fop=std::filesystem;
	if(!fop::exists(x)||!fop::is_directory(x)){
		fop::create_directory(x);
		std::cerr<<"created directory: "s<<x<<"\n"s;
	}
}
std::ofstream fout;
void	gen_in(std::string file,auto &&func){
	fout.open(file);
	func();
	fout.close();
	std::cerr<<"gened input: "s<<file<<"\n"s;
}
void	gen_ans(std::string task,std::string stdx){
	std::string cmd="./"s+stdx+" < "s+task+".in > "s+task+".ans"s;
	std::system(cmd.c_str());
	std::cerr<<"gened answer: "s<<task+".ans"s<<"\n"s;
}
}
#endif	// _FUSULIB_H_

#pragma once

/*
����ģʽ������һϵ�е��㷨,������һ������װ����, ����ʹ���ǿ��໥�滻��

��Ҫ��������ж����㷨���Ƶ�����£�ʹ�� if��else �������ĸ��Ӻ�����ά����

��ʱʹ�ã�һ��ϵͳ���������࣬���������ǵ�ֻ������ֱ�ӵ���Ϊ��

��ν��������Щ�㷨��װ��һ��һ�����࣬������滻��

�ؼ����룺ʵ��ͬһ���ӿڡ�

Ӧ��ʵ���� 1��������Ľ�����ƣ�ÿһ�����Ҿ���һ�����ԡ� 2�����еĳ��η�ʽ��ѡ�������г�����������ÿһ�����з�ʽ����һ�����ԡ� 3��JAVA AWT �е� LayoutManager��

�ŵ㣺 1���㷨���������л��� 2������ʹ�ö��������жϡ� 3����չ�����á�

ȱ�㣺 1������������ࡣ 2�����в����඼��Ҫ���Ⱪ¶��

ʹ�ó����� 1�������һ��ϵͳ����������࣬����֮���������������ǵ���Ϊ����ôʹ�ò���ģʽ���Զ�̬����һ�������������Ϊ��ѡ��һ����Ϊ�� 2��һ��ϵͳ��Ҫ��̬���ڼ����㷨��ѡ��һ�֡� 3�����һ�������кܶ����Ϊ���������ǡ����ģʽ����Щ��Ϊ��ֻ��ʹ�ö��ص�����ѡ�������ʵ�֡�

ע��������һ��ϵͳ�Ĳ��Զ����ĸ�������Ҫ����ʹ�û��ģʽ��������������͵����⡣
*/

#include <memory>
#include <iostream>

using namespace std;

class StrategyBase
{
public:
	StrategyBase() = default;
	virtual ~StrategyBase() {};
public:
	virtual void doSomething(int i) = 0;
};

class StrategyA : public StrategyBase
{
public:
	StrategyA() :StrategyBase() {};
	~StrategyA() {};

	void doSomething(int i) override {
		cout << "StrategyA for i*100=:" << i * 100 << endl;
	};
private:

};

class StrategyB : public StrategyBase
{
public:
	StrategyB() :StrategyBase() {};
	~StrategyB() {};

	void doSomething(int i) override {
		cout << "StrategyB for i*2=:" << i * 2 << endl;
	};
private:

};


class Context
{
public:
	Context(int type) {
		switch (type)
		{
		case 0:
			_pStrategy = make_shared<StrategyA>();
			break;
		case 1:
			_pStrategy = make_shared<StrategyB>();
			break;
		default:
			break;
		}
	};
	~Context() {};
public:
	void doSomething(int i) {
		_pStrategy->doSomething(i);
	};
private:
	shared_ptr<StrategyBase> _pStrategy;
};

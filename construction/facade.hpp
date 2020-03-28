#pragma once

/*
���ģʽ��Facade Pattern������ϵͳ�ĸ����ԣ�����ͻ����ṩ��һ���ͻ��˿��Է���ϵͳ�Ľӿڡ��������͵����ģʽ���ڽṹ��ģʽ���������е�ϵͳ���һ���ӿڣ�������ϵͳ�ĸ����ԡ�

����ģʽ�漰��һ����һ���࣬�����ṩ�˿ͻ�������ļ򻯷����Ͷ�����ϵͳ�෽����ί�е��á�

����
��ͼ��Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һ�µĽ��棬���ģʽ������һ���߲�ӿڣ�����ӿ�ʹ����һ��ϵͳ��������ʹ�á�

��Ҫ��������ͷ��ʸ���ϵͳ���ڲ���ϵͳʱ�ĸ��Ӷȣ��򻯿ͻ�����֮�Ľӿڡ�

��ʱʹ�ã� 1���ͻ��˲���Ҫ֪��ϵͳ�ڲ��ĸ�����ϵ������ϵͳֻ���ṩһ�����Ӵ�Ա�����ɡ� 2������ϵͳ����ڡ�

��ν�����ͻ��˲���ϵͳ��ϣ��������ϵͳ��ϡ�

�ؼ����룺�ڿͻ��˺͸���ϵͳ֮���ټ�һ�㣬��һ�㽫����˳��������ϵ�ȴ���á�

Ӧ��ʵ���� 1��ȥҽԺ����������Ҫȥ�Һš�������ۡ�ȡҩ���û��߻��߼������úܸ��ӣ�������ṩ�Ӵ���Ա��ֻ�ýӴ���Ա�������ͺܷ��㡣 2��JAVA �����㿪��ģʽ��

�ŵ㣺 1������ϵͳ�໥������ 2���������ԡ� 3������˰�ȫ�ԡ�

ȱ�㣺�����Ͽ���ԭ�����Ҫ�Ķ������鷳���̳���д�������ʡ�

ʹ�ó����� 1��Ϊ���ӵ�ģ�����ϵͳ�ṩ�����ʵ�ģ�顣 2����ϵͳ��Զ����� 3��Ԥ����ˮƽ��Ա�����ķ��ա�

ע������ڲ�λ��ṹ�У�����ʹ�����ģʽ����ϵͳ��ÿһ�����ڡ�

*/

#include <memory>
#include <iostream>
using namespace std;

class SubSysOne
{
public:
	SubSysOne() {};
	~SubSysOne() {};

	void methodOne() {
		cout << __FUNCTION__ << " called" << endl;
	};

private:

};

class SubSysTwo
{
public:
	SubSysTwo() {};
	~SubSysTwo() {};

	void methodTwo() {
		cout << __FUNCTION__ << " called" << endl;
	};

private:

};

class SubSysThree
{
public:
	SubSysThree() {};
	~SubSysThree() {};

	void methodThree() {
		cout << __FUNCTION__ << " called" << endl;
	};

private:

};

class SubSysFour
{
public:
	SubSysFour() {};
	~SubSysFour() {};

	void methodFour() {
		cout << __FUNCTION__ << " called" << endl;
	};

private:

};




class Facade
{
public:
	Facade() {
		_spSubOne = make_shared<SubSysOne>();
		_spSubTwo = make_shared<SubSysTwo>();
		_spSubThree = make_shared<SubSysThree>();
		_spSubFour = make_shared<SubSysFour>();
	};
	~Facade() {};
public:
	void method() {
		_spSubOne->methodOne();
		_spSubTwo->methodTwo();
		_spSubThree->methodThree();
		_spSubFour->methodFour();
	};
private:
	shared_ptr<SubSysOne> _spSubOne;
	shared_ptr<SubSysTwo> _spSubTwo;
	shared_ptr<SubSysThree> _spSubThree;
	shared_ptr<SubSysFour> _spSubFour;
};

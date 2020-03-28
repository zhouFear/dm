#pragma once
#include <iostream>
/*
װ����ģʽ
װ����ģʽ��Decorator Pattern��������һ�����еĶ�������µĹ��ܣ�ͬʱ�ֲ��ı���ṹ���������͵����ģʽ���ڽṹ��ģʽ��������Ϊ���е����һ����װ��

����ģʽ������һ��װ���࣬������װԭ�е��࣬���ڱ����෽��ǩ�������Ե�ǰ���£��ṩ�˶���Ĺ��ܡ�

����ͨ�������ʵ������ʾװ����ģʽ���÷������У����ǽ���һ����״װ���ϲ�ͬ����ɫ��ͬʱ�ֲ��ı���״�ࡣ

����
��ͼ����̬�ظ�һ���������һЩ�����ְ�𡣾����ӹ�����˵��װ����ģʽ������������Ϊ��

��Ҫ�����һ��ģ�����Ϊ����չһ���ྭ��ʹ�ü̳з�ʽʵ�֣����ڼ̳�Ϊ�����뾲̬����������������չ���ܵ����࣬���������͡�

��ʱʹ�ã��ڲ������Ӻܶ�������������չ�ࡣ

��ν���������幦��ְ�𻮷֣�ͬʱ�̳�װ����ģʽ��

�ؼ����룺 1��Component ��䵱�����ɫ����Ӧ�þ���ʵ�֡� 2�����������úͼ̳� Component �࣬������չ����д���෽����

Ӧ��ʵ���� 1��������� 72 �䣬������ɡ���������ĸ�������һֻ���ӣ�����������������Ĺ��ܡ� 2������һ������û�л��򶼿��Թ���ǽ�ϣ�����ͨ�������л���ģ�����ʵ�����ǻ��򱻹���ǽ�ϡ��ڹ���ǽ��֮ǰ�������Ա����ϲ�����װ���������ʱ���������ͻ����γ���һ�����塣

�ŵ㣺װ����ͱ�װ������Զ�����չ�������໥��ϣ�װ��ģʽ�Ǽ̳е�һ�����ģʽ��װ��ģʽ���Զ�̬��չһ��ʵ����Ĺ��ܡ�

ȱ�㣺���װ�αȽϸ��ӡ�

ʹ�ó����� 1����չһ����Ĺ��ܡ� 2����̬���ӹ��ܣ���̬������
*/
using namespace std;


//������һ������ӿڣ����Ը���Щ����̬�����ְ��
class Component
{
public:
	virtual void operation() = 0;
};


// ������󣬿��Ը�����������ְ��
class ConcreteComponent :
	public Component
{
public:
	ConcreteComponent() {};
	~ConcreteComponent()
	{

	}
public:
	void operation() override
	{
		cout << "ConcreteComponent Operation\n";
	}
};

// װ�γ����� ���̳���Component����չComponent�Ĺ���
class Decorator: public Component
{
public:
	Decorator() {};
	~Decorator() {};

public:
	void setComponent(Component* com) {
		component = com;
	}

	void operation() override {
		component->operation();
	};
private:
	Component* component = nullptr;
};


class ConcreteDecoratorA :public Decorator
{
public:
	ConcreteDecoratorA() {};
	~ConcreteDecoratorA() {};

public:
	void operation() override {
		__super::operation();
		cout << "ConcreteDecoratorA Operation\n";
		operationA();
	};

	void operationA() {
		cout << "ConcreteDecoratorA Add something\n";
	}
};


class ConcreteDecoratorB :public Decorator
{
public:
	ConcreteDecoratorB() {};
	~ConcreteDecoratorB() {};

public:
	void operation() override {
		__super::operation();
		cout << "ConcreteDecoratorB Operation\n";
		operationB();
	};

	void operationB() {
		cout << "ConcreteDecoratorB Add something\n";
	}
};
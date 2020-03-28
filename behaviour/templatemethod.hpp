#pragma once
/*
����һ�������е��㷨�ĹǼܣ�����һЩ�����ӳٵ������С�ģ�巽��ʹ��������Բ��ı�һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�ض����衣

��Ҫ�����һЩ����ͨ�ã�ȴ��ÿһ�����඼����д����һ������

��ʱʹ�ã���һЩͨ�õķ�����

��ν��������Щͨ���㷨���������

�ؼ����룺�ڳ�����ʵ�֣���������������ʵ�֡�

Ӧ��ʵ���� 1�����췿�ӵ�ʱ�򣬵ػ������ߡ�ˮ�ܶ�һ����ֻ���ڽ����ĺ��ڲ��мӱڳ���դ���Ȳ��졣 2�����μ������������õ� 81 �ѣ������һ��������߼��Ǽܡ� 3��spring �ж� Hibernate ��֧�֣���һЩ�Ѿ����õķ�����װ���������翪�����񡢻�ȡ Session���ر� Session �ȣ�����Ա���ظ�д��Щ�Ѿ��淶�õĴ��룬ֱ�Ӷ�һ��ʵ��Ϳ��Ա��档

�ŵ㣺 1����װ���䲿�֣���չ�ɱ䲿�֡� 2����ȡ�������룬����ά���� 3����Ϊ�ɸ�����ƣ�����ʵ�֡�

ȱ�㣺ÿһ����ͬ��ʵ�ֶ���Ҫһ��������ʵ�֣�������ĸ������ӣ�ʹ��ϵͳ�����Ӵ�

ʹ�ó����� 1���ж�����๲�еķ��������߼���ͬ�� 2����Ҫ�ġ����ӵķ��������Կ�����Ϊģ�巽����

ע�����Ϊ��ֹ���������һ��ģ�巽�������� final �ؼ��ʡ�
*/

#include <stdio.h>

class TemplateMethodBase
{
public:
	TemplateMethodBase() = default;
	virtual ~TemplateMethodBase() {}

	void templateMethod() {
		printf("templateMethod:\n");
		operationA();
		operationB();
	}

	virtual void operationA() = 0;

	virtual void operationB() = 0;

private:

};


class MethodA : public TemplateMethodBase
{
public:
	MethodA() = default;
	~MethodA(){};

	void operationA() override {
		printf("MethodA:operationA\n");
	};

	void operationB() override {
		printf("MethodA:operationB\n");
	}

private:

};

class MethodB : public TemplateMethodBase
{
public:
	MethodB() = default;
	~MethodB() {};

	void operationA() override {
		printf("MethodB:operationA\n");
	};

	void operationB() override {
		printf("MethodB:operationB\n");
	}

private:

};
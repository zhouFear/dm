#pragma once
/*
������ģʽ��Builder Pattern��ʹ�ö���򵥵Ķ���һ��һ��������һ�����ӵĶ����������͵����ģʽ���ڴ�����ģʽ�����ṩ��һ�ִ����������ѷ�ʽ��

һ�� Builder ���һ��һ���������յĶ��󡣸� Builder ���Ƕ�������������ġ�

����
��ͼ����һ�����ӵĹ��������ʾ����룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��

��Ҫ�������Ҫ��������ϵͳ�У���ʱ�������š�һ�����Ӷ��󡱵Ĵ�����������ͨ���ɸ������ֵ��Ӷ�����һ�����㷨���ɣ���������ı仯��������Ӷ���ĸ������־��������ž��ҵı仯�����ǽ����������һ����㷨ȴ����ȶ���

��ʱʹ�ã�һЩ������������䣬������Ͼ����仯��ʱ��

��ν���������벻����뿪��

�ؼ����룺�����ߣ��������ṩʵ�������ݣ������������ʵ����������ϵ��

Ӧ��ʵ���� 1��ȥ�ϵ»������������֡�������ը������ǲ���ģ���������Ǿ����仯�ģ����ɳ���ν�ġ��ײ͡��� 2��JAVA �е� StringBuilder��

�ŵ㣺 1�������߶���������չ�� 2�����ڿ���ϸ�ڷ��ա�

ȱ�㣺 1����Ʒ�����й�ͬ�㣬��Χ�����ơ� 2�����ڲ��仯���ӣ����кܶ�Ľ����ࡣ

ʹ�ó����� 1����Ҫ���ɵĶ�����и��ӵ��ڲ��ṹ�� 2����Ҫ���ɵĶ����ڲ����Ա����໥������

ע������빤��ģʽ�������ǣ�������ģʽ���ӹ�ע�����װ���˳��
*/

#include <string>
#include <iostream>
#include <assert.h>
#include <memory>

#define NOCOPY(classname)   classname(const classname& other) = delete;\
							classname& operator=(const classname& other) = delete;

#define INTERFACE virtual
#define PURE =0

using std::string;
using namespace std;

class Product
{
public:
	Product() = default;
	~Product() = default;

public:
	void setTie(const string& t) {
		tie = t;
	}

	void setEngine(const string& e) {
		engine = e;
	}

	void setChangebox(const string& c) {
		changebox = c;
	}

	void setName(const string& n) {
		name = n;
	}

	void showCar() {
		cout << "name:" << name << " engine:" << engine <<
			" changebox:" << changebox << " tie:" << tie << endl;
	}
private:
	string name;
	string tie;
	string engine;
	string changebox;
};

class BuilderBase
{
public:
	BuilderBase() = default;
	virtual ~BuilderBase() {
		if (pProduct) {
			delete pProduct;
			pProduct = nullptr;
		}
	};
	NOCOPY(BuilderBase);
public:
	INTERFACE void buildTie() PURE;
	INTERFACE void buildEngine() PURE;
	INTERFACE void buildChangebox() PURE;
	INTERFACE void buildName() PURE;
	Product* getProduct() {
		return pProduct;
	};
protected:
	Product* pProduct = new Product();
};


class BuildBenze : public BuilderBase
{
public:
	BuildBenze() : BuilderBase() {};
	~BuildBenze() = default;

	NOCOPY(BuildBenze);

public:
	void buildTie() override {
		assert(pProduct);
		pProduct->setTie("Michelin");
	}

	void buildEngine() override {
		assert(pProduct);
		pProduct->setEngine("Benze V8");
	}

	void buildChangebox() override {
		assert(pProduct);
		pProduct->setChangebox("cvt 12");
	}

	void buildName() override {
		assert(pProduct);
		pProduct->setName("Benze");
	}
private:

};

class BuildFerrir : public BuilderBase
{
public:
	BuildFerrir() : BuilderBase() {};
	~BuildFerrir() = default;

	NOCOPY(BuildFerrir);

public:
	void buildTie() override {
		assert(pProduct);
		pProduct->setTie("Bridgestone");
	}

	void buildEngine() override {
		assert(pProduct);
		pProduct->setEngine("f2020 V8");
	}

	void buildChangebox() override {
		assert(pProduct);
		pProduct->setChangebox("vt 12");
	}

	void buildName() override {
		assert(pProduct);
		pProduct->setName("Ferrir");
	}
private:

};




class Director
{
public:
	Director() = default;
	~Director() = default;

public:
	void construct(shared_ptr<BuilderBase> spBuilder) {
		spBuilder->buildTie();
		spBuilder->buildChangebox();
		spBuilder->buildEngine();
	}
private:
	
};

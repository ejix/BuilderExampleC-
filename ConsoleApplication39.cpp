// ConsoleApplication39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>

class ZestawKomputerowy {
private:
	std::string monitor;
	std::string procesor;
	std::string grafika;
	std::string ram;
	std::string hdd;
public:
	void setMonitor(std::string m) {
		monitor = m;
	}
	void setProcesor(std::string p) {
		procesor = p;
	}
	void setGrafika(std::string g) {
		grafika = g;
	}
	void setRam(std::string r) {
		ram = r;
	}
	void setHdd(std::string h) {
		hdd = h;
	}
	void show() {
		if (monitor != "")std::cout << "monitor = " << monitor << std::endl;
		if (procesor != "")std::cout << "procesor= " << procesor << std::endl;
		if (grafika != "")std::cout << "grafika= " << grafika << std::endl;
		if (ram != "")std::cout << "ram= " << ram << std::endl;
		if (hdd != "")std::cout << "hdd= " << hdd << std::endl;

	}
};

class Builder {
protected:
	ZestawKomputerowy* zestawKomputerowy;
public:
	void newZestaw() {
		zestawKomputerowy =  new ZestawKomputerowy();
	}
	ZestawKomputerowy getZestaw() {
		return*zestawKomputerowy;
	}
	virtual void buildMonitor() = 0;
	virtual void buildProcesor() = 0;
	virtual void buildGrafika() = 0;
	virtual void buildRam() = 0;
	virtual void buildHdd() = 0;

};

class set001 :public Builder {
public:
	set001() :Builder() {}
	void buildMonitor() {
		zestawKomputerowy->setMonitor("benq 19");
	}
	virtual void buildProcesor() {
		zestawKomputerowy->setProcesor("Intel");
	}
	virtual void buildGrafika() {
		zestawKomputerowy->setGrafika("ATI");
	}
	virtual void buildRam() {
		zestawKomputerowy->setRam("DDR3");
	}
	virtual void buildHdd() {
		zestawKomputerowy->setHdd("Samsung");
	}
};
class set002:public Builder {
public:
	set002() :Builder() {}
	void buildMonitor() {
		zestawKomputerowy->setMonitor("benq 21");
	}
	virtual void buildProcesor() {
		zestawKomputerowy->setProcesor("AMD");
	}
	virtual void buildGrafika() {
		zestawKomputerowy->setGrafika("NvIDIA");
	}
	virtual void buildRam() {
		zestawKomputerowy->setRam("DDR4");
	}
	virtual void buildHdd() {
		zestawKomputerowy->setHdd("seagate");
	}
};

class Director {
private:
	Builder *builder;
public:
	void setBuilder(Builder *b ) {
		builder = b;
	}
	ZestawKomputerowy getZestaw() {
		return builder->getZestaw();
	}
	void skladaj() {
		builder->newZestaw();
		builder->buildMonitor();
		builder->buildProcesor();
		builder->buildHdd();
		builder->buildRam();
		builder->buildGrafika();
	}
};
int main()
{
	Director *szef = new Director();
	Builder * builder = new set001();
	Builder * builder2 = new set002();
	std::cout << "ZESTAW 1: " << std::endl;
	szef->setBuilder(builder);
	szef->skladaj();
	ZestawKomputerowy zestaw1 = szef->getZestaw();
	zestaw1.show();
	std::cout << "ZESTAW 2: " << std::endl;
	szef->setBuilder(builder2);
	szef->skladaj();
	ZestawKomputerowy zestaw2 = szef->getZestaw();
	zestaw2.show();
    return 0;
}


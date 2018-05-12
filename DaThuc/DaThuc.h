#ifndef DATHUC_H
#define DATHUC_H
#pragma once
#include "DonThuc.h"
class DaThuc
{
private:
	unsigned int size;
	DonThuc **arr;

public:
	DaThuc * nhan(float k);
	DaThuc * nhan(DonThuc *don);
	DaThuc * nhan(DaThuc *da);
	DaThuc * cong(DonThuc *don);
	DaThuc * cong(DaThuc *da);
	DaThuc * tru(DonThuc *don);
	DaThuc * tru(DaThuc *da);
	DaThuc * chia(DonThuc *don);
	DaThuc * chia(DaThuc *da);
	DaThuc * phanDu(DaThuc *da);
	DaThuc * createCopy();
public:
	DaThuc();
	DaThuc(DonThuc * don);
	DaThuc(unsigned int SoMuMax);
	
	~DaThuc();
private:

	DaThuc(DonThuc ** arr, unsigned int size);

public:
	void write(char x = 'x');
	void writeline(char x = 'x');
public:
	void chuanHoa();
	DonThuc * getDonThucMax();
	int isEqual(DaThuc *da);
};
#endif


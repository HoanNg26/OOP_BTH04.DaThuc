#ifndef DONTHUC_H
#define DONTHUC_H
#pragma once
//#include "DaThuc.h"
class DaThuc;

class DonThuc
{
private:
	float hs;
	int sm;

public:
	float getHs();
	void setHs(float hs);
	int getSm();
	float tinhGiaTri(float x);

public:
	int isCungBac(DonThuc * don);
	int isEqual(DonThuc * don);
	DonThuc * nhan(DonThuc * don);
	DonThuc * nhan(float k);
	DaThuc *cong(DonThuc * don);
	DaThuc *cong(DaThuc * da);
	DonThuc *chia(DonThuc * don);
	DonThuc *chia(DaThuc * da);

public:
	void write(char x = 'x');
	void writeline(char x = 'x');
public:
	DonThuc();
	DonThuc(int sm);
	DonThuc(float hs);
	DonThuc(float hs, int sm);
	DonThuc(const DonThuc * don);
	~DonThuc();
};

#endif
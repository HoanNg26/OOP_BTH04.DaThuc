#include "stdafx.h"
#include "DonThuc.h"
#include "DaThuc.h"
#include <math.h>
#include <stdio.h>

float DonThuc::getHs()
{
	return this->hs;
}

void DonThuc::setHs(float hs)
{
	this->hs = hs;
}

int DonThuc::getSm()
{
	return this->sm;
}

float DonThuc::tinhGiaTri(float x)
{
	return (this->hs) * pow(x,this->sm);
}

int DonThuc::isCungBac(DonThuc * don)
{
	if (don == NULL)
		return 0;
	if (this->sm == don->sm)
		return 1; //cung bac
	return 0;
}

int DonThuc::isEqual(DonThuc * don)
{
	if (don == NULL)
		return 0;
	if (this->hs = don->hs && this->sm == don->sm)
		return 1;
	return 0;
}

DonThuc * DonThuc::nhan(DonThuc * don)
{
	if (don == NULL)
		return NULL;
	DonThuc * tmp = new DonThuc();
	tmp->hs = this->hs * don->hs;
	tmp->sm = this->sm + don->sm;
	return tmp;
}

DonThuc * DonThuc::nhan(float k)
{
	return new DonThuc(this->hs*k,this->sm);
}

DaThuc * DonThuc::cong(DonThuc * don)
{
	DaThuc * da1 = new DaThuc(this);
	DaThuc * da2 = new DaThuc(don);
	DaThuc * da3 = da1->cong(da2);
	delete da1;
	delete da2;

	return da3;
}

DaThuc * DonThuc::cong(DaThuc * da)
{
	if (da == NULL)
		return new DaThuc(this);
	return da->cong(this);
}

DonThuc * DonThuc::chia(DonThuc * don)
{
	if (don == NULL)
		return NULL;
	if (don->hs == 0)
		return NULL;
	if (this->sm < don->sm)
		return new DonThuc(0, 0);
	return new DonThuc(this->hs / don->hs, this->sm - don->sm);
}

DonThuc * DonThuc::chia(DaThuc * da)
{
	if (da == NULL)
		return NULL;
	da->chuanHoa();
	DonThuc *don = da->getDonThucMax();
	if (don->getHs() == 0)
		return NULL;
	return this->chia(don);
}


void DonThuc::write(char x)
{
	printf("%0.1f%c%d", this->hs,x,this->sm);
}

void DonThuc::writeline(char x)
{
	printf("%0.1f%c%d\n", this->hs, x, this->sm);
}

DonThuc::DonThuc()
{
	this->hs = 0;
	this->sm = 0;
}

DonThuc::DonThuc(int sm)
{
	this->hs = 1;
	this->sm = sm;
}

DonThuc::DonThuc(float hs)
{
	this->hs = hs;
	this->sm = 0;
}

DonThuc::DonThuc(float hs, int sm)
{
	this->hs = hs;
	this->sm = sm;
}

DonThuc::DonThuc(const DonThuc * don)
{
	this->hs = don->hs;
	this->sm = don->sm;
}


DonThuc::~DonThuc()
{
}

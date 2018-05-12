#include "stdafx.h"
#include "DaThuc.h"


DaThuc * DaThuc::nhan(float k)
{
	DaThuc *temp = this->createCopy();
	for (unsigned int i = 0; i < temp->size; i++)
		temp->arr[i]->setHs(k* temp->arr[i]->getHs());
	temp->chuanHoa();
	return temp;
}

DaThuc * DaThuc::nhan(DonThuc * don)
{
	if (don == NULL)
		return NULL;
	unsigned int tmpSize = this->size + don->getSm();
	DonThuc ** tmpArr = new DonThuc *[tmpSize];
	for (unsigned i = 0; i < tmpSize; i++) {
		tmpArr[i] = new DonThuc(0, i);
	}
	for (unsigned i = don->getSm(); i< tmpSize; i++) {
		tmpArr[i]->setHs(arr[i - don->getSm()]->getHs()*don->getHs());
	}
	return new DaThuc(tmpArr, tmpSize);
}

DaThuc * DaThuc::nhan(DaThuc * da)
{
	if (da == NULL) {
		return NULL;
	}
	DaThuc *tmp = this->nhan(da->arr[da->size - 1]);
	for (unsigned int i = 0; i < da->size - 1; i++) {
		DaThuc * tmp1 = this->nhan(da->arr[i]);
		DaThuc * tmp2 = tmp->cong(tmp1);
		delete tmp1;
		delete tmp;
		tmp = tmp2;
	}
	return tmp;
}

DaThuc * DaThuc::cong(DonThuc * don)
{
	if (don == NULL)
		return NULL;
	//1. max (so mu dathuc) >= so mu don thuc
	if (this->arr[this->size-1]->getSm() >= don->getSm()) {
		unsigned int tmpSize = this->size;
		DonThuc ** tmpArr = new DonThuc *[tmpSize];
		for (unsigned int i = 0; i < tmpSize; i++) {
			tmpArr[i] = new DonThuc(this->arr[i]);
		}
		tmpArr[don->getSm()]->setHs(arr[don->getSm()]->getHs() + don->getHs());
		return new DaThuc(tmpArr, this->size);
	}
	else { //so mu do thuc > so mu Dathuc
		unsigned int tmpSize = don->getSm() + 1;
		DonThuc ** tmpArr = new DonThuc *[tmpSize];
		for (unsigned int i = 0; i < tmpSize; i++) {
			tmpArr[i] = new DonThuc(0, i);
		}
		tmpArr[tmpSize-1]->setHs(don->getHs());
		for (unsigned int i = 0; i < this->size; i++) {
			tmpArr[i]->setHs(this->arr[i]->getHs());
		}
		return new DaThuc(tmpArr, tmpSize);
	}
}

DaThuc * DaThuc::cong(DaThuc * da)
{
	if (da == NULL) {
		unsigned int tmpSize = this->size;
		DonThuc ** tmpArr = new DonThuc *[tmpSize];
		for (unsigned int i = 0; i < tmpSize; i++) {
			tmpArr[i] = new DonThuc(this->arr[i]);
		}
		return new DaThuc(tmpArr, this->size);
	}
	DaThuc *tmp = this->cong(da->arr[da->size-1]);
	for (unsigned int i = 0; i < da->size-1; i++) {
		DaThuc * tmp1 = tmp->cong(da->arr[i]);
		delete tmp;
		tmp = tmp1;
	}
	return tmp;
}

DaThuc * DaThuc::tru(DonThuc * don)
{
	if (don == NULL)
		return this->createCopy();
	DonThuc *don1 = don->nhan(-1);
	DaThuc *temp = this->cong(don1);
	delete don1;
	return temp;
}

DaThuc * DaThuc::tru(DaThuc * da)
{
	DaThuc *da1 = da->createCopy();
	//da1->writeline();
	DaThuc *da2 = da1->nhan(-1);
	//da2->writeline();
	DaThuc *da3 = this->cong(da2);
	//da3->writeline();
	da3->chuanHoa();
	//da3->writeline();
	delete da1;
	delete da2;
	return da3;
}

DaThuc * DaThuc::chia(DonThuc * don)
{
	if (don == NULL)
		return NULL;
	if (don->getHs() == 0)
		return NULL;
	if (this->getDonThucMax()->getSm() < don->getSm())
		return new DaThuc(new DonThuc(0, 0));
	unsigned int tmpSize = 1 + this->getDonThucMax()->getSm() - don->getSm();
	DonThuc ** tmpArr = new DonThuc *[tmpSize];
	for (unsigned int i = 0; i < tmpSize; i++) {
		tmpArr[i] = this->arr[i + don->getSm()]->chia(don);
	}
	return new DaThuc(tmpArr,tmpSize);
}

DaThuc * DaThuc::chia(DaThuc * da)
{
	if (da == NULL)
		return NULL;
	da->chuanHoa();
	if (da->getDonThucMax()->getHs() == 0)
		return NULL;
	this->chuanHoa();
	if (this->getDonThucMax()->getHs() == 0)
		return new DaThuc(new DonThuc(0, 0));
	if(this->getDonThucMax()->getSm() < da->getDonThucMax()->getSm())
		return new DaThuc(new DonThuc(0, 0));
	unsigned int tmpSize = 1 + this->getDonThucMax()->getSm() - da->getDonThucMax()->getSm();
	DonThuc ** tmpArr = new DonThuc *[tmpSize];
	for (unsigned int i = 0; i< tmpSize; i++) {
		tmpArr[i] = new DonThuc(0, i);
	}
	DaThuc * da1 = this->createCopy();
	while (da1->getDonThucMax()->getSm() >= da->getDonThucMax()->getSm()) {
		//da1->writeline();
		DonThuc * don1 = da1->getDonThucMax()->chia(da->getDonThucMax());
		//don1->writeline();
		tmpArr[don1->getSm()]->setHs(don1->getHs());
		//tmpArr[don1->getSm()]->writeline();
		DaThuc *da2 = da->nhan(tmpArr[don1->getSm()]);
		//da2->writeline();
		DaThuc *da3 = da1->tru(da2);
		//da3->writeline();

		delete don1;
		delete da1;
		delete da2;
		da1 = da3;
	}
	if(da1 != NULL)
		delete da1;

	return new DaThuc(tmpArr, tmpSize);
}

DaThuc * DaThuc::phanDu(DaThuc * da)
{
	DaThuc * tmp = this->chia(da);
	DaThuc * tmp1 = da->nhan(tmp);
	DaThuc * tmp2 = this->tru(tmp1);
	delete tmp;
	delete tmp1;
	return tmp2;
}

DaThuc * DaThuc::createCopy()
{
	this->chuanHoa();
	DonThuc ** tmpArr = new DonThuc*[this->size];
	for (unsigned int i = 0; i < this->size; i++)
		tmpArr[i] = new DonThuc(this->arr[i]->getHs(), this->arr[i]->getSm());
	return new DaThuc(tmpArr,this->size);
}

DaThuc::DaThuc()
{
	this->size = 1;
	arr = new DonThuc*[this->size];
	arr[0] = new DonThuc();
}

DaThuc::DaThuc(DonThuc * don)
{
	if (don == NULL) {
		this->size = 1;
		arr = new DonThuc*[this->size];
		arr[0] = new DonThuc();
	}
	else {
		this->size = don->getSm() + 1;
		this->arr = new DonThuc*[this->size];
		for (unsigned int i = 0; i < this->size; i++)
			arr[i] = new DonThuc(0, i);
		this->arr[don->getSm()]->setHs(don->getHs());
	}
}

DaThuc::DaThuc(unsigned int SoMuMax)
{
	this->size = SoMuMax + 1;
	arr = new DonThuc*[this->size];
	for (unsigned int i= 0; i < this->size; i++ )
		arr[i] = new DonThuc(1, i);
}

DaThuc::DaThuc(DonThuc ** arr, unsigned int size)
{
	this->arr = arr;
	this->size = size;
}

void DaThuc::write(char x)
{
	for (unsigned int i = 0; i < this->size; i++) {
		printf("%0.1f%c%d", this->arr[i]->getHs(), x, this->arr[i]->getSm());
	}
}

void DaThuc::writeline(char x)
{
	for (unsigned int i = 0; i < this->size; i++) {
		printf("%0.1f%c%d ", this->arr[i]->getHs(), x, this->arr[i]->getSm());
	}
	printf("\n");
}

void DaThuc::chuanHoa()
{
	int i = this->size - 1;
	while (i >= 0) {
		if (this->arr[i]->getHs() != 0) {
			break;
		}
		i = i - 1;
	}
	if (i == this->size - 1)
		return;
	if (i < 0) {
		for (unsigned int j = 0; j < this->size; j++) {
			if (this->arr[j] != NULL)
				delete arr[j];
		}
		delete[]arr;
		this->size = 1;
		arr = new DonThuc*[this->size];
		arr[0] = new DonThuc();
		return;
	}
	unsigned int tempSize = i + 1;
	DonThuc ** tmpArr = new DonThuc *[tempSize];
	for (unsigned int j = 0; j < tempSize; j++) {
		if (this->arr[j] != NULL)
			tmpArr[j] = new DonThuc(arr[j]);
		else
			tmpArr[j] = new DonThuc(0, j);
	}
	for (unsigned int j = 0; j < this->size; j++) {
		if (this->arr[j] != NULL)
			delete arr[j];
	}
	delete[]arr;
	this->size = tempSize;
	arr = tmpArr;
}

DonThuc * DaThuc::getDonThucMax()
{
	this->chuanHoa();
	return this->arr[this->size - 1];
}

int DaThuc::isEqual(DaThuc * da)
{
	if (da == NULL)
		return 0;
	if (this->size == da->size) {
		unsigned int i = 0;
		for (i = 0; i < this->size; i++) {
			if (this->arr[i]->isEqual(da->arr[i]) == 0)
				break;
		}
		if (i >= this->size)
			return 1;
	}
	return 0;
}


DaThuc::~DaThuc()
{
	if (arr == NULL)
		return;
	for (unsigned int i = 0; i < this->size; i++) {
		if(arr[i]!=NULL)
			delete arr[i];
	}
	delete[]arr;
	arr = NULL;
}

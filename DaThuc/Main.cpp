// DaThuc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include "DonThuc.h"
#include "DaThuc.h"
int main()
{
	DaThuc *da1 = new DaThuc(4);
	DaThuc *da2 = new DaThuc(3);
	printf("da1: "); da1->writeline();
	printf("da2: "); da2->writeline();
	DaThuc *da3 = da1->chia(da2);
	printf("da3:=da1/da2: "); da3->writeline();
	DaThuc *da4 = da2->chia(da1);
	printf("da4:=da2/da1: "); da4->writeline();
	DaThuc *da5 = da1->nhan(da2);
	printf("da5:=da1*da2: "); da5->writeline();
	DaThuc *da6 = da5->chia(da1);
	printf("da6:=da5/da1=da2: "); da6->writeline();
	int flag = da6->isEqual(da2);
	printf("da6:=da2?: %d", flag);

	//DonThuc * don = new DonThuc(1, 6);
	//don->writeline('X');
	//DaThuc *da = new DaThuc(4);
	//da->writeline('X');
	//DaThuc *da1 = da->nhan(don);
	//da1->writeline('X');
	//DaThuc *da2 = da->cong(don);
	//da2->writeline('X');
	//DaThuc *da3 = da1->cong(da2);
	//da3->writeline('X');
	//DaThuc *da4 = da2->nhan(da3);
	//da4->writeline('X');

	//DonThuc *don1 = new DonThuc(2.5, 3);
	//don1->writeline();
	//DaThuc *da5 = da4->chia(don1);
	//da5->writeline();

	//DaThuc *da6 = new DaThuc(3);
	//da6->writeline();
	//DonThuc *don3 = new DonThuc(2, 2);
	//don3->writeline();
	//DaThuc *da7 = da4->chia(da6);
	//da7->writeline();
	//DaThuc *da8 = da4->phanDu(da6);
	//da8->writeline();
	////retest
	//printf("\nRetest\n");
	//DaThuc * da9 = da7->nhan(da6);
	//da9->writeline();
	//DaThuc * da10 = da9->cong(da8);
	//da10->writeline();
	//DaThuc *da11 = da10->tru(da4);
	//da11->writeline();
	
	//delete don;
	//delete da;
	//delete da1;
	getchar();
    return 0;
}


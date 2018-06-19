﻿#include <iostream>
#include <cstdlib>//产生随机数用    rand()
#include <ctime>//产生随机数用  ，可以产生一个种子。
#include <conio.h>//getch使用的库
#include <cmath>
#include <iomanip>//setw()函数使用的库
//#include <windows.h>//

#include "moeneko.h"//函数声明

using namespace std;



/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：游戏步骤（左）   int left(int (*a)[4])
.					作用：计算向左运行的结果，并重新排序
.					输入值：1.需要计算的4*4的数组
.					类型：int
.					返回值：需要相加的分数。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
int left(int(*a)[4]) {
	int x = 0, y = 0;
	int m = 0, n = 0;
	int i = 0, j = 0, k = 0;
	int add_score = 0;
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			if (a[y][x] != 0) {
				for (i = 1; i <= 3 - x; i++) {
					if (a[y][x] == a[y][x + i]) {
						if (i == 1) {
							a[y][x] = a[y][x] * 2;
							a[y][x + i] = 0;
							add_score += a[y][x];
						}
						else if (i == 2) {
							if (a[y][x + 1] == 0) {
								a[y][x] = a[y][x] * 2;
								a[y][x + i] = 0;
								add_score += a[y][x];
							}
						}
						else {
							if (a[y][x + 1] == 0 && a[y][x + 2] == 0) {
								a[y][x] = a[y][x] * 2;
								a[y][x + i] = 0;
								add_score += a[y][x];
							}
						}
						i = 999;//防止多次运算，
						x = x + 1;//防止多次运算，
					}
				}
			}
		}
	}
	for (k = 0; k < 3; k++) {
		for (y = 0; y <= 3; y++) {
			for (x = 0; x <= 3; x++) {
				if (a[y][x] == 0 && a[y][x + 1] != 0 && x + 1 <= 3) {
					a[y][x] = a[y][x + 1];
					a[y][x + 1] = 0;
				}
			}
		}
	}
	return add_score;
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：游戏步骤（上）   int up(int (*a)[4])
.					作用：计算向上运行的结果，并重新排序
.					输入值：1.需要计算的4*4的数组
.					类型：int
.					返回值：需要相加的分数。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
int up(int(*a)[4]) {
	int add_score_temp = 0;
	xtoy(a);
	add_score_temp = left(a);
	xtoy(a);
	return add_score_temp;
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：游戏步骤（右）   int rigut(int (*a)[4])
.					作用：计算向右运行的结果，并重新排序
.					输入值：1.需要计算的4*4的数组
.					类型：int
.					返回值：需要相加的分数。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
int right(int(*a)[4]) {
	int add_score_temp = 0;
	xtox(a);
	add_score_temp = left(a);
	xtox(a);
	return add_score_temp;
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：游戏步骤（下）   int down(int (*a)[4])
.					作用：计算向下运行的结果，并重新排序
.					输入值：1.需要计算的4*4的数组
.					类型：int
.					返回值：需要相加的分数。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
int down(int(*a)[4]) {
	int add_score_temp = 0;
	ytoy(a);
	xtoy(a);
	add_score_temp = left(a);
	xtoy(a);
	ytoy(a);
	return add_score_temp;
}

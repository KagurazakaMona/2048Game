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

.			函数	名称：游戏步骤（左）   void left(int (*a)[4])
.					作用：计算向左运行的结果，并重新排序
.					输入值：1.需要计算的4*4的数组
.					类型：void
.					返回值：无。备注：会直接修改主函数里的数组。（主要函数，绝对正确，勿修改）

*//////////////////////////////////////////////////////////////////////////////
void left(int(*a)[4]) {
	int x = 0, y = 0;
	int m = 0, n = 0;
	int i = 0, j = 0, k = 0;
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			if (a[y][x] != 0) {
				for (i = 1; i <= 3 - x; i++) {
					if (a[y][x] == a[y][x + i]) {
						if (i == 1) {
							a[y][x] = a[y][x] * 2;
							a[y][x + i] = 0;
							i = 999;//防止多次运算，
							x = x + 1;//防止多次运算，
						}
						else if (i == 2) {
							if (a[y][x + 1] == 0) {
								a[y][x] = a[y][x] * 2;
								a[y][x + i] = 0;
								i = 999;//防止多次运算，
								x = x + 1;//防止多次运算，
							}
						}
						else {
							if (a[y][x + 1] == 0 && a[y][x + 2] == 0) {
								a[y][x] = a[y][x] * 2;
								a[y][x + i] = 0;
								i = 999;//防止多次运算，
								x = x + 1;//防止多次运算，
							}
						}
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
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：游戏步骤（上）   void up(int (*a)[4])
.					作用：计算向上运行的结果，并重新排序
.					输入值：1.需要计算的4*4的数组
.					类型：void
.					返回值：无。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
void up(int(*a)[4]) {
	xtoy(a);
	left(a);
	xtoy(a);
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：游戏步骤（右）   void rigut(int (*a)[4])
.					作用：计算向右运行的结果，并重新排序
.					输入值：1.需要计算的4*4的数组
.					类型：void
.					返回值：无。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
void right(int(*a)[4]) {
	xtox(a);
	left(a);
	xtox(a);
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：游戏步骤（下）   void down(int (*a)[4])
.					作用：计算向下运行的结果，并重新排序
.					输入值：1.需要计算的4*4的数组
.					类型：void
.					返回值：无。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
void down(int(*a)[4]) {
	ytoy(a);
	xtoy(a);
	left(a);
	xtoy(a);
	ytoy(a);
}

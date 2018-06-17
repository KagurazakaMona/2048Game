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

.			函数	名称：纵横变换   void xtoy(int (*a)[4])
.					作用：将数组由纵向变为横向，颠倒位置
.					输入值：1.需要计算的4*4的数组
.					类型：void
.					返回值：无。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
void xtoy(int(*a)[4]) {
	int x = 0, y = 0;
	int temp[4][4];
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			temp[x][y] = a[y][x];
		}
	}
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			a[y][x] = temp[y][x];
		}
	}
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：横向变换   void xtox(int (*a)[4])
.					作用：将数组横向颠倒位置
.					输入值：1.需要计算的4*4的数组
.					类型：void
.					返回值：无。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
void xtox(int(*a)[4]) {
	int x = 0, y = 0;
	int temp[4][4];
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			temp[y][3 - x] = a[y][x];
		}
	}
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			a[y][x] = temp[y][x];
		}
	}
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：纵向变换   void ytoy(int (*a)[4])
.					作用：将数组纵向颠倒位置
.					输入值：1.需要计算的4*4的数组
.					类型：void
.					返回值：无。备注：会直接修改主函数里的数组。

*//////////////////////////////////////////////////////////////////////////////
void ytoy(int(*a)[4]) {
	int x = 0, y = 0;
	int temp[4][4];
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			temp[3 - y][x] = a[y][x];
		}
	}
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			a[y][x] = temp[y][x];
		}
	}
}

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

.			函数	名称：游戏失败判断器（横向）   bool gameoverleft(int(*a)[4])
.					作用：从横向的角度判断游戏是否结束
.					输入值：1.需要判断的4*4的数组
.					类型：bool
.					返回值：  0 = fause（游戏可以继续）     或      1 = ture（游戏失败）。

*//////////////////////////////////////////////////////////////////////////////
bool gameoverleft(int(*a)[4]) {
	int x = 0, y = 0, m = 1;//假设游戏结束，假设游戏没有空位了。
	int x1 = 0, y1 = 0;
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			if (a[y][x] == 0) {//判断还有没有空位了
				m--;
				return 0;//如果还有空位，则游戏可以继续运行
			}
		}
	}
	if (m == 1) {//如果没有空位，则进行下一步的判断
		for (y1 = 0; y1 < 3; y1++) {
			for (x1 = 0; x1 < 3; x1++) {
				if (a[y1][x1] == a[y1][x1 + 1]) {
					cout << "横向判断为0,false,游戏可以继续" << endl;
					return 0;//游戏还可以进行下去
				}
			}
		}
	}
	return 1;
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：游戏失败判断器（纵向）   bool gameoverup(int(*a)[4])
.					作用：从纵向的角度判断游戏是否结束
.					输入值：1.需要判断的4*4的数组
.					类型：bool
.					返回值：  0（游戏可以继续）     或      1（游戏失败）。

*//////////////////////////////////////////////////////////////////////////////
bool gameoverup(int(*a)[4]) {
	//xtoy(a);
	int x = 0, y = 0, m = 1;//假设游戏结束，假设游戏没有空位了。
	int x1 = 0, y1 = 0;
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			if (a[y][x] == 0) {//判断还有没有空位了
				m--;
				//xtoy(a);
				return 0;//如果还有空位，则游戏可以继续运行
			}
		}
	}
	if (m == 1) {//如果没有空位，则进行下一步的判断
		for (y1 = 0; y1 < 3; y1++) {
			for (x1 = 0; x1 < 3; x1++) {
				if (a[y1][x1] == a[y1 + 1][x1]) {
					//xtoy(a);
					cout << "纵向判断为0,false,游戏可以继续" << endl;
					return 0;//游戏还可以进行下去
				}
			}
		}
	}
	//xtoy(a);
	return 1;
}

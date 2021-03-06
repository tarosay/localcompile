/*******************************************************************************
* GR-SAKURA LIBRARY LICENSE.  LIMITATION and DISCLAIMER of WARRANTY
*
* This software is supplied by Tokushu Denshi Kairo Inc. and is only intended 
* for use with Gadget Renesas projects. No other uses are authorized.
* This software is owned by Tokuden and is protected under all applicable laws,
* including copyright laws. Disclosure or redistribution to others this headder
* file and related library file alone is not allowed.
* You can redistribute the executable object file (only SREC or BIN file) which
* is generated as a result of compilation and link your program.
* Of cource the limitation of this library license does not effect to your code.
* THIS SOFTWARE IS PROVIDED "AS IS" AND TOKUDEN MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* Tokuden reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* http://rx.tokudenkairo.co.jp/
* (C) Copyright 2011-2012 Tokushu Denshi Kairo Inc.
*******************************************************************************/

#ifndef WIRING_H_
#define WIRING_H_
/**************************************************************************//**
 * @file    wiring.h
 * @brief   算術演算、数学演算、論理演算など細かなルーチン
 ******************************************************************************/
#define PI          3.1415926535
#define HALF_PI     1.5707963267
#define TWO_PI      6.2831853071
#define DEG_TO_RAD  0.0174532925
#define RAD_TO_DEG 57.295779513
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif




/*********************************************************************//**
 * @brief		指定したビットを論理1(high)にする
 * @param[in]	b ビット番号
 *
 * @return		unsigned long
 **********************************************************************/
//inline unsigned long bit(unsigned long b);
#define bit(b) (1UL << (b))

/*********************************************************************//**
 * @brief		変数の下位1バイトを取り出す
 * @param[in]	w 変数(int)
 *
 * @return		unsigned char
 **********************************************************************/
//inline unsigned char lowByte(unsigned long w);
#define lowByte(w) ((uint8_t) ((w) & 0xff))

/*********************************************************************//**
 * @brief		変数の上位1バイトを取り出す.(2バイトより大きな型に対しては,下位から2番目の変数を取り出す)
 * @param[in]	w 変数(int)
 *
 * @return		unsigned char
 **********************************************************************/
//inline unsigned char highByte(unsigned long w);
#define highByte(w) ((uint8_t) ((w) >> 8))

/*********************************************************************//**
 * @brief		変数から指定したビットを読み取る.
 * @param[in]	value 読み取る対象となる変数(unsigned long)
 * @param[in]	bit 読み取るビットの位置．右端から数えて何ビット目か(int)
 *
 * @return		0 または1
 **********************************************************************/
//inline unsigned long bitRead(unsigned long value, int bit);
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

/*********************************************************************//**
 * @brief		変数から指定したビットをセットする.
 * @param[in]	value 対象となる変数(unsigned long)
 * @param[in]	bit セットするビットの位置．右端から数えて何ビット目か(int)
 *
 * @return		なし
 **********************************************************************/
//inline void bitSet(unsigned long value, int bit);
#define bitSet(value, bit) ((value) |= (1UL << (bit)))

/*********************************************************************//**
 * @brief		変数から指定したビットをクリアする.
 * @param[in]	value 対象となる変数(unsigned long)
 * @param[in]	bit クリアするビットの位置．右端から数えて何ビット目か(int)
 *
 * @return		なし
 **********************************************************************/
//inline void bitClear(unsigned long value, int bit);
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))

/*********************************************************************//**
 * @brief		変数から指定したビットをセットする.
 * @param[in]	value 対象となる変数(unsigned long)
 * @param[in]	bit セットするビットの位置．右端から数えて何ビット目か(int)
 * @param[in]	bitvalue セットする値 0か1
 * @return		なし
 **********************************************************************/
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
//inline void bitWrite(unsigned long value, int bit, int bitvalue);

/*********************************************************************//**
 * @brief		2つの数値のうち小さいほうの値を返す
 * @param[in]	a 1つ目の値
 * @param[in]	b 2つ目の値
 *
 * @return		小さいほうの数値(int)
 **********************************************************************/
#define min(a,b) ((a)<(b)?(a):(b))

/*********************************************************************//**
 * @brief		2つの数値のうち大きいほうの値を返す
 * @param[in]	a 1つ目の値
 * @param[in]	b 2つ目の値
 *
 * @return		大きい方の数値(int)
 **********************************************************************/
#define max(a,b) ((a)>(b)?(a):(b))

/*********************************************************************//**
 * @brief		絶対値を計算する
 * @param[in]	x 数値
 *
 * @return		xが0以上のときはxをそのまま返し,xが0より小さいときは-xを返す(int)
 **********************************************************************/
//inline int abs(int x);
#define abs(x) ((x)>0?(x):-(x))

/*********************************************************************//**
 * @brief		数値を指定した範囲の中に収める
 * @param[in]	amt 計算対象の値
 * @param[in]	low 範囲の下限
 * @param[in]	high 範囲の上限
 *
 * @return		amtがlow以上のhigh以下のときはamtをそのまま返し,amtがlowより小さいときはlowを,
 * 				amtがhighより大きいときはhighを返す(int)
 **********************************************************************/
//inline int constrain(int amt, int low, int high);
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

/*********************************************************************//**
 * @brief		指定された浮動小数点数を最も近い整数値に丸める
 * @param[in]	x 計算対象の値
 *
 * @return		long(戻り値の定義に注意)
 * @warning		この関数は実装されていません
 **********************************************************************/
//inline long round(double x);
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

/*********************************************************************//**
 * @brief		指定されたdegree値をradianに変換する
 * @param[in]	deg 計算対象の値
 *
 * @return		double
 **********************************************************************/
//inline double radians(double deg);
#define radians(deg) ((deg)*DEG_TO_RAD)

/*********************************************************************//**
 * @brief		指定されたradian値をdegreeに変換する
 * @param[in]	rad 計算対象の値
 *
 * @return		計算結果
 **********************************************************************/
//inline double degrees(double rad);
#define degrees(rad) ((rad)*RAD_TO_DEG)

/*********************************************************************//**
 * @brief		指定された値の2乗を求める
 * @param[in]	x 計算対象の値
 *
 * @return		計算結果
 **********************************************************************/
//inline int sq(int x);
#define sq(x) ((x)*(x))

/*********************************************************************//**
 * @brief		指定された値の常用対数を求める
 * @param[in]	x 計算対象の値
 *
 * @return		計算結果
 **********************************************************************/
#define log10(x) (log(x)/log(10))


/*********************************************************************//**
 * @brief		数値をある範囲から別の範囲に変換する.
 * 				in_minと同じ値を与えると,out_minが返り,in_maxと同じ値ならout_highとなります.
 * 				その中間の値は,2つの範囲の大きさの比に基づいて計算されます.
 * 				そのほうが便利な場合があるので,この関数は範囲外の値も切り捨てません.
 * 				ある範囲のなかに収めたい場合は,constrain関数と併用してください.
 * @param[in]	x 変換したい値
 * @param[in]	in_min		現在の範囲の下限
 * @param[in]	in_max		現在の範囲の上限
 * @param[in]	out_min		変換後の範囲の下限
 * @param[in]	out_max		変換後の範囲の上限
 *
 * @return		変換後の数値 (long)
 **********************************************************************/
#define map(x,in_min,in_max,out_min,out_max) \
(((x) - (in_min)) * ((out_max) - (out_min)) / ((in_max) - (in_min)) + (out_min))

// 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
// 以下の関数,マクロはwiring.hに定義されているものであるが,ここではコメントアウトしている
/*
#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define INTERNAL1V1 2
#define INTERNAL2V56 3
#else
#define INTERNAL 3
#endif
#define DEFAULT 1
#define EXTERNAL 0

#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() sei()
#define noInterrupts() cli()

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( ((a) * 1000L) / (F_CPU / 1000L) )
#define microsecondsToClockCycles(a) ( ((a) * (F_CPU / 1000L)) / 1000L )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#define bit(b) (1UL << (b))

typedef unsigned int word;
*/

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef __cplusplus
	}
#endif

#endif /* WIRING_H_ */

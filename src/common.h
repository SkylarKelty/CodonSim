#ifndef COMMON_H
#define COMMON_H 1

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * Shortcut for getting value from /dev/random
 */
inline static int frandom() {
	int data = open("/dev/random", O_RDONLY);
	int result = 0;
	read(data, &result, sizeof result);
	close(data);
	return result;
}

/**
 * Shortcut for min,max rand
 */
inline static int simRand(int min, int max) {
	return (rand() % ((max - min) + 1)) + min;
}

const char *dAAToS(int aa);
int dSToAA(const char *aa);
int dSToCodon(const char *codon);
const char *dCodonToS(int val);

// AA numerical representation
#define ILE 0
#define LEU 1
#define VAL 2
#define PHE 3
#define MET 4
#define CYS 5 
#define ALA 6
#define GLY 7
#define PRO 8
#define THR 9
#define SER 10
#define TYR 11
#define TRP 12
#define GLN 13
#define ASN 14
#define HIS 15
#define GLU 16
#define ASP 17
#define LYS 18
#define ARG 19
#define STOP 20

// Codon's numerical representation
#define NOCODON 0
#define AAA 1
#define AAC 2
#define AAG 3
#define AAU 4
#define ACA 5
#define ACC 6
#define ACG 7
#define ACU 8
#define AGA 9
#define AGC 10
#define AGG 11
#define AGU 12
#define AUA 13
#define AUC 14
#define AUG 15
#define AUU 16
#define CAA 17
#define CAC 18
#define CAG 19
#define CAU 20
#define CCA 21
#define CCC 22
#define CCG 23
#define CCU 24
#define CGA 25
#define CGC 26
#define CGG 27
#define CGU 28
#define CUA 29
#define CUC 30
#define CUG 31
#define CUU 32
#define GAA 33
#define GAC 34
#define GAG 35
#define GAU 36
#define GCA 37
#define GCC 38
#define GCG 39
#define GCU 40
#define GGA 41
#define GGC 42
#define GGG 43
#define GGU 44
#define GUA 45
#define GUC 46
#define GUG 47
#define GUU 48
#define UAA 49
#define UAC 50
#define UAG 51
#define UAU 52
#define UCA 53
#define UCC 54
#define UCG 55
#define UCU 56
#define UGA 57
#define UGC 58
#define UGG 59
#define UGU 60
#define UUA 61
#define UUC 62
#define UUG 63
#define UUU 64

// http://www.endmemo.com/bio/codon.php
const int codonMap[21][6] = {
	{AUU, AUC, AUA, NOCODON, NOCODON, NOCODON},
	{CUU, CUC, CUA, CUG, UUA, UUG},
	{GUU, GUC, GUA, GUG, NOCODON, NOCODON},
	{UUU, UUC, NOCODON, NOCODON, NOCODON, NOCODON},
	{AUG, NOCODON, NOCODON, NOCODON, NOCODON, NOCODON},
	{UGU, UGC, NOCODON, NOCODON, NOCODON, NOCODON},
	{GCU, GCC, GCA, GCG, NOCODON, NOCODON},
	{GGU, GGC, GGA, GGG, NOCODON, NOCODON},
	{CCU, CCC, CCA, CCG, NOCODON, NOCODON},
	{ACU, ACC, ACA, ACG, NOCODON, NOCODON},
	{UCU, UCC, UCA, UCG, AGU, AGC},
	{UAU, UAC, NOCODON, NOCODON, NOCODON, NOCODON},
	{UGG, NOCODON, NOCODON, NOCODON, NOCODON, NOCODON},
	{CAA, CAG, NOCODON, NOCODON, NOCODON, NOCODON},
	{AAU, AAC, NOCODON, NOCODON, NOCODON, NOCODON},
	{CAU, CAC, NOCODON, NOCODON, NOCODON, NOCODON},
	{GAA, GAG, NOCODON, NOCODON, NOCODON, NOCODON},
	{GAU, GAC, NOCODON, NOCODON, NOCODON, NOCODON},
	{AAA, AAG, NOCODON, NOCODON, NOCODON, NOCODON},
	{CGU, CGC, CGA, CGG, AGA, AGG},
	{UAA, UAG, UGA, NOCODON, NOCODON, NOCODON}
};

const int cognateMap[65][2] = {
	{0, 0},
	{23, 0},
	{7, 0},
	{24, 0},
	{7, 0},
	{34, 0},
	{35, 0},
	{36, 0},
	{35, 0},
	{3, 0},
	{30, 0},
	{4, 5},
	{30, 0},
	{17, 0},
	{18, 0},
	{25, 0},
	{18, 0},
	{10, 0},
	{16, 0},
	{11, 0},
	{16, 0},
	{29, 0},
	{28, 0},
	{29, 0},
	{28, 0},
	{6, 0},
	{6, 0},
	{5, 0},
	{6, 0},
	{19, 0},
	{20, 0},
	{19, 0},
	{19, 0},
	{12, 0},
	{8, 0},
	{43, 0},
	{8, 0},
	{1, 0},
	{2, 0},
	{1, 0},
	{2, 0},
	{13, 0},
	{15, 0},
	{14, 0},
	{15, 0},
	{39, 0},
	{40, 0},
	{41, 0},
	{40, 0},
	{42, 0},
	{38, 0},
	{42, 0},
	{38, 0},
	{31, 0},
	{32, 0},
	{33, 0},
	{32, 0},
	{42, 0},
	{9, 0},
	{37, 0},
	{9, 0},
	{21, 0},
	{27, 0},
	{22, 0},
	{27, 0}
};

const int nearCognateMap[65][6] = {
	{},
	{44},
	{38, 23},
	{23, 43},
	{23, 38, 43},
	{31, 32, 35},
	{32, 33, 34},
	{34},
	{32, 34},
	{},
	{3, 9},
	{3, 37},
	{3, 9},
	{18, 21},
	{17, 27},
	{17, 22},
	{17, 27},
	{7},
	{7, 10, 38},
	{10, 24},
	{7, 10 },
	{24, 28 , 31, 32, 34},
	{29, 32, 35},
	{28, 33, 36},
	{29, 32, 35},
	{3},
	{9, 30},
	{4, 37},
	{9, 30},
	{17, 18, 21},
	{18, 19, 27},
	{22, 25},
	{18, 20, 27},
	{23, 43},
	{7, 12, 38},
	{12, 24},
	{7, 12, 38, 43},
	{2, 31, 32, 34, 35},
	{1, 34, 45},
	{33, 36},
	{1, 34, 45},
	{3},
	{9, 13, 30},
	{4, 13, 37},
	{9, 13, 30},
	{17, 18, 21, 40},
	{18, 27},
	{22, 25},
	{18, 27},
	{10, 23, 43},
	{7, 10, 16},
	{10, 11, 23, 24, 43},
	{7, 10, 16, 43},
	{1, 28, 29, 32, 34, 35},
	{28, 31, 35},
	{1, 28, 29, 31, 34, 36},
	{28, 31, 35},
	{3, 6},
	{6, 30},
	{4, 5, 42},
	{6, 30},
	{17, 18, 19},
	{18, 19, 20, 21},
	{19, 21, 25},
	{18, 19, 20, 21}
};

#endif

#include "common.h"

/**
 * Converts a defined Amino Acid to string form (for output)
 * 
 * @param  aa Defined Amino Acid
 * @return string String representation (e.g. Lys)
 */
const char *dAAToS(int aa) {
	switch (aa) {
		case ILE:
			return "ILE";
		case LEU:
			return "LEU";
		case VAL:
			return "VAL";
		case PHE:
			return "PHE";
		case MET:
			return "MET";
		case CYS:
			return "CYS"; 
		case ALA:
			return "ALA";
		case GLY:
			return "GLY";
		case PRO:
			return "PRO";
		case THR:
			return "THR";
		case SER:
			return "SER";
		case TYR:
			return "TYR";
		case TRP:
			return "TRP";
		case GLN:
			return "GLN";
		case ASN:
			return "ASN";
		case HIS:
			return "HIS";
		case GLU:
			return "GLU";
		case ASP:
			return "ASP";
		case LYS:
			return "LYS";
		case ARG:
			return "ARG";
		case STOP:
			return "STOP";
		default:
			return "None";
	}
}

/**
 * Converts a string representing an Amino Acid to int form (for processing)
 * 
 * @param  aa String representation of Amino Acid
 * @return int Integer representation (e.g. 1)
 */
int dSToAA(const char *aa) {
	if (strcmp(aa, "ILE") == 0)
		return ILE;
	if (strcmp(aa, "LEU") == 0)
		return LEU;
	if (strcmp(aa, "VAL") == 0)
		return VAL;
	if (strcmp(aa, "PHE") == 0)
		return PHE;
	if (strcmp(aa, "MET") == 0)
		return MET;
	if (strcmp(aa, "CYS") == 0)
		return CYS; 
	if (strcmp(aa, "ALA") == 0)
		return ALA;
	if (strcmp(aa, "GLY") == 0)
		return GLY;
	if (strcmp(aa, "PRO") == 0)
		return PRO;
	if (strcmp(aa, "THR") == 0)
		return THR;
	if (strcmp(aa, "SER") == 0)
		return SER;
	if (strcmp(aa, "TYR") == 0)
		return TYR;
	if (strcmp(aa, "TRP") == 0)
		return TRP;
	if (strcmp(aa, "GLN") == 0)
		return GLN;
	if (strcmp(aa, "ASN") == 0)
		return ASN;
	if (strcmp(aa, "HIS") == 0)
		return HIS;
	if (strcmp(aa, "GLU") == 0)
		return GLU;
	if (strcmp(aa, "ASP") == 0)
		return ASP;
	if (strcmp(aa, "LYS") == 0)
		return LYS;
	if (strcmp(aa, "ARG") == 0)
		return ARG;
	return STOP;
}

/**
 * Given a string, return the int variable
 * 
 * @param  codon  string of the codon
 * @return int int of the codon
 */
int dSToCodon(const char *codon) {
	if (strcmp(codon, "UUU") == 0)
		return UUU;
	if (strcmp(codon, "UUC") == 0)
		return UUC;
	if (strcmp(codon, "UUA") == 0)
		return UUA;
	if (strcmp(codon, "UUG") == 0)
		return UUG;
	if (strcmp(codon, "CUU") == 0)
		return CUU;
	if (strcmp(codon, "CUC") == 0)
		return CUC;
	if (strcmp(codon, "CUA") == 0)
		return CUA;
	if (strcmp(codon, "CUG") == 0)
		return CUG;
	if (strcmp(codon, "AUU") == 0)
		return AUU;
	if (strcmp(codon, "AUC") == 0)
		return AUC;
	if (strcmp(codon, "AUA") == 0)
		return AUA;
	if (strcmp(codon, "AUG") == 0)
		return AUG;
	if (strcmp(codon, "GUU") == 0)
		return GUU;
	if (strcmp(codon, "GUC") == 0)
		return GUC;
	if (strcmp(codon, "GUA") == 0)
		return GUA;
	if (strcmp(codon, "GUG") == 0)
		return GUG;
	if (strcmp(codon, "UCU") == 0)
		return UCU;
	if (strcmp(codon, "UCC") == 0)
		return UCC;
	if (strcmp(codon, "UCA") == 0)
		return UCA;
	if (strcmp(codon, "UCG") == 0)
		return UCG;
	if (strcmp(codon, "AGU") == 0)
		return AGU;
	if (strcmp(codon, "AGC") == 0)
		return AGC;
	if (strcmp(codon, "CCU") == 0)
		return CCU;
	if (strcmp(codon, "CCC") == 0)
		return CCC;
	if (strcmp(codon, "CCA") == 0)
		return CCA;
	if (strcmp(codon, "CCG") == 0)
		return CCG;
	if (strcmp(codon, "ACU") == 0)
		return ACU;
	if (strcmp(codon, "ACC") == 0)
		return ACC;
	if (strcmp(codon, "ACA") == 0)
		return ACA;
	if (strcmp(codon, "ACG") == 0)
		return ACG;
	if (strcmp(codon, "GCU") == 0)
		return GCU;
	if (strcmp(codon, "GCC") == 0)
		return GCC;
	if (strcmp(codon, "GCA") == 0)
		return GCA;
	if (strcmp(codon, "GCG") == 0)
		return GCG;
	if (strcmp(codon, "UAU") == 0)
		return UAU;
	if (strcmp(codon, "UAC") == 0)
		return UAC;
	if (strcmp(codon, "CAU") == 0)
		return CAU;
	if (strcmp(codon, "CAC") == 0)
		return CAC;
	if (strcmp(codon, "CAA") == 0)
		return CAA;
	if (strcmp(codon, "CAG") == 0)
		return CAG;
	if (strcmp(codon, "AAU") == 0)
		return AAU;
	if (strcmp(codon, "AAC") == 0)
		return AAC;
	if (strcmp(codon, "AAA") == 0)
		return AAA;
	if (strcmp(codon, "AAG") == 0)
		return AAG;
	if (strcmp(codon, "GAU") == 0)
		return GAU;
	if (strcmp(codon, "GAC") == 0)
		return GAC;
	if (strcmp(codon, "GAA") == 0)
		return GAA;
	if (strcmp(codon, "GAG") == 0)
		return GAG;
	if (strcmp(codon, "UGU") == 0)
		return UGU;
	if (strcmp(codon, "UGC") == 0)
		return UGC;
	if (strcmp(codon, "UGG") == 0)
		return UGG;
	if (strcmp(codon, "CGU") == 0)
		return CGU;
	if (strcmp(codon, "CGC") == 0)
		return CGC;
	if (strcmp(codon, "CGA") == 0)
		return CGA;
	if (strcmp(codon, "CGG") == 0)
		return CGG;
	if (strcmp(codon, "AGA") == 0)
		return AGA;
	if (strcmp(codon, "AGG") == 0)
		return AGG;
	if (strcmp(codon, "GGU") == 0)
		return GGU;
	if (strcmp(codon, "GGC") == 0)
		return GGC;
	if (strcmp(codon, "GGA") == 0)
		return GGA;
	if (strcmp(codon, "GGG") == 0)
		return GGG;
	if (strcmp(codon, "UAA") == 0)
		return UAA;
	if (strcmp(codon, "UAG") == 0)
		return UAG;
	if (strcmp(codon, "UGA") == 0)
		return UGA;
	return NOCODON;
}


/**
 * Given a codon, return the string variable
 * 
 * @param  int int of the codon
 * @return const char* String of codon
 */
const char *dCodonToS(int val) {
	if (val == UUU)
		return "UUU";
	if (val == UUC)
		return "UUC";
	if (val == UUA)
		return "UUA";
	if (val == UUG)
		return "UUG";
	if (val == CUU)
		return "CUU";
	if (val == CUC)
		return "CUC";
	if (val == CUA)
		return "CUA";
	if (val == CUG)
		return "CUG";
	if (val == AUU)
		return "AUU";
	if (val == AUC)
		return "AUC";
	if (val == AUA)
		return "AUA";
	if (val == AUG)
		return "AUG";
	if (val == GUU)
		return "GUU";
	if (val == GUC)
		return "GUC";
	if (val == GUA)
		return "GUA";
	if (val == GUG)
		return "GUG";
	if (val == UCU)
		return "UCU";
	if (val == UCC)
		return "UCC";
	if (val == UCA)
		return "UCA";
	if (val == UCG)
		return "UCG";
	if (val == AGU)
		return "AGU";
	if (val == AGC)
		return "AGC";
	if (val == CCU)
		return "CCU";
	if (val == CCC)
		return "CCC";
	if (val == CCA)
		return "CCA";
	if (val == CCG)
		return "CCG";
	if (val == ACU)
		return "ACU";
	if (val == ACC)
		return "ACC";
	if (val == ACA)
		return "ACA";
	if (val == ACG)
		return "ACG";
	if (val == GCU)
		return "GCU";
	if (val == GCC)
		return "GCC";
	if (val == GCA)
		return "GCA";
	if (val == GCG)
		return "GCG";
	if (val == UAU)
		return "UAU";
	if (val == UAC)
		return "UAC";
	if (val == CAU)
		return "CAU";
	if (val == CAC)
		return "CAC";
	if (val == CAA)
		return "CAA";
	if (val == CAG)
		return "CAG";
	if (val == AAU)
		return "AAU";
	if (val == AAC)
		return "AAC";
	if (val == AAA)
		return "AAA";
	if (val == AAG)
		return "AAG";
	if (val == GAU)
		return "GAU";
	if (val == GAC)
		return "GAC";
	if (val == GAA)
		return "GAA";
	if (val == GAG)
		return "GAG";
	if (val == UGU)
		return "UGU";
	if (val == UGC)
		return "UGC";
	if (val == UGG)
		return "UGG";
	if (val == CGU)
		return "CGU";
	if (val == CGC)
		return "CGC";
	if (val == CGA)
		return "CGA";
	if (val == CGG)
		return "CGG";
	if (val == AGA)
		return "AGA";
	if (val == AGG)
		return "AGG";
	if (val == GGU)
		return "GGU";
	if (val == GGC)
		return "GGC";
	if (val == GGA)
		return "GGA";
	if (val == GGG)
		return "GGG";
	if (val == UAA)
		return "UAA";
	if (val == UAG)
		return "UAG";
	if (val == UGA)
		return "UGA";
	return "NOCODON";
}
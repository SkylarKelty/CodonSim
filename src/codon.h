#ifndef CODON_H
#define CODON_H

#include "common.h"

class Codon {
private:
	int *m_map, *m_trna_map;
	int m_type, m_mapCount, m_cognate, m_nearCognate;

	void setValue(int val);

public:
	Codon(int *trna);
	Codon(int *trna, int t);
	~Codon();

	int toAminoAcid();

	inline int get_type() {
		return m_type;
	}

	inline float get_time() {
		if (m_nearCognate == 0) return 0;
		return (float)m_cognate / (float)m_nearCognate;
	}

	inline float get_time(int cognate, int nearCognate) {
		if (nearCognate == 0) return 0;
		return (float)cognate / (float)nearCognate;
	}

	int countCognate(int codon);
	int countNearCognate(int codon);

	void optimal();
	void suboptimal();

	void mutate();
	void process();

	void set_cognate(int val) { m_cognate = val; }
	void set_nearCognate(int val) { m_nearCognate = val; }

	inline Codon *clone() {
		return new Codon(m_trna_map, m_type);
	}
};

#endif
#ifndef RNA_H
#define RNA_H

#include "common.h"
#include "codon.h"

struct PopulationNode;

struct CodonNode {
	Codon *codon;
	CodonNode *next;

	inline CodonNode *clone() {
		CodonNode *c = new CodonNode();
		c->codon = codon->clone();
		if (next != 0) {
			c->next = next->clone();
		}
		return c;
	}
};

class RNA {
private:
  	CodonNode *m_chain;
	int m_length, m_destroy_trna, m_product;
	int *m_trna;
	float m_time;

	void build();
	void build_trna();
	void destroy_chain();
	void set_chain(CodonNode *chain);

public:
	RNA();
	RNA(int len);
	RNA(int len, int *trna);
	~RNA();
	
  	static int t_product;

	void optimal();
	void suboptimal();

	void mutate();
	void synswch(int chance);

	void process(int chance, PopulationNode *pop);

	float get_time();
	inline float get_production_rate() {
		return 1 / get_time();
	}

	void print();

	inline RNA *clone() {
		RNA *clone = new RNA(0, m_trna);
		clone->set_chain(m_chain->clone());
		return clone;
	}
};

#endif
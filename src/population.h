#ifndef POPULATION_H
#define POPULATION_H

#include "common.h"
#include "rna.h"

struct PopulationNode {
	RNA *rna;
	PopulationNode *next;

	float get_best(float base) {
		float t = rna->get_time();
		if (t > base && base > 0) t = base;

		if (next != 0)
			return next->get_best(t);
		else
			return t;
	}

	float get_worse(float base) {
		float t = rna->get_time();
		if (t < base && base > 0) t = base;

		if (next != 0)
			return next->get_worse(t);
		else
			return t;
	}

	void process(int chance, PopulationNode *pop) {
		rna->process(chance, pop);
		if (next != 0)
			next->process(chance, pop);
	}

	void mutate() {
		rna->mutate();
		if (next != 0)
			next->mutate();
	}

	void kill_random() {
		if (simRand(1, 1000) == 1) {
			if (next != 0) {
				delete next->rna;
				PopulationNode *old = next;
				next = next->next;
				delete old;
			}

			return;
		}

		if (next != 0)
			next->kill_random();
	}

	void add_RNA(RNA *nRNA) {
		if (rna == 0) {
			rna = nRNA;
			return;
		}
		if (next == 0)
			next = new PopulationNode();
		next->add_RNA(nRNA);
	}
};

class Population {
private:
  	PopulationNode *m_pop;
	int m_len, m_product;
	int *m_trna;

	void build();

public:
	Population();
	Population(int len);
	~Population();

	inline int get_product() {
		return m_product;
	}

	// Time
	float get_optimal();
	float get_suboptimal();
	float get_best();
	float get_worse();

	void mutate();
	void process(int chance);

	void print();
};

#endif
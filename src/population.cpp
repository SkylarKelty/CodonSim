
#include "population.h"

/**
 * Create a new population with a random length
 */
Population::Population() {
	m_len = simRand(1, 1000);
	m_product = 0;
	build();
}

/**
 * Create a new population with a given length
 */
Population::Population(int len) {
	m_len = len;
	m_product = 0;
	build();
}

/**
 * Destructor for the population
 */
Population::~Population() {
	// Delete the population
	if (m_pop != 0) {
		PopulationNode *p = m_pop, *n;
		do {
			n = p->next;
			delete p;
			p = n;
		} while (p != 0);
	}

	delete[] m_trna;
}

/**
 * Build the population
 * @internal
 */
void Population::build() {
	// Generate TRNA
	m_trna = new int[45];
	m_trna[0] = 0;
	for (int i = 1; i < 45; i++) {
		m_trna[i] = simRand(20000, 200000);
	}

	RNA *start = new RNA(10);

	m_pop = new PopulationNode();
	for (int i = 0; i < m_len; i++) {
		m_pop->add_RNA((i == 0 ? start : start->clone()));
	}
}

/**
 * Get the optimal time for processing the codon sequence we
 * are starting with
 */
float Population::get_optimal() {
	RNA *rna = m_pop->rna->clone();
	rna->optimal();
	float t = rna->get_time();
	delete rna;
	return t;
}

/**
 * Get the worst time for processing the codon sequence we
 * are starting with
 */
float Population::get_suboptimal() {
	RNA *rna = m_pop->rna->clone();
	rna->suboptimal();
	float t = rna->get_time();
	delete rna;
	return t;
}

/**
 * Get the best time of all the RNA sequences in this population
 */
float Population::get_best() {
	return m_pop->get_best(-1.0f);
}

/**
 * Get the worst time of all the RNA sequences in this population
 */
float Population::get_worse() {
	return m_pop->get_worse(-1.0f);
}

/**
 * Mutate every RNA in the population
 */
void Population::mutate() {
	m_pop->mutate();
}

/**
 * Process every RNA in the population
 */
void Population::process(int chance) {
	m_pop->process(chance, m_pop);
}

/**
 * Print out the population
 */
void Population::print() {

}

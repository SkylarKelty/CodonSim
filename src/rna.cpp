
#include "rna.h"
#include "population.h"

int RNA::t_product = 0;

/**
 * RNA chain of random length
 */
RNA::RNA() {
	m_chain = new CodonNode();
	m_length = simRand(10, 10000);
	m_time = 0.0f;
	m_product = 0;
	build_trna();
	build();
}

/**
 * RNA chain of given length
 */
RNA::RNA(int len) {
	m_chain = new CodonNode();
	m_length = len;
	m_time = 0.0f;
	m_product = 0;
	build_trna();
	build();
}

/**
 * RNA chain of given length with given trna
 */
RNA::RNA(int len, int *trna) {
	m_chain = new CodonNode();
	m_trna = trna;
	m_length = len;
	m_destroy_trna = 0;
	m_time = 0.0f;
	m_product = 0;
	build();
}

/**
 * Destroy the RNA
 */
RNA::~RNA() {
	destroy_chain();

	if (m_destroy_trna == 1)
		delete[] m_trna;
}

/**
 * Build the RNA chain
 */
void RNA::build() {
	// Generate Codons
	CodonNode *c = m_chain;
	for (int i = 0; i < m_length; i++) {
		c->codon = new Codon(m_trna);
		if (i + 1 < m_length) {
			c->next = new CodonNode();
			c = c->next;
		}
	}
}

/**
 * Build a trna map
 */
void RNA::build_trna() {
	m_destroy_trna = 1;

	// Generate TRNA
	m_trna = new int[45];
	m_trna[0] = 0;
	for (int i = 1; i < 45; i++) {
		m_trna[i] = simRand(20000, 200000);
	}
}

/**
 * Destroy the RNA chain
 */
void RNA::destroy_chain() {
	if (m_chain != 0) {
		CodonNode *c = m_chain;
		while (c->next != 0) {
			CodonNode *nc = c->next;
			delete c->codon;
			delete c;
			c = nc;
		}
		delete c->codon;
		delete c;
	}
}

/**
 * Set a new RNA chain
 */
void RNA::set_chain(CodonNode *chain) {
	destroy_chain();
	m_chain = chain;
}

/**
 * Optimize this RNA chain (choose the best codons for the tRNA distribution)
 */
void RNA::optimal() {
	CodonNode *c = m_chain;
	while (c->next != 0) {
		c->codon->optimal();
		c = c->next;
	}
	c->codon->optimal();
}

/**
 * De-Optimize this RNA chain (choose the worst codons for the tRNA distribution)
 */
void RNA::suboptimal() {
	CodonNode *c = m_chain;
	while (c->next != 0) {
		c->codon->suboptimal();
		c = c->next;
	}
	c->codon->suboptimal();
}

/**
 * Mutate every codon in the chain (always mutates everything)
 */
void RNA::mutate() {
	CodonNode *c = m_chain;
	while (c->next != 0) {
		c->codon->mutate();
		c = c->next;
	}
	c->codon->mutate();
}

/**
 * Synonymously switch codons with a given chance
 */
void RNA::synswch(int chance) {
	CodonNode *c = m_chain;
	do {
		if (chance != 100 && simRand(0, 100) <= chance) {
			c->codon->process();
		}
		c = c->next;
	} while (c != 0);
}

/**
 * Process the chain, with a given chance of processing individual codons
 * This goes through every codon, and has a chance of "synswch" it meaning
 * the codon will choose either itself or another, synonymous codon, instead
 */
void RNA::process(int chance, PopulationNode *pop) {
	chance = chance % 100;

	m_time += get_time();
	m_product++;
	RNA::t_product++;
	printf("%f, %d\n", m_time, t_product);

	if (m_product >= 3 && m_product % 3 == 0) {
		// After 3 products, mutate self and add to pop
		RNA *n = clone();
		n->synswch(chance);
		pop->add_RNA(n);
	}
}

/**
 * Returns the time it takes to translate this chain
 */
float RNA::get_time() {
	float t = 0;

	CodonNode *c = m_chain;
	do {
		t += c->codon->get_time();
		c = c->next;
	} while (c != 0);

	return t;
}

/**
 * Print the chain (including time to translate)
 */
void RNA::print() {
	CodonNode *c = m_chain;
	while (c->next != 0) {
		printf("%s-", dCodonToS(c->codon->get_type()));
		c = c->next;
	}
	printf("%s (%fms)\n", dCodonToS(c->codon->get_type()), get_time());
}

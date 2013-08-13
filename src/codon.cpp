
#include "codon.h"

/**
 * Picks a random Codon
 */
Codon::Codon(int *trna) {
	m_type = 0;
	m_mapCount = 0;
	m_cognate = 0;
	m_nearCognate = 0;
	m_trna_map = trna;
	
	setValue(simRand(1, 64));
}

/**
 * Choose a specific Codon
 */
Codon::Codon(int *trna, int t) {
	m_type = 0;
	m_mapCount = 0;
	m_cognate = 0;
	m_nearCognate = 0;
	m_trna_map = trna;
	
	setValue(t);
}

Codon::~Codon() {
	delete[] m_map;
}

/**
 * Set the Codon value
 */
void Codon::setValue(int val) {
	m_type = val;

	m_cognate = countCognate(val);
	m_nearCognate = countNearCognate(val);

	if (m_mapCount != 0) return;

	// Get our map
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 6; j++) {
			if (codonMap[i][j] == m_type) {

				// Set map Count
				m_mapCount = 0;
				for (int k = 0; k < 6; k++)
					if (codonMap[i][k] != 0)
						m_mapCount++;
					else
						break;

				// Set map - this function can only be called once, so dont worry about an old array
				m_map = new int[m_mapCount];
				for (int k = 0; k < 6; k++)
					if (codonMap[i][k] != 0)
						m_map[k] = codonMap[i][k];
					else
						break;

				return;
			}
		}
	}
}

/**
 * Counts Cognate tRNA for a given codon
 */
int Codon::countCognate(int codon) {
	const int *map = cognateMap[codon];
	return m_trna_map[map[0]] + m_trna_map[map[1]];
}

/**
 * Counts Near-Cognate tRNA for a given codon
 */
int Codon::countNearCognate(int codon) {
	const int *map = nearCognateMap[codon];
	int count = 0;
	for (int i = 0; i < 6; i++)
		count += m_trna_map[map[i]];
	return count;
}

/**
 * Return the Amino Acid representation
 */
int Codon::toAminoAcid() {
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 6; j++)
			if (codonMap[i][j] == m_type) return i;
	return -1;
}

void Codon::optimal() {
	float bestTime = get_time();
	for (int i = 0; i < m_mapCount; i++) {
		if (m_map[i] != 0) {
			float cTime = get_time(countCognate(m_map[i]), countNearCognate(m_map[i]));
			if (bestTime > cTime) {
				bestTime = cTime;
				setValue(m_map[i]);
			}
		}
	}
}

void Codon::suboptimal() {
	float worstTime = get_time();
	for (int i = 0; i < m_mapCount; i++) {
		if (m_map[i] != 0) {
			float cTime = get_time(countCognate(m_map[i]), countNearCognate(m_map[i]));
			if (worstTime < cTime) {
				worstTime = cTime;
				setValue(m_map[i]);
			}
		}
	}
}

/**
 * Mutates this codon (with guaranteed mutation)
 */
void Codon::mutate() {
	if (m_mapCount <= 1) return; // We can do nothing.

	// Create a map without the current type in it
	int *map = new int[m_mapCount - 1];
	int ptr = 0;
	for (int i = 0; i < m_mapCount; i++) {
		if (m_map[i] != 0 && m_map[i] != m_type) {
			map[ptr++] = m_map[i];
		}
	}

	// Finally! Pick a random new Codon
	int old = m_type;
	setValue(map[simRand(0, m_mapCount - 2)]);

	// Cleanup
	delete[] map;
}

/**
 * Processes the Codon (chance of mutation)
 */
void Codon::process() {
	if (m_mapCount <= 1) return; // We cant do anything.

	setValue(m_map[simRand(0, m_mapCount - 1)]);
}
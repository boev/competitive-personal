/*
 * index_tree.cpp
 *
 *  Created on: May 2, 2019
 *      Author: danko
 */
#include <iostream>
#include <vector>

#define MAXVAL 300
/**
 * Implementation for + operation. Can be easily transformed for other reversible operations or V can overload + operation.
 * Type not restricted on purpose.
 * Assumes 1-array indexing, otherwise lowest-set-bit trick does not work.
 */
template<typename V>
class IndexTree {

private:
	std::vector<V> data;

public:
	IndexTree(int n) {
		data.resize(n + 1, 0);
	}

	IndexTree(const std::vector<V> &list) {
		// O(n) initialization
		for (int i = 0; i < list.size(); i++) {
			data[i + 1] = list[i];
		}
		for (int i = 1; i < data.size(); i++) {
			int inext = i + (i & -i);
			if (inext < data.size()) {
				data[inext] += data[i];
			}
		}
	}

	/**
	 * 1-array indexing
	 * O(log n)
	 */
	void update(int id, V value) {
		while (id < data.size()) {
			data[id] += value;
			id += (id & (-id));
		}
	}

	/**
	 * 1-array indexing, inclusive on both
	 */
	V range_query(int from, int to) {
		if (from <= 1) {
			return prefix_query(to);
		}
		return prefix_query(to) - prefix_query(from - 1);
	}

	/**
	 * 1-array indexing
	 * O(log n)
	 */
	V prefix_query(int id) {
		V rslt = 0;
		while (id > 0) {
			rslt += data[id];
			id -= (id & (-id));
		}
		return rslt;
	}
};

template<typename V>
class ArrayImplementation {

private:
	std::vector<V> data;

public:
	ArrayImplementation(int n) {
		data.resize(n + 1, 0);
	}

	/**
	 * O(n)
	 */
	ArrayImplementation(const std::vector<V> &list) {
		for (int i = 0; i < list.size(); i++) {
			data[i + 1] = list[i];
		}
	}

	/**
	 * O(1)
	 */
	void update(int id, V value) {
		data[id] += value;
	}

	/**
	 * 1-array indexing, inclusive on both
	 * O(n)
	 */
	V range_query(int from, int to) {
		V rslt = 0;
		for (int i = from; i <= to; i++) {
			rslt += data[i];
		}
		return rslt;
	}

};

int main() {

	// seed for rand()
	srand(time(NULL));

	int n;
	std::cout << "Enter size: ";
	std::cin >> n;
	IndexTree<int> index_tree(n);
	ArrayImplementation<int> array_impl(n);
	int count = 0;
	while (1) {
		int updateId = rand() % n;
		int val = rand() % MAXVAL;
		val = val - (MAXVAL / 2);
		updateId++;
		index_tree.update(updateId, val);
		array_impl.update(updateId, val);

		int id1 = rand() % n;
		int id2 = rand() % n;
		id1++;
		id2++;
		int from = std::min(id1, id2);
		int to = std::max(id1, id2);
		if (index_tree.range_query(from, to)
				!= index_tree.range_query(from, to)) {
			std::cout << "Range " << from << " " << to << " different values\n";
			std::cout << " Index Tree says: "
					<< index_tree.range_query(from, to) << "\n";
			std::cout << " Array Impls says: "
					<< array_impl.range_query(from, to) << "\n";
			throw std::logic_error("Implementation have different values!");
		}
		count++;
		if (count % (1<<20) == 0) {
			std::cout << "1M update/query pairs all correct.\n";
		}

	}
	return 0;
}


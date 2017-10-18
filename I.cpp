#include <iostream>

void qsort(int array[], int lo, int lhi)
{
	int i = lo, j = lhi;
	int changer;
	int middle = array[(lhi + lo) / 2];

	while (i <= j) {
		while (array[i] < middle) {
			i++;
		}
		while (array[j] > middle) {
			j--;
		}
		if (i <= j) {
			changer = array[i];
			array[i] = array[j];
			array[j] = changer;
			i++;
			j--;
		}
	}

	// Рекурсивно повторяем алгоритм
	if (lo < j)
		qsort(array, lo, j);
	if (i < lhi)
		qsort(array, i, lhi);

}

int main()
{
	int N, amount, summ;
	std::cin >> N;
	int array[N];
	summ = 0;
	for (int k1 = 0; k1 < N; k1++) {
		std::cin >> array[k1];
	}
	qsort(array, 0, N - 1);
	for (int k2 = 0; k2 < N-1; k2++) {
		amount = array[k2 + 1] - array[k2] - 1;
		summ += amount;
	}
	std::cout << summ << std::endl;
}

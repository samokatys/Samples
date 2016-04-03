// main.cpp : Defines the entry point for the console application.
//

#include <tchar.h>

#include <stdio.h>
#include <cstdlib>
#include <time.h>

#include <vector>
#include <algorithm>

#include "myalgorithms.h"

// const int TEST_DATA[] = { 16 };
const int TEST_DATA[] = { 16, 7, 10, 1, 5, 11, 3, 8, 14, 4, 2, 12, 6, 13, 9, 15 };
const int TEST_DATA_SIZE = sizeof(TEST_DATA) / sizeof(TEST_DATA[0]);

const int SEARCH_TEST_NUM = 4;

void printVector(const std::vector<int> &vec);

void testSeqFind();
void testBinFind();

void testSort();

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	testSeqFind();
	testBinFind();

	testSort();

	return 0;
}

void printVector(const std::vector<int> &vec)
{
	for (int i = 0; i < vec.size(); ++i) {
		printf("%d%c", vec[i], (i + 1) == vec.size() ? '\n' : ' ');
	}
}

void testSeqFind()
{
	printf("Start testing sequential search:\n");
	for (int i = 0; i < TEST_DATA_SIZE; ++i) {
		printf("%d%c", TEST_DATA[i], (i + 1) == TEST_DATA_SIZE ? '\n' : ' ');
	}

	const int *end = TEST_DATA + TEST_DATA_SIZE;
	for (int i = 0; i < SEARCH_TEST_NUM; ++i) {
		int val = 0;
		if (i == 0) {
			val = TEST_DATA[0];
		}
		else if (i == 1) {
			val = TEST_DATA[TEST_DATA_SIZE - 1];
		}
		else {
			val = 2 * (rand() % TEST_DATA_SIZE);
		}

		auto elem = seqfind(TEST_DATA, end, val);
		if (elem == end) {
			printf("The value=%d not found\n", val);
		}
		else {
			printf("The value=%d found, index=%d\n", val, elem - TEST_DATA);
		}
	}

	printf("----------------------------------\n");
}

void testBinFind()
{
	printf("Start testing binary search:\n");

	std::vector<int> vec(TEST_DATA, TEST_DATA + TEST_DATA_SIZE);
	std::sort(vec.begin(), vec.end());
	printVector(vec);
	

	for (int i = 0; i < SEARCH_TEST_NUM; ++i) {
		int val = 0;
		if (i == 0) {
			val = *vec.begin();
		}
		else if (i == 1) {
			val = *(vec.end() - 1);
		}
		else {
			val = 2 * (rand() % vec.size());
		}

		auto elem = binfind(vec.begin(), vec.end(), val);
		if (elem == vec.end()) {
			printf("The value=%d not found\n", val);
		}
		else {
			printf("The value=%d found, index=%d\n", val, elem - vec.begin());
		}
	}

	printf("----------------------------------\n");
}

void testSort()
{
	printf("Start testing binary search:\n");
	std::vector<int> vec(TEST_DATA, TEST_DATA + TEST_DATA_SIZE);
	printVector(vec);

	printf("STD sort:\n");
	std::sort(vec.begin(), vec.end());
	printVector(vec);

	vec.assign(TEST_DATA, TEST_DATA + TEST_DATA_SIZE);
	insertion_sort(vec.begin(), vec.end());
	printf("My insertion sort:\n");
	printVector(vec);
	
	vec.assign(TEST_DATA, TEST_DATA + TEST_DATA_SIZE);
	buble_sort(vec.begin(), vec.end());
	printf("My buble sort:\n");
	printVector(vec);

	vec.assign(TEST_DATA, TEST_DATA + TEST_DATA_SIZE);
	shell_sort(vec.begin(), vec.end());
	printf("My shell sort:\n");
	printVector(vec);
	

	printf("----------------------------------\n");
}

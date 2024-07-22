#include <cstdio>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end,
            int *output) {
  int sum = 0;
  for (auto it = start; it < end; ++it) {
    sum += *it;
  }
  *output = sum;

  thread::id this_id = std::this_thread::get_id();
  printf("쓰레드 %d 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start,
         *(end - 1), sum);
}

int main() {
  vector<int> data(10000);
  std::iota(begin(data), end(data), 0);

  vector<int> partial_sums(4);

  vector<thread> workers;
  for (int i = 0; i < 4; i++) {
    workers.push_back(thread(worker, data.begin() + i * 2500,
                             data.begin() + (i + 1) * 2500, &partial_sums[i]));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  int total = 0;
  for (int i = 0; i < 4; i++) {
    total += partial_sums[i];
  }
  std::cout << "Total sum: " << total << std::endl;
}
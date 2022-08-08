#include <iostream>
#include <vector>

struct Data {
	int val;
	int I, J;
};

int main() {
  int n, k;
	std::vector<int> maxCost(10000);
	  
	try	{
		int iter;
		std::cin >> iter;
		if (iter <= 0 && iter > 10000) throw "Error";

		for (int GLOB_I = 0; GLOB_I < iter; GLOB_I++) {

			std::cin >> n >> k;
			if (n % 2 != 0 && k <= 0 && n > 0 && k >= 1000) throw "Error";

			std::vector<int> arr(n);

			for (int i = 0; i < n; i++) {
				int input;
				std::cin >> input;
				arr[i] = input;
			}

			for (int i = 0; i < maxCost.size(); i++)
				maxCost[i] = 0;
			while (n) {
				std::vector<Data> data(n);
				for (int i = 0; i < n; i++) {
					for (int j = i + 1; j < n; j++) {
						data[i].val = (arr[i] + arr[j]) / k;
						data[i].I = i;
						data[i].J = j;
					}
				}

				Data max;
				max.val = 0;
				for (int i = 0; i < n - 1; i++) {
					if (data[i].val > max.val) {
						max.val = data[i].val;
						max.I = data[i].I;
						max.J = data[i].J;
					}
				}

				if (arr.size() != 0) {
					arr.erase(arr.begin() + max.I);
					arr.erase(arr.begin() + max.J - 1);
				}	else break;

				maxCost[GLOB_I] += max.val;
				n = n - 2;

			}
			std::cout << maxCost[GLOB_I] << std::endl;
		}
	}
	catch (const std::exception&)	{}

  return 0;
}

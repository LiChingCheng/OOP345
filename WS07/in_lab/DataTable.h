//Li-Ching, Cheng 143292175 SEE

#ifndef SICT_DATATABLE_H
#define SICT_DATATABLE_H
#include <iostream>
#include <fstream>
#include <utility>
#include <numeric>
#include <iomanip>
#include <vector>
#include <algorithm>

extern int FW;
extern int ND;

namespace sict {
	template <typename T>
	class DataTable {
		std::vector<T> xValue;
		std::vector<T> yValue;
		T mean()const;
		T sigma()const;
	public:
		DataTable(std::ifstream& file) {
			T x, y;
			if (file.is_open()) {
				while (file >> x >> y) {
					xValue.push_back(x);
					yValue.push_back(y);
				}
			}
		}

		void displayData(std::ostream& os) const {
			os << "Data Values" << std::endl << "------------" << std::endl;
			os << std::setw(FW) << std::right << "x" << std::setw(FW) << std::right << "y" << std::endl;
			for (size_t i = 0; i < xValue.size(); i++) {
				os << std::setw(FW) << std::right << std::setprecision(ND) << std::fixed << xValue[i] << std::setw(FW) << yValue[i] << std::endl;
			}
			os << std::endl;
		}

		void displayStatistics(std::ostream& os) const {
			os << "Statistics" << std::endl << "----------" << std::endl;
			os << std::setw(FW) << std::left << "  y mean " << " = " << std::setw(FW) << std::right << mean() << std::endl;
			os << std::setw(FW) << std::left << "  y sigma" << " = " << std::setw(FW) << std::right << sigma() << std::endl;
		}
	};

	template <typename T>
	T DataTable<T>::mean() const {
		T mean;
		mean = std::accumulate(yValue.begin(), yValue.end(), (T)0) / yValue.size();
		return mean;
	}

	template <typename T>
	T DataTable<T>::sigma() const {
		T count{ 0 };
		T sigma{ 0 };
		for (int i = 0; i < yValue.size(); i++) {
			count += (yValue[i] - mean())*(yValue[i] - mean());
		}
		sigma = std::sqrt(count / (yValue.size() - 1));
		return sigma;
	}
}
#endif // !SICT_DATATABLE_H

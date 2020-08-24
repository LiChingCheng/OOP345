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
		T mean() const;
		T sigma() const;
		T median() const;
		T slope() const;
		T intercept() const;
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
			os << std::setw(FW) << std::left << "  y mean    = " << std::setw(FW) << std::right << mean() << std::endl;
			os << std::setw(FW) << std::left << "  y sigma   = " << std::setw(FW) << std::right << sigma() << std::endl;
			os << std::setw(FW) << std::left << "  y median  = " << std::setw(FW) << std::right << median() << std::endl;
			os << std::setw(FW) << std::left << "  slope     = " << std::setw(FW) << std::right << slope() << std::endl;
			os << std::setw(FW) << std::left << "  intercept = " << std::setw(FW) << std::right << intercept() << std::endl;
		}
	};

	template <typename T>
	T DataTable<T>::mean() const {
		T mean = std::accumulate(yValue.begin(), yValue.end(), (T)0) / yValue.size();
		return mean;
	}

	template <typename T>
	T DataTable<T>::sigma() const {
		T count{ 0 };
		T sigma{ 0 };
		count = std::accumulate(yValue.begin(), yValue.end(), (T)0, [=](T a, T b) {return a + (b - mean())*(b + mean()); });
		sigma = std::sqrt(count / (yValue.size() - 1));
		return sigma;
	}

	template <typename T>
	T DataTable<T>::median() const {
		std::vector<T> sortY = yValue;
		std::sort(sortY.begin(), sortY.end());
		return sortY[sortY.size() / 2];
	}

	template <typename T>
	T DataTable<T>::slope() const {
		T size = xValue.size();
		T sumX = std::accumulate(xValue.begin(), xValue.end(), (T)0);
		T sumY = std::accumulate(yValue.begin(), yValue.end(), (T)0);
		T sumXY = std::inner_product(xValue.begin(), xValue.end(), yValue.begin(), (T)0);
		T sumXX = std::inner_product(xValue.begin(), xValue.end(), xValue.begin(), (T)0);
		T slope = (size*sumXY - sumX * sumY) / (size*sumXX - sumX * sumX);
		return slope;
	}

	template <typename T>
	T DataTable<T>::intercept() const {
		T sumX = std::accumulate(xValue.begin(), xValue.end(), (T)0);
		T sumY = std::accumulate(yValue.begin(), yValue.end(), (T)0);
		T intercept = (sumY - slope()*sumX) / xValue.size();
		return intercept;
	}
}
#endif // !SICT_DATATABLE_H

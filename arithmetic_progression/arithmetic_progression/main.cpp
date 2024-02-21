#include <iostream>
using namespace std;

class ArProg {
private:
	int a0, d;
public:
	ArProg(int a0, int d) { this->a0 = a0; this->d = d; }

	void operator<<(int n) {	//Вывод прогрессии по n-ый член
		if (n < 1) { cout << "Некорректный индекс: " << n << endl; }
		else {
			for (int i = 1; i <= n; i++) {
				int an = a0 + d * (i - 1);
				cout << an << " ";
			}
			cout << endl;
		}
	}

	int operator[](int n) {//Вывод n-ого члена прогрессии
		return a0 + d * (n - 1);
	}

	int operator()(int n) {	//Вывод суммы прогрессии по n-ый член
		int sum_prog = 0;
		for (int i = 1; i <= n; i++) {
			sum_prog += a0 + d * (i - 1);
		}
		return sum_prog;
	}

	int operator()(int n1, int n2) {//Вывод суммы прогрессии с n1 по n2
		int sum_prog = 0;
		for (int i = n1; i <= n2; i++) {
			sum_prog += (*this)[i];
		}
		return sum_prog;
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	ArProg prog1(2, 5);				//2, 7, 12, 17, 22, 27, ...
	prog1 << 10;
	cout << prog1[4] << endl;		//17
	cout << prog1(4) << endl;		//38
	cout << prog1(3, 3) << endl;	//12
	cout << prog1(2, 5) << endl;	//58
	return 0;
}
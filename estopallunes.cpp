#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

void mostrar1(int x)
{
	cout << "Mostrando primer termino: " << x << endl;
}

void mostrar2(int y)
{
	cout << "Mostrando segundo termino: " << y << endl;
}

void suma(int x, int y)
{
	cout << "mostrando suma: " << x+y << endl;
}

void resta(int x, int y)
{
	cout << "mostrando resta: " << x-y << endl;
}

void restainv(int x, int y)
{
	cout << "mostrando resta inversa: " << y-x << endl;
}

void multip(int x, int y)
{
	cout << "mostrando multiplicacion: " << x*y << endl;
}

void div(int x, int y)
{
	double divi;
	divi=x/y;
	cout << "mostrando division: " << divi << endl;
}

void divinv(int x, int y)
{
	double divi;
	divi=y/x;
	cout << "mostrando division inversa: " << divi << endl;
}

int main()
{
	int x, y;
	cout << "Primer Termino: " << endl;
	cin >> x;
	cout << "Segundo Termino: " << endl;
	cin >> y;
	thread t1(mostrar1, x);
	thread t2(mostrar2, y);
	thread t3(suma, x, y);
	thread t4(resta, x, y);
	thread t5(restainv, x, y);
	thread t6(multip, x, y);
	thread t7(div, x, y);
	thread t8(divinv, x, y);
	
	cout << "Ahora mismo se realizan ocho hebras simultaneas de funciones!" << endl;
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	
	cout << "Y ahora todas las hebras finalizaron..." << endl;
	return 0;
}

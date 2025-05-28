#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "array_utils.h"
#include "matrix_algorithms/traditional.h"
#include "matrix_algorithms/divide_and_conquer.h"
#include "matrix_algorithms/strassen.h"

using namespace std;
using namespace std::chrono;

std::vector<int> MATRIX_SIZE = {32, 64, 128, 256, 512, 1024, 2048, 4096};
std::vector<double> time_traditional, time_dr1, time_dr2;

void test_times()
{
    time_traditional.clear();
    time_dr1.clear();
    time_dr2.clear();

    for (int size : MATRIX_SIZE)
    {
        Matrix m1 = generate_matrix(size);
        Matrix m2 = generate_matrix(size);

        // Medición tiempo para algoritmo tradicional
        auto t1 = high_resolution_clock::now();
        traditional_multiplication(m1, m2);
        auto t2 = high_resolution_clock::now();
        double t_traditional = duration<double, milli>(t2 - t1).count();
        time_traditional.push_back(t_traditional);

        // Medición tiempo para DR1
        auto t3 = high_resolution_clock::now();
        dr1_multiplication(m1, m2);
        auto t4 = high_resolution_clock::now();
        double t_dr1 = duration<double, milli>(t4 - t3).count();
        time_dr1.push_back(t_dr1);

        // Medición tiempo para DR2
        auto t5 = high_resolution_clock::now();
        dr2_multiplication(m1, m2);
        auto t6 = high_resolution_clock::now();
        double t_dr2 = duration<double, milli>(t6 - t5).count();
        time_dr2.push_back(t_dr2);
    }
}

void print_results()
{
    cout << string(80, '=') << endl;
    cout << left << setw(15) << "n"
         << setw(25) << "Algoritmo Tradicional"
         << setw(25) << "DR1"
         << setw(25) << "DR2" << endl;

    ofstream archivo("./resultados.txt");
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    cout << string(80, '=') << endl;

    archivo << string(80, '=') << endl;
    archivo << left << setw(15) << "n"
            << setw(25) << "Algoritmo Tradicional"
            << setw(25) << "DR1"
            << setw(25) << "DR2" << endl;
    archivo << string(80, '=') << endl;

    for (size_t i = 0; i < MATRIX_SIZE.size(); ++i)
    {
        std::ostringstream ss_traditional, ss_dr1, ss_dr2;
        ss_traditional << fixed << setprecision(2) << time_traditional[i] << " ms";
        ss_dr1 << fixed << setprecision(2) << time_dr1[i] << " ms";
        ss_dr2 << fixed << setprecision(2) << time_dr2[i] << " ms";

        cout << left << setw(15) << MATRIX_SIZE[i]
             << setw(25) << ss_traditional.str()
             << setw(25) << ss_dr1.str()
             << setw(25) << ss_dr2.str()
             << endl;

        archivo << left << setw(15) << MATRIX_SIZE[i]
                << setw(25) << fixed << setprecision(2) << time_traditional[i]
                << setw(25) << fixed << setprecision(2) << time_dr1[i]
                << setw(25) << fixed << setprecision(2) << time_dr2[i]
                << endl;
    }
    cout << string(80, '=') << endl;
    cout << "\n"
         << endl;

    archivo.close();
}
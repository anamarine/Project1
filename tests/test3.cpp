#include <iostream>
#include <Dense>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include<boost/random.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/timer/timer.hpp>

int main () {
    using namespace boost::numeric::ublas;
    using namespace boost::timer;
    using namespace std;
    using namespace boost::random;

    cpu_timer timer0;
    std::cout << "_________________________________________" << std::endl;
    std::cout << "     SW DEVELOPMENT TOOLS & METHODS      " << std::endl;
    std::cout << "                PROJECT 1                " << std::endl;
    std::cout << "_________________________________________" << std::endl;
    std::cout << "      Execution with BOOST/UBLAS         " << std::endl;
    std::cout << "_________________________________________" << std::endl;

    const int size = 500;
    std::cout << "\nSelected matrix size: " << size << std::endl;

    matrix <double> m1(size,size);
    matrix <double> m2(size,size);
    boost::numeric::ublas::vector <double> v(size);
    double s = rand() % 100;

    std::cout << "\nCreating random matrix 1, m1..." << std::endl;
    std::cout << "\n Creating random matrix 2, m2..." << std::endl;
    std::cout << "\n Creating random vector, v" << std::endl;

    for (unsigned i = 0; i < m1.size1(); ++ i) {
        for (unsigned j = 0; j < m1.size2 (); ++ j) {
            m1(i, j) = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
            m2(i, j) = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
        }
        v (i) = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
    }

    matrix <double > res1 (size, size);
    matrix <double > res2 (size, size);
    matrix <double > res3 (size, size);
    boost::numeric::ublas::vector <double > res4 (size);
    matrix <double > res5 (size, size);
    matrix <double > res6 (size, size);

    std::cout << "_________________________________________" << std::endl;
    std::cout << "Executing Test 1 - addition & subtraction" << std::endl;
    std::cout << "_________________________________________" << std::endl;

    cpu_timer timer;
    std::cout << "Executing m1 + m2..." << std::endl << std::endl;
    res1 = m1 + m2;
    string t1 = timer.format();

    timer.start();
    std::cout << "Executing m1 - m2..." << std::endl << std::endl;
    res2 = m1 - m2;
    string t2 = timer.format();

    timer.start();
    std::cout << "Executing m1 += m2..." << std::endl << std::endl;
    res3 = m1 += m2;
    string t3 = timer.format();

    std::cout << "_________________________________________" << std::endl;
    std::cout << "Executing Test 2 - multiplication" << std::endl;
    std::cout << "_________________________________________" << std::endl;

    timer.start();
    std::cout << "Multiplying by a vector v" << std::endl;
    cout << "Executing m1 * v..." << std::endl;
    res4 = prod(m1,v);
    string t4 = timer.format();

    timer.start();
    timer.start();
    std::cout << "\nMultiplying by a random scalar" << std::endl;
    cout << "Executing m2 * s..." << std::endl;
    res5 = m2 * s;
    string t5 = timer.format();

    timer.start();
    std::cout << "\nMultiplying two matrix" << std::endl;
    cout << "Executing m1 * m2..." << std::endl;
    res6 = prod(m1,m2);
    string t6 = timer.format();

    //std::cout << res1 << std::endl;
    //std::cout << res2 << std::endl;
    //std::cout << res3 << std::endl;
    //std::cout << res4 << std::endl;
    //std::cout << res5 << std::endl;
    //std::cout << res6 << std::endl;

    string t0 = timer0.format();

    std::cout << "\n_________________________________________" << std::endl;
    std::cout << "\n Execution times:" << std::endl;
    std::cout << "_________________________________________" << std::endl;
    std::cout << "m1 + m2" << endl << t1 << '\n';
    std::cout << "m1 - m2" << endl << t2 << '\n';
    std::cout << "m1 += m2" << endl << t3 << '\n';
    std::cout << "m1 * v" << endl << t4 << '\n';
    std::cout << "m2 * s" << endl << t5 << '\n';
    std::cout << "m1 * m2" << endl << t6 << '\n';
    std::cout << "\nTotal execution time:" << endl << t0 << '\n';

}


#include <iostream>
#include <Dense>
#include <boost/timer/timer.hpp>



using namespace Eigen;
using namespace std;
using namespace boost::timer;


using Eigen::MatrixXd;

int main()
{
    std::cout << "_________________________________________" << std::endl;
    std::cout << "     SW DEVELOPMENT TOOLS & METHODS      " << std::endl;
    std::cout << "                PROJECT 1                " << std::endl;
    std::cout << "_________________________________________" << std::endl;
    std::cout << "          Execution with EIGEN           " << std::endl;
    std::cout << "_________________________________________" << std::endl;
    const int size = 3;
    std::cout << "\nSelected matrix size: " << size << std::endl;
    std::cout << "\nCreating random matrix 1, m1" << std::endl;
    MatrixXd m1 = MatrixXd::Random(size,size);
    std::cout << m1 << std::endl;
    std::cout << "\n Creating random matrix 2, m2" << std::endl;
    MatrixXd m2 = MatrixXd::Random(size,size);
    std::cout << m2 << std::endl;

    std::cout << "_________________________________________" << std::endl;
    std::cout << "Executing Test 1 - addition & subtraction" << std::endl;
    std::cout << "_________________________________________" << std::endl;

    cpu_timer timer;
    std::cout << "Executing m1 + m2..." << std::endl << std::endl;
    MatrixXd m3 = m1 + m2;
    std::cout << m3 << std::endl << std::endl;
    string t1 = timer.format();

    timer.start();
    std::cout << "Executing m1 - m2..." << std::endl << std::endl;
    m3 = m1 - m2;
    std::cout << m3 << std::endl << std::endl;
    string t2 = timer.format();

    timer.start();
    std::cout << "Executing m1 += m2..." << std::endl << std::endl;
    m3 = m1 += m2;
    std::cout << m3 << std::endl;
    string t3 = timer.format();


    std::cout << "_________________________________________" << std::endl;
    std::cout << "Executing Test 2 - multiplication" << std::endl;
    std::cout << "_________________________________________" << std::endl;

    timer.start();
    std::cout << "Multiplying by a vector v" << std::endl;
    VectorXd v = VectorXd::Random(size);
    cout << "Executing m1 * v..." << std::endl;
    m3 = m1 * v;
    std::cout << m3 << std::endl;
    string t4 = timer.format();

    timer.start();
    std::cout << "\nMultiplying by a scalar, s = 3.75" << std::endl;
    double s = 3.75;
    cout << "Executing m2 * s..." << std::endl;
    m3 = m2 * s;
    std::cout << m3 << std::endl;
    string t5 = timer.format();

    timer.start();
    std::cout << "\nMultiplying two matrix" << std::endl;
    cout << "Executing m1 * m2..." << std::endl;
    m3 = m1 * m2;
    std::cout << m3 << std::endl;
    string t6 = timer.format();


    std::cout << "\n_________________________________________" << std::endl;
    std::cout << "\n Execution times:" << std::endl;
    std::cout << "_________________________________________" << std::endl;
    std::cout << "m1 + m2" << endl << t1 << '\n';
    std::cout << "m1 - m2" << endl << t2 << '\n';
    std::cout << "m1 += m2" << endl << t3 << '\n';
    std::cout << "m1 * v" << endl << t4 << '\n';
    std::cout << "m2 * s" << endl << t5 << '\n';
    std::cout << "m1 * m2" << endl << t6 << '\n';
}
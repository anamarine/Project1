#include <iostream>
#include <Dense>
#include <boost/timer/timer.hpp>



using namespace Eigen;
using namespace boost::timer;


using Eigen::MatrixXd;

int main()
{
    cpu_timer timer;
    std::cout << "_________________________________________" << std::endl;
    std::cout << "Executing Test 1 - addition & subtraction" << std::endl;
    std::cout << "_________________________________________" << std::endl;

    MatrixXd m1(2, 2);
    m1 << 1, 2, 3, 4;
    Matrix2d m2;
    m2 << 4, 3, 2, 1;
    std::cout << "\n matrix 1, m1:" << std::endl;
    std::cout << m1 << std::endl;
    std::cout << "\n matrix 2, m2:" << std::endl;
    std::cout << m2 << std::endl;
    std::cout << "\n m1 + m2" << std::endl << std::endl;
    std::cout << m1 + m2 << std::endl << std::endl;
    std::cout << "\n m1 - m2" << std::endl << std::endl;
    std::cout << m1 - m2 << std::endl << std::endl;
    std::cout << "\n m2 - m1" << std::endl << std::endl;
    std::cout << m2 - m1 << std::endl << std::endl;

    std::cout << "\n Execution time:" << std::endl;
    std::cout << timer.format() << '\n';
}
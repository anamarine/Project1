#include <iostream>
#include <Dense>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/timer/timer.hpp>

    int main () {
        using namespace boost::numeric::ublas;
        using namespace boost::timer;

        cpu_timer timer;

        std::cout << "_________________________________________" << std::endl;
        std::cout << "Executing Test 2 - ublas" << std::endl;
        std::cout << "_________________________________________" << std::endl;

        matrix <double > m (100, 100);
        vector <double > v (100);
        for (unsigned i = 0; i < std::min (m.size1 (), v.size ()); ++ i) {
            for (unsigned j = 0; j < m.size2 (); ++ j)
                m (i, j) = 3 * i + j;
            v (i) = i;
        }

        vector <double > res1 (3);
        vector <double > res2 (3);
        matrix <double > res3 (3, 3);
        res1 = prod(m,v);
        res2 = prod(v,m);
        res3 = prod(m,m);
        std::cout << res1 << std::endl;
        std::cout << res2 << std::endl;
        std::cout << res3 << std::endl;

        std::cout << "\n Execution time:" << std::endl;
        std::cout << timer.format() << '\n';
    }





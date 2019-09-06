#include "catch2/catch.hpp"

#include <cstddef>

#include "blaspp/blas.hh"

#include "measure.hpp"

TEST_CASE("`orient_2d`", "[measure]") {
    //Just basic tests. Relying mostly on `test_tri_measure`.
    const std::size_t N = 2;
    const double a[N] = {5, 3};
    const double b[N] = {3, 4};
    const double c[N] = {3, 3};
    REQUIRE(helpers::orient_2d(a, b, c) == 2);
    REQUIRE(helpers::orient_2d(b, a, c) == -2);
    REQUIRE(helpers::orient_2d(a, a, c) == 0);
}

TEST_CASE("`orient_3d`", "[measure]") {
    //Just basic tests. Relying mostly on `test_tet_measure`.
    const std::size_t N = 3;
    const double a[N] = {0, 23, 1};
    const double b[N] = {-8, 3, -2};
    const double c[N] = {8, 8, 0};
    const double d[N] = {-4, 22, -1};
    const double determinant = 428;
    REQUIRE(helpers::orient_3d(a, b, c, d) == determinant);
    REQUIRE(helpers::orient_3d(a, b, d, c) == -determinant);
}

TEST_CASE("edge measure", "[measure]") {
    const std::size_t N = 6;
    const double a[N] = {
        0, 0, 0,
        1,-2, 3
    };
    const double base_length = helpers::edge_measure(a);
    REQUIRE(base_length == Approx(std::sqrt(14)));

    SECTION("edge measure respects translation invariance") {
        double b[N];
        blas::copy(N, a, 1, b, 1);
        const double shift[3] = {2, -10, 5};
        for (std::size_t i = 0; i < N; i += 3) {
            blas::axpy(3, 1, shift, 1, b + i, 1);
        }
        REQUIRE(helpers::edge_measure(b) == Approx(base_length));
    }

    SECTION("edge measure behaves properly under dilation") {
        const double factors[3] = {0.5, 2, 5};
        for (double factor : factors) {
            double b[N];
            blas::copy(6, a, 1, b, 1);
            //Scale both endpoints at once.
            blas::scal(N, factor, b, 1);
            //Relying on `factor` being nonnegative here.
            const double expected = factor * base_length;
            REQUIRE(helpers::edge_measure(b) == Approx(expected));
        }
    }

    SECTION("edge measure invariant under permutation") {
        double b[N];
        blas::copy(3, a + 0, 1, b + 3, 1);
        blas::copy(3, a + 3, 1, b + 0, 1);
        REQUIRE(helpers::edge_measure(b) == Approx(base_length));
    }
}

TEST_CASE("triangle measure", "[measure]") {
    const std::size_t N = 9;
    const double a[N] = {
        3, 1, 1,
        0, 2, 0,
        0, 4, -2
    };
    const double base_area = helpers::tri_measure(a);
    {
        const double expected = 4.242640687119284;
        REQUIRE(base_area == Approx(expected));
    }

    SECTION("triangle measure respects translation invariance") {
        double b[N];
        blas::copy(N, a, 1, b, 1);
        const double shift[3] = {21, 21, 3};
        for (std::size_t i = 0; i < N; i += 3) {
            blas::axpy(3, 1, shift, 1, b + i, 1);
        }
        REQUIRE(helpers::tri_measure(b) == Approx(base_area));
    }

    SECTION("triangle measure behaves properly under dilation") {
        const double factors[3] = {0.01, 121, 920};
        for (double factor : factors) {
            double b[N];
            blas::copy(N, a, 1, b, 1);
            //Scale all vertices at once.
            blas::scal(N, factor, b, 1);
            const double expected = factor * factor * base_area;
            REQUIRE(helpers::tri_measure(b) == Approx(expected));
        }
    }

    SECTION("triangle measure invariant under permutation") {
        double b[N];
        blas::copy(3, a + 0, 1, b + 3, 1);
        blas::copy(3, a + 3, 1, b + 6, 1);
        blas::copy(3, a + 6, 1, b + 0, 1);
        REQUIRE(helpers::tri_measure(b) == Approx(base_area));
    }
}

TEST_CASE("tetrahedron measure", "[measure]") {
    const std::size_t N = 12;
    const double a[N] = {
        0, 0, 0,
        1, 0, 0,
        0, 2, 0,
        0, 0, -4
    };
    const double base_volume = helpers::tet_measure(a);
    {
        const double expected = 8. / 6.;
        REQUIRE(base_volume == Approx(expected));
    }

    SECTION("tetrahedron measure respects translation invariance") {
        double b[N];
        blas::copy(N, a, 1, b, 1);
        const double shift[3] = {-3, 17, 92};
        for (std::size_t i = 0; i < N; i += 3) {
            blas::axpy(3, 1, shift, 1, b + i, 1);
        }
        REQUIRE(helpers::tet_measure(b) == Approx(base_volume));
    }

    SECTION("tetrahedron measure behaves properly under dilation") {
        const double factors[3] = {0.375, 1.8, 12};
        for (double factor : factors) {
            double b[N];
            blas::copy(N, a, 1, b, 1);
            //Scale all vertices at once.
            blas::scal(N, factor, b, 1);
            //Relying on `factor` being nonnegative here.
            const double expected = factor * factor * factor * base_volume;
            REQUIRE(helpers::tet_measure(b) == Approx(expected));
        }
    }

    SECTION("tetrahedron measure invariant under permutation") {
        double b[N];
        blas::copy(3, a + 0, 1, b + 6, 1);
        blas::copy(3, a + 3, 1, b + 0, 1);
        blas::copy(3, a + 6, 1, b + 9, 1);
        blas::copy(3, a + 9, 1, b + 3, 1);
        REQUIRE(helpers::tet_measure(b) == Approx(base_volume));
    }
}

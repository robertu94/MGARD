#include <string>
#include <vector>

#include "mgard_nuni_float.h"

namespace mgard_common {

template <>
int parse_cmdl<float>(int argc, char **argv, int &nrow, int &ncol, int &nfib,
                      float &tol, float &s, std::string &in_file,
                      std::string &coord_file);

template <> float max_norm<float>(const std::vector<float> &v);

template <>
inline float interp_1d<float>(float x, float x1, float x2, float q00,
                              float q01);

template <>
inline float interp_2d<float>(float q11, float q12, float q21, float q22,
                              float x1, float x2, float y1, float y2, float x,
                              float y);

template <>
inline float interp_3d<float>(float q000, float q100, float q110, float q010,
                              float q001, float q101, float q111, float q011,
                              float x1, float x2, float y1, float y2, float z1,
                              float z2, float x, float y, float z);

template <>
inline float get_h<float>(const std::vector<float> &coords, int i, int stride);

template <>
inline float get_dist<float>(const std::vector<float> &coords, int i, int j);

template <>
void qread_2D_interleave<float>(const int nrow, const int ncol,
                                const int nlevel, float *v, std::string infile);

template <> inline short encode<float>(float x);

template <> inline float decode<float>(short x);

template <>
void qread_2D_bin<float>(const int nrow, const int ncol, const int nlevel,
                         float *v, std::string infile);

template <>
void qwrite_2D_bin<float>(const int nrow, const int ncol, const int nlevel,
                          const int l, float *v, float tol, float norm,
                          const std::string outfile);

template <>
void qwrite_2D_interleave<float>(const int nrow, const int ncol,
                                 const int nlevel, const int l, float *v,
                                 float tol, float norm,
                                 const std::string outfile);

template <>
void qwrite_3D_interleave<float>(const int nrow, const int ncol, const int nfib,
                                 const int nlevel, const int l, float *v,
                                 float tol, float norm,
                                 const std::string outfile);

template <>
void qwrite_3D_interleave2<float>(const int nrow, const int ncol,
                                  const int nfib, const int nlevel, const int l,
                                  float *v, float tol, float norm,
                                  const std::string outfile);

template <>
void copy_slice<float>(float *work, std::vector<float> &work2d, int nrow,
                       int ncol, int nfib, int is);

template <>
void copy_from_slice<float>(float *work, std::vector<float> &work2d, int nrow,
                            int ncol, int nfib, int is);

} // namespace mgard_common

namespace mgard_cannon {

template <>
void assign_num_level<float>(const int nrow, const int ncol, const int l,
                             float *v, float num);

template <>
void subtract_level<float>(const int nrow, const int ncol, const int l,
                           float *v, float *work);

template <>
void pi_lminus1<float>(const int l, std::vector<float> &v,
                       const std::vector<float> &coords);

template <>
void restriction<float>(const int l, std::vector<float> &v,
                        const std::vector<float> &coords);

template <>
void prolongate<float>(const int l, std::vector<float> &v,
                       const std::vector<float> &coords);

template <>
void solve_tridiag_M<float>(const int l, std::vector<float> &v,
                            const std::vector<float> &coords);

template <>
void mass_matrix_multiply<float>(const int l, std::vector<float> &v,
                                 const std::vector<float> &coords);

template <>
void write_level_2D<float>(const int nrow, const int ncol, const int l,
                           float *v, std::ofstream &outfile);

template <>
void copy_level<float>(const int nrow, const int ncol, const int l, float *v,
                       std::vector<float> &work);

template <>
void copy_level3<float>(const int nrow, const int ncol, const int nfib,
                        const int l, float *v, std::vector<float> &work);

} // namespace mgard_cannon

namespace mgard_gen {

template <>
inline float *
get_ref<float>(std::vector<float> &v, const int n, const int no,
               const int i); // return reference to logical element

template <>
inline float get_h_l<float>(const std::vector<float> &coords, const int n,
                            const int no, int i, int stride);

template <>
float l2_norm<float>(const int l, const int n, const int no,
                     std::vector<float> &v, const std::vector<float> &x);

template <>
float l2_norm2<float>(const int l, int nr, int nc, int nrow, int ncol,
                      std::vector<float> &v, const std::vector<float> &coords_x,
                      const std::vector<float> &coords_y);

template <>
float l2_norm3<float>(const int l, int nr, int nc, int nf, int nrow, int ncol,
                      int nfib, std::vector<float> &v,
                      const std::vector<float> &coords_x,
                      const std::vector<float> &coords_y,
                      const std::vector<float> &coords_z);

template <>
void write_level_2D_l<float>(const int l, float *v, std::ofstream &outfile,
                             int nr, int nc, int nrow, int ncol);

template <>
void qwrite_3D<float>(const int nr, const int nc, const int nf, const int nrow,
                      const int ncol, const int nfib, const int nlevel,
                      const int l, float *v, const std::vector<float> &coords_x,
                      const std::vector<float> &coords_y,
                      const std::vector<float> &coords_z, float tol, float s,
                      float norm, const std::string outfile);

template <>
void quantize_3D<float>(const int nr, const int nc, const int nf,
                        const int nrow, const int ncol, const int nfib,
                        const int nlevel, float *v, std::vector<int> &work,
                        const std::vector<float> &coords_x,
                        const std::vector<float> &coords_y,
                        const std::vector<float> &coords_z, float norm,
                        float tol);

template <>
void quantize_3D<float>(const int nr, const int nc, const int nf,
                        const int nrow, const int ncol, const int nfib,
                        const int nlevel, float *v, std::vector<int> &work,
                        const std::vector<float> &coords_x,
                        const std::vector<float> &coords_y,
                        const std::vector<float> &coords_z, float s, float norm,
                        float tol);

template <>
void quantize_2D<float>(const int nr, const int nc, const int nrow,
                        const int ncol, const int nlevel, float *v,
                        std::vector<int> &work,
                        const std::vector<float> &coords_x,
                        const std::vector<float> &coords_y, float s, float norm,
                        float tol);

template <>
void dequantize_3D<float>(const int nr, const int nc, const int nf,
                          const int nrow, const int ncol, const int nfib,
                          const int nlevel, float *v,
                          std::vector<int> &out_data,
                          const std::vector<float> &coords_x,
                          const std::vector<float> &coords_y,
                          const std::vector<float> &coords_z);

template <>
void dequantize_3D<float>(const int nr, const int nc, const int nf,
                          const int nrow, const int ncol, const int nfib,
                          const int nlevel, float *v,
                          std::vector<int> &out_data,
                          const std::vector<float> &coords_x,
                          const std::vector<float> &coords_y,
                          const std::vector<float> &coords_z, float s);

template <>
void dequantize_2D<float>(const int nr, const int nc, const int nrow,
                          const int ncol, const int nlevel, float *v,
                          std::vector<int> &work,
                          const std::vector<float> &coords_x,
                          const std::vector<float> &coords_y, float s);

template <>
void dequant_3D<float>(const int nr, const int nc, const int nf, const int nrow,
                       const int ncol, const int nfib, const int nlevel,
                       const int l, float *v, float *work,
                       const std::vector<float> &coords_x,
                       const std::vector<float> &coords_y,
                       const std::vector<float> &coords_z, float s);

template <>
void copy_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                         int nrow, int ncol);

template <>
void subtract_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                             int nrow, int ncol);

template <>
void pi_lminus1_l<float>(const int l, std::vector<float> &v,
                         const std::vector<float> &coords, int n, int no);

template <>
void pi_lminus1_first<float>(std::vector<float> &v,
                             const std::vector<float> &coords, int n, int no);

template <>
void pi_Ql_first<float>(const int nr, const int nc, const int nrow,
                        const int ncol, const int l, float *v,
                        const std::vector<float> &coords_x,
                        const std::vector<float> &coords_y,
                        std::vector<float> &row_vec,
                        std::vector<float> &col_vec);

template <>
void pi_Ql<float>(const int nr, const int nc, const int nrow, const int ncol,
                  const int l, float *v, const std::vector<float> &coords_x,
                  const std::vector<float> &coords_y,
                  std::vector<float> &row_vec, std::vector<float> &col_vec);

template <>
void pi_Ql3D<float>(const int nr, const int nc, const int nf, const int nrow,
                    const int ncol, const int nfib, const int l, float *v,
                    const std::vector<float> &coords_x,
                    const std::vector<float> &coords_y,
                    const std::vector<float> &coords_z,
                    std::vector<float> &row_vec, std::vector<float> &col_vec,
                    std::vector<float> &fib_vec);

template <>
void pi_Ql3D_first<float>(
    const int nr, const int nc, const int nf, const int nrow, const int ncol,
    const int nfib, const int l, float *v, const std::vector<float> &coords_x,
    const std::vector<float> &coords_y, const std::vector<float> &coords_z,
    std::vector<float> &row_vec, std::vector<float> &col_vec,
    std::vector<float> &fib_vec);

template <>
void assign_num_level<float>(const int l, std::vector<float> &v, float num,
                             int n, int no);

template <>
void assign_num_level_l<float>(const int l, float *v, float num, int nr, int nc,
                               const int nrow, const int ncol);

template <>
void restriction_first<float>(std::vector<float> &v, std::vector<float> &coords,
                              int n, int no);

template <>
void solve_tridiag_M_l<float>(const int l, std::vector<float> &v,
                              std::vector<float> &coords, int n, int no);

template <>
void add_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                        int nrow, int ncol);

template <>
void add3_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                         int nf, int nrow, int ncol, int nfib);

template <>
void sub3_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                         int nf, int nrow, int ncol, int nfib);

template <>
void sub3_level<float>(const int l, float *v, float *work, int nrow, int ncol,
                       int nfib);

template <>
void sub_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                        int nf, int nrow, int ncol, int nfib);

template <>
void project_first<float>(const int nr, const int nc, const int nrow,
                          const int ncol, const int l_target, float *v,
                          std::vector<float> &work,
                          std::vector<float> &coords_x,
                          std::vector<float> &coords_y,
                          std::vector<float> &row_vec,
                          std::vector<float> &col_vec);

template <>
void prep_2D<float>(const int nr, const int nc, const int nrow, const int ncol,
                    const int l_target, float *v, std::vector<float> &work,
                    std::vector<float> &coords_x, std::vector<float> &coords_y,
                    std::vector<float> &row_vec, std::vector<float> &col_vec);

template <>
void mass_mult_l<float>(const int l, std::vector<float> &v,
                        std::vector<float> &coords, const int n, const int no);

template <>
void restriction_l<float>(const int l, std::vector<float> &v,
                          std::vector<float> &coords, int n, int no);

template <>
float ml2_norm3<float>(const int l, int nr, int nc, int nf, int nrow, int ncol,
                       int nfib, const std::vector<float> &v,
                       std::vector<float> &coords_x,
                       std::vector<float> &coords_y,
                       std::vector<float> &coords_z);

template <>
void prolongate_l<float>(const int l, std::vector<float> &v,
                         std::vector<float> &coords, int n, int no);

template <>
void refactor_1D<float>(const int l_target, std::vector<float> &v,
                        std::vector<float> &work, std::vector<float> &coords,
                        int n, int no);

template <>
void refactor_2D<float>(const int nr, const int nc, const int nrow,
                        const int ncol, const int l_target, float *v,
                        std::vector<float> &work, std::vector<float> &coords_x,
                        std::vector<float> &coords_y,
                        std::vector<float> &row_vec,
                        std::vector<float> &col_vec);

template <>
void refactor_2D_full<float>(const int nr, const int nc, const int nrow,
                             const int ncol, const int l_target, float *v,
                             std::vector<float> &work,
                             std::vector<float> &coords_x,
                             std::vector<float> &coords_y,
                             std::vector<float> &row_vec,
                             std::vector<float> &col_vec);

template <>
void refactor_2D_first<float>(const int nr, const int nc, const int nrow,
                              const int ncol, const int l_target, float *v,
                              std::vector<float> &work,
                              std::vector<float> &coords_x,
                              std::vector<float> &coords_y,
                              std::vector<float> &row_vec,
                              std::vector<float> &col_vec);

template <>
void copy3_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                          int nf, int nrow, int ncol, int nfib);

template <>
void copy3_level<float>(const int l, float *v, float *work, int nrow, int ncol,
                        int nfib);

template <>
void assign3_level_l<float>(const int l, float *v, float num, int nr, int nc,
                            int nf, int nrow, int ncol, int nfib);

template <>
void refactor_3D<float>(const int nr, const int nc, const int nf,
                        const int nrow, const int ncol, const int nfib,
                        const int l_target, float *v, std::vector<float> &work,
                        std::vector<float> &work2d,
                        std::vector<float> &coords_x,
                        std::vector<float> &coords_y,
                        std::vector<float> &coords_z);

template <>
void compute_zl<float>(const int nr, const int nc, const int nrow,
                       const int ncol, const int l_target,
                       std::vector<float> &work, std::vector<float> &coords_x,
                       std::vector<float> &coords_y,
                       std::vector<float> &row_vec,
                       std::vector<float> &col_vec);

template <>
void compute_zl_last<float>(const int nr, const int nc, const int nrow,
                            const int ncol, const int l_target,
                            std::vector<float> &work,
                            std::vector<float> &coords_x,
                            std::vector<float> &coords_y,
                            std::vector<float> &row_vec,
                            std::vector<float> &col_vec);

template <>
void prolongate_last<float>(std::vector<float> &v, std::vector<float> &coords,
                            int n, int no);

template <>
void prolong_add_2D<float>(const int nr, const int nc, const int nrow,
                           const int ncol, const int l_target,
                           std::vector<float> &work,
                           std::vector<float> &coords_x,
                           std::vector<float> &coords_y,
                           std::vector<float> &row_vec,
                           std::vector<float> &col_vec);

template <>
void prolong_add_2D_last<float>(const int nr, const int nc, const int nrow,
                                const int ncol, const int l_target,
                                std::vector<float> &work,
                                std::vector<float> &coords_x,
                                std::vector<float> &coords_y,
                                std::vector<float> &row_vec,
                                std::vector<float> &col_vec);

template <>
void prep_3D<float>(const int nr, const int nc, const int nf, const int nrow,
                    const int ncol, const int nfib, const int l_target,
                    float *v, std::vector<float> &work,
                    std::vector<float> &work2d, std::vector<float> &coords_x,
                    std::vector<float> &coords_y, std::vector<float> &coords_z);

template <>
void recompose_3D<float>(const int nr, const int nc, const int nf,
                         const int nrow, const int ncol, const int nfib,
                         const int l_target, float *v, std::vector<float> &work,
                         std::vector<float> &work2d,
                         std::vector<float> &coords_x,
                         std::vector<float> &coords_y,
                         std::vector<float> &coords_z);

template <>
void postp_3D<float>(const int nr, const int nc, const int nf, const int nrow,
                     const int ncol, const int nfib, const int l_target,
                     float *v, std::vector<float> &work,
                     std::vector<float> &coords_x, std::vector<float> &coords_y,
                     std::vector<float> &coords_z);

template <>
void recompose_2D<float>(const int nr, const int nc, const int nrow,
                         const int ncol, const int l_target, float *v,
                         std::vector<float> &work, std::vector<float> &coords_x,
                         std::vector<float> &coords_y,
                         std::vector<float> &row_vec,
                         std::vector<float> &col_vec);

template <>
void recompose_2D_full<float>(const int nr, const int nc, const int nrow,
                              const int ncol, const int l_target, float *v,
                              std::vector<float> &work,
                              std::vector<float> &coords_x,
                              std::vector<float> &coords_y,
                              std::vector<float> &row_vec,
                              std::vector<float> &col_vec);

template <>
void postp_2D<float>(const int nr, const int nc, const int nrow, const int ncol,
                     const int l_target, float *v, std::vector<float> &work,
                     std::vector<float> &coords_x, std::vector<float> &coords_y,
                     std::vector<float> &row_vec, std::vector<float> &col_vec);

template <>
void qwrite_2D_l<float>(const int nr, const int nc, const int nrow,
                        const int ncol, const int nlevel, const int l, float *v,
                        float tol, float norm, const std::string outfile);

template <>
float qoi_norm<float>(int nrow, int ncol, int nfib,
                      std::vector<float> &coords_x,
                      std::vector<float> &coords_y,
                      std::vector<float> &coords_z,
                      float (*qoi)(int, int, int, std::vector<float>), float s);

template <>
float qoi_norm<float>(int nrow, int ncol, int nfib,
                      std::vector<float> &coords_x,
                      std::vector<float> &coords_y,
                      std::vector<float> &coords_z,
                      float (*qoi)(int, int, int, float *), float s);

} // namespace mgard_gen

namespace mgard_2d {

namespace mgard_common {

template <>
int parse_cmdl<float>(int argc, char **argv, int &nrow, int &ncol, float &tol,
                      std::string &in_file, std::string &coord_file);

template <> float max_norm<float>(const std::vector<float> &v);

template <>
inline float interp_2d<float>(float q11, float q12, float q21, float q22,
                              float x1, float x2, float y1, float y2, float x,
                              float y);

template <>
inline float get_h<float>(const std::vector<float> &coords, int i, int stride);

template <>
inline float get_dist<float>(const std::vector<float> &coords, int i, int j);

template <>
void qread_2D_interleave<float>(const int nrow, const int ncol,
                                const int nlevel, float *v, std::string infile);

template <>
void qwrite_2D_interleave<float>(const int nrow, const int ncol,
                                 const int nlevel, const int l, float *v,
                                 float tol, float norm,
                                 const std::string outfile);

} // namespace mgard_common

namespace mgard_cannon {

template <>
void assign_num_level<float>(const int nrow, const int ncol, const int l,
                             float *v, float num);

template <>
void subtract_level<float>(const int nrow, const int ncol, const int l,
                           float *v, float *work);

template <>
void pi_lminus1<float>(const int l, std::vector<float> &v,
                       const std::vector<float> &coords);

template <>
void restriction<float>(const int l, std::vector<float> &v,
                        const std::vector<float> &coords);

template <>
void prolongate<float>(const int l, std::vector<float> &v,
                       const std::vector<float> &coords);

template <>
void solve_tridiag_M<float>(const int l, std::vector<float> &v,
                            const std::vector<float> &coords);

template <>
void mass_matrix_multiply<float>(const int l, std::vector<float> &v,
                                 const std::vector<float> &coords);

template <>
void write_level_2D<float>(const int nrow, const int ncol, const int l,
                           float *v, std::ofstream &outfile);

template <>
void copy_level<float>(const int nrow, const int ncol, const int l, float *v,
                       std::vector<float> &work);

} // namespace mgard_cannon

namespace mgard_gen {

template <>
inline float *get_ref<float>(std::vector<float> &v, const int n, const int no,
                             const int i);

template <>
inline float get_h_l<float>(const std::vector<float> &coords, const int n,
                            const int no, int i, int stride);

template <>
void write_level_2D_l<float>(const int l, float *v, std::ofstream &outfile,
                             int nr, int nc, int nrow, int ncol);

template <>
void copy_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                         int nrow, int ncol);

template <>
void subtract_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                             int nrow, int ncol);

template <>
void pi_lminus1_l<float>(const int l, std::vector<float> &v,
                         const std::vector<float> &coords, int n, int no);

template <>
void pi_lminus1_first<float>(std::vector<float> &v,
                             const std::vector<float> &coords, int n, int no);

template <>
void pi_Ql_first<float>(const int nr, const int nc, const int nrow,
                        const int ncol, const int l, float *v,
                        const std::vector<float> &coords_x,
                        const std::vector<float> &coords_y,
                        std::vector<float> &row_vec,
                        std::vector<float> &col_vec);

template <>
void pi_Ql<float>(const int nr, const int nc, const int nrow, const int ncol,
                  const int l, float *v, const std::vector<float> &coords_x,
                  const std::vector<float> &coords_y,
                  std::vector<float> &row_vec, std::vector<float> &col_vec);

template <>
void assign_num_level_l<float>(const int l, float *v, float num, int nr, int nc,
                               const int nrow, const int ncol);

template <>
void restriction_first<float>(std::vector<float> &v, std::vector<float> &coords,
                              int n, int no);

template <>
void solve_tridiag_M_l<float>(const int l, std::vector<float> &v,
                              std::vector<float> &coords, int n, int no);

template <>
void add_level_l<float>(const int l, float *v, float *work, int nr, int nc,
                        int nrow, int ncol);

template <>
void project_first<float>(const int nr, const int nc, const int nrow,
                          const int ncol, const int l_target, float *v,
                          std::vector<float> &work,
                          std::vector<float> &coords_x,
                          std::vector<float> &coords_y,
                          std::vector<float> &row_vec,
                          std::vector<float> &col_vec);

template <>
void prep_2D<float>(const int nr, const int nc, const int nrow, const int ncol,
                    const int l_target, float *v, std::vector<float> &work,
                    std::vector<float> &coords_x, std::vector<float> &coords_y,
                    std::vector<float> &row_vec, std::vector<float> &col_vec);

template <>
void mass_mult_l<float>(const int l, std::vector<float> &v,
                        std::vector<float> &coords, const int n, const int no);

template <>
void restriction_l<float>(const int l, std::vector<float> &v,
                          std::vector<float> &coords, int n, int no);

template <>
void prolongate_l<float>(const int l, std::vector<float> &v,
                         std::vector<float> &coords, int n, int no);

template <>
void refactor_2D<float>(const int nr, const int nc, const int nrow,
                        const int ncol, const int l_target, float *v,
                        std::vector<float> &work, std::vector<float> &coords_x,
                        std::vector<float> &coords_y,
                        std::vector<float> &row_vec,
                        std::vector<float> &col_vec);

template <>
void recompose_2D<float>(const int nr, const int nc, const int nrow,
                         const int ncol, const int l_target, float *v,
                         std::vector<float> &work, std::vector<float> &coords_x,
                         std::vector<float> &coords_y,
                         std::vector<float> &row_vec,
                         std::vector<float> &col_vec);

template <>
void prolongate_last<float>(std::vector<float> &v, std::vector<float> &coords,
                            int n, int no);

template <>
void postp_2D<float>(const int nr, const int nc, const int nrow, const int ncol,
                     const int l_target, float *v, std::vector<float> &work,
                     std::vector<float> &coords_x, std::vector<float> &coords_y,
                     std::vector<float> &row_vec, std::vector<float> &col_vec);

template <>
void qwrite_2D_l<float>(const int nr, const int nc, const int nrow,
                        const int ncol, const int nlevel, const int l, float *v,
                        float tol, float norm, const std::string outfile);

} // namespace mgard_gen

} // namespace mgard_2d

#include "mgard_nuni.tpp"

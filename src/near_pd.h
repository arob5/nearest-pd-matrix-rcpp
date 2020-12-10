#ifndef NEAR_PD_H_
#define NEAR_PD_H_

#include <armadillo> 

void ensure_symmetry(arma::mat& X, bool force_symmetry);
arma::mat nearPD_cpp(arma::mat& X, bool force_symmetry); 

#endif





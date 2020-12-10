#include <iostream>
#include <stdexcept> 
#include "near_pd.h"

void ensure_symmetry(arma::mat &X, bool force_symmetry) {
	if(!X.is_symmetric()) {
		if(force_symmetry) {
			std::cout << "X is not symmetric. Enforcing symmetry." << std::endl; 
			X = (X + X.t()) / 2; 
		} else {
			throw std::logic_error("X is not symmetric and force_symmetry is false."); 
		}
	}		
}

arma::mat nearPD_cpp(arma::mat &X, bool force_symmetry) {

	ensure_symmetry(X, force_symmetry); 

	/*
	n = X.ncols; 
	if(keep_diag)
		diag_X0 = diag(X); 
	*/

	return X; 

}

int main() {

	arma::arma_rng::set_seed_random(); 
	arma::mat X(5, 5, arma::fill::randu);  
	X = nearPD_cpp(X, true); 
	X.print(); 

	return 0; 

}



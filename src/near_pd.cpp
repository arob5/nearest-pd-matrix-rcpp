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

arma::mat nearPD_cpp(arma::mat &X, bool force_symmetry, bool keep_diag, size_t max_iter, bool do_dykstra) {

	ensure_symmetry(X, force_symmetry); 

	arma::uword n = X.n_cols; 
	if(keep_diag)
		arma::vec diag_X0 = X.diag(); 

	if(do_dykstra)
		arma::mat D_S(n, n, arma::fill::zeros);

	size_t iter = 0; 
	bool converged = false; 
	
	while(iter < max_iter && !converged) {
		iter += 1; 
	}


	return X; 

}

int main() {

	arma::arma_rng::set_seed_random(); 
	arma::mat X(5, 5, arma::fill::randu);  
	X = nearPD_cpp(X, true, true, 10); 
	X.print(); 

	return 0; 

}



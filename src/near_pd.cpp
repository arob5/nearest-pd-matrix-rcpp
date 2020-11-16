#include <iostream>
#include <stdexcept> 
#include <armadillo> 

using namespace std; 


arma::mat ensure_symmetry(arma::mat X, bool force_symmetry) {
	if(X.is_symmetric())
		return X; 

	if(force_symmetry)
		return (X + X.t()) / 2; 
	else
		throw std::logic_error("Matrix is not symmetric and force_symmetry is false."); 
}

arma::mat nearPD_cpp(arma::mat X, bool force_symmetry) {

	X = ensure_symmetry(X, force_symmetry); 

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
	nearPD_cpp(X, true); 
	X.print(); 

	return 0; 

}



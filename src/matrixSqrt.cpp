#include <Rcpp.h>
using namespace Rcpp;

//' Serially compute square root of matrix elements
//'
//' @param orig A matrix
//'
//' @returns A matrix in which each element is the square root of the corresponding element in the original matrix
//'
//' @examples
//' m <- matrix(as.numeric(c(1:1000000)), nrow = 1000, ncol = 1000)
//' matrixSqrt(m)
//' @export
// [[Rcpp::export]]
NumericMatrix matrixSqrt(NumericMatrix orig) {

  // allocate the matrix we will return
  NumericMatrix mat(orig.nrow(), orig.ncol());

  // transform it
  std::transform(orig.begin(), orig.end(), mat.begin(), ::sqrt);

  // return the new matrix
  return mat;
}

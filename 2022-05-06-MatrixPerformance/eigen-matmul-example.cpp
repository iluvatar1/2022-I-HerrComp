int main() {
double multiply(int size)
{
  // create matrices
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(size, size);

  auto start = std::chrono::steady_clock::now();
  auto C{A*B}; // MULTIPLY
  double tmp = C(0, 0); // use the matrix to make eigen compute it
  auto end = std::chrono::steady_clock::now();

  std::clog << tmp << std::endl; // use the matrix to make eigen compute it

  std::chrono::duration<double> elapsed_seconds = end-start;
  return elapsed_secons.count();
}
return 0;
}

#ifndef PID_H
#define PID_H
#include<vector>
#include<fstream>

using namespace std;
class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double twi_err;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  
  /*
  *Twiddle Variables
  */
  //Param vector
  std::vector<double> p;
  //Param change factor
  std::vector<double> dp;
  //Error variables
  double best_err, err;
  //flags and counter
  int flag, fsign, fchange, n, ctr;
  //Declaring file to write
  fstream myfile;
  //Twiddle init
  void initTwiddle();
  //Twiddle Function
  int Twiddle();
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

 };
 
#endif /* PID_H */

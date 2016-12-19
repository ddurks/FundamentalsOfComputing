//David Durkin
//Fund Comp II
//mortgage.h
//Class file

//Mortgage class with required functions and variables
class Mortgage{

public:
	Mortgage();
	Mortgage(double, double, double);
	void credit(double);
	double getPrincipal();
	void amortize();

private:
	double principal;
	double rate;
	double payment;

};

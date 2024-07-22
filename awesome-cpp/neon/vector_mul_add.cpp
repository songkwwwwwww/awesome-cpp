#include <iostream>
#include <vector>

#include <cstdlib>

const int MAX_N = 20000000;

std::vector<float> A(MAX_N,0);
std::vector<float> B(MAX_N,0);
std::vector<float> C(MAX_N,0);
std::vector<float> D(MAX_N,0);
std::vector<float> E(MAX_N,0);

std::vector<float> tmp1(MAX_N,0);
std::vector<float> tmp2(MAX_N,0);

void add(int n, std::vector<float>& A, std::vector<float>& B, std::vector<float>& C)
{
    for(int i = 0; i < n; i++)
    {
	C[i] = A[i] + B[i];
    }
}

void mul(int n, std::vector<float>& A, std::vector<float>& B, std::vector<float>& C)
{
    for(int i = 0; i < n; i++)
    {
	C[i] = A[i] * B[i];
    }
}

void fused(int n, std::vector<float>& A, std::vector<float>& B, std::vector<float>& C,
	std::vector<float>& D, std::vector<float>& E)
{
    for(int i = 0; i < n; i++)
    {

	C[i] = A[i] * B[i];
    }
}

void test1()
{
    std::cout << "test1" << std::endl;
    add(MAX_N, A, B, tmp1);
    mul(MAX_N, tmp1, C, tmp2);
    add(MAX_N, tmp2, D, E);
}

void test2()
{
    std::cout << "test2" << std::endl;
}

int main(int argc, char *argv[])
{

    if( argc < 2)
    {
	std::cout << "argc must be larger than 2" << std::endl;
	return 0;
    }

    int num = atoi(argv[1]);
    std::cout<< "argv[1] : " << num << std::endl;
    if( num == 1 )
    {
	test1();
    }
    else
    {
	test2();
    }

}

#include <vector>
#include <iostream>

typedef unsigned long long ull;

class ProdFib{
public:
  static std::vector<ull> productFib(ull prod){
    ull n_m2 = 0;
    ull n_m1 = 1;
    ull prod_n = 0;

    ull equal = 0;

    while(prod_n < prod){
      ull n = n_m1 + n_m2;
      n_m2 = n_m1;
      n_m1 = n;

      prod_n = n_m1*n_m2;
    }

    if(prod_n == prod) equal = 1;

    std::vector<ull> result = {n_m2, n_m1, equal};
    return result;
  }
};

int main(){
  const ull n = 800;
  auto productFib = ProdFib();
  auto result = productFib.productFib(n);

  std::cout << "{" << result[0] << ", " << result[1] << ", " << result[2] << "}" <<std::endl;
}
